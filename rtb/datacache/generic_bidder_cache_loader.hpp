/*
 * File:   generic_bidder_cache_loader.hpp
 * Author: Vladimir Venediktov
 * Copyright (c) 2016-2018 Venediktes Gruppe, LLC
 *
 * Created on December 18, 2017, 1:42 PM
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef VANILLA_RTB_GENERIC_BIDDER_CACHE_LOADER_HPP
#define VANILLA_RTB_GENERIC_BIDDER_CACHE_LOADER_HPP

#include "rtb/core/core.hpp"

namespace vanilla {
    template<typename ...Entities>
    struct GenericBidderCacheLoader;

    template<typename Entity, typename ...Entities>
    struct GenericBidderCacheLoader<Entity, Entities ...> : GenericBidderCacheLoader<Entities ...> {
    public:
        template<typename Config>
        GenericBidderCacheLoader(const Config &config): GenericBidderCacheLoader<Entities...>(config), entity(config)
        {}
        void load() noexcept(false) {
           entity.load();
           GenericBidderCacheLoader<Entities...>::load();
        }
        Entity entity;
    };

    template<typename Entity>
    struct GenericBidderCacheLoader<Entity> {
    public:
        template<typename Config>
        GenericBidderCacheLoader(const Config &config): entity(config)
        {}
        void load() noexcept(false) {
            entity.load();
        }
        Entity entity;
    };
}


#endif //VANILLA_RTB_GENERIC_BIDDER_CACHE_LOADER_HPP