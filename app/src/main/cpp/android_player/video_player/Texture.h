//
// Created by zwt on 2020/6/30.
//

#ifndef ANDROID_QUIET_VIDEOPLAYER_TEXTURE_H
#define ANDROID_QUIET_VIDEOPLAYER_TEXTURE_H

#include <stdlib.h>
#include <stdio.h>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

class Texture {
public:
    Texture();

    ~Texture();

    bool createTexture();

    void updateDataToTexture(uint8_t *pixels, int width, int height);

    bool bindTexture(GLint uniformSampler);

    void dealloc();

private:
    GLuint texture = 0;

    int initTexture();
};


#endif //ANDROID_QUIET_VIDEOPLAYER_TEXTURE_H
