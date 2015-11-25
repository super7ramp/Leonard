package com.ihm;

import android.app.Activity;
import android.content.Intent;
import android.view.View;
import android.widget.TextView;

/**
 * Created by Lux on 05/11/2015.
 */

public class MenuHandling implements View.OnClickListener {
    public static final int RESULT_CLOSE_ALL = -1;



    /**
     * The view associate to the menu
     */
    View menu;

    /**
     * Activity which has created the menu
     */
    Activity activity;


    /**
     * "FindyApp" Text
     */
    TextView findyAppText;

    /**
     * "Disconnect" Text
     */
    TextView disconnectionText;

    /**

    /**
     * Menu creation
     * @param activity Activity which is creating the menu
     * @param menu View which contains the menu
     */
    public MenuHandling(Activity activity, View menu) {
        // Recuperation des objets
        this.menu = menu;
        this.activity = activity;

        this.disconnectionText = (TextView) menu.findViewById(R.id.disconnectText);
        this.disconnectionText.setOnClickListener(this);

        this.findyAppText = (TextView) menu.findViewById(R.id.FindyApp);
        this.findyAppText.setOnClickListener(this);

        if(activity instanceof ConnectActivity) {
            disconnectionText.setVisibility(View.INVISIBLE);
        }
        else {
            disconnectionText.setVisibility(View.VISIBLE);
        }
    }

    /**
     * Methode declenchee lorsqu'on clique sur l'un des boutons
     * Si on clique sur profil, on ouvre l'activite montrant le profil de l'utilisateur
     * Si on clique sur deconnexion, on deconnecte l'utilisateur
     * @param arg0 Bouton clique
     */
    @Override
    public void onClick(View arg0) {
        // Si on a clique sur deconnexion
       if(arg0.equals(disconnectionText)) {
         //   facade.performDisconnect(); // On deconnecte l'utilisateur
            Intent i = new Intent();
            activity.setResult(MenuHandling.RESULT_CLOSE_ALL, i); // On previent l'activite precedente qu'il faut se quitter
            activity.finish(); // On quitte cette activite
        } else if (arg0.equals(findyAppText)) { // Si on a clique sur profil
            //facade.setProfileLogin(facade.getLogin()); // On previent qu'on veut voir le profil de l'utilisateur
            //facade.changeActivityProfile(activity); // On ouvre une nouvelle activite
        }

    }

}
