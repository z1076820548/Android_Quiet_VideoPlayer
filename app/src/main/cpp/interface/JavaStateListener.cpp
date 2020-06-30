//
// Created by zwt on 2020/6/29.
//

#include "JavaStateListener.h"
#include <android/log.h>

#define MODULE_NAME  "JavaStateListener"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, MODULE_NAME, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, MODULE_NAME, __VA_ARGS__)

/**
 * 要考虑到多线程调用回调，参考博客https://www.jianshu.com/p/e576c7e1c403
 * */
JavaStateListener::JavaStateListener(JNIEnv *env, jobject listener) {
    env->GetJavaVM(&vm);
    this->listener = env->NewGlobalRef(listener);
    jclass cls = env->GetObjectClass(listener);
    this->progressChangedMethod = env->GetMethodID(cls, "onProgressChanged", "(JZ)V");
    this->playStateChangedMethod = env->GetMethodID(cls, "onPlayStateChanged", "(Z)V");
}

JavaStateListener::~JavaStateListener() {
    if (vm != NULL) {
        JNIEnv *env;
        bool needDetach = false;
        if (vm->GetEnv((void **) &env, JNI_VERSION_1_6) == JNI_EDETACHED) {
            needDetach = true;
            if (vm->AttachCurrentThread(&env, 0) != 0) {
                LOGE("Error to attach env when finalize");
                return;
            }
        }
        env->DeleteGlobalRef(listener);
        if (needDetach) {
            vm->DetachCurrentThread();
        }
    }
}

void JavaStateListener::progressChanged(int64_t currentProgress, bool isPlayFinished) {
    LOGD("JavaStateListener:progressChanged,position = %ld", currentProgress);
    if (vm == NULL || listener == NULL || progressChangedMethod == NULL) {
        return;
    }

    JNIEnv *env;
    bool needDetach = false;
    if (vm->GetEnv((void **) &env, JNI_VERSION_1_6) == JNI_EDETACHED) {
        needDetach = true;
        if (vm->AttachCurrentThread(&env, 0) != 0) {
            LOGE("Error to attach env when progressChanged");
            return;
        }
    }
    env->CallVoidMethod(listener, progressChangedMethod, currentProgress, isPlayFinished);
    if (needDetach) {
        vm->DetachCurrentThread();
    }
}

void JavaStateListener::playStateChanged(bool isPlay) {
    LOGD("JavaStateListener:playStateChanged,isPlay=%d", isPlay);
    if (vm == NULL || listener == NULL || playStateChangedMethod == NULL) {
        return;
    }
    JNIEnv *env;
    bool needDetach = false;
    if (vm->GetEnv((void **) &env, JNI_VERSION_1_6) == JNI_EDETACHED) {
        needDetach = true;
        if (vm->AttachCurrentThread(&env, 0) != 0) {
            LOGE("Error to attach env when progressChanged");
            return;
        }
    }
    env->CallVoidMethod(listener, playStateChangedMethod, isPlay);
    if(needDetach)
    {
        vm->DetachCurrentThread();
    }
}