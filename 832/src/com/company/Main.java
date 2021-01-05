package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code here
        int[][] A = {{1,1,0},{1,0,1},{0,0,0}};
        flipAndInvertImage(A);
        for(int[] a: A)
        {
            for (int i: a)
                System.out.print(i+" ");
            System.out.println();
        }

    }

    public static int[][] flipAndInvertImage(int[][] A) {
        for(int[] a: A) {
            for(int i = 0; i < a.length/2; i++)
            {
                int temp = a[i];
                a[i] = a[a.length-1-i];
                a[a.length-1-i] = temp;
            }
            for(int i = 0; i < a.length; i++)
                a[i] = 1 ^ a[i];

        }

        return A;
    }
}
