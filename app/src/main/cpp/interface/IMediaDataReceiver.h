//
// Created by zwt on 2020/6/29.
//

#ifndef ANDROID_QUIET_VIDEOPLAYER_IMEDIADATARECEIVER_H
#define ANDROID_QUIET_VIDEOPLAYER_IMEDIADATARECEIVER_H

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "IVideoFrameProvider.h"
#include "IAudioFrameProvider.h"

//用于接收解码好的音视频数据的接口  它是用来维护并存储已经解码好的音视频数据和使用过的音视频数据。
class IMediaDataReceiver {
public:
    virtual void receiveAudioFrame(AudioFrame *audioData) = 0;

    virtual void receiveVideoFrame(VideoFrame *videoData) = 0;

    virtual AudioFrame *getUsedAudioFrame() = 0;

    virtual VideoFrame *getUsedVideoFrame() = 0;

    virtual void putUsedAudioFrame(AudioFrame *audioData) = 0;

    virtual void putUsedVideoFrame(VideoFrame *videoData) = 0;
};


#endif //ANDROID_QUIET_VIDEOPLAYER_IMEDIADATARECEIVER_H
