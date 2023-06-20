#pragma once

extern "C"
{
#include <string>
#include <functional>

#include "query_hit.hpp"
#include "address.hpp"
#include "peer.hpp"

    bool connect_to_network(std::string network_name);
    void explore_networks(std::function<void(std::string)> consume_net_name_func);

    void ping();
    void pong(Address targ_adr, Peer peer);
    void query(std::string criteria);
    void query_hit(QueryHit query_hit);

    void subscribe_ping(void (*consumer_fnc)());
    void subscribe_pong(void (*consumer_fnc)(Peer peer));
    void subscribe_query(void (*consumer_fnc)(std::string criteria));
    void subscribe_query_hit(void (*consumer_fnc)(QueryHit hit_details));
}