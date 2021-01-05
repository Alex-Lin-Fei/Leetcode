package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code here
        System.out.print(judgeSquareSum(1000));
    }

    public static boolean judgeSquareSum(int c) {
        int l = 0, r = (int) Math.sqrt(c);
        while (l <= r) {
            int sum = l * l + r * r;
            if (sum == c)
                break;
            else if (sum < c)
                l++;
            else
                r--;
        }
        return l <= r;
    }
}

