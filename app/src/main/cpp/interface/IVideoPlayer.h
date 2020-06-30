//
// Created by zwt on 2020/6/29.
//

#ifndef ANDROID_QUIET_VIDEOPLAYER_IVIDEOPLAYER_H
#define ANDROID_QUIET_VIDEOPLAYER_IVIDEOPLAYER_H

#include <stdlib.h>
#include "IVideoFrameProvider.h"

//视频播放接口
class IVideoPlayer {
public:
    virtual bool create() = 0;

    virtual void release() = 0;

    virtual void refresh() = 0;

    // 面向IVideoPlayer的音频数据的提供源，它为IVideoPlayer提供解码好的音频数据
    virtual void setVideoFrameProvider(IVideoFrameProvider *provider) = 0;

    virtual void removeVideoFrameProvider(IVideoFrameProvider *provider) = 0;

    virtual void setWindow(void *window) = 0;

    virtual void setSize(int32_t width, int32_t height) = 0;

    virtual bool isReady() = 0;
};


#endif //ANDROID_QUIET_VIDEOPLAYER_IVIDEOPLAYER_H
