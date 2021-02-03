#cmake_minimum_required(VERSION 3.10.2)
cmake_minimum_required(VERSION 3.4.1)

project("ffmpegtest")

#导入库文件（include文件夹）
include_directories(include)


#库导入方式2：此方式静态库和动态库都适用，推荐使用
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_SOURCE_DIR}/libs/${CMAKE_ANDROID_ARCH_ABI}")

file(GLOB src_files *.cpp)

add_library(
        native-lib
        SHARED
        ${src_files})

target_link_libraries(
        native-lib
        #        -Wl,--start-group和-Wl,--end-group直接插入库，用于解决库导入顺序的问题
        -Wl,--start-group
        avcodec avfilter avformat avutil swresample swscale
        -Wl,--end-group
        log
        z
)


#cmake_minimum_required(VERSION 3.4.1)
#
#include_directories(include)
#
#
##add_library(
##        avcodec
##        STATIC
##        IMPORTED)
##set_target_properties(
##        avcodec
##        PROPERTIES
##        IMPORTED_LOCATION
##        ${CMAKE_SOURCE_DIR}/libs/${CMAKE_ANDROID_ARCH_ABI}/libavcodec.a
##)
#
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_SOURCE_DIR}/libs/${CMAKE_ANDROID_ARCH_ABI}")
#
#file(GLOB src_files *.cpp)
#
##aux_source_directory()
#
#add_library(
#        native-lib
#        SHARED
#        ${src_files})
#
##解决问题的能力
#target_link_libraries(
#        native-lib
#        # TODO
#        #        avcodec avfilter avformat avutil swresample swscale
#        #        avformat avcodec avfilter  avutil swresample swscale
#        #        -Wl,--start-group
#        avcodec avfilter avformat avutil swresample swscale
#        #        -Wl,--end-group
#        log
#        #        z
#)