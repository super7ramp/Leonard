#!/bin/sh
HOST='192.168.1.1'
FILE='computeLocation.elf'

ftp -n $HOST <<END_SCRIPT
put $FILE
quit
END_SCRIPT
exit 0
