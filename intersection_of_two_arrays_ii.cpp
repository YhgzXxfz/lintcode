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
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        auto p1 = nums1.begin(), p2 = nums2.begin();
        
        while (p1 != nums1.end() && p2 != nums2.end()) {
            if (*p1 == *p2) {
                result.push_back(*p1);
                p1++; p2++;
            } else if (*p1 < *p2) {
                p1++;
            } else {
                p2++;
            }
        }
        return result;
    }
};
