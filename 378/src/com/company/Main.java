package com.company;

public class Main {

    public int kthSmallest(int[][] matrix, int k) {
        int row = matrix.length, col = matrix[0].length;
        int left = matrix[0][0], right = matrix[row - 1][col - 1];
        while (left < right) {
            int mid = (left + right)>>1;
            if (checkIn(matrix, mid, k)) {
                right = mid;
            }
            else
                left = mid+1;
        }
        return left;
    }

    public boolean checkIn(int[][] matrix, int mid, int k) {
        int r = matrix.length - 1;
        int c = 0;
        int sum = 0;
        while (r >= 0 && c < matrix[0].length) {
            if (matrix[r][c] <= mid) {
                sum += r + 1;
                c++;
            } else
                r--;
        }
        return sum >= k;
    }

    public static void main(String[] args) {
	// write your code here
    }
}
