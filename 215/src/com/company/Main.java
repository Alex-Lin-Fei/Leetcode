package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code here
        int[] nums = {3,2,1,5,6,4};
        System.out.print(findKthLargest(nums, 2));
    }

    public static int findKthLargest(int[] nums, int k) {
        int l = 0, r = nums.length - 1, target = nums.length - k;

        while(l<r) {
            int mid = partition(nums, l, r);
            if (mid == target)
                return nums[mid];
            else if (mid < target)
                l = mid + 1;
            else
                r = mid - 1;

        }
        return nums[l];
    }

    public static int partition(int[] nums, int l, int r) {
        int first = l, last = r, key = nums[l];

        while (first < last) {
            while (first < last && nums[last] >= key)
                last--;
            nums[first] = nums[last];
            while (first < last && nums[first] <= key)
                first++;
            nums[last] = nums[first];
        }
        nums[first] = key;
        return first;
    }

}
