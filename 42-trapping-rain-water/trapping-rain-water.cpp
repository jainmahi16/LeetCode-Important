class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1;
        int trappedWater = 0;
        int leftMax = 0, rightMax = 0;

        while (l < r) {
            leftMax = max(leftMax, height[l]);
            rightMax = max(rightMax, height[r]);

            if (leftMax < rightMax) {
                trappedWater += leftMax - height[l];
                l++;
            } else {
                trappedWater += rightMax - height[r];
                r--;
            }
        }

        return trappedWater;
    }
};