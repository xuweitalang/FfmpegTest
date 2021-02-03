//
// Created by EDZ on 2021/2/3.
//

#ifndef FFMPEGTEST_TESTFFMPEG_H
#define FFMPEGTEST_TESTFFMPEG_H


#include "JavaCallHelper.h"
#include "AudioChannel.h"
#include "VideoChannel.h"
#include "macro.h"
#include <pthread.h>

extern "C" {
#include <libavformat/avformat.h>
}

class TestFFmpeg {
public:
    TestFFmpeg(JavaCallHelper *javaCallHelper, char *dataSource);

    ~TestFFmpeg();

    void prepare();

    void _prepare();

private:
    JavaCallHelper *javaCallHelper = 0;
    AudioChannel *audioChannel = 0;
    VideoChannel *videoChannel = 0;
    char *dataSource;
    pthread_t pid_prepare;
};


#endif //FFMPEGTEST_TESTFFMPEG_H
