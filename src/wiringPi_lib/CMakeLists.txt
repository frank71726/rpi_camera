include_directories(${PROJECT_SOURCE_DIR}/src/wiringPi_lib)

ADD_LIBRARY(piface_lib mcp23s17.c wiringPi.c wiringPiSPI.c softPwm.c softTone.c piFace.c piHiPri.c piThread.c)
