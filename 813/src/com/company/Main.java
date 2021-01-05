package com.company;


public class Main {

    public static double largestSumOfAverages(int[] A, int K) {
        double[][] dp = new double[A.length][K+1];
        double[] preSum = new double[A.length];
        preSum[0] = A[0];
        for (int i = 1; i < A.length; i++)
            preSum[i] = preSum[i-1] + A[i];
//        for (double d: preSum)
//            System.out.print(d + " ");
//        System.out.println();

        for (int i = 0; i < A.length; i++) {
            dp[i][0] = 0;
            dp[i][1] = preSum[i];
        }
        for (int i = 0; i < A.length; i++) {
            for (int k = 2; k <= K; k++) {
                for (int j = 1; j < i; j++) {
                    dp[i][k] = Math.max(dp[i][k], dp[j][k - 1] + (preSum[i] - preSum[j]) / (i - j));
                }
            }
        }

        for (int i = 0; i < A.length; i++) {
            for (int k = 0; k <= K; k++) {
                System.out.print(dp[i][k] + " ");
            }
            System.out.println();
        }

        return 0;
    }

    public static void main(String[] args) {
	// write your code here
        int[] A = new int[]{9, 1, 2, 3, 9};
        int k = 3;
        largestSumOfAverages(A, k);
    }
}
