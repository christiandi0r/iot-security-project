# IoT Security Project

This project simulates an IoT network using MQTT and investigates how network security tools can detect and analyze suspicious activity.

The system uses a Mosquitto MQTT broker, a simulated sensor publisher, and a subscriber. Later stages of the project will incorporate intrusion detection, packet capture, controlled attacks, and security improvements.

## Project Goals

- Simulate IoT sensor traffic using MQTT
- Configure a Mosquitto MQTT broker
- Publish simulated temperature and humidity data
- Subscribe to MQTT sensor topics
- Capture and analyze MQTT traffic
- Detect suspicious network activity
- Reconstruct incidents using packet captures and logs
- Improve the MQTT system using authentication, access controls, and encryption

## Current Architecture

```text
Sensor Publisher
       |
       | MQTT
       v
Mosquitto Broker
       |
       | MQTT
       v
Subscriber
```
## Contributors

- **Christian Ruelas** — IoT/MQTT System & Integration
- **Damaris Sanchez Meraz** — Attack Simulation
- **Victoria Hofmeister** — Intrusion Detection
- **Cirena Arabit** — Network Forensics & Packet Analysis
