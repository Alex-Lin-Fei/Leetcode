package com.company;

public class Frame {
    String info;
    int seq;
    int ack;

    public Frame(String info, int seq, int ack) {
        this.info = info;
        this.seq = seq;
        this.ack = ack;
    }
    public String toString() {
        return "" + seq + "|" + ack + "|" + info;
    }
}
