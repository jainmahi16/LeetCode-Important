class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = nums[0];
        int currsum = 0;
        for(int n : nums){
            currsum = max(currsum , 0);
            currsum += n;
            maxsum = max(maxsum , currsum);
        }
        return maxsum;
        
    }
};