#include "sensorSubscriber.hpp"

int main()
{
    SensorSubscriber subscriber;

    subscriber.connect();
    subscriber.subscribe();
    subscriber.listen();

    return 0;
}
