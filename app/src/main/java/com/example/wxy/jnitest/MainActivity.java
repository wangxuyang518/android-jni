package com.example.wxy.jnitest;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {


    static {
        System.loadLibrary("native-lib");
    }

    private Button button1;
    private Button button2;
    private Button button3;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        button1= (Button) findViewById(R.id.button1);
        button2= (Button) findViewById(R.id.button2);
        button3= (Button) findViewById(R.id.button3);
        button1.setOnClickListener(this);
        button2.setOnClickListener(this);
        button3.setOnClickListener(this);
    }


    public native String stringFromJNI();
    public native String stringFromJNI1();
    public native String stringFromJNI2();

    @Override
    public void onClick(View v) {
        switch (v.getId()){
            case R.id.button1:
                Toast.makeText(this, stringFromJNI(), Toast.LENGTH_SHORT).show();
                break;
            case R.id.button2:
               Toast.makeText(this, stringFromJNI1(), Toast.LENGTH_SHORT).show();
                break;
            case R.id.button3:
                Toast.makeText(this, stringFromJNI2(), Toast.LENGTH_SHORT).show();
                break;
        }
    }
    private  String getString(){
        return "wxy";
    }
}
