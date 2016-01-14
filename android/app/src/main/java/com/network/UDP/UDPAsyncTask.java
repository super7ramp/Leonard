package com.network.UDP;

import android.os.AsyncTask;

/**
 * Created by Lux on 12/11/2015.
 */
public class UDPAsyncTask extends AsyncTask<ComParams, String, String> {

    @Override
    protected String doInBackground(ComParams... params) {
        String result = "!!!!!! N'est pas passé dans le switch d'envoi";

        return result;
    }

    public void onPostExecute(String result) {
        System.out.println(result);
    }
}