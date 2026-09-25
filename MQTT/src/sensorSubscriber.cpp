#include "sensorSubscriber.hpp"

#include <iostream>

void SensorSubscriber::connect()
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

void SensorSubscriber::subscribe()
{
    try
    {
        auto temp_token = _client.subscribe(_temperatureTopic, 0);
        auto hum_token = _client.subscribe(_humidityTopic, 0);

        temp_token->wait();
        hum_token->wait(); 

        std::cout << "Subscribed to sensor topics." << std::endl;
    }

    catch (const mqtt::exception& exc)
    {
        std::cerr << exc.what() << std::endl;
    }
}

void SensorSubscriber::listen()
{

}
