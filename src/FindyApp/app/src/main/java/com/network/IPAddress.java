package com.network;

import java.net.InetAddress;
import java.net.NetworkInterface;
import java.util.Enumeration;

/**
 * Created by Lux on 12/11/2015.
 */

public class IPAddress {

    /**
     * Parcours toutes les adresses ips des carte réseau de la machine et retourne seulement l'adresse IPV4 (qui n'est pas celle de loopback).
     * @return Une liste des addresses ip
     */
    public static InetAddress getIp(){
        InetAddress ips = null;

        try{
            Enumeration<NetworkInterface> interfaces = NetworkInterface.getNetworkInterfaces();

            while (interfaces.hasMoreElements()) {  // carte reseau trouvee
                NetworkInterface interfaceN = (NetworkInterface)interfaces.nextElement();
                Enumeration<InetAddress> ienum = interfaceN.getInetAddresses();
                while (ienum.hasMoreElements()) {  // retourne l adresse IPv4 et IPv6
                    InetAddress ia = (InetAddress) ienum.nextElement();
                    String address = ia.getHostAddress().toString();
                    System.out.println("@ :" + ia.getHostAddress());

                    if( address.indexOf(":") == -1){          //On s'assure ainsi que l'adresse IP est bien IPv4
                        if(address.startsWith("127")){  //Ce n'est pas l'adresse IP Local'
                            System.out.println("@ local" + ia.getHostAddress());
                        } else {
                            System.out.println("@ retenu " + ia.getHostAddress());
                            ips = ia;
                        }
                    } else {
                        System.out.println("Adresse IP non trouvé");
                    }


                }
            }
        }
        catch(Exception e){
            System.out.println("pas de carte reseau");
            e.printStackTrace();
        }
        System.out.println("On retourne l'adresse :" + ips);
        return ips;
    }


}