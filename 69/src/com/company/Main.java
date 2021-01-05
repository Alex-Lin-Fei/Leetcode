package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code here
        System.out.print(mySqrt(8));
    }

    public static int mySqrt(int x) {
        if (x == 0)
            return 0;
        int l = 1, r = x, mid;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (x / mid == mid)
                return mid;
            else if (mid > x / mid)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return r;
    }
}
