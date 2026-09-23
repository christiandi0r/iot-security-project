#ifndef SENSORPUBLISHER_HPP
#define SENSORPUBLISHER_HPP

#include <string>
#include <mqtt/async_client.h>

class SensorPublisher
{
    public:

        SensorPublisher() : _brokerAddress{"tcp://localhost:1883"}, 
                            _temperatureTopic{"iot/sensor1/temperature"},
                            _humidityTopic{"iot/sensor1/humidity"},
                            _clientID{"sensor1_publisher"},
                            _client{_brokerAddress, _clientID} {}

        SensorPublisher(const std::string& brokerAddress,
                        const std::string& tempTopic,
                        const std::string& humTopic,
                        const std::string& clientID
                        ) : _brokerAddress{brokerAddress}, _temperatureTopic{tempTopic}, _humidityTopic{humTopic}, 
                            _clientID{clientID}, _client{_brokerAddress, _clientID} {}

        void connect();
        void publishTemperature(double temperature);
        void publishHumidity(double humidity);

    private:

        std::string _brokerAddress;
        std::string _temperatureTopic;
        std::string _humidityTopic;
        std::string _clientID;

        mqtt::async_client _client;
};

#endif 
