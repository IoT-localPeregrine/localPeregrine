#include "../gnutella-cpp/include/net.hpp"

#include "../gnutella-c/include/net.h"

void gnutella_cpp::inet::init(std::string net_name) { inet_init(utils::ToSString(net_name)); }
void gnutella_cpp::inet::exit() { inet_exit(); }

NetError gnutella_cpp::inet::connect_to_network(std::string network_name) { inet_connect_to_network(utils::ToSString(network_name)); }
NetError gnutella_cpp::inet::explore_networks(void (*callback)(SString)) { inet_explore_networks((Wrapper_ExploreNetworkConsumerFunc){callback}); }

NetError gnutella_cpp::inet::create(std::string net_name) { inet_create(utils::ToSString(net_name)); }

NetError gnutella_cpp::inet::ping() { inet_ping(); }
NetError gnutella_cpp::inet::query(std::string criteria) { inet_query(utils::ToSString(criteria)); }

NetError subscribe_ping(::Peer (*callback)()) { inet_subscribe_ping((Wrapper_PingConsumerFunc){callback}); }
NetError subscribe_pong(void (*callback)(::Peer)) { inet_subscribe_pong((Wrapper_PongConsumerFunc){callback}); }
NetError subscribe_query(QueryHit (*callback)(SString)) { inet_subscribe_query((Wrapper_QueryConsumerFunc){callback}); }
NetError subscribe_query_hit(void (*callback)(QueryHit)) { inet_subscribe_query_hit((Wrapper_QueryHitConsumerFunc){callback}); }