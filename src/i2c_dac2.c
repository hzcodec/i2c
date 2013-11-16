/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-11-16
    File        : i2c_dac2.c
    Reference   : 
    Description : Control MCP4725 DAC.
                  Read information from DAC.
		  Run i2c_dac1.c first. The written data shall
		  show up in buf[1] and buf[2].
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

    printf("*** DAC test program 2 ***,\n");

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

    // set up address and data
    int addr = DAC_MCP4725;

    // set port options
    if (ioctl(file,I2C_SLAVE,addr) < 0) {
        printf("Unable to get bus access to talk to slave\n");
	exit(1);
    }

    // int handle, void *buffer, int nbyte
    if (read(file,buf,3) != 3) {
        printf("Unable to read from slave\n");
	exit(1);
    }

    printf("buf[0]: %02x\n",buf[0]);
    printf("buf[1]: %02x\n",buf[1]);
    printf("buf[2]: %02x\n",buf[2]);

    return 0;
}
