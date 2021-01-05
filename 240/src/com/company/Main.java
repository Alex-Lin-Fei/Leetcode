package com.company;

import java.util.Arrays;

public class Main {

    public static boolean searchMatrix(int[][] matrix, int target) {
        int row = matrix.length, col = matrix[0].length;
        if (col == 0)
            return false;
        int r = row - 1;
        int c = 0;
        while (r >= 0 && c < col) {
            if (matrix[r][c] == target)
                return true;
            else if (matrix[r][c] < target) {
                c++;
            }
            else
                r--;
        }
        return false;
    }

    public static void main(String[] args) {
	// write your code here
    }
}
