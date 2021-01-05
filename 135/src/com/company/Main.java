package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code here
    }

    public int candy(int[] ratings) {
        int[] candy = new int[ratings.length];
        for (int i = 1; i < ratings.length; i++)
            if (ratings[i] > ratings[i - 1])
                candy[i] = candy[i - 1] + 1;
        for (int i = ratings.length - 2; i >= 0; i--)
            if (ratings[i] > ratings[i + 1])
                candy[i] = candy[i + 1] + 1;
        int cnt = 0;
        for (int i : candy)
            cnt += i;
        return cnt + candy.length;
    }
}
