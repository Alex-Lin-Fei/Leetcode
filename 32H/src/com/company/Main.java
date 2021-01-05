package com.company;

import java.util.Stack;

public class Main {

    public int longestValidParentheses(String s) {
        Stack<Character> stack = new Stack<>();
        int maxL = Integer.MIN_VALUE;
        for (int i = 0; i < s.length(); i++) {
            if (stack.empty())
                stack.push(s.charAt(i));
            else {
                if (stack.peek() == '(' && s.charAt(i) == ')') {
                    stack.pop();
                    if (stack.empty())
                        maxL = Math.max(maxL, i - stack.size());
                }
                else
                    stack.push(s.charAt(i));
            }
        }
        return s.length() - stack.size();
    }

    public static void main(String[] args) {
	// write your code here
    }
}
