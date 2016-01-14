echo Lancement de la compilation--------------------------------------------------
echo Suppression du resultat \(.elf\) de la dernière compilation...
rm -rf *.elf

arm-linux-gnueabi-gcc -march=armv7-a \
 src/shortest_path/shortest_path.c \
 src/shortest_path/map_common.c \
 src/shortest_path/map_reader.c \
\
 src/com/navdata_controller.c\
 src/com/spoof_udp.c \
 src/com/at-sender.c \
 src/com/message_drone.c\
 src/com/at-commands.c \
\
 src/movement/movement.c \
\
 src/state_machine/KCG/system_state_machine.c\
 src/state_machine/KCG/kcg_types.c\
 src/state_machine/Main_thread_create.c\
 src/state_machine/controlTask.c\
 src/state_machine/control_com.c\
 src/state_machine/regulation.c\
 src/state_machine/bluetooth_com.c\
 src/state_machine/driver_uart.c\
\
 src/uart/display.c \
 src/uart/localisation.c \
 src/uart/parser.c \
 src/uart/uart.c \
 -lpcap -lpthread -lm -I lib/libpcap/include -L lib/libpcap/lib -o Control_law_test.elf



#src/navdata_controller.
#src/spoof_udp.c

echo Nom du fichier de sortie : Control_law_test
