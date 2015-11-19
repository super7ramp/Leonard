package com.ihm;

import android.app.Activity;
import android.content.Intent;

import com.network.FacadeCom;

/**
 * Created by Lux on 06/11/2015.
 */
public class FacadeView {

    private static FacadeView singleton;
    private FacadeCom com;
    private Activity firstActivity;

    private FacadeView(Activity activity) {
        //controller = ControllerFacade.getInstance(this);
        firstActivity = activity;
        this.com = FacadeCom.getInstance(this);
    }

    /**
     * Permet de recuperer l'instance de FacadeView
     * @return singleton
     */
    public static FacadeView getInstance (Activity activity) {
        if (singleton == null) {
            singleton = new FacadeView(activity) ;
        }
        return singleton ;
    }


    /**
     * permet de changer d'activity
     * @param activity
     */
    public void changeActivity(Class activity) {
        Intent i = new Intent(firstActivity, activity);
        i.addFlags(Intent.FLAG_ACTIVITY_NO_ANIMATION);
        firstActivity.startActivityForResult(i, 1);
    }


}
