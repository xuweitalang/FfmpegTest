#include <jni.h>
#include <string>
#include "JavaCallHelper.h"
#include "TestFFmpeg.h"

extern "C" {
#include <libavutil/avutil.h>
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_ffmpegtest_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(av_version_info());
//    return env->NewStringUTF(hello.c_str());


}extern "C"
JNIEXPORT void JNICALL
Java_com_example_ffmpegtest_TestPlayer_prepareNative(JNIEnv *env, jobject thiz,
                                                     jstring data_source) {
    const char *dataSource = env->GetStringUTFChars(data_source, 0);
    JavaCallHelper *javaCallHelper = new JavaCallHelper();
    TestFFmpeg *ffmpeg = new TestFFmpeg(javaCallHelper, const_cast<char *>(dataSource));
    ffmpeg->prepare();
    env->ReleaseStringUTFChars(data_source, dataSource);
}