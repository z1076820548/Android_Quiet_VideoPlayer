#include <jni.h>
#include <string>
#include <iostream>
#include <stdlib.h>

#include <android/log.h>
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

#include "VideoPlayController.h"
#include "JavaStateListener.h"

using namespace std;

#define MODULE_NAME "native_lib"

#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, MODULE_NAME, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, MODULE_NAME, __VA_ARGS__)

VideoPlayController *controller = NULL;
ANativeWindow *window = NULL;
JavaStateListener *stateListener = NULL;

extern "C"
JNIEXPORT void JNICALL
Java_com_quiet_videoplayer_PlayActivity_nInit(JNIEnv *env, jobject thiz) {
    // TODO: implement nInit()
    LOGD("call nInit");
    controller = new VideoPlayController();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_quiet_videoplayer_PlayActivity_nDestroy(JNIEnv *env, jobject thiz) {
    // TODO: implement nDestroy()
    LOGD("call nDestroy");
    if(controller == NULL)
    {
        LOGE("controller is NULL when call nDestroy");
        return;
    }
    delete(controller);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_quiet_videoplayer_PlayActivity_nStart(JNIEnv *env, jobject thiz) {
    // TODO: implement nStart()
    LOGD("call nStart");
    if(controller == NULL)
    {
        LOGE("controller is NULL when call nStart");
        return;
    }
    controller->start();
}
extern "C"
JNIEXPORT void JNICALL
Java_com_quiet_videoplayer_PlayActivity_nStop(JNIEnv *env, jobject thiz) {
    // TODO: implement nStop()
    LOGD("call nStop");
    if(controller == NULL)
    {
        LOGE("controller is NULL when call nStop");
        return;
    }
    controller->stop();
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_quiet_videoplayer_PlayActivity_nOpenFile(JNIEnv *env, jobject thiz, jstring filePath) {
    // TODO: implement nOpenFile()
    LOGD("nOpenFile");
    if(controller == NULL)
    {
        LOGE("controller is NULL when call nOpenFile");
        return false;

    }
    const char *pathChars = env->GetStringUTFChars(filePath, NULL);

    bool result =  controller->openFile(pathChars);

    env->ReleaseStringUTFChars(filePath, pathChars);

    return result;
}extern "C"
JNIEXPORT void JNICALL
Java_com_quiet_videoplayer_PlayActivity_nCloseFile(JNIEnv *env, jobject thiz) {
    // TODO: implement nCloseFile()
    LOGD("call nCloseFile");
    if(controller == NULL)
    {
        LOGE("controller is NULL when call nCloseFile");
        return;
    }
    controller->closeFile();
}extern "C"
JNIEXPORT void JNICALL
Java_com_quiet_videoplayer_PlayActivity_nSetSurface(JNIEnv *env, jobject thiz,
                                                    jobject surface) {
    // TODO: implement nSetSurface()
    LOGD("call nSetSurface");
    if(controller == NULL)
    {
        LOGE("controller is NULL when call nSetSurface");
        return;
    }
    window = ANativeWindow_fromSurface(env, surface);
    controller->setWindow(window);
}extern "C"
JNIEXPORT void JNICALL
Java_com_quiet_videoplayer_PlayActivity_nSetSize(JNIEnv *env, jobject thiz, jint width,
                                                 jint height) {
    // TODO: implement nSetSize()
    LOGD("call nSetSize");
    if(controller == NULL)
    {
        LOGE("controller is NULL when call nSetSize");
        return;
    }
    controller->setSize(width, height);
}extern "C"
JNIEXPORT void JNICALL
Java_com_quiet_videoplayer_PlayActivity_nSeek(JNIEnv *env, jobject thiz, jlong position) {
    // TODO: implement nSeek()
    LOGD("call nSeek");
    if(controller == NULL)
    {
        LOGE("controller is NULL when call nSetSize");
        return;
    }
    controller->seek(position);
}extern "C"
JNIEXPORT jlong JNICALL
Java_com_quiet_videoplayer_PlayActivity_nGetDuration(JNIEnv *env, jobject thiz) {
    // TODO: implement nGetDuration()
    LOGD("call nSetSize");
    if(controller == NULL)
    {
        LOGE("controller is NULL when call nSetSize");
        return 0;
    }
    return controller->getDuration();
}extern "C"
JNIEXPORT void JNICALL
Java_com_quiet_videoplayer_PlayActivity_nSetPlayStateListener(JNIEnv *env, jobject thiz,
                                                              jobject listener) {
    // TODO: implement nSetPlayStateListener()
    LOGD("call nSetSize");
    if(controller == NULL)
    {
        LOGE("controller is NULL when call nSetSize");
        return;
    }
    stateListener = new JavaStateListener(env, listener);
    controller->setPlayStateListener(stateListener);
}extern "C"
JNIEXPORT void JNICALL
Java_com_quiet_videoplayer_PlayActivity_nRemovePlayStateListener(JNIEnv *env, jobject thiz) {
    // TODO: implement nRemovePlayStateListener()
    LOGD("call nSetSize");
    if(controller == NULL)
    {
        LOGE("controller is NULL when call nSetSize");
        return;
    }

    controller->removePlayStateListener();
    if(stateListener)
    {
        delete(stateListener);
    }
}extern "C"
JNIEXPORT jboolean JNICALL
Java_com_quiet_videoplayer_PlayActivity_nIsPlaying(JNIEnv *env, jobject thiz) {
    // TODO: implement nIsPlaying()
    LOGD("call nSetSize");
    if(controller == NULL)
    {
        LOGE("controller is NULL when call nSetSize");
        return false;
    }

    return controller->isPlaying();

}