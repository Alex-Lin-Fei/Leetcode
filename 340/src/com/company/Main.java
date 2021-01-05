package com.company;

import java.util.HashMap;

public class Main {

    public static void main(String[] args) {
	// write your code here
    }

    public int lengthOfLongestSubstringKDistinct(String s, int k) {
        if (s == null || s.length() == 0 || k <= 0)
            return 0;
        HashMap<Character, Integer> map = new HashMap<>();
        int len = 0;
        int max = 0;
        int start = 0;

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (map.containsKey(c))
                map.put(c, map.get(c) + 1);
            else {
                map.put(c, 1);
                while (map.size() > k) {
                    char rm = s.charAt(start);
                    int tempCount = map.get(rm);
                    if (tempCount <= 1)
                        map.remove(rm);
                    else
                        map.put(rm, tempCount - 1);
                    start++;
                    len--;
                }
            }
            len++;
            max = Math.max(len, max);
        }
        return max;
    }
}
