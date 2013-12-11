#   Auther      : Heinz Samuelsson
#   Date        : 2013-11-25
#   File        : write_test2.sh
#   Reference   : -
#   Description : The script is setting parameters in Adafruit's 
#                 16 channel 12 bit PWM/Servo driver (PCA9685).
#                 Four different setups are done.
#                 Formula for calculating degrees.
#                 y = -0.4x + 240, y = degress, x = value in dec
#                 Servo HS-322
#                 
#                 x    y
#                 600  0
#                 150  180

#!/bin/bash

echo "*** 10 deg"

# LED0_ON_L/_H
i2cset -y 1 0x40 0x06 0x00 b
i2cset -y 1 0x40 0x07 0x00 b

# LED0_OFF_L/_H
i2cset -y 1 0x40 0x08 0x44 b
i2cset -y 1 0x40 0x09 0x02 b

echo -n "*** Push for 20 deg"
read dummy

# LED0_ON_L/_H
i2cset -y 1 0x40 0x06 0x00 b
i2cset -y 1 0x40 0x07 0x00 b

# LED0_OFF_L/_H
i2cset -y 1 0x40 0x08 0x2b b
i2cset -y 1 0x40 0x09 0x02 b

echo -n "*** Push for 45 deg"
read dummy

# LED0_ON_L/_H
i2cset -y 1 0x40 0x06 0x00 b
i2cset -y 1 0x40 0x07 0x00 b

# LED0_OFF_L/_H
i2cset -y 1 0x40 0x08 0xe8 b
i2cset -y 1 0x40 0x09 0x01 b

echo -n "*** Push for 90 deg"
read dummy

# LED0_ON_L/_H
i2cset -y 1 0x40 0x06 0x00 b
i2cset -y 1 0x40 0x07 0x00 b

# LED0_OFF_L/_H
i2cset -y 1 0x40 0x08 0x77 b
i2cset -y 1 0x40 0x09 0x01 b

echo -n "*** Push for 120 deg"
read dummy

# LED0_ON_L/_H
i2cset -y 1 0x40 0x06 0x00 b
i2cset -y 1 0x40 0x07 0x00 b

# LED0_OFF_L/_H
i2cset -y 1 0x40 0x08 0x2c b
i2cset -y 1 0x40 0x09 0x01 b

echo -n "*** Push for 160 deg"
read dummy

# LED0_ON_L/_H
i2cset -y 1 0x40 0x06 0x00 b
i2cset -y 1 0x40 0x07 0x00 b

# LED0_OFF_L/_H
i2cset -y 1 0x40 0x08 0xc8 b
i2cset -y 1 0x40 0x09 0x00 b

echo -n "*** Push for 170 deg"
read dummy

# LED0_ON_L/_H
i2cset -y 1 0x40 0x06 0x00 b
i2cset -y 1 0x40 0x07 0x00 b

# LED0_OFF_L/_H
i2cset -y 1 0x40 0x08 0xaa b
i2cset -y 1 0x40 0x09 0x00 b

echo -n "*** Push for 5 deg"
read dummy

# LED0_ON_L/_H
i2cset -y 1 0x40 0x06 0x00 b
i2cset -y 1 0x40 0x07 0x00 b

# LED0_OFF_L/_H
i2cset -y 1 0x40 0x08 0x4e b
i2cset -y 1 0x40 0x09 0x02 b

