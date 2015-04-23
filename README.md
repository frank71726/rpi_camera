This project based on [WiringPi](http://wiringpi.com) uses CMAKE to compile application.

At the beginning, it's only flash led ont PIFACE.
In the future, I'm going to porting the others peripherial functions to make it bacome camera with infrared led.

1.  Download toolchain from [here](https://github.com/raspberrypi/tools/tree/master/arm-bcm2708)
or [here-including rootfs](https://github.com/frank71726/pi_cross)
2.  Adding code as below to $HOME/.bashrc

        export RPI_ROOT="/home/frank/hpbProject/pi_cross/tools-master/arm-bcm2708/arm-bcm2708hardfp-linux-gnueabi"
        export PATH=$RPI_ROOT/bin/:$PATH
3.  Download usr/ and lib/ folders of raspberry pi to host machine.

    These folders will be used at toolchain-rpi.cmake.

    When using cross complier, it is goiing to take some data by search path of CMAKE_FIND_ROOT_PATH.

        scp -r pi@192.168.1.187:/home/usr ./
        scp -r pi@192.168.1.187:/home/lib ./
4.  Follow steps as below

        mkdir build
        cd build
        cmake ../
        make
        sudo make install

>>**Important**: I have added a nice feature in the CMake configuration of this project in order to
                mount automatically the $HOME folder of the RPi in our host machine using sshfs.
                Therefore, we will need to have sshfs package installed in our system. Setting in
                the CMake configuration the variable CMAKE_INSTALL_PREFIX to this path,
                we are able to copy the binaries directly to the RPi with the command make install.
                If you don’t like or want this feature, comment or delete the lines 16-22.
                In this case you should copy the binaries to your raspberry pi using, for example, **scp** command.

##Reference
*   [Cross-compiling & debugging for RaspberryPi using CMake and gdbserver/gdb](http://plagatux.es/2013/03/cross-compiling-debugging-for-raspberrypi-using-cmake-and-gdbservergdb/)
