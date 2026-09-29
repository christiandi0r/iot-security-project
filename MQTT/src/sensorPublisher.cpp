#include "sensorPublisher.hpp"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

// Connects the MQTT client to the configured Mosquitto broker.
void SensorPublisher::connect()
{
    try
    {
        // Start the asynchronous connection attempt.
        auto token = _client.connect();

        // Wait until the connection attempt completes.
        token->wait();
        
        if (_client.is_connected()) {std::cout << "Connected to MQTT broker." << std::endl;}
    }

    catch (const mqtt::exception& exc) 
    {
        std::cerr << exc.what() << std::endl;
    }
}

// Publishes a temperature reading to the configured temperature topic.
void SensorPublisher::publishTemperature(double temperature)
{
    std::ostringstream stream;
    
    stream << std::fixed << std::setprecision(1) << temperature;
    
    // Convert the formatted reading into an MQTT payload string.
    std::string payload = stream.str();

    try
    {
        // Publish the temperature payload to the broker.
        auto token = _client.publish(_temperatureTopic, payload);
        
        token->wait();   
    }

    catch (const mqtt::exception& exc)
    {
        std::cerr << exc.what() << std::endl;
    }
}

// Publishes a humidity reading to the configured humidity topic.
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
