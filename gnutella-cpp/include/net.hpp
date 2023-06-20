#pragma once

#include <string>
#include <functional>

#include "query_hit.hpp"
#include "address.hpp"
#include "peer.hpp"

struct INet
{
    bool connect_to_network(const std::string &network_name);
    void explore_networks(std::function<void(std::string)> consume_net_name_func);

    void ping();
    void pong(const Address &targ_adr, const Peer &peer);
    void query(const std::string &criteria);
    void query_hit(const QueryHit &query_hit);

    void subscribe_ping(std::function<void()>);
    void subscribe_pong(void (*consumer_fnc)(Peer peer));
    void subscribe_query(void (*consumer_fnc)(std::string criteria));
    void subscribe_query_hit(void (*consumer_fnc)(QueryHit hit_details));
};