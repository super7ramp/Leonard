package com.network.UDP;

import com.network.FacadeCom;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.ObjectInput;
import java.io.ObjectInputStream;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;

/**
 * Created by Lux on 12/11/2015.
 */
public class UDPReceiver extends Thread {

    /**
     * Object used to receive message
     */

    private FacadeCom fcom;
    private DatagramSocket server ;
    private byte[] bufIn;
    private InetAddress addrLoc;


    /**
     * UDPReceiver constructeur :
     * instancie les champs FacadeCom, Datagram socket et byte[]
     * @param f : FacadeCom
     * @param soc : DatagramSocket
     * @throws IOException
     */
    public UDPReceiver(FacadeCom f, DatagramSocket soc,InetAddress addr) throws IOException {
        this.fcom = f;
        this.server = soc;
        bufIn = new byte[5000];
        this.addrLoc = addr;
    }


    /**
     * run() : instancie un DatagramPacket (packet), lance la methode receive(packet) de la classe DatagramSocket.
     * Gére l'AbstractMessage reçu et suivant le type de l'AbstractMessage, appelle la bonne methode de la FacadeCom.
     */
    public void run() {
        ObjectInput in = null;
        ByteArrayInputStream byteIn = new ByteArrayInputStream(bufIn);
        try {

            while (true) {
                // le socket bloque jusqu'a ce qu'il recoive un DatagramPacket
                DatagramPacket packet = new DatagramPacket(bufIn, bufIn.length);
                this.server.receive(packet);

                // Traitement du packet pour le re-transformer en AbstractMessage
                byteIn.reset();
                in = new ObjectInputStream(byteIn);
                //AbstractMessage inMessage = (AbstractMessage) in.readObject();


                if(!(packet.getAddress().equals(this.addrLoc))) {
                  /*  if (inMessage.getTypeContenu() == typeContenu.HELLO) {
                        Hello helloSerialise = (Hello) inMessage;
                        System.out.println(this.nom + " : Je reçois un HELLO de " + packet.getAddress() + " ! ");
                        this.fcom.processHello(packet.getAddress());
                    } else if (inMessage.getTypeContenu() == typeContenu.HELLOACK) {
                        HelloAck helloackSerialise = (HelloAck) inMessage;
                        System.out.println(this.nom + " : Je reçois HELLOACK de " + packet.getAddress() + " ! ");
                        this.fcom.processHelloAck(packet.getAddress());
                    } else if (inMessage.getTypeContenu() == typeContenu.GOODBYE) {
                        Goodbye goodbyeSerialise = (Goodbye) inMessage;
                        System.out.println(this.nom + " : Je reçois un GOODBYE de " + packet.getAddress() + "  ! ");
                        this.fcom.processGoodbye();
                    } else if (inMessage.getTypeContenu() == typeContenu.INFORMATIONS) {
                        Informations msg = (Informations) inMessage;
                        System.out.println(this.nom + ":" + msg.toString());
                        this.fcom.processInfo(msg);
                    } else if (inMessage.getTypeContenu()==typeContenu.PHOTO){
                        Photo img = (Photo) inMessage;
                        System.out.println(this.nom + " : Je reçois une photo de " + packet.getAddress() + "  ! ");
                        this.fcom.processPhoto(img);
                    } else if (inMessage.getTypeContenu() == typeContenu.DebutPhoto){
                        System.out.println(this.nom + " : Je reçois un DébutPhoto de " + packet.getAddress() + "  ! ");
                        this.fcom.processDebutPhoto();
                    } else if (inMessage.getTypeContenu() == typeContenu.FinPhoto){
                        System.out.println(this.nom + " : Je reçois un fin photo de " + packet.getAddress() + "  ! ");
                        this.fcom.processFinPhoto();
                    } else if (inMessage.getTypeContenu() == typeContenu.BluetoothDetecte){
                        System.out.println(this.nom + " : Je reçois un Bluetooth detecte de " + packet.getAddress() + "  ! ");
                        this.fcom.processBluetoothDetecte();
                    }*/

                } else {
                    System.out.println("Je reçois mon propre Hello (" + packet.getAddress() + ") je ne le traite pas ! " + " ! ");
                }
            }
        } catch (SocketException e) {
            this.interrupt();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }


    /**
     * GETTERS AND SETTERS
     */

    /**
     * getServer()
     * @return server : DatagramSocket
     */
    public DatagramSocket getServer() {
        return server;
    }

    /**
     * setServer()
     * @param server : DatagramSocket
     */
    public void setServer(DatagramSocket server) {
        this.server = server;
    }

}