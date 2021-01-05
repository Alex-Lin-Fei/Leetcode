package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code here
    }

    public boolean checkStraightLine(int[][] coordinates) {
        int x1 = coordinates[0][0], y1 = coordinates[0][1];
        int x2 = coordinates[1][0], y2 = coordinates[1][1];
        for (int i = 2; i < coordinates.length; i++) {
            int xn = coordinates[i][0], yn = coordinates[i][1];
            if ((y2-y1) * (xn-x2) != (yn-y2)*(x2-x1))
                return false;
        }
        return true;
    }

}
