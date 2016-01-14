package com.network.UDP;

import com.network.FacadeCom;

/**
 * Created by Lux on 12/11/2015.
 */
public class ComParams {

    private UDPSender sender;
    private FacadeCom com;

    /**
     * Constructeur utilisé pour l'envoi d'un objet Informations
     */
    public ComParams(FacadeCom com) {
        this.com = com;
        this.sender = this.com.getSender();
    }



    public UDPSender getSender() {
        return sender;
    }

    public FacadeCom getCom() {
        return com;
    }


}