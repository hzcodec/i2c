/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-11-15
    File        : i2c_dac1.c
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

   if (argc > 1) {
        printf("*** DAC test program 3 ***\n");
    }
    else {
        printf("No parameter is entered\n");
	exit(1);
    }

    int   file;
    char  filename[20];
    char   buf[10];
    float voltage = atof(argv[1]);
    char str[3];
    char str2[3];

    printf("Voltage:   %f\n",voltage);
    float voltage_value = voltage * 4095.0 / 3.3;
    int voltage_int = (int)(voltage_value+0.5);
    printf("Value:     %d\n",voltage_int);
    sprintf(str,"%x",voltage_int);
    printf("Hex value: %s\n\n",str);

    printf("concatenate %s\n",strncat(str2,str,3));
//    strcpy(s1,str);
//    strcpy(s2,str[2]);

    buf[0] = str[0];
    buf[1] = 0xa3;


    // print to buffer
    snprintf(filename,19,"/dev/i2c-%d",PORT_NO);

    // open port for read/write
    file = open(filename,O_RDWR);
    if (file < 0) {
        printf("Failed to open i2c port\n");
	exit(1);
    }

    // set up address and data, 0x500 ~1.0 V
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
