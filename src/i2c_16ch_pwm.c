/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-11-17
    File        : i2c_16ch_pwm.c
    Reference   : learn.adafruit.com/assets/1720
    Description : Control Adafruit's 16 channel 12-bit PWM/Servo driver.
                  Art.no PCA9685.
		  The code is reading data form the PWM/Servo driver.
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

// 16 channel PWM/Servo address
#define PWM_16CH 0x40;
// i2c port
#define PORT_NO  1
// Registers
#define MODE1      0x00
#define LED0_OFF_L 0x08
#define PRE_SCALE  0xfe


int main(int argc, char **argv) {

    printf("*** 16 channel PWM/Servo test program 1 ***,\n");

    int   file;
    char  filename[20];
    char  wr_buf[10];
    char  buf[20];

    // print to buffer
    snprintf(filename,19,"/dev/i2c-%d",PORT_NO);

    // open port for read/write
    file = open(filename,O_RDWR);
    if (file < 0) {
        printf("Failed to open i2c port\n");
	exit(1);
    }

    // set up control and mode1 register
    int addr = PWM_16CH;

    // uncomment the register you want to read
    //wr_buf[0] = MODE1;
    //wr_buf[0] = LED0_OFF_L;
    wr_buf[0] = PRE_SCALE;

    // set port options
    if (ioctl(file,I2C_SLAVE,addr) < 0) {
        printf("Unable to get bus access to talk to slave\n");
	exit(1);
    }

    // write initial phase so read can be done later
    if (write(file,wr_buf,1) != 1) {
        printf("Unable to write to slave\n");
	exit(1);
    }

    // read internal registers from PWM/Servo driver
    if (read(file,buf,2) != 2) {
        printf("Unable to write to slave\n");
	exit(1);
    }

    // print out result
    printf("MODE1:   %02x\n",buf[0]);

    return 0;
}
