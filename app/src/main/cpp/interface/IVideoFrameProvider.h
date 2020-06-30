//
// Created by zwt on 2020/6/29.
//

#ifndef ANDROID_QUIET_VIDEOPLAYER_IVIDEOFRAMEPROVIDER_H
#define ANDROID_QUIET_VIDEOPLAYER_IVIDEOFRAMEPROVIDER_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

using namespace std;

struct VideoFrame {
    int64_t pts;
    uint8_t *data;
    int32_t width;
    int32_t height;

    int32_t maxDataSizeInByte = 0;

    VideoFrame(int32_t dataLenInByte) {
        this->maxDataSizeInByte = dataLenInByte;
        data = (uint8_t *) malloc(maxDataSizeInByte);
        memset(data, 0, maxDataSizeInByte);
    }

    ~VideoFrame() {
        if (data != NULL) {
            free(data);
        }
    }

};

class IVideoFrameProvider {
public:
    virtual VideoFrame *getVideoFrame() = 0;

    virtual void putBackUsed(VideoFrame *data) = 0;
};


#endif //ANDROID_QUIET_VIDEOPLAYER_IVIDEOFRAMEPROVIDER_H
