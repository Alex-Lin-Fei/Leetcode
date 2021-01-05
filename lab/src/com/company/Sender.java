package com.company;

import com.company.Main;

import com.company.Frame;
import jdk.nashorn.internal.codegen.CompilerConstants;

import java.awt.*;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;
import java.util.concurrent.*;

public class Sender {
    //    滑动窗口
    static long timeout = 10000;    //等待ack时间
    public static int MAX_Q = 7;  //滑动窗口大小
    public static boolean canSend=true; //是否可以继续发送数据 即当前窗口大小不能超过MAX_Q
    public static String[] buffer = new String[MAX_Q + 1]; //缓存帧
    public static String[] timer = new String[MAX_Q + 1]; //每一个帧的计时器 保存发送的时间
    public static int ack_expected; //第一个未收到确认的帧号
    public static int next_frame_to_send; //下一个发送的帧号
    public static int nbuffered; //缓存帧数目
//    用于设置随机时间长度的变量
    public final static int MAXNUM = 10;
    public final static int MINNUM = 1;

//    发送/接收数据
    public static DataInputStream in;
    public static DataOutputStream out;

    public static void main(String[] args) throws IOException, ParseException, AWTException {
        ack_expected = 0;
        next_frame_to_send = 0;
        nbuffered = 0;
        String str;

        int port = 8000;

        ServerSocket server;
        Socket socket;

        server = new ServerSocket(port);
        socket = server.accept();
        out = new DataOutputStream(socket.getOutputStream());
        in = new DataInputStream(socket.getInputStream());

        while(true) {
//                System.out.println("enter the number " + next_frame_to_send + " packet: ");
//                System.out.print(">>");
//                Scanner input = new Scanner(System.in);
//                buffer[next_frame_to_send] = input.next();
//                nbuffered++;
//                sendData(next_frame_to_send, Receiver.getFrame());
//                next_frame_to_send = (next_frame_to_send + 1) % (MAX_Q + 1);

            long randomNum = System.currentTimeMillis();
            int ran = (int) (randomNum % (Sender.MAXNUM - Sender.MINNUM) + Sender.MINNUM);
            Robot r = new Robot();
            r.delay(ran * 3000);

            ExecutorService exec = Executors.newFixedThreadPool(1);

            Callable<String> call = new Callable<String>() {
                @Override
                public String call() throws Exception {
                    return in.readUTF();
                }
            };

            try {
                Future<String> future = exec.submit(call);
                str = future.get(7000, TimeUnit.MILLISECONDS);
                future.cancel(true);
//                int ack = Integer.parseInt(String.valueOf(str.charAt(2)));
                System.out.println("Receive: " + str);
//                while (between(ack_expected, ack, next_frame_to_send)) {
//                    nbuffered--;
//                    timer[ack_expected] = "0";
//                    ack_expected = (ack_expected + 1) % (MAX_Q+1);
//                }
//                System.out.println("ack_expected: " +ack_expected + " next_frame_to_send: " + next_frame_to_send);
            } catch (InterruptedException | ExecutionException | TimeoutException e) {
                e.printStackTrace();
            }
        }
    }

    public static void sendData(int frame_nr, int frame_expected) throws IOException {
//        buffer[next_frame_to_send] = "";
        timer[frame_nr] = new SimpleDateFormat("hh:mm:ss").format(new Date());
        com.company.Frame s = new Frame(buffer[frame_nr], frame_nr, (frame_expected + MAX_Q) % (MAX_Q + 1));

//发送数据
        out.writeUTF(s.toString());
        System.out.println("has send frame Info:  " + buffer[frame_nr] + " Seq: " + frame_nr + " Ack: " + frame_expected);
    }

    public static boolean between(int a, int b, int c) {
        return a <= b && b < c || c < a && a <= b || b < c && c < a;
    }

    //    超时重发
    public static void re_send() throws ParseException, IOException {
        next_frame_to_send = ack_expected;
        for (int i = 1; i <= nbuffered; i++) {
            sendData(next_frame_to_send, Receiver.getFrame());
            next_frame_to_send = (next_frame_to_send + 1) % (MAX_Q + 1);
        }
    }

    public static boolean isTimeout() throws ParseException {
        String s = new SimpleDateFormat("hh:mm:ss").format(new Date());
        Date d1 = new SimpleDateFormat("hh:mm:ss").parse(s);

        for (int i = 0; i < nbuffered; i++) {
            int idx = (ack_expected+i)%(MAX_Q+1);
            if (timer[idx].equals("0"))
                continue;
            Date d2 = new SimpleDateFormat("hh:mm:ss").parse(timer[idx]);
            if (d1.getTime() - d2.getTime() > timeout)
                return true;
        }
        return false;
    }
}
