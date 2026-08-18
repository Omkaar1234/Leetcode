class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        if (k == 1) {
            unordered_map<int, int> freq;

            for (int x : nums) {
                freq[x]++;
            }

            int ans = -1;

            for (int x : nums) {
                if (freq[x] == 1) {
                    ans = max(ans, x);
                }
            }

            return ans;
        }

        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        int first = nums[0];
        int last = nums[n - 1];

        bool firstInside = false;
        bool lastInside = false;

        for (int i = 1; i < n - 1; i++) {
            if (nums[i] == first) firstInside = true;

            if (nums[i] == last) lastInside = true;
        }

        if (first == last) return -1;

        if (!firstInside && !lastInside) return max(first, last);

        if (!firstInside) return first;
        if (!lastInside)  return last;

        return -1;
    }
};