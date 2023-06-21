#pragma once

#include <stdio.h>
#include <memory>
#include <list>
#include <optional>

#include "../gnutella-cpp/include/net.hpp"

namespace local_peregrine
{
    namespace net
    {
        class Network
        {
        private:
            static gnutella_cpp::Peer self_;

        private:
            Network()
            {
                gnutella_cpp::inet::init("SomeName");

                gnutella_cpp::inet::subscribe_ping([]() -> ::Peer
                                                   { return self_; });

                gnutella_cpp::inet::subscribe_pong([](::Peer trg_peer) -> void {});
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