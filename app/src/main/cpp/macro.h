//
// Created by EDZ on 2021/2/3.
//

#ifndef FFMPEGTEST_MACRO_H
#define FFMPEGTEST_MACRO_H

#include <android/log.h>

//定义一个宏函数：用于释放资源
#define DELETE(object) if(object){delete object; object = 0;}

//定义日志打印宏函数
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, "TestFFmpeg",__VA_ARGS__)

#endif //FFMPEGTEST_MACRO_H
