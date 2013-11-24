/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-11-17
    File        : i2c_16ch_pwm2.c
    Reference   : -
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
    if (write(file,reg,1) != 1) {
        printf("Unable to write to slave\n");
	exit(1);
    }
}

void write_byte2(int file, char* reg) {
    if (write(file,reg,1) != 1) {
        printf("Unable to write2 to slave\n");
	exit(1);
    }
}

void read_byte(int file, char* reg) {

    // read internal registers from PWM/Servo driver
    if (read(file,reg,2) != 2) {
        printf("Unable read from slave\n");
	exit(1);
    }
}

void read_byte2(int file, char* reg, char reg2[20]) {

    write_byte2(file,reg2);

    // read internal registers from PWM/Servo driver
    if (read(file,reg,2) != 2) {
        printf("Unable to read from slave\n");
	exit(1);
    }
}


int main(int argc, char **argv) {

    printf("*** 16 channel PWM/Servo test program 2 ***,\n");

    int   file;
    char  filename[20];
    char  wr_buf[10];
    char  rd_buf[20];
    int   addr = PWM_16CH;

    file = open_device(filename);
    set_port(file, addr);

    // read from registers
    wr_buf[0] = MODE1;
    write_byte(file,wr_buf);
    read_byte(file,rd_buf);
    // print out result
    printf("MODE1:      %02x\n",rd_buf[0]);

    wr_buf[0] = MODE2;
    write_byte(file,wr_buf);
    read_byte(file,rd_buf);
    // print out result
    printf("MODE2:      %02x\n",rd_buf[0]);

    wr_buf[0] = LED0_OFF_L;
    write_byte(file,wr_buf);
    read_byte(file,rd_buf);
    // print out result
    printf("LED0_OFF_L: %02x\n",rd_buf[0]);

    wr_buf[0] = LED0_OFF_H;
    write_byte(file,wr_buf);
    read_byte(file,rd_buf);
    // print out result
    printf("LED0_OFF_H: %02x\n",rd_buf[0]);

    wr_buf[0] = PRE_SCALE;
    write_byte(file,wr_buf);
    read_byte(file,rd_buf);
    // print out result
    printf("PRE_SCALE:  %02x\n",rd_buf[0]);

    // read2
    wr_buf[0] = MODE2;
    read_byte2(file,rd_buf,wr_buf);
    // print out result
    printf("MODE2:  %02x\n",rd_buf[0]);

    return 0;
}
