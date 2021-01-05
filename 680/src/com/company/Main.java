package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code here
        System.out.print(validPalindrome("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga"));
    }

    public static boolean validPalindrome(String s) {
        int l = 0, r = s.length()-1;
        while(l<=r) {
            if (s.charAt(l) != s.charAt(r)) {
                {
                    String str1 = s.substring(l, r);
                    String s1 = new StringBuilder(str1).reverse().toString();
                    String str2 = s.substring(l+1, r+1);
                    String s2 = new StringBuilder(str2).reverse().toString();
                    return str1.equals(s1) || str2.equals(s2);
                }
            }
            else{
                l++;
                r--;
            }
        }
        return true;
    }
}
