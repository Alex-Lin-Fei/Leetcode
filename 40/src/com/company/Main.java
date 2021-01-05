package com.company;

import java.util.Arrays;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Main {
    static List<List<Integer>> ansList = new ArrayList<>();
    static Set<List<Integer>> s = new HashSet<>();
    public static void main(String[] args) {
	// write your code here
        int[] nums = new int[]{10,1,2,7,6,1,5};
        combinationSum2(nums, 8);
    }

    public static List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates,0, candidates.length);
        ansList.clear();
        s.clear();

        dfs(candidates, target, 0, new ArrayList<Integer>());

        for(List list: ansList){
            for (Object i: list)
                System.out.print(i+" ");
            System.out.println();
        }

        return ansList;
    }

    public static void dfs(int[] candidates, int target, int cur, List<Integer> nowList) {
        if (target == 0) {
            List<Integer> temp = new ArrayList<>(nowList);
            if (!s.contains(temp)) {
                ansList.add(temp);
                s.add(temp);
            }
        }
        else if (cur < candidates.length && candidates[cur] <= target) {
            nowList.add(candidates[cur]);
            dfs(candidates, target - candidates[cur], cur + 1, nowList);
            nowList.remove(nowList.size()-1 );
            dfs(candidates, target, cur + 1, nowList);
        }
    }
}
