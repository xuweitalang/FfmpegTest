package com.example.ffmpegtest;

import android.os.Bundle;
import android.os.Environment;
import android.view.SurfaceView;

import androidx.appcompat.app.AppCompatActivity;

import java.io.File;

public class MainActivity extends AppCompatActivity {
    SurfaceView surfaceView;
    private TestPlayer testPlayer;

//    static {
//        System.loadLibrary("native-lib");
//    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        surfaceView = findViewById(R.id.surfaceView);

        testPlayer = new TestPlayer();
        testPlayer.setDataSource(new File(Environment.getExternalStorageDirectory() + File.separator + "demo.mp4").getAbsolutePath());
        testPlayer.setListener(new TestPlayer.MyErrorListener() {
            @Override
            public void onError(int errorCode) {

            }
        });
    }

    @Override
    protected void onResume() {
        super.onResume();
        testPlayer.prepare();
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
}