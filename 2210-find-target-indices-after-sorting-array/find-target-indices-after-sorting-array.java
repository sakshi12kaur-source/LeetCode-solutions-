class Solution {
    public List<Integer> targetIndices(int[] nums, int target) {
        List<Integer>ans=new ArrayList<>();
        int index=0,valCount=0;
        for(int val:nums){
            if(val<target)index++;
            if(val==target)valCount++;
        }
        while(valCount-->0){
            ans.add(index++);
        }
        return ans;
    }
}