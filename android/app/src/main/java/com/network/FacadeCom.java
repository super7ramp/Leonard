package com.network;

import com.ihm.FacadeView;
import com.network.UDP.UDPReceiver;
import com.network.UDP.UDPSender;

import java.io.IOException;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;

/**
 * Created by Lux on 12/11/2015.
 */
public class FacadeCom {

    private static FacadeCom singleton;
    private DatagramSocket daSocket;
    private InetAddress addrLoc;
    private int port;
    private UDPReceiver receiver;
    private UDPSender sender;
    private FacadeView view;
    private InetAddress addrDist;

    private FacadeCom(FacadeView view) {
        try {
            //this.nom = nom;
            this.port = 1234;
            this.daSocket = new DatagramSocket(this.port);
            this.daSocket.setBroadcast(true);
            this.sender = new UDPSender(this.port, this.daSocket);
            this.addrLoc = IPAddress.getIp();
            this.receiver = new UDPReceiver(this, this.daSocket, this.addrLoc);
            this.receiver.start();
            //this.etat = etatCom.Deconnecte;
            //this.info = new Informations(0.0,0.0,0);
            this.view = view;
        } catch (SocketException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /**
     * Return FacadeCom instance with (FacadeView view) argument
     * @return singleton
     */
    public static FacadeCom getInstance(FacadeView view) {
        if (singleton == null) {
            singleton = new FacadeCom(view) ;
        }
        return singleton ;
    }



    public static FacadeCom getSingleton() {
        return singleton ;
    }


    /**
     * Methiode appelée par l'application pilote lors de la connection du pilote au drone. Cette methode appelle la methode sendHello() du sender.
     **/
    public void demandeConnect() {
        /*this.etat = etatCom.EnConnexion;
        while (this.etat == etatCom.EnConnexion) {

            ComParams params = new ComParams(this, typeContenu.HELLO, this.drone);
            UDPAsyncTask task = new UDPAsyncTask();
            task.execute(params);
            System.out.println("Envoi hello");
            try {
                currentThread().sleep(1000);
            } catch (Exception e) {
                e.printStackTrace();
            }
        }*/
    }


    /**
     * Methode appelée par l'application pilote lors de la deconnection du pilote au drone. Cette methode va appeler la methode sendGoodbye() du sender.
     * La methode send goodBye() sera appelé 3 fois maximum ou jusqu'à ce qu'il ait recu un ack.
     **/
    public void demandeDeconnect() {
        /*int compteur = 0;
        this.etat = etatCom.Fin_Wait1;
        while (this.etat == etatCom.Fin_Wait1 && compteur < 3) {
            ComParams params = new ComParams(this, typeContenu.GOODBYE, this.drone);
            UDPAsyncTask task = new UDPAsyncTask();
            task.execute(params);
            compteur++;
            try {
                currentThread().sleep(1000);
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        this.etat = etatCom.Deconnecte;
        this.addrDist = null;
        this.sender.setAddrDist(null);*/
    }

    /**
     * Methode appelée lors de la reception d'un hello. Si le drone recoit un hello, l'application va afficher "reception d'un hello" puis renvoyer
     * un helloAck. Cette methode prend en paramètre l'addresse IP de l'emetteur du hello. Elle va ensuite l'enregistrer dans son sender.
     **/
    public void processHello(InetAddress addr) {
       /* this.addrDist = addr;
        this.etat = etatCom.Connecte;
        this.sender.setAddrDist(this.addrDist);

        helloHandler.post(new Runnable() {
            private FacadeCom fcom;
            public void run() {
                this.fcom = FacadeCom.getSingleton();
                if (this.fcom.getNom() == typeUser.DRONE) {
                    ComParams params2 = new ComParams(this.fcom, this.fcom.isDrone(), "Reception d'un hello");
                    UDPAsyncTask task2 = new UDPAsyncTask();
                    task2.execute(params2);
                }
            }
        });


        helloHandler.post(new Runnable() {
            private FacadeCom fcom;
            public void run() {
                this.fcom = FacadeCom.getSingleton();
                ComParams params = new ComParams(this.fcom, this.fcom.isDrone(), "Envoi d'un hello ack");
                UDPAsyncTask task = new UDPAsyncTask();
                task.execute(params);
            }
        });

        this.sender.envoiHelloAck();


        if (this.nom == typeUser.DRONE) {
            this.screen.onConnectedState();
        }*/
    }



    /**
     * Methode appelée lors de la reception d'un helloAck. Cette methode prend en paramètre l'addresse IP de l'emetteur du hello. Elle va ensuite l'enregistrer dans son sender.
     **/
    public void processHelloAck(InetAddress addr) {
        this.addrDist = addr;
        //this.etat = etatCom.Connecte;
        this.sender.setAddrDist(this.addrDist);
        // appeler fonction connexion réussi de l'interface
    }


    /**
     * Methode appelée lors de la reception d'un goodbye. Si cette reception est une réponse à un precedent goodbye envoyé, l'application se considére déconnectée, sinon elle renvoie un goodbye et se considère déconnecté.
     * Dans tous les cas elle met à null l'adresse Ip de l'application distante.
     **/
    public void processGoodbye() {
      /*  if (this.etat == etatCom.Fin_Wait1) {
            this.etat = etatCom.Deconnecte;
            //fonction déconnexion réussie
        } else {
            ComParams params;
            params = new ComParams(this, typeContenu.GOODBYE, this.drone);
            UDPAsyncTask task = new UDPAsyncTask();
            task.execute(params);
            this.etat = etatCom.Deconnecte;
        }
        this.addrDist = null;
        this.sender.setAddrDist(null);
        if (this.drone)
            this.screen.onDeconnectedState();
*/
    }


    /**
     * Methode appelée pour l'envoi périodique de l'objet info.
     **/
    public void sendInfo() {
       /* infoHandler.post(new Runnable() {
            public void run() {
                ComParams params = new ComParams(FacadeCom.getSingleton(), typeContenu.INFORMATIONS, FacadeCom.info, FacadeCom.drone);
                UDPAsyncTask task = new UDPAsyncTask();
                task.execute(params);
            }
        });*/
    }

 /*   public void processInfo(Informations infos) {
        this.view.processInfo(infos);
    }*/


    /**
     * ***********************************************************
     *                      Getter et setter
     * ***********************************************************
     * */


    public void setAddrDist(InetAddress addr) {
        this.addrDist = addr;
    }

    public InetAddress getAddrDist() {
        return this.addrDist;
    }

    public UDPSender getSender() {
        return sender;
    }


    public FacadeView getView() {
        return view;
    }


}
