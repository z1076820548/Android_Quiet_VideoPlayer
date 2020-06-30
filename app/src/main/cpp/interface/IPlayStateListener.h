//
// Created by zwt on 2020/6/29.
//

#ifndef ANDROID_QUIET_VIDEOPLAYER_IPLAYSTATELISTENER_H
#define ANDROID_QUIET_VIDEOPLAYER_IPLAYSTATELISTENER_H
#include <stdlib.h>
#include <stdint.h>

class IPlayStateListener {
public:
    virtual void progressChanged(int64_t currentProgress, bool isPlayFinished) = 0;
    virtual void playStateChanged(bool isPlay) = 0;
};


#endif //ANDROID_QUIET_VIDEOPLAYER_IPLAYSTATELISTENER_H
