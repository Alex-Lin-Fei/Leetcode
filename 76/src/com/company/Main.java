package com.company;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class Main {

    public static void main(String[] args) {
	// write your code here
        String S = "AA", T = "AA";
        System.out.println(minWindow(S,T));
    }
    public static String minWindow(String s, String t) {
        int[] chars = new int[128];
        boolean[] flag = new boolean[128];

        for(int i = 0; i < t.length(); i++){
            flag[t.charAt(i)]=true;
            ++chars[t.charAt(i)];
        }
        int cnt=  0, l = 0, min_l = 0, min_size= s.length()+1;
        for(int r = 0; r < s.length(); r++) {
            if (flag[s.charAt(r)]){
                if(--chars[s.charAt(r)] >= 0)
                    ++cnt;
            }
            while(cnt==t.length()) {
                if (r-l+1 < min_size) {
                    min_l = l;
                    min_size = r-l+1;
                }
                if (flag[s.charAt(l)] && ++chars[s.charAt(l)] > 0)
                    --cnt;
                ++l;
            }
        }
        return min_size > s.length()? "": s.substring(min_l, min_l+min_size);
    }
}
