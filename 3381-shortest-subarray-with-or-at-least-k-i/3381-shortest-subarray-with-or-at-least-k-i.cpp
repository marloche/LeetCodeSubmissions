class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int minLength = n + 1; // Set initial length to a large value
        
        for (int i = 0; i < n; ++i) {
            int orValue = 0;
            // Try all subarrays starting from i
            for (int j = i; j < n; ++j) {
                orValue |= nums[j]; // Calculate OR for the current subarray
                if (orValue >= k) {
                    minLength = min(minLength, j - i + 1); // Update minimum length
                    break; // No need to check longer subarrays starting from i
                }
            }
        }
        
        // If no valid subarray found, return -1
        return minLength == n + 1 ? -1 : minLength;
    }
};
