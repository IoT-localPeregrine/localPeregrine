#pragma once

#include <string>
#include <functional>

#include "query_hit.hpp"
#include "peer.hpp"
#include "error.hpp"

namespace gnutella_cpp
{
    namespace inet
    {
        void init(std::string);

        NetError connect_to_network(std::string network_name);
        NetError explore_networks(void (*)(std::string));

        NetError create(std::string network_name);

        NetError ping();
        NetError query(std::string criteria);

        NetError subscribe_ping(Peer (*)());
        NetError subscribe_pong(void (*)(Peer));
        NetError subscribe_query(QueryHit (*)(std::string));
        NetError subscribe_query_hit(void (*)(QueryHit));
    };
}
