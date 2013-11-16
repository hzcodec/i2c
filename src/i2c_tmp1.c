/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-11-14
    File        : i2c_tmp1.c
    Reference   : www.agilart.com/blog/tmp102-raspberry-pi
    Description : Read temperature from TMP102.
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


int main(int argc, char **argv) {

    unsigned int  temp = 0;
    unsigned char msb;
    unsigned char lsb;

    printf("*** TMP102 test program ***,\n");

    int           fd;
    char          *fileName = "/dev/i2c-1";  // port name
    int           address   = 0x48;          // TMP102 address
    unsigned char buf[10];                   // buffer read/write data

    // open port, read/write
    if ((fd = open(fileName,O_RDWR)) < 0) {
        printf("Failed to open i2c port\n");
	exit(1);
    }

    // set port options
    if (ioctl(fd,I2C_SLAVE,address) < 0) {
        printf("Unable to get bus access to talk to slave\n");
	exit(1);
    }

    buf[0] = 0;

    if ((write(fd,buf,1)) != 1) {
        printf("Error writing to i2c slave\n");
	exit(1);
    }

    if (read(fd,buf,1) != 1) {
        printf("Unable to read from slave\n");
	exit(1);
    }
    else {
        msb = buf[0];
	printf("0x%02x ",msb);

	if (read(fd,buf,1) != 1) {
            printf("Unable to read from slave\n");
	    exit(1);
	}
	else {
            lsb = buf[0];
	    temp = (msb<<8) | lsb;
	    temp >>= 4;
	    printf("The temperature is: %f \n",temp*0.0625);
	}
    }

    return 0;
}
