/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-11-15
    File        : i2c_tmp2.c
    Reference   : 
    Description : Read temperature from TMP102. A simplifed version
                  of i2c_tmp1.c
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
#define TMP102 0x48;


int main(int argc, char **argv) {

    printf("*** TMP102 test program 2 ***,\n");

    int   file;
    int   adapter_nr = 1;
    char  filename[20];
    char  buf[10];

    // print to buffer
    snprintf(filename,19,"/dev/i2c-%d",adapter_nr);

    // open port for read/write
    file = open(filename,O_RDWR);
    if (file < 0) {
        printf("Failed to open i2c port\n");
	exit(1);
    }

    int addr = TMP102;

    // set port options
    if (ioctl(file,I2C_SLAVE,addr) < 0) {
        printf("Unable to get bus access to talk to slave\n");
	exit(1);
    }

    // int handle, void *buffer, int nbyte
    if (read(file,buf,1) != 1) {
        printf("Unable to read from slave\n");
	exit(1);
    }
    printf("\nbuf[0]: 0x%02x\n",buf[0]);
    printf("buf[1]: 0x%02x\n",buf[1]);

    return 0;
}
