/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-11-15
    File        : i2c_dac2.c
    Reference   : 
    Description : Control MCP4725 DAC.
                  4095 = 0xfff = 3.3 V
		  1240 = 0x4d9 = 1.0 V
		   620 = 0x26c = 0.5 V
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
#define DAC_MCP4725 0x62;
// i2c port
#define PORT_NO  1


int main(int argc, char **argv) {

    printf("*** DAC 2 test program 2 ***,\n");

    int   file;
    char  filename[20];
    char   buf[10];

    // print to buffer
    snprintf(filename,19,"/dev/i2c-%d",PORT_NO);

    // open port for read/write
    file = open(filename,O_RDWR);
    if (file < 0) {
        printf("Failed to open i2c port\n");
	exit(1);
    }

    int addr = DAC_MCP4725;
    buf[0] = 0x05;
    buf[1] = 0x00;


    // set port options
    if (ioctl(file,I2C_SLAVE,addr) < 0) {
        printf("Unable to get bus access to talk to slave\n");
	exit(1);
    }

    // int handle, void *buffer, int nbyte
    if (write(file,buf,2) != 2) {
        printf("Unable to write to slave\n");
	exit(1);
    }

    return 0;
}
