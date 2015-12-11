echo Lancement de la complilation--------------------------------------------------

arm-linux-gnueabi-gcc -march=armv7-a src/state_machine/KCG/system_state_machine.c src/state_machine/KCG/kcg_types.c src/state_machine/KCG/include/kcg_assign.h src/state_machine/KCG/libraries/libmathext/macro_libmathext.h src/state_machine/Main_thread_create.c  src/state_machine/controlTask.c src/state_machine/control_com.c src/state_machine/regulation.c src/state_machine/bluetooth_com.c src/state_machine/driver_uart.c src/message_drone.c src/at-commands.c   src/sender.c -lpcap -lpthread -lm -I lib/libpcap/include -L lib/libpcap/lib -o test_stat_machine 

echo Utilisation de control_com.c
echo ------------de regulation.c
echo ------------de message_drone.c
echo ------------de at-commands.c
echo ------------de sender.c
echo ------------de navdata_controller.c

#src/navdata_controller.
#src/spoof_udp.c

echo Nom du fichier de sortie : test_stat_machine
