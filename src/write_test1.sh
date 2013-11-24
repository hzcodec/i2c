#   Auther      : Heinz Samuelsson
#   Date        : 2013-11-24
#   File        : write_test1.sh
#   Reference   : www.adafruit.com/products/815
#   Description : The script is setting parameters in Adafruit's 
#                 16 channel 12 bit PWM/Servo driver (PCA9685).
#                 Four different setups are done.

#!/bin/bash

echo "*** Test1 ***"

# LED0_ON_L/_H
i2cset -y 1 0x40 0x06 0x00 b
i2cset -y 1 0x40 0x07 0x00 b

# LED0_OFF_L/_H
i2cset -y 1 0x40 0x08 0x58 b
i2cset -y 1 0x40 0x09 0x02 b

echo -n "Push <Return> for new values"
read dummy

# LED0_ON_L/_H
i2cset -y 1 0x40 0x06 0x00 b
i2cset -y 1 0x40 0x07 0x00 b

# LED0_OFF_L/_H
i2cset -y 1 0x40 0x08 0x96 b
i2cset -y 1 0x40 0x09 0x00 b

echo -n "Push <Return> for new values"
read dummy

# LED0_ON_L/_H
i2cset -y 1 0x40 0x06 0x00 b
i2cset -y 1 0x40 0x07 0x00 b

# LED0_OFF_L/_H
i2cset -y 1 0x40 0x08 0x2c b
i2cset -y 1 0x40 0x09 0x01 b

echo -n "Push <Return> for new values"
read dummy

# LED0_ON_L/_H
i2cset -y 1 0x40 0x06 0x00 b
i2cset -y 1 0x40 0x07 0x00 b

# LED0_OFF_L/_H
i2cset -y 1 0x40 0x08 0xf4 b
i2cset -y 1 0x40 0x09 0x01 b

