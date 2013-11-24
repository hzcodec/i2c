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
