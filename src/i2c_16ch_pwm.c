/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-11-17
    File        : i2c_16ch_pwm.c
    Reference   : learn.adafruit.com/assets/1720
    Description : Control Adafruit's 16 channel 12-bit PWM/Servo driver.
                  Art.no PCA9685.
*/

#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

// TMP102 address
#define PWM_16CH 0x40;
// i2c port
#define PORT_NO  1


int main(int argc, char **argv) {

    printf("*** 16 channel PWM/Servo test program 1 ***,\n");

    int   file;
    char  filename[20];
    char  wr_buf[10];
    char  buf[10];

    // print to buffer
    snprintf(filename,19,"/dev/i2c-%d",PORT_NO);

    // open port for read/write
    file = open(filename,O_RDWR);
    if (file < 0) {
        printf("Failed to open i2c port\n");
	exit(1);
    }

    // set up address and data, 0x500 ~1.0 V
    int addr = PWM_16CH;
    wr_buf[0] = 0x00;
    wr_buf[1] = 0x31;

    // set port options
    if (ioctl(file,I2C_SLAVE,addr) < 0) {
        printf("Unable to get bus access to talk to slave\n");
	exit(1);
    }

    // int handle, void *buffer, int nbyte
    if (write(file,wr_buf,2) != 2) {
        printf("Unable to write to slave\n");
	exit(1);
    }

    // int handle, void *buffer, int nbyte
    if (read(file,buf,10) != 10) {
        printf("Unable to write to slave\n");
	exit(1);
    }

    printf("MODE1: %02x\n",buf[0]);
    printf("MODE2: %02x\n",buf[1]);
    printf("SUBADR1: %02x\n",buf[2]);
    printf("SUBADR2: %02x\n",buf[3]);
    printf("SUBADR3: %02x\n",buf[4]);
    printf("LED0_ON_L: %02x\n",buf[5]);
    printf("LED0_ON_H: %02x\n",buf[6]);
    printf("LED0_OFF_L: %02x\n",buf[7]);
    printf("LED0_ODD_H: %02x\n",buf[8]);
    printf("buf[9]: %02x\n",buf[9]);
    printf("buf[10]: %02x\n",buf[10]);

    return 0;
}