//
// Created by zwt on 2020/6/29.
//

#ifndef ANDROID_QUIET_VIDEOPLAYER_IAUDIOPLAYER_H
#define ANDROID_QUIET_VIDEOPLAYER_IAUDIOPLAYER_H

#include <iostream>
#include <stdlib.h>

#include "IAudioFrameProvider.h"

//音频播放器接口
class IAudioPlayer {
public:
    virtual bool create() = 0;
    virtual void release() = 0;
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual bool isPlaying() = 0;
    //面向IAudioPlayer的音频数据的提供源，它为IAudioPlayer提供解码好的音频数据
    virtual void setAudioFrameProvider(IAudioFrameProvider *provider)=0;
    virtual void removeAudioFrameProvider(IAudioFrameProvider *provider) = 0;
};

#endif //ANDROID_QUIET_VIDEOPLAYER_IAUDIOPLAYER_H
