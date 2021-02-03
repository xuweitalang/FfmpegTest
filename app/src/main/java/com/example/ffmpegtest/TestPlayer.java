package com.example.ffmpegtest;

/**
 * @Author: xuwei
 * @Date: 2021/2/3 10:59
 * @Description:
 */
class TestPlayer {
    static {
        System.loadLibrary("native-lib");
    }

    //直播地址或者媒体文件路径
    private String dataSource;

    public void setDataSource(String dataSource) {
        this.dataSource = dataSource;
    }

    //播放准备工作
    public void prepare() {
        prepareNative(dataSource);
    }

    MyErrorListener listener;

    /**
     * 给jni回调用的
     * @param errorCode errorCode 从jni通过反射传递过来
     */
    public void onError(int errorCode) {
        if (listener != null) {
            listener.onError(errorCode);
        }
    }

    interface MyErrorListener {
        void onError(int errorCode);
    }

    public void setListener(MyErrorListener listener) {
        this.listener = listener;
    }

    private native void prepareNative(String dataSource);
}
