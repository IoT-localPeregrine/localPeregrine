#include "gnutella-cpp/include/peer.hpp"

gnutella_cpp::Peer::operator ::Peer() const
{
    return (struct ::Peer){.id = utils::ToSString(id), .number_of_files_shd = number_of_files_shd, .number_of_kb_shd = number_of_kb_shd};
}

void gnutella_cpp::Peer::AddTrackedPeer(Peer new_peer) noexcept
{
    network_peers.push_back(new_peer);
}
