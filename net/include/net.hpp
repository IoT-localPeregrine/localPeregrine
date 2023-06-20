#pragma once

#include "string.h"
#include "address.h"
#include "peer.h"
#include "error.h"
#include "query_hit.h"

struct INet;

struct INet *inet_new();

NetError inet_connect_to_network(struct INet, String network_name);
NetError inet_explore_networks(struct INet, void (*consumer_fnc)(String net_name));

NetError inet_ping(struct INet);
NetError inet_pong(struct INet, Address targ_adr, Peer peer);
NetError inet_query(struct INet, String criteria);
NetError inet_query_hit(struct INet, QueryHit query_hit);

NetError inet_subscribe_ping(void (*consumer_fnc)());
NetError inet_subscribe_pong(void (*consumer_fnc)(Peer peer));
NetError inet_subscribe_query(void (*consumer_fnc)(struct string criteria));
NetError inet_subscribe_query_hit(void (*consumer_fnc)(QueryHit hit_details));