ADD_SUBDIRECTORY(wiringPi_lib)

find_package(Threads REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/src/wiringPi_lib)
link_directories(${PROJECT_SOURCE_DIR}/src/wiringPi_lib)

add_executable(piface_prj blink.c)

target_link_libraries(piface_prj ${CMAKE_THREAD_LIBS_INIT})

target_link_libraries(piface_prj piface_lib)

install(TARGETS piface_prj DESTINATION bin)
