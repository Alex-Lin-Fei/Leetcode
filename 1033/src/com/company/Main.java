package com.company;

public class Main {

    public int[] numMovesStones(int a, int b, int c) {
        if (a > b) {
            a += b;
            b = a - b;
            a = a - b;
        }
        if (a > c) {
            a += c;
            c = a - c;
            a = a - c;
        }
        if (b > c) {
            b += c;
            c = b - c;
            b = b - c;
        }

        int[] res = new int[2];

        res[1] = c - a - 2;
        if (res[1] != 0) {
            if (b - a <= 2 || c - b <= 2)
                res[0] = 1;
            else
                res[0] = 2;
        }
        return res;
    }

    public static void main(String[] args) {
	// write your code here
    }
}
