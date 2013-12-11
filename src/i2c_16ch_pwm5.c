/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-11-27
    File        : i2c_16ch_pwm4.c
    Reference   : -
    Description : Control Adafruit's 16 channel 12-bit PWM/Servo driver.
                  Servo HS-55.
		  The code is controlling the module.
                  y = -0.731x + 432, y = degress, x = value in dec
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
#include <inttypes.h>

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

    printf("*** 16 channel PWM/Servo test program 5 ***\n");

    int   file;
    char  filename[20];
    char  wr_buf[10];
    int   addr = PWM_16CH;
    int   c;

    file = open_device(filename);
    set_port(file, addr);

    printf("Enter an angel: ");
    scanf("%d",&c);

    while (c > 0) {

        if (c > 359 || c < 1) {
            c = 90;		
	}

        // calculate the corresponding value for the entered angel
        float value = (591 - c) / 1.369;
        int int_val = (int)value;
        uint16_t val_hex = (uint16_t)int_val;

	// fix lo/hi byte
        uint8_t lo_byte = val_hex & 0xff;
        uint8_t hi_byte = val_hex>>8 & 0xff;

        // write to registers
        wr_buf[0] = LED0_OFF_L;
        wr_buf[1] = lo_byte;
        write_byte(file,wr_buf);

        wr_buf[0] = LED0_OFF_H;
        wr_buf[1] = hi_byte;
        write_byte(file,wr_buf);

        printf("Enter an angel: ");
        scanf("%d",&c);
    }

    return 0;
}
