#include "sensorPublisher.hpp"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

void SensorPublisher::connect()
{
    try
    {
        auto token = _client.connect();

        token->wait();

        if (_client.is_connected()) {std::cout << "Connected to MQTT broker." << std::endl;}
    }

    catch (const mqtt::exception& exc) 
    {
        std::cerr << exc.what() << std::endl;
    }
}

void SensorPublisher::publishTemperature(double temperature)
{
    std::ostringstream stream;
    
    stream << std::fixed << std::setprecision(1) << temperature;
    
    std::string payload = stream.str();

    try
    {
        auto token = _client.publish(_temperatureTopic, payload);

        token->wait();   
    }

    catch (const mqtt::exception& exc)
    {
        std::cerr << exc.what() << std::endl;
    }
}

void SensorPublisher::publishHumidity(double humidity)
{
    std::ostringstream stream;
    
    stream << std::fixed << std::setprecision(1) << humidity;
    
    std::string payload = stream.str();

    try
    {
        auto token = _client.publish(_humidityTopic, payload);

        token->wait();   
    }

    catch (const mqtt::exception& exc)
    {
        std::cerr << exc.what() << std::endl;
    }
}
