package com.company;

import javax.imageio.ImageTranscoder;

public class Main {

    public static void main(String[] args) {
        // write your code here
        int[][] matrix = {
                {1, 2},
                {2, 2}};
        System.out.println(isToeplitzMatrix(matrix));
    }

    public static boolean isToeplitzMatrix(int[][] matrix) {
        for (int i = matrix.length - 1; i >= 0; i--) {
            int pre = matrix[i][0];
            for (int x = i + 1, y = 1; x < matrix.length && y < matrix[0].length; x++, y++) {
                if (matrix[x][y] != pre)
                    return false;
            }
        }

        for (int j = 1; j < matrix[0].length; j++) {
            int pre = matrix[0][j];
            for (int x = 1, y = j + 1; x < matrix.length && y < matrix[0].length; x++, y++) {
                if (matrix[x][y] != pre)
                    return false;
            }
        }

        return true;
    }
}
