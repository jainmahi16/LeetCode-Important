class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int first = -1;

        // Find first occurrence
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                first = mid;
                high = mid - 1; // keep searching left
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        int low1 = 0, high1 = nums.size() - 1;
        int last = -1;

        // Find last occurrence
        while (low1 <= high1) {
            int mid1 = (low1 + high1) / 2;
            if (nums[mid1] == target) {
                last = mid1;
                low1 = mid1 + 1; // keep searching right
            } else if (nums[mid1] < target) {
                low1 = mid1 + 1;
            } else {
                high1 = mid1 - 1;
            }
        }

        return {first, last};
    }
};