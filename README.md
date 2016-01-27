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

[TODO]

### Use

[TODO]
[subpoints:
 * bluetooth beacons position, map
 * user program
 * embedded program]
