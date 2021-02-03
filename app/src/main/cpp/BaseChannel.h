//
// Created by EDZ on 2021/2/3.
//

#ifndef FFMPEGTEST_BASECHANNEL_H
#define FFMPEGTEST_BASECHANNEL_H

/**
 * VideoChannel和AudioChannel的父类
 */
class BaseChannel {
public:
    //构造函数
    BaseChannel() {}

    //析构函数(加了virtual关键字代表虚析构函数)，作为父类，析构函数需要是虚析构函数
    virtual ~BaseChannel() {

    }
};


#endif //FFMPEGTEST_BASECHANNEL_H
