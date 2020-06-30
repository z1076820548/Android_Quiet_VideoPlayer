//
// Created by zwt on 2020/6/29.
//

#ifndef ANDROID_QUIET_VIDEOPLAYER_JAVASTATELISTENER_H
#define ANDROID_QUIET_VIDEOPLAYER_JAVASTATELISTENER_H

#include <jni.h>
#include <stdlib.h>
#include <iostream>
#include "IPlayStateListener.h"
using namespace std;

class JavaStateListener :public IPlayStateListener{
public:
    JavaStateListener(JNIEnv *env,jobject listener);
    ~JavaStateListener();
    void progressChanged(int64_t currentProgress, bool isPlayFinished) override;
    void playStateChanged(bool isPlay) override;

private:
    JavaVM *vm = NULL;
    jobject listener = NULL;
    jmethodID progressChangedMethod = NULL;
    jmethodID playStateChangedMethod = NULL;
};


#endif //ANDROID_QUIET_VIDEOPLAYER_JAVASTATELISTENER_H
