# Project Leonard: Indoor Guiding Drone

![](https://sites.google.com/site/projetsecinsa/_/rsrc/1446308035277/projets-2015-2016/project-leonard/project.jpg)

Upset about being lost in a new building? Feeling the urge to reach a specific room but you do not want to get lost? It seems like you need the help of our guiding drone!

We are proud to introduce to you are newest product: **Findy**! **Findy** is a completely autonomous drone acting inside of buildings. Thanks to Bluetooth beacons deployed in all of the building, the drone is able to calculate his position and define paths to get to any equipped room or hallway!

Why would I choose Findy, you may ask? Maybe you do not understand how to read a map. And well, who bring a map when he goes to the mall? 

## Features

Here are the mains features of **Findy**:
* Autonomous flight: flight controls are designed with [SCADE Suite®](http://www.systerel.fr/).
* Guiding procedure: **Findy** is able to choose the shortest path to reach a specific destination. All you have to do is to tell him where you want to go.
* Drone location retrieving: you are able to get the drone position at any time (pc application).
* Remote control with Android application (not implemented yet, for now there is a small pc application)
* Definition of meeting point (not implemented yet)

For more details, please visit [our website](https://sites.google.com/site/projetsecinsa/projets-2015-2016/project-leonard).

![](http://www.systerel.fr/wp-content/uploads/2014/09/scade-300x116.jpg)

## Get it started

There are two programs:
* One embedded on the drone, which controls the drone movements.
* One running on a computer, which communicates with the drone.

The procedure described here has been tested on Linux, you'll have to adjust it if you want to use other platforms.

### Compilation

You need a cross-compiler in order to compile the embedded program (drone side).

If you use Ubuntu, you can use the ARM cross-compiler from the repositories.
```bash
 $ sudo apt-get install gcc-arm-linux-gnueabi
```

Note: You can use other cross-compilers, just edit the `CC` variable in the Makefile.

Once you have installed the cross-compiler, you just have to run the Makefile.
```bash
 $ make
```

The generated program is named `Control_Law.elf`.

The user program (pc side) needs to be compiled separately:
```bash
 $ cd src/user_app
 $ make
```

The Makefile in `src/user_app` defines GCC as compiler, just change the `CC` variable if you want to use something else.
The generated program is named `Findy`.

### Installation

#### Drone

##### Drone hardware

In order to make the drone detect the beacons, you need to plug the BLE Nano under the drone, on the available Serial pins. The Ble Nano takes his power from the drone too. The BLE Nano is mounted on a board which has to be connected respecting the following schematic:
![](https://www.github.com/super7ramp/Leonard/captures/pinout.jpg)

##### Drone software

The drone program is an ARM executable, therefore designed to be runned on the drone.

To send it on the drone you need to...
1. Power on the drone
2. Connect by Wifi to the drone
3. Put the executable with ftp:
```bash
 $ ftp 192.168.1.1
 ftp> put Control_Law.elf
```

It will be send in the `/data/video` folder of the drone filesystem.

Also, the drone uses a predefined map of the room to locate itself and compute the paths to the given destination. Therefore, the map needs to be adapted to the test room.

The map is written in a simple text format. You’ll find a description of the format in `src/shortest_path/map_format.md`, examples in `src/shortest_path/examples`, and scripts to help you to create and visualize your map in `src/shortest_path/scripts`.

Once your map is ready, you’ll have to rename it `demo_map` and install it on the drone:
```bash
 $ ftp 192.168.1.1
 ftp> put demo_map
```

**Warning:** in this first release, the bluetooth beacons position and geolocation parameters are hardcoded. Therefore you’ll need to edit `src/uart/parser.c` in addition to your map file.

#### Beacons software

[TODO]

#### User application

The pc application is a standalone executable, it can be launched from anywhere so you can install it wherever you want.

### Use

First, deploy the beacons in the room. Once is done, you can switch on the drone.

**Warning:** In this first release, the magnetometer control is not as robust as it should. Make sure to positionate your drone’s head approximately 90° counterclockwise from the north before starting the executable, in order to be sure that the calibration goes well.

There is no daemon to start our drone program so you’ll have to connect to the drone with telnet in order to launch it.
```
 $ telnet 192.168.1.1
 # cd /data/video/
 # ./Control_Law.elf
```

Once the drone program is launched, you can launch the user application from your computer to control the drone and ask it to go to a destination.
```bash
 $ src/user_app/Findy
```

If you have connection issues:
* Make sure you’re connected by Wifi to the drone and that there is no other devices connected by wifi to the drone.
* Disable your firewall (the drone will try to connect to your device).
