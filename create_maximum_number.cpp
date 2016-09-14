class Solution {
public:
    /**
     * @param nums1 an integer array of length m with digits 0-9
     * @param nums2 an integer array of length n with digits 0-9
     * @param k an integer and k <= m + n
     * @return an integer array
     */
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        // Write your code here
        int m = nums1.size(), n = nums2.size();
        vector<int> result(k, 0);
        for (int i = max(0, k-n); i <= k && i <= m ; ++i) {
            auto candidate = Merge(MaxArray(nums1, i), MaxArray(nums2, k-i), k);
            if (IsGreater(candidate, 0, result, 0)) result = candidate;
        }
        return result;
    }
    
private:
    vector<int> Merge(const vector<int>& nums1, const vector<int>& nums2, int k) {
        vector<int> result(k, 0);
        for (int i = 0, j = 0, r = 0; r < k; ++r) {
            result[r] = IsGreater(nums1, i, nums2, j) ? nums1[i++] : nums2[j++];
        }
        return result;
    }
    
    bool IsGreater(const vector<int>& nums1, int i, const vector<int>& nums2, int j) {
        int m = nums1.size(), n = nums2.size();
        while (i < m && j < n && nums1[i] == nums2[j]) {
            ++i; ++j;
        }
        return j == n || (i < m && nums1[i] > nums2[j]);
    }
    
    vector<int> MaxArray(const vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> result(k, 0);
        for (int i = 0, j = 0; i < len; ++i) {
            while (len-i +j > k && j > 0 && result[j-1] < nums[i]) --j;
            if (j < k) {
                result[j] = nums[i];
                j++;
            }
        }
        return result;
    }
};
