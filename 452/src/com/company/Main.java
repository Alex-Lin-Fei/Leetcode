package com.company;

import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
	// write your code here
        int[][] points = new int[][]{{-2147483648,2147483647}};
//        Arrays.sort(points);
//        for(int[] p: points){
//            System.out.println(p[0] +" " + p[1]);
//        }
        System.out.println(findMinArrowShots(points));
    }

    public static int findMinArrowShots(int[][] points) {
        Space[] spaces = new Space[points.length];
        for(int i = 0; i < points.length; i++)
            spaces[i] = new Space(points[i][0], points[i][1]);


        int cnt = 0;
        Arrays.sort(spaces);
        long s = Long.MIN_VALUE, t = Long.MIN_VALUE;
        for (Space space : spaces) {
            if (space.start <= t) {
                s = Long.min(s, space.start);
                t = Long.min(t, space.end);
            } else {
                cnt++;
                s = space.start;
                t = space.end;
            }
        }
        return cnt;
    }
}

class Space implements Comparable{
    public int start, end;

    public Space(int s, int t){
        start = s;
        end = t;
    }

    @Override
    public int compareTo(Object o) {
        if (start != ((Space) o).start)
            return start - ((Space) o).start;
        else
            return end - ((Space) o).end;
    }
}
