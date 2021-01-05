package com.company;

import org.omg.Messaging.SYNC_WITH_TRANSPORT;

import java.util.Comparator;
import java.util.List;

public class Main {

    public static void main(String[] args) {
        // write your code here

    }

    public static String findLongestWord(String s, List<String> d) {
        d.sort(new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                if (o1.length() == o2.length())
                    return o1.compareTo(o2);
                return o2.length() - o1.length();
            }
        });
        for(String str: d) {
            if(isSubsequence(s, str))
                return str;
        }
        return "";
    }

    public static boolean isSubsequence(String str1, String str2) {
        int j = 0;
        for (int i = 0; i < str1.length() && j < str2.length(); i++) {
            if (str1.charAt(i) == str2.charAt(j))
                j++;
        }
        return j == str2.length();
    }
}