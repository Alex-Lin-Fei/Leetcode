package com.company;

import java.awt.*;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.util.Random;

public class Receiver{
    public static int frame_expected = 0;
    public static void main(String[] args) throws IOException, AWTException {
        int id=0;
        int port = 8000;
        String host = "localhost";
        DataInputStream in;
        DataOutputStream out;
        Socket socket;

        socket = new Socket(host, port);
        in = new DataInputStream(socket.getInputStream());
        out = new DataOutputStream(socket.getOutputStream());
        Random rd = new Random();

        while (true) {
            System.out.println("Waiting for frame " + frame_expected + "...");
            String s = in.readUTF();

           int p = rd.nextInt(10);
            if (p > 3) {
                int seq = Integer.parseInt(String.valueOf(s.charAt(0)));
                if (seq == frame_expected) {
                    System.out.println("receive frame " + s);
                    long randomNum = System.currentTimeMillis();
                    int ran = (int) (randomNum % (Sender.MAXNUM - Sender.MINNUM) + Sender.MINNUM);
                    Robot r = new Robot();
                    r.delay(3 * 100);

                    Frame f = new Frame("ack", id, seq);
                    id = (id + 1) % (Sender.MAX_Q + 1);
                    out.writeUTF(f.toString());
                    System.out.println("Send Ack: " + seq);
                    frame_expected = (frame_expected + 1) % (Sender.MAX_Q + 1);
                }
            } else {
                System.out.println("Drop frame " + s.charAt(0));
            }
        }

    }
    public static int getFrame() {
        return frame_expected;
    }
}

