arm-linux-gnueabi-gcc-5 -Wall -march=armv7-a  *.c -o computeLocation.elf
#ftp -v -n 192.168.1.1 <<END
#binary
#put computeLocation.elf
#quit
#END
