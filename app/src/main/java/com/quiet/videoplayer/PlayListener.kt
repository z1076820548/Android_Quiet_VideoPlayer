package com.quiet.videoplayer

interface PlayListener {
    fun onProgressChanged(positionMS: Long, isPlayFinished: Boolean)
    fun onPlayStateChanged(isPlay: Boolean)
}