package com.quiet.videoplayer

import android.Manifest
import android.content.Intent
import android.content.pm.PackageManager
import android.os.Bundle
import android.util.Log
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import androidx.core.app.ActivityCompat
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import com.quiet.videoplayer.adapter.VideoFileAdapter
import com.quiet.videoplayer.bean.VideoBean
import com.quiet.videoplayer.util.loadVideoFiles
import com.tbruyelle.rxpermissions2.RxPermissions
import io.reactivex.Observable
import io.reactivex.android.schedulers.AndroidSchedulers
import io.reactivex.functions.Consumer
import io.reactivex.schedulers.Schedulers
import kotlinx.android.synthetic.main.activity_main.*


class MainActivity : AppCompatActivity() {


    val TAG = "MainActivity"
    var videoList: ArrayList<VideoBean>? = null
        set(value) {
            field = value
            adapter.data = value
        }
    var adapter = VideoFileAdapter()
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val rxPermissions = RxPermissions(this) // where this is an Activity or Fragment instance

        rxPermissions.request(
            Manifest.permission.READ_EXTERNAL_STORAGE,
            Manifest.permission.WRITE_EXTERNAL_STORAGE
        ).subscribe { aBoolean ->
            if (aBoolean) {
                //申请的权限全部允许
                rv_files.layoutManager = LinearLayoutManager(this, RecyclerView.VERTICAL, false)
                rv_files.adapter = adapter
                adapter.itemClickListener = {
                    val path = videoList!![it].path
                    var intent = Intent(this, PlayActivity::class.java)
                    intent.putExtra("path", path)
                    startActivity(intent)
                }
                Observable.fromCallable {
                    loadVideoFiles(this)
                }.subscribeOn(Schedulers.io())
                    .observeOn(AndroidSchedulers.mainThread())
                    .subscribe {
                        videoList = it
                    }
            } else {
                //只要有一个权限被拒绝，就会执行
                Toast.makeText(this@MainActivity, "未授权权限，部分功能不能使用", Toast.LENGTH_SHORT).show()
            }
        }

    }


}
