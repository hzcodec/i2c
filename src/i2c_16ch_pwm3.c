/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-11-27
    File        : i2c_16ch_pwm3.c
    Reference   : -
    Description : Control Adafruit's 16 channel 12-bit PWM/Servo driver.
                  Art.no PCA9685.
		  The code is controlling the module.
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
#define MODE2      0x01
#define LED0_ON_L  0x06
#define LED0_ON_H  0x07
#define LED0_OFF_L 0x08
#define LED0_OFF_H 0x09
#define PRE_SCALE  0xfe


int open_device(char* filename) {

    // print to buffer
    snprintf(filename,19,"/dev/i2c-%d",PORT_NO);

    // open port for read/write
    int file = open(filename,O_RDWR);
    if (file < 0) {
        printf("Failed to open i2c port\n");
	exit(1);
    }

    return file;
}

void set_port(int file, int addr) {
    // set port options
    if (ioctl(file,I2C_SLAVE,addr) < 0) {
        printf("Unable to get bus access to talk to slave\n");
	exit(1);
    }
}

void write_byte(int file, char reg[20]) {
    if (write(file,reg,2) != 2) {
        printf("Unable to write to slave\n");
	exit(1);
    }
}


int main(int argc, char **argv) {

    printf("*** 16 channel PWM/Servo test program 3 ***\n");

    int   file;
    char  filename[20];
    char  wr_buf[10];
    int   addr = PWM_16CH;
    int   x = 1;

    file = open_device(filename);
    set_port(file, addr);

    while (x < 8) {

        printf("Round: %d\n",x);
        // write to registers
        wr_buf[0] = LED0_OFF_L;
        wr_buf[1] = 0x2b;
        write_byte(file,wr_buf);

        wr_buf[0] = LED0_OFF_H;
        wr_buf[1] = 0x02;
        write_byte(file,wr_buf);

	sleep(2);

        // write to registers
        wr_buf[0] = LED0_OFF_L;
        wr_buf[1] = 0x77;
        write_byte(file,wr_buf);

        wr_buf[0] = LED0_OFF_H;
        wr_buf[1] = 0x01;
        write_byte(file,wr_buf);

	sleep(2);

        // write to registers
        wr_buf[0] = LED0_OFF_L;
        wr_buf[1] = 0xc8;
        write_byte(file,wr_buf);

        wr_buf[0] = LED0_OFF_H;
        wr_buf[1] = 0x00;
        write_byte(file,wr_buf);

	sleep(1);
        x++;
    }

    return 0;
}
