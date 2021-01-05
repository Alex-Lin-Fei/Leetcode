package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code here
    }

    public int minimumOperations(String leaves) {
        int[][] f = new int[leaves.length()][3];
        f[0][0] = leaves.charAt(0) == 'r' ? 0 : 1;
        f[0][1] = f[0][2] = f[1][2] = Integer.MAX_VALUE;
        for (int i = 1; i < leaves.length(); i++) {
            int isRed = leaves.charAt(i) == 'r' ? 1 : 0;
            int isYellow = 1 - isRed;
            f[i][0] = f[i - 1][0] + isYellow;
            f[i][1] = Integer.min(f[i - 1][0], f[i - 1][1]) + isRed;
            if (i >= 2)
                f[i][2] = Math.min(f[i - 1][1], f[i - 1][2]) + isYellow;
        }

        return f[leaves.length() - 1][2];
    }
}
