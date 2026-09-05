class Solution {
    public int firstStableIndex(int[] nums, int k) {
        int n = nums.length;
        int result = Integer.MAX_VALUE;

        int max = Integer.MIN_VALUE;
        int[] preMax = new int[n];

        for(int i = 0; i < n; i++){
            max = Math.max(max,nums[i]);
            preMax[i] = max;
        }

        int min = Integer.MAX_VALUE;
        int[] sufMin = new int[n];

        for(int i = n-1; i >= 0; i--){
            min = Math.min(min,nums[i]);
            sufMin[i] = min;
        }

        for(int i = 0; i < n; i++){
            if(preMax[i] - sufMin[i] <= k)
            result = Math.min(result,i);
        }

         if(result == Integer.MAX_VALUE)
        return -1;
        else
        return result;
    }
}