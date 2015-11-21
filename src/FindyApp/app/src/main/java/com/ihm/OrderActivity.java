package com.ihm;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

import com.ihm.FacadeView;
import com.ihm.R;

import java.util.ArrayList;

public class OrderActivity extends Activity {

    private FacadeView facade;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_order);

        View menu = findViewById(R.id.menu);
        MenuHandling menuH = new MenuHandling(this, menu);

        // Facade creation
        this.facade = FacadeView.getInstance(this);


    }


    public void onPlaceButtonClick(View v) {
        if(v.getId() == R.id.hall) {
            Toast.makeText(getApplicationContext(), "hall order", Toast.LENGTH_SHORT).show();
        }
        else if(v.getId() == R.id.gei13) {
            Toast.makeText(getApplicationContext(), "gei13 order", Toast.LENGTH_SHORT).show();
        }
        else if(v.getId() == R.id.gei15) {
            Toast.makeText(getApplicationContext(), "gei15 order", Toast.LENGTH_SHORT).show();
        }
        else if(v.getId() == R.id.toilet) {
            Toast.makeText(getApplicationContext(), "Toilet order", Toast.LENGTH_SHORT).show();
        }
    }

}
