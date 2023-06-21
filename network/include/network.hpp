#pragma once

#include <stdio.h>
#include <memory>
#include <list>
#include <optional>

#include "../gnutella-c/include/net.h"
#include "../gnutella-cpp/include/query_hit.hpp"

#include "../logger/include/logger.hpp"

#include "../fs/include/file.hpp"

namespace local_peregrine
{
    namespace net
    {
        class Network
        {
            Peer self_;
            std::unique_ptr<logger::ILog> log_driver_;
            std::list<Peer> peers_;

            std::function<std::optional<fs::File>(std::string)> search_criteria_fnc;

        public:
            std::list<std::string> ExploreNetworks();
            bool ConnectToNetwork(std::string network_name);

            File FindElement(QueryCriteria criteria);

        private:
            void consume_ping(Address address)
            {
                log_driver_->write(logger::LogLevel::kInfo, "Ping message received!");

                inet_pong(address, self_);
            }

            void consume_pong(Peer peer)
            {
                log_driver_->write(logger::LogLevel::kInfo, "Pong message received!");

                // TODO Что делать при многопоточке
                peers_.push_back(peer);
            }

            void consume_query(SString criteria)
            {
                log_driver_->write(logger::LogLevel::kInfo, "Query message received!");

                std::string criteria_std_str = std::string(criteria.val, criteria.cnt);
                auto search_file = search_criteria_fnc(criteria_std_str);

                if (search_file.has_value())
                {
                    inet_query_hit()
                }
            }

            static void consume_query_hit(QueryHit query_hit)
            {
            }
        };
    }
}