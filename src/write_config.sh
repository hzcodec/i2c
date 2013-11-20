#!/bin/bash

echo -n "Enter LED0_ON_L: "
read led0_on_l

echo -n "Enter LED0_ON_H: "
read led0_on_h

i2cset -y 1 0x40 0x06 0x$led0_on_l  b
i2cset -y 1 0x40 0x07 0x$led0_on_h  b

