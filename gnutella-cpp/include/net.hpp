#pragma once

#include <string>
#include <functional>

#include "query_hit.hpp"
#include "peer.hpp"
#include "utils.hpp"

#include "../gnutella-c/include/error.h"

namespace gnutella_cpp
{
    namespace inet
    {
        void init(std::string);
        void exit();

        NetError connect_to_network(std::string network_name);
        NetError explore_networks(void (*)(SString));

        NetError create(std::string network_name);

        NetError ping();
        NetError query(std::string criteria);

        NetError subscribe_ping(::Peer (*)());
        NetError subscribe_pong(void (*)(::Peer));
        NetError subscribe_query(QueryHit (*)(SString));
        NetError subscribe_query_hit(void (*)(QueryHit));
    };
}
