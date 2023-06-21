#pragma once

extern "C"
{

#include "sstring.h"
#include "peer.h"
#include "error.h"
#include "query_hit.h"

#define WRAP(FUNC_NAME) \
    typedef struct      \
    {                   \
        FUNC_NAME func; \
    } Wrapper_##FUNC_NAME;

    void inet_init(SString);
    void inet_exit();

    NetError inet_connect_to_network(SString network_name);

    typedef void (*ExploreNetworkConsumerFunc)(SString host_name);
    WRAP(ExploreNetworkConsumerFunc);
    NetError inet_explore_networks(Wrapper_ExploreNetworkConsumerFunc);

    NetError inet_create(SString network_name);

    NetError inet_ping();
    NetError inet_query(SString criteria);

    typedef Peer (*PingConsumerFunc)();
    WRAP(PingConsumerFunc);
    NetError inet_subscribe_ping(Wrapper_PingConsumerFunc);

    typedef void (*PongConsumerFunc)(Peer);
    WRAP(PongConsumerFunc);
    NetError inet_subscribe_pong(Wrapper_PongConsumerFunc src_peer);

    typedef QueryHit (*QueryConsumerFunc)(SString criteria);
    WRAP(QueryConsumerFunc);
    NetError inet_subscribe_query(Wrapper_QueryConsumerFunc);

    typedef void (*QueryHitConsumerFunc)(QueryHit);
    WRAP(QueryHitConsumerFunc);
    NetError inet_subscribe_query_hit(Wrapper_QueryHitConsumerFunc);
}