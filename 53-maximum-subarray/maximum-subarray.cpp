class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = nums[0];//initializing the sum to the maxsum of the element
        int currsum = 0;//start with the curr sum = 0
        for(int n : nums){
            currsum = max(currsum , 0);//// If currsum is negative, reset it to 0
            currsum += n;// // Add the current number to currsum
            maxsum = max(maxsum , currsum);//// Update maxsum if currsum is larger
    }
        
        return maxsum;//return the maxsum found
        
    }
};