package com.ihm;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;

import com.ihm.R;

/**
 * Created by Lux on 06/11/2015.
 */
public class ConnectActivity extends Activity {

    private FacadeView facade;

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_connect);

        View menu = findViewById(R.id.menu);
        MenuHandling menuH = new MenuHandling(this, menu);

        // Facade creation
        facade = FacadeView.getInstance(this);

    }

    public void onConnectButtonClick(View v) {

        /*
         * Add management of connection
         */

        this.facade.changeActivity(OrderActivity.class);

    }




}
