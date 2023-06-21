#include "../gnutella-cpp/include/peer.hpp"

gnutella_cpp::Peer::operator ::Peer() const {
    return (struct Peer) {.id = id, .number_of_files_shd = number_of_files_shd, .number_of_kb_shd = number_of_kb_shd};
} 

