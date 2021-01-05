package com.company;

import java.util.*;

public class Main {

    public static void main(String[] args) {
        // write your code here
        partitionLabels("ababcbacadefegdehijhklij");
    }

    public static List<Integer> partitionLabels(String S) {
        List<Integer> list = new ArrayList<>();
        Set<Character> visitedSet = new HashSet<Character>();
        List<Space> spaceList = new ArrayList<>();
        int s=Integer.MAX_VALUE, t=Integer.MIN_VALUE;

        for(int i = 0; i < S.length(); i++){
            if (!visitedSet.contains(S.charAt(i)))
            {
                visitedSet.add(S.charAt(i));
                Space space = new Space(i, S.lastIndexOf(S.charAt(i)));
                spaceList.add(space);
            }
        }
        Collections.sort(spaceList);
//        for(Space space: spaceList)
//            System.out.println(space.start + " " + space.end);
        for (Space space : spaceList) {
            if (space.start < t || (space.start == t || space.end == t)) {
                s = Integer.min(s, space.start);
                t = Integer.max(t, space.end);
            } else {
                list.add(t - s + 1);
                s = space.start;
                t = space.end;
            }
        }
        list.add(t-s+1);
        list.remove(0);

        return list;
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