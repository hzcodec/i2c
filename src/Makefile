CC     = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall

d1: i2c_dac1.c
	$(CC) $(CFLAGS) i2c_dac1.c -o i2c_dac1

d2: i2c_dac2.c
	$(CC) $(CFLAGS) i2c_dac2.c -o i2c_dac2

d3: i2c_dac3.c
	$(CC) $(CFLAGS) i2c_dac3.c -o i2c_dac3

t1: i2c_tmp1.c
	$(CC) $(CFLAGS) i2c_tmp1.c -o i2c_tmp1

t2: i2c_tmp2.c
	$(CC) $(CFLAGS) i2c_tmp2.c -o i2c_tmp2

c1: i2c_16ch_pwm.c
	$(CC) $(CFLAGS) i2c_16ch_pwm.c -o i2c_16ch_pwm

c2: i2c_16ch_pwm2.c
	$(CC) $(CFLAGS) i2c_16ch_pwm2.c -o i2c_16ch_pwm2

clean:
	rm -f a.out i2c_dac1 i2c_dac2 i2c_dac3 i2c_tmp1 i2c_tmp2 i2c_16ch_pwm i2c_16ch_pwm2
