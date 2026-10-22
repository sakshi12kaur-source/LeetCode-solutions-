class Solution {
    public int minOperations(int[] nums) {
        int ascCount=0,dscCount=0,n=nums.length;
        for(int i=1;i<n;i++){
            ascCount+=(nums[i]==(nums[i-1]+1)%n)?1:0;
            dscCount+=(nums[i-1]==(nums[i]+1)%n)?1:0;
        }
        if(ascCount==n-1&&nums[0]==0)return 0;
        if(ascCount==n-1){
            int left=n-nums[0];
            int right=nums[n-1]+1+2;
            return Math.min(right,left);
        }else if(dscCount==n-1){
            int left=n-nums[n-1]+1;
            int right=(nums[0]+1)%n+1;
            return Math.min(right,left);
        }
        return -1;
    }
}