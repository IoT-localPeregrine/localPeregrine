#pragma once

#include <stdio.h>
#include <memory>
#include <list>
#include <optional>

#include "gnutella-cpp/include/net.hpp"

#include "fs/include/repository.hpp"

#include "gnutella-cpp/include/utils.hpp"

namespace local_peregrine
{
    namespace net
    {
        class Network
        {
        private:
            static gnutella_cpp::Peer self_;
            static fs::Repository repository_;

        private:
            Network()
            {
                gnutella_cpp::inet::init("SomeName");

                gnutella_cpp::inet::subscribe_ping([]() -> ::Peer
                                                   { return self_; });

                gnutella_cpp::inet::subscribe_pong([](::Peer trg_peer) -> void
                                                   { self_.AddTrackedPeer(trg_peer); });

                gnutella_cpp::inet::subscribe_query([](SString sstring) -> ::QueryHit {
                    std::list<::File*> files = repository_.FindByCriteria(gnutella_cpp::utils::FromSString(sstring));
                    return gnutella_cpp::QueryHit(files);
                });

                gnutella_cpp::inet::subscribe_query_hit([](::QueryHit query_hit) -> void {
                    
                });
            }

        public:
            static Network &getInstance()
            {
                static Network instance;
                return instance;
            }

        public:
            /*
                std::list<std::string> ExploreNetworks();
                bool ConnectToNetwork(std::string network_name);

                File FindElement(QueryCriteria criteria);
            */
        };
    }
}