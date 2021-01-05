package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code here
        System.out.print(countGoodTriplets(new int[]{3,0,1,1,9,7}, 7, 2, 3));
    }

    public static int countGoodTriplets(int[] arr, int a, int b, int c) {
        int res=0;

        for(int i = 0; i < arr.length; i++)
            for (int j = i+1; j < arr.length; j++) {
                if(Math.abs(arr[i]-arr[j]) <= a) {
                    for (int k = j + 1; k < arr.length; k++) {
                        if (Math.abs(arr[j]-arr[k]) <= b && Math.abs(arr[i]-arr[k]) <= c)
                            res++;
                    }
                }
            }
        return res;
    }
}
