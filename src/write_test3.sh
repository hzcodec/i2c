#   Auther      : Heinz Samuelsson
#   Date        : 2013-12-07
#   File        : write_test3.sh
#   Reference   : -
#   Description : The script is setting parameters in Adafruit's 
#                 16 channel 12 bit PWM/Servo driver (PCA9685).
#                 Four different setups are done.
#                 Formula for calculating degrees.
#                 y = -0.4x + 240, y = degress, x = value in dec
#                 Servo HS-55
#                 1500 us - 1900 us.
#                 
#                 x    y

#!/bin/bash

echo "*** 1 deg"

# LED0_ON_L/_H
i2cset -y 1 0x40 0x06 0x00 b
i2cset -y 1 0x40 0x07 0x00 b

# LED0_OFF_L/_H
i2cset -y 1 0x40 0x08 0xb0 b
i2cset -y 1 0x40 0x09 0x01 b

echo -n "*** Push for 360 deg"
read dummy

# LED0_ON_L/_H
i2cset -y 1 0x40 0x06 0x00 b
i2cset -y 1 0x40 0x07 0x00 b

# LED0_OFF_L/_H
#i2cset -y 1 0x40 0x08 0x4b b
i2cset -y 1 0x40 0x08 0xa9 b
i2cset -y 1 0x40 0x09 0x00 b

