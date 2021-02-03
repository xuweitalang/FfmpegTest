//
// Created by EDZ on 2021/2/3.
//

#include "TestFFmpeg.h"
#include "../../../../../../Android_SDK/Sdk/ndk/20.0.5594570/toolchains/llvm/prebuilt/windows-x86_64/sysroot/usr/include/c++/v1/cstring"

TestFFmpeg::TestFFmpeg(JavaCallHelper *javaCallHelper, char *dataSource) {
    this->javaCallHelper = javaCallHelper;
    //这里的dataSource是从java传过来的字符串，通过JNI接口转成了C++字符串，在JNI方法中被释放掉，导致dataSource变成悬空指针（指向一块已经释放了的内存）,所有不能用以下方法赋值，需要做内存拷贝
//    this->dataSource = dataSource;

    //内存拷贝，自己管理内存
    //strlen:获取字符串长度，strcpy:拷贝字符串

    //c++中字符串是以"\0"结尾的，比如java中字符串是："hello",转成c++字符串为"hello\0",所以下面要申请的长度是dataSource+1
    this->dataSource = new char[strlen(dataSource) + 1];
    strcpy(this->dataSource, dataSource);
}

//在析构函数中释放资源
TestFFmpeg::~TestFFmpeg() {
    //来自宏函数
    DELETE(dataSource)
    DELETE(javaCallHelper)

//    if (dataSource) {
//        delete dataSource;
//        dataSource = 0;
//    }
//
//    if(javaCallHelper) {
//        delete javaCallHelper;
//        javaCallHelper = 0;
//    }
}

/**
 * 线程中的工作
 * @param args
 * @return
 */
void *task_prepare(void *args) {
    TestFFmpeg *ffmpeg = static_cast<TestFFmpeg *>(args);
    ffmpeg->_prepare();
    return 0; //这里一定要返回0
}

void TestFFmpeg::_prepare() {
    AVFormatContext *formatContext = avformat_alloc_context();
    AVDictionary *avDictionary = 0;
    av_dict_set(&avDictionary, "timeout", "10000000", 0); //设置超时时间未10秒，这里的单位是微秒
    int ret = avformat_open_input(&formatContext, dataSource, 0, &avDictionary);
    av_dict_free(&avDictionary);
    if (ret) { //ret=0,表示成功，不为0失败
        LOGE("打开媒体失败：%s", av_err2str(ret));
        //失败，回调给java层
        // javaCallHelper jni 回调java方法
    }
}

/**
 * 播放准备
 * 这里需要创建子线程，因为视频播放需要放在子线程中进行
 */
void TestFFmpeg::prepare() {
    //创建子线程
    // pthread_t* __pthread_ptr, pthread_attr_t const* __attr, void* (*__start_routine)(void*), void*
    pthread_create(&pid_prepare, 0, task_prepare, this);
}
