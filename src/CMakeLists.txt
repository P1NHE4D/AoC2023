
FILE(GLOB CSources *.cpp)
ADD_EXECUTABLE(${CMAKE_PROJECT_NAME} ${CSources}
        day02.h
        day02.cpp)