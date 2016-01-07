echo Lancement de la complilation--------------------------------------------------

arm-linux-gnueabi-gcc -march=armv7-a src/com/params.h src/com/sender.c src/com/receiver.c src/spoof_udp.c src/map/map_common.c src/map/map_reader.c src/state_machine/KCG/system_state_machine.c src/state_machine/KCG/kcg_types.c src/state_machine/KCG/include/kcg_assign.h src/navdata_controller.c src/state_machine/KCG/libraries/libmathext/macro_libmathext.h src/state_machine/Main_thread_create.c  src/state_machine/controlTask.c src/state_machine/control_com.c src/state_machine/regulation.c src/state_machine/bluetooth_com.c src/state_machine/driver_uart.c src/message_drone.c src/at-commands.c   src/sender.c src/shortest_path.c src/uart/display.c src/uart/localisation.c src/uart/parser.c src/uart/uart.c -lpcap -lpthread -lm -I lib/libpcap/include -L lib/libpcap/lib -o Control_law_test.elf

echo Utilisation de src/state_machine/control_com.c
echo ------------de src/state_machine/regulation.c
echo ------------de src/message_drone.c
echo ------------de src/at-commands.c
echo ------------de src/sender.c
echo ------------de src/navdata_controller.c
echo ------------de src/spoof_udp.c
echo ------------de src/state_machine/KCG/system_state_machine.c
echo ------------de src/state_machine/KCG/kcg_types.c 
echo ------------de src/state_machine/KCG/include/kcg_assign.h 
echo ------------de src/navdata_controller.c
echo ------------de src/state_machine/KCG/libraries/libmathext/macro_libmathext.h 
echo ------------de src/state_machine/Main_thread_create.c 
echo ------------de src/state_machine/controlTask.c 
echo ------------de src/state_machine/control_com.c 
echo ------------de src/state_machine/bluetooth_com.c 
echo ------------de src/state_machine/driver_uart.c 
echo ------------de src/shortest_path.c
echo ------------de src/map/map_reader.c
echo ------------de src/map/map_common.c

#src/navdata_controller.
#src/spoof_udp.c

echo Nom du fichier de sortie : Control_law_test
