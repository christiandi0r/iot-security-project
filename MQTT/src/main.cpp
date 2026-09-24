#include "sensorPublisher.hpp"

#include <random>
#include <chrono>
#include <thread>

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> tempDist(68.0, 76.0);
    std::uniform_real_distribution<double> humDist(40.0, 55.0);
    
    SensorPublisher sensor;

    sensor.connect();

    while(1)
    {
        sensor.publishTemperature(tempDist(gen));
        sensor.publishHumidity(humDist(gen));

        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
    
    return 0;
}
