cmake_minimum_required(VERSION 3.22)
project(HELLOAPP VERSION 1.1)

set(SRC_FILES main.cpp src/calc.cpp)
# # message(WARNING "Src File has ${SRC_FILES}")
# # message(FATAL_ERROR "Src File has ${SRC_FILES}")
# message("CMAKE_SOURCE_DIR is ${CMAKE_SOURCE_DIR}")
# # message("${MINGW}")

# message(STATUS "Src File has ${SRC_FILES}")
# #list(APPEND CMAKE_PREFIX_PATH  /usr/share/mingw-w64)

# #important variables
# message(STATUS "CMAKE_SOURCE_DIR ${CMAKE_SOURCE_DIR}")
# message(STATUS "CMAKE_CURRENT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}")
# message(STATUS "CMAKE_BINARY_DIR ${CMAKE_BINARY_DIR}")
# message(STATUS "CMAKE_CURRENT_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}")
# message(STATUS "CMAKE_GENERATOR ${CMAKE_GENERATOR}")

# #set value of built-in variables
# # set(CMAKE_CXX_STANDARD 14)
# # set(CMAKE_CXX_STANDARD_REQUIRED true)
# MESSAGE(STATUS "show c++ standard: ${CMAKE_CXX_STANDARD}")
# MESSAGE(STATUS "show c++ standard required: ${CMAKE_CXX_STANDARD_REQUIRED}")

# #rephrase: set(SRC_FILES main.cpp src/calc.cpp)
# set (SRC_FILES "main.cpp;src/calc.cpp")

# #environment variable
# set(p $ENV{PATH})
# message(STATUS "PATH $ENV{PATH}")

# #define value in cmake command argument list
# message(STATUS "Argument value is ${myValue}")
# message(STATUS "CMAKE_CXX_STANDARD is ${CMAKE_CXX_STANDARD}")


#add child cmake in lib folder
add_subdirectory(${CMAKE_SOURCE_DIR}/lib)
add_executable(hellobinary ${SRC_FILES})
target_include_directories(hellobinary PUBLIC include/ lib/)

target_link_libraries(hellobinary PUBLIC wifi_lib)


#configure file
set(PRODUCT_YEAR "2021")
configure_file(default_config.h.in default_config.h)
target_include_directories(hellobinary PUBLIC ${PROJECT_BINARY_DIR})

# set(DEBUG 1)
#if/for each
if(DEBUG)
    set(DEBUGINFO "author mariam shobita")
#else()
# elseif()
endif()

#if examples
    #if(NOT DEBUG)
    #if(Var1 AND Var2)
    #if(Var1 OR Var2)
    #if(myVal MATCHES regularExpression)
    #if(EXISTS file)
    #if(Var1 LESS Var2)
    #if(Var1 GREATER Var2)
    #if(Var1 EQUAL Var2)
    #if(TARGET wifi_lib)

# #foreach
# #with items
# foreach(F IN ITEMS M O A T A S E M)
#     message(STATUS ${F})
# endforeach()

# #with lists
# set(List E L S A Y E D)
# foreach(F IN LISTS List)
#     message(STATUS ${F})
# endforeach()


# #while
# set(Var1 10)
# while(Var1)
#     message(${Var1})
#     math(EXPR Var1 "${Var1} - 1")
# endwhile()


# #function
# function(happynewyear arg1)
#     message("Arg1 ${arg1}") #name of the variable
#     message("Arg1 ${${arg1}}") #show values of list
#     message("Arg1 ${ARGN}") #extra argument
#     message("Arg1 ${ARGC}") #count
# endfunction()

# set(var1 2 0 2 2)
# happynewyear(var1 jan)

#cache
# option(CVar "BOOL Var" TRUE)
set(var2 TRUE CACHE BOOL "bool variable")
option(DEBUG "BOOL Var" 1)

#compile
target_compile_definitions(hellobinary PUBLIC "STD_CXX=20")
target_compile_definitions(hellobinary PUBLIC -march=native)

#install
install(FILES "${PROJECT_BINARY_DIR}/hellobinary"
        DESTINATION "${PROJECT_BINARY_DIR}/executable")
install(FILES "${CMAKE_SOURCE_DIR}/lib/Wifi.hpp"
                # "${CMAKE_SOURCE_DIR}/include/calc.hpp"
        DESTINATION "${PROJECT_BINARY_DIR}/include")