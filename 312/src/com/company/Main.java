package com.company;

public class Main {

    public int maxCoins(int[] nums) {
        int[] scores = new int[nums.length + 2];
        System.arraycopy(nums, 0, scores, 1, nums.length);
        scores[0] = scores[nums.length + 1] = 1;
        int[][] dp = new int[scores.length][scores.length];

        for (int i = nums.length; i >= 0; i--)
            for (int j = i + 1; j < scores.length; j++)
                for (int k = i + 1; k < j; k++)
                    dp[i][j] = Math.max(dp[i][j], dp[i][k] + dp[k][j] + scores[i] * scores[j] * scores[k]);
        return dp[0][nums.length + 1];
    }

    public static void main(String[] args) {
	// write your code here
    }
}
