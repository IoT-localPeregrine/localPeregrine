#include "gnutella-cpp/include/peer.hpp"

void gnutella_cpp::Peer::AddTrackedPeer(Peer new_peer) noexcept
{
    network_peers.push_back(new_peer);
}
