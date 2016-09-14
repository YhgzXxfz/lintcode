class Solution {
public:
    /**
     * @param nums1 an integer array
     * @param nums2 an integer array
     * @return an integer array
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Write your code here
        vector<int> result;
        if (nums1.empty() || nums2.empty()) return result;
        
        unordered_set<int> st(nums1.begin(), nums1.end());
        for (auto num : nums2) {
            if (st.count(num)) {
                result.push_back(num);
                st.erase(num);
            }
        }
        return result;
    }
};
