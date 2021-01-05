package com.company;

import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
	// write your code here
        int[][] intervals = {{1,2}, {1,2}, {1,2}};
        System.out.println(eraseOverlapIntervals(intervals));
    }

    public static int eraseOverlapIntervals(int[][] intervals) {
        int cnt=0;

        Space[] spaces = new Space[intervals.length];
        for (int i = 0; i < intervals.length; i++)
            spaces[i] = new Space(intervals[i][0], intervals[i][1]);
        Arrays.sort(spaces);
        int end = Integer.MIN_VALUE;
        for (Space s: spaces){
            if (s.start < end)
                cnt++;
            else
                end = s.end;
        }

        return cnt;
    }
}

class Space implements Comparable {
    public int start, end;
    public Space(int start, int end) {
        this.start = start;
        this.end = end;
    }

    public int compareTo(Object o) {
        return end - ((Space) o).end;
    }
}
