package com.network.UDP;

import java.io.ByteArrayOutputStream;
import java.io.ObjectOutput;
import java.io.ObjectOutputStream;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;

/**
 * Created by Lux on 12/11/2015.
 */
public class UDPSender {


    /**
     * Use for sending message
     */
    private ByteArrayOutputStream bos;
    private DatagramSocket soc;
    private int destPort;
    private InetAddress addrDist;



    /**
     * UDPReceiver constructeur :
     * instancie les champs hostnaùe, bos (ByteArrayOutputStream), soc et destPort
     * @param port : int
     * @param soc : DatagramSocket
     * @throws java.net.SocketException
     */
    public UDPSender(int port, DatagramSocket soc) throws SocketException {
        this.bos = new ByteArrayOutputStream(5000);
        this.soc = soc;
        this.destPort = port;
        this.addrDist = null;
    }



    private void sendTo() {

    }

    /**
     * Call for Drone-App connection before sending Hello
     */
    public void connect() {

    }

    /********************************************
     * Warning catch exception addr = null; *
     ********************************************/

    public void sendHelloAck() {

    }


    public void sendGoodbye() {

    }

    public void sendMessage() {

    }

    public void setAddrDist(InetAddress addr) {
        this.addrDist = addr;
    }
}