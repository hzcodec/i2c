CC     = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall

d1: i2c_dac1.c
	$(CC) $(CFLAGS) i2c_dac1.c -o i2c_dac1

d2: i2c_dac2.c
	$(CC) $(CFLAGS) i2c_dac2.c -o i2c_dac2

t1: i2c_tmp1.c
	$(CC) $(CFLAGS) i2c_tmp1.c -o i2c_tmp1

t2: i2c_tmp2.c
	$(CC) $(CFLAGS) i2c_tmp2.c -o i2c_tmp2

clean:
	rm -f a.out i2c_dac1 i2c_dac2 i2c_tmp1 i2c_tmp2
