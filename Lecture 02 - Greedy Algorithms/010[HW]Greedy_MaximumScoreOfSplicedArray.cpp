/*

https://leetcode.com/problems/maximum-score-of-spliced-array/

*/

class Solution {
public:

    int kadanes(const vector<int>& nums) {

        int x = nums[0];
        int maxSoFar = x;

        for (int j = 1; j < (int)nums.size(); j++) {
            x = max(x + nums[j], nums[j]);
            maxSoFar = max(maxSoFar, x);
        }

        return maxSoFar;

    }

    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {

        int n = (int)nums1.size();

        int s1  = accumulate(nums1.begin(), nums1.end(), 0);
        int s2  = accumulate(nums2.begin(), nums2.end(), 0);

        int ans = max(s1, s2);

        vector<int> nums3(n); // nums3[i] = nums2[i] - nums1[i]
        for (int i = 0; i < n; i++) {
            nums3[i] = nums2[i] - nums1[i];
        }

        ans = max(ans, s1 + kadanes(nums3));

        for (int i = 0; i < n; i++) {
            nums3[i] *= -1;
        }

        // nums3[i] = nums1[i] - nums2[i]

        ans = max(ans, s2 + kadanes(nums3));

        return ans;
    }
};