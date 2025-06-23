class Solution {
public:
    vector<vector<int>> res;
    
    void backtrack(vector<int>& nums, int start) {
        if (start == nums.size()) {
            res.push_back(nums);
            return;
        }
        
        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);  // Choose
            backtrack(nums, start + 1);  // Explore
            swap(nums[start], nums[i]);  // Un-choose (backtrack)
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0);
        return res;
    }
};
