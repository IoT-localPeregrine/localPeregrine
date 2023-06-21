#pragma once

#include <string>
#include <functional>

#include "query_hit.hpp"
#include "peer.hpp"

#include "../gnutella-c/include/error.h"

namespace gnutella_cpp
{
    namespace INet
    {
        void init(std::string);
        void exit();

        NetError connect_to_network(std::string network_name);
        NetError explore_networks(std::function<void(std::string)> explr_consumer_fnc);

        NetError create(std::string network_name);

        NetError ping();
        NetError query(std::string criteria);

        NetError subscribe_ping(std::function<Peer()> ping_consumer_fnc);
        NetError subscribe_pong(std::function<void(Peer)> ping_consumer_fnc);
        NetError subscribe_query(std::function<QueryHit(std::string)> query_consumer_fnc);
        NetError subscribe_query_hit(std::function<void(QueryHit)> query_hit_consumer_fnc);
    };
}