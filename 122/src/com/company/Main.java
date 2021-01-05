package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code here
        System.out.println(maxProfit(new int[]{1,2,3,4,5}));
    }

    public static int maxProfit(int[] prices) {
        int ans = 0;
        int idx = 0;
        while (idx < prices.length-1) {

            while (idx < prices.length - 1 && prices[idx + 1] <= prices[idx])
                idx++;
            int a = prices[idx];
            while (idx < prices.length - 1 && prices[idx + 1] >= prices[idx])
                idx++;
            int b = prices[idx];
            ans += b - a;
        }
        return ans;
    }

}
