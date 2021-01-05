package com.company;

import org.omg.CORBA.INTERNAL;

import java.lang.reflect.Array;
import java.util.*;

public class Main {

    public static void main(String[] args) {
	// write your code here
        int[] nums = {3,3,0,3};
        permuteUnique(nums);
    }

    public static List<List<Integer>> permuteUnique(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<>();
        HashMap<Integer, Integer> sum= new HashMap<>();
        for (int i : nums) {
            if (sum.containsKey(i))
                sum.put(i, sum.get(i) + 1);
            else
                sum.put(i, 1);
        }
        ArrayList<Integer> temp = new ArrayList<>();
        dfs(ans, sum ,nums, 0, temp);
        for(List list: ans) {
            for(Object i : list)
                System.out.print((int)i+" ");

        }

        return ans;
    }

    public static void dfs(List<List<Integer>> ans, HashMap<Integer, Integer> map, int[] nums, int curIndex, ArrayList<Integer> temp) {
        if(curIndex == nums.length)
        {
            ArrayList<Integer> now = new ArrayList<>(temp);
            ans.add(now);
            return;
        }
        for(int i = 0; i < nums.length; i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                int sum1 = 0;
                for (int j = 0; j < curIndex; j++) {
                    if (temp.get(j) == nums[i])
                        sum1++;
                }
                if (sum1 == map.get(nums[i]))
                    continue;
                temp.add(nums[i]);
                dfs(ans, map, nums, curIndex+1, temp);
                temp.remove(temp.size()-1);
            }
        }
    }

}
