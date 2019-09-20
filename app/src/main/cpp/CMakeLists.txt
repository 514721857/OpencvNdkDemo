cmake_minimum_required(VERSION 3.4.1)
#该变量为真时会创建完整版本的Makefile
set(CMAKE_VERBOSE_MAKEFILE on)

#定义变量ocvlibs使后面的命令可以使用定位具体的库文件
set(opencvlibs "D:/AndroidWork/OpenCV-android-sdk/sdk/native/libs")

#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../jniLibs/${ANDROID_ABI})

#调用头文件的具体路径
include_directories(D:/AndroidWork/OpenCV-android-sdk/sdk/native/jni/include)

#增加我们的动态库
add_library(libopencv_java4 SHARED IMPORTED)

#建立链接
set_target_properties(libopencv_java4 PROPERTIES IMPORTED_LOCATION
        "${opencvlibs}/${ANDROID_ABI}/libopencv_java4.so")

add_library( # Sets the name of the library.
             native-lib
             SHARED
             native-lib.cpp )


find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

target_link_libraries( # Specifies the target library.
                       native-lib libopencv_java4

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )