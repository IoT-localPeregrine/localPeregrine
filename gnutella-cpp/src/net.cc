#include "gnutella-cpp/include/net.hpp"

#include "gnutella-c/include/net.h"

extern "C"
{
    void gnutella_cpp::inet::init(std::string net_name) { inet_init(utils::ToSString(net_name)); }

    NetError gnutella_cpp::inet::connect_to_network(std::string network_name) { return inet_connect_to_network(utils::ToSString(network_name)); }
    NetError gnutella_cpp::inet::explore_networks(void (*callback)(SString)) { return inet_explore_networks((Wrapper_ExploreNetworkConsumerFunc){callback}); }

    NetError gnutella_cpp::inet::create(std::string net_name) { return inet_create(utils::ToSString(net_name)); }

    NetError gnutella_cpp::inet::ping() { return inet_ping(); }
    NetError gnutella_cpp::inet::query(std::string criteria) { return inet_query(utils::ToSString(criteria)); }

    NetError subscribe_ping(::Peer (*callback)()) { return inet_subscribe_ping((Wrapper_PingConsumerFunc){callback}); }
    NetError subscribe_pong(void (*callback)(::Peer)) { return inet_subscribe_pong((Wrapper_PongConsumerFunc){callback}); }
    NetError subscribe_query(::QueryHit (*callback)(SString)) { return inet_subscribe_query((Wrapper_QueryConsumerFunc){callback}); }
    NetError subscribe_query_hit(void (*callback)(::QueryHit)) { return inet_subscribe_query_hit((Wrapper_QueryHitConsumerFunc){callback}); }
}