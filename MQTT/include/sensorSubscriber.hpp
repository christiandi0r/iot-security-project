#ifndef SENSORSUBSCRIBER_HPP
#define SENSORSUBSCRIBER_HPP

#include <string>
#include <mqtt/async_client.h>

class SensorSubscriber
{
    public:

        SensorSubscriber() : _brokerAddress{"tcp://localhost:1883"}, 
                            _temperatureTopic{"iot/sensor1/temperature"},
                            _humidityTopic{"iot/sensor1/humidity"},
                            _clientID{"sensor1_subscriber"},
                            _client{_brokerAddress, _clientID} {}

        SensorSubscriber(const std::string& brokerAddress,
                        const std::string& tempTopic,
                        const std::string& humTopic,
                        const std::string& clientID
                        ) : _brokerAddress{brokerAddress}, _temperatureTopic{tempTopic}, _humidityTopic{humTopic}, 
                            _clientID{clientID}, _client{_brokerAddress, _clientID} {}

        void connect();
        void subscribe();
        void listen();

    private:

        std::string _brokerAddress;
        std::string _temperatureTopic;
        std::string _humidityTopic;
        std::string _clientID;

        mqtt::async_client _client;
};

#endif
