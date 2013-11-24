#   Auther      : Heinz Samuelsson
#   Date        : 2013-11-24
#   File        : read_test1.sh
#   Reference   : www.adafruit.com/products/815
#   Description : The script is reading parameters from 
#                 16 channel 12 bit PWM/Servo driver (PCA9685).
#
#                 Normal operation result:
#                 Mode1: 0x00
#                 Mode2: 0x04
#                 ALLCALLADR: 0xe0
#                 LED0_ON_L: 0x00
#                 LED0_ON_H: 0x00
#                 LED0_OFF_L: 0xf4
#                 LED0_OFF_H: 0x01
#                 PRE_SCALE: 0x65
#                 TestMode: 0x00
#
#!/bin/bash

echo -n "Mode1: "
i2cget -y 1 0x40 0x00 b

echo -n "Mode2: "
i2cget -y 1 0x40 0x01 b

echo -n "ALLCALLADR: "
i2cget -y 1 0x40 0x05 b

echo -n "LED0_ON_L: "
i2cget -y 1 0x40 0x06 b

echo -n "LED0_ON_H: "
i2cget -y 1 0x40 0x07 b

echo -n "LED0_OFF_L: "
i2cget -y 1 0x40 0x08 b

echo -n "LED0_OFF_H: "
i2cget -y 1 0x40 0x09 b

echo -n "PRE_SCALE: "
i2cget -y 1 0x40 0xfe b

echo -n "TestMode: "
i2cget -y 1 0x40 0xff b
