#include "sensorSubscriber.hpp"

#include <iostream>

// Connects the MQTT subscriber client to the configured Mosquitto broker.
void SensorSubscriber::connect()
{
    try
    {
        // Start the asynchronous connection attempt.
        auto token = _client.connect();

        token->wait();

        if (_client.is_connected()) {std::cout << "Connected to MQTT broker." << std::endl;}
    }

    catch (const mqtt::exception& exc) 
    {
        std::cerr << exc.what() << std::endl;
    }
}

// Subscribes the client to the temperature and humidity MQTT topics.
void SensorSubscriber::subscribe()
{
    try
    {
        // Subscribe to both sensor topics using QoS 0
        // (at most one delivery, no acknowledgment required).
        auto temp_token = _client.subscribe(_temperatureTopic, 0);  
        auto hum_token = _client.subscribe(_humidityTopic, 0);      

        // Wait until both subscription requests complete.
        temp_token->wait();
        hum_token->wait(); 

        std::cout << "Subscribed to sensor topics." << std::endl;
    }

    catch (const mqtt::exception& exc)
    {
        std::cerr << exc.what() << std::endl;
    }
}

// Continuously listens for incoming MQTT sensor messages.
void SensorSubscriber::listen()
{
    // Begin queueing incoming MQTT messages for consumption.
    _client.start_consuming();

    while(1)
    {
        // Wait for and retrieve the next incoming MQTT message.
        auto message = _client.consume_message();

        // Prevent access to an invalid/null message.
        if (!message)
        {
            std::cout << "Error: No message" << std::endl;
            continue;
        }

        // Extract the topic and payload from the received message.
        auto topic = message->get_topic();
        auto payload = message->to_string();

        if (topic == _temperatureTopic) { std::cout << "Temperature: " << payload << std::endl; }
        else if (topic == _humidityTopic) { std::cout << "Humidity: " << payload << std::endl; }
    }
}
