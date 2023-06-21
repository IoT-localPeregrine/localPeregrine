#pragma once

#include <stdint.h>
#include <string>
#include <list>

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
        void AddTrackedPeer(Peer) noexcept;
    };
}
