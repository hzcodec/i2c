/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-11-15
    File        : i2c_dac3.c
    Reference   : 
    Description : Control MCP4725 DAC. Run program by
                  > i2c_dac3 <voltage>
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

// TMP102 address
#define DAC_MCP4725 0x62;
// i2c port
#define PORT_NO  1


int main(int argc, char **argv) {

    if (argc > 1) {
        printf("*** DAC test program 3 ***\n");
    }
    else {
        printf("No parameter is entered\n");
	exit(1);
    }

    int      file;
    char     filename[20];
    char     buf[10];
    float    voltage = atof(argv[1]);
    uint16_t u_value;
    uint8_t  u_value1;
    uint8_t  u_value2;

    printf("Voltage:   %f\n",voltage);
    if (voltage > 3.3) {
        printf("Error! To large value entered. Max is 3.3\n");
        exit(1);
    }

    float voltage_value = voltage * 4095.0 / 3.3;
    // round and cast to int
    int voltage_int = (int)(voltage_value+0.5);

    u_value = (uint16_t)voltage_int; 
    u_value1 = (u_value&0xff00)>>8; // 4 msb
    u_value2 = (u_value&0x00ff);    // 8 lsb

    // set parameters to DAC
    buf[0] = u_value1;
    buf[1] = u_value2;

    // print to buffer
    snprintf(filename,19,"/dev/i2c-%d",PORT_NO);

    // open port for read/write
    file = open(filename,O_RDWR);
    if (file < 0) {
        printf("Failed to open i2c port\n");
	exit(1);
    }

    // set up address to DAC
    int addr = DAC_MCP4725;

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
