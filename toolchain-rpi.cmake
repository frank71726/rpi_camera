#jNCLUDE(CMakeForceCompiler)

SET(CMAKE_SYSTEM_NAME Linux) # this one is important
SET(CMAKE_SYSTEM_VERSION 1)  # this one not so much

SET(CMAKE_C_COMPILER   $ENV{RPI_ROOT}/bin/arm-bcm2708hardfp-linux-gnueabi-gcc)
SET(CMAKE_CXX_COMPILER $ENV{RPI_ROOT}/bin/arm-bcm2708hardfp-linux-gnueabi-g++)
#SET(CMAKE_AR           $ENV{RPI_ROOT}/bin/arm-bcm2708hardfp-linux-gnueabi-ar)
#SET(CMAKE_LINKER       $ENV{RPI_ROOT}/bin/arm-bcm2708hardfp-linux-gnueabi-ld)
#SET(CMAKE_NM           $ENV{RPI_ROOT}/bin/arm-bcm2708hardfp-linux-gnueabi-nm)
#SET(CMAKE_OBJCOPY      $ENV{RPI_ROOT}/bin/arm-bcm2708hardfp-linux-gnueabi-objcopy)
#SET(CMAKE_OBJDUMP      $ENV{RPI_ROOT}/bin/arm-bcm2708hardfp-linux-gnueabi-objdump)
#SET(CMAKE_STRIP        $ENV{RPI_ROOT}/bin/arm-bcm2708hardfp-linux-gnueabi-strip)
#SET(CMAKE_RANLIB       $ENV{RPI_ROOT}/bin/arm-bcm2708hardfp-linux-gnueabi-ranlib)

# where is the target environment
SET(CMAKE_FIND_ROOT_PATH  $ENV{RPI_ROOT}/rpi_rootfs)

# search for programs in the build host directories
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)

# for libraries and headers in the target directories
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

