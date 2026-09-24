#include "sensorPublisher.hpp"

int main()
{
    SensorPublisher sensor;

    sensor.connect();

    sensor.publishTemperature(72.5);
    sensor.publishHumidity(46.8);

    return 0;
}
