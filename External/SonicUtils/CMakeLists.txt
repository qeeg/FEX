cmake_minimum_required(VERSION 3.10)
set(NAME SonicUtils)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SRCS
  Source/ELFLoader.cpp
  Source/ELFSymbolDatabase.cpp
  Source/LogManager.cpp
  Source/VM.cpp)

add_library(${NAME} SHARED ${SRCS})
target_include_directories(${NAME} PUBLIC include/)

install(TARGETS ${NAME}
  LIBRARY
    DESTINATION lib
    COMPONENT Libraries)

install(DIRECTORY include/SonicUtils
  DESTINATION include
  COMPONENT Development)

