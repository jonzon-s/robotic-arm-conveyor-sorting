# Robotic Arm & Conveyor Sorting System

A functional prototype that automatically picks objects from a conveyor belt and places them into a target container, using an infrared sensor to detect item position.

## How it works
- An infrared sensor detects when an object reaches the pickup point on the conveyor
- The conveyor motors (via an H-bridge driver) stop feeding once an object is detected
- A 4-servo robotic arm (base rotation, two arm joints, and gripper) picks up the object and places it in the delivery container
- The arm then returns to a neutral position and the cycle repeats

## Hardware
- Arduino (Uno/Mega)
- 4x servo motors (base, 2 arm joints, gripper)
- DC motor driver (dual H-bridge) for the conveyor
- Infrared proximity sensor
