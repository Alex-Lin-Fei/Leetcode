package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code here
        System.out.println(numJewelsInStones("aA", "aAAbbbb"));
    }

    public static int numJewelsInStones(String J, String S) {
        int cnt = 0;
        for (char ch : S.toCharArray()) {
            if (J.contains(ch + ""))
                cnt++;
        }
        return cnt;
    }
}
