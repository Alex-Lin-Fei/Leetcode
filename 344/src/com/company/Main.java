package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code here
    }

    public static void reverseString(char[] s) {
        for(int i = 0; i < s.length / 2; i++)
        {
            char ch = s[i];
            s[i] = s[s.length-1-i];
            s[s.length-1-i] = ch;
        }
    }
}
