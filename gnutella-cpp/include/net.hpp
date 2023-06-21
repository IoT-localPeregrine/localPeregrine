#pragma once

#include <string>
#include <functional>

#include "query_hit.hpp"
#include "peer.hpp"
#include "utils.hpp"

#include "../gnutella-c/include/error.h"
#include "../gnutella-c/include/net.h"

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

        NetError subscribe_ping(Peer (*)());
        NetError subscribe_pong(void (*)(Peer));
        NetError subscribe_query(QueryHit (*)(SString));
        NetError subscribe_query_hit(void (*)(QueryHit));
    };
}

void gnutella_cpp::inet::init(std::string net_name) { inet_init(utils::ToSString(net_name)); }
void gnutella_cpp::inet::exit() { inet_exit(); }

NetError gnutella_cpp::inet::connect_to_network(std::string network_name) { inet_connect_to_network(utils::ToSString(network_name)); }
NetError gnutella_cpp::inet::explore_networks(void (*callback)(SString)) { inet_explore_networks((Wrapper_ExploreNetworkConsumerFunc){callback}); }

NetError gnutella_cpp::inet::create(std::string net_name) { inet_create(utils::ToSString(net_name)); }

NetError gnutella_cpp::inet::ping() { inet_ping(); }
NetError gnutella_cpp::inet::query(std::string criteria) { inet_query(utils::ToSString(criteria)); }

NetError subscribe_ping(Peer (*callback)()) { inet_subscribe_ping((Wrapper_PingConsumerFunc){callback}); }
NetError subscribe_pong(void (*callback)(Peer)) { inet_subscribe_pong((Wrapper_PongConsumerFunc){callback}); }
NetError subscribe_query(QueryHit (*callback)(SString)) { inet_subscribe_query((Wrapper_QueryConsumerFunc){callback}); }
NetError subscribe_query_hit(void (*callback)(QueryHit)) { inet_subscribe_query_hit((Wrapper_QueryHitConsumerFunc){callback}); }
