#pragma once

#include <stdio.h>
#include <memory>
#include <list>
#include <optional>
#include <iostream>

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
                                                   { std::cout << "Ping" << std::endl;
                                                   return self_; });

                gnutella_cpp::inet::subscribe_pong([](::Peer trg_peer) -> void
                                                   { std::cout << "Pong" << std::endl;
                                                   self_.AddTrackedPeer(trg_peer); });

                gnutella_cpp::inet::subscribe_query([](SString sstring) -> ::QueryHit
                                                    {
                    std::cout << "Query" << std::endl;

                    std::list<::File*> files = repository_.FindByCriteria(gnutella_cpp::utils::FromSString(sstring));
                    return gnutella_cpp::QueryHit(files); });

                gnutella_cpp::inet::subscribe_query_hit([](::QueryHit query_hit) -> void
                                                        { std::cout << "Query hit" << std::endl; });
            }

        public:
            static Network &getInstance()
            {
                static Network instance;
                return instance;
            }

        public:
                std::list<std::string> ExploreNetworks() {}
                bool ConnectToNetwork(std::string network_name) {}

                File FindElement(std::string criteria) {}
        };
    }
}