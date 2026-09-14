class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minNum = INT_MAX;
        int maxNum = INT_MIN;
        int minIn = -1;
        int maxIn = -1;
        for(int i =0; i<n; i++){
            if(nums[i] < minNum){
                minNum = nums[i];
                minIn = i;
            }
            if(nums[i] > maxNum){
                maxNum = nums[i];
                maxIn = i;
            }
        }

        int i = min(minIn,maxIn);
        int j = max(minIn,maxIn);
        int fromFront = j+1;
        int fromBack = (n-i);
        int fromBoth = (i+1) + (n-j);
        int ans = min({fromBack,fromFront,fromBoth});
        return ans;
        
    }
};