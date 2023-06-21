#pragma once

#include <stdint.h>
#include <string>
#include <list>

#include "utils.hpp"

#include "gnutella-c/include/peer.h"

namespace gnutella_cpp
{
    struct Peer
    {
        std::string id;
        uint32_t number_of_files_shd;
        uint32_t number_of_kb_shd;

    public:
        std::list<Peer> network_peers;

    public:
        Peer(::Peer c_peer) : id(utils::FromSString(c_peer.id)), number_of_files_shd(c_peer.number_of_files_shd), number_of_kb_shd(c_peer.number_of_kb_shd) {}
        operator ::Peer() const;

    public:
        void AddTrackedPeer(Peer) noexcept;
    };
}