# Ultrasonic Sensor Robot - README

Welcome to the repository of my ultrasonic sensor-based robot code! Here's a brief guide to help you understand and use this code effectively.

## Description

This code is designed to control a robot equipped with ultrasonic sensors for obstacle detection and navigation. The robot uses two ultrasonic sensors to measure distances in front of it and to the side (for wall following).

## Components Used

- Arduino board (or compatible microcontroller)
- Two HC-SR04 ultrasonic sensors
- Motor driver (for controlling motors)
- Robot chassis with wheels and motors

## Setup

1. Connect the ultrasonic sensors and motors according to the defined pins in the code (`trigPin1`, `echoPin1`, `trigPin2`, `echoPin2`, `LM1`, `LM2`, `RM1`, `RM2`).
2. Make sure the motor driver is correctly wired to control the robot's movement.
3. Upload the code to your Arduino board.

## Functionality

The robot's behavior is governed by the distances measured by the ultrasonic sensors. Here's a breakdown of the robot's behavior:

- The robot moves forward when there is ample space in front (`rangeFront > toCloseFront`).
- If there is a wall within a certain distance (`rangeWall < toCloseWall`), the robot turns left and moves forward.
- If the wall is at an intermediate distance (`toCloseWall < rangeWall < toFarWall`), the robot continues moving forward.
- If there is an obstacle too close in front (`rangeFront < toCloseFront`), the robot takes evasive action by moving backward, turning right, and then continuing forward.

## Usage

This code is a foundation for building a robot that can navigate and avoid obstacles using ultrasonic sensors. Feel free to modify the code to fit your specific robot's setup and requirements.

**Note:**
- The distances `toCloseFront`, `toCloseWall`, and `toFarWall` can be adjusted based on your robot's dimensions and environment.
- Ensure the pins in the code match your wiring configuration.

## Contributions and Enhancements

This code is open for contributions and enhancements. If you find any issues or have suggestions for improvements, please feel free to create pull requests or discussions.

Happy robot building!
