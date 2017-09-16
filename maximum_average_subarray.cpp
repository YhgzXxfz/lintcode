class Solution {
public:
    /**
     * @param nums an array with positive and negative numbers
     * @param k an integer
     * @return the maximum average
     */
    double maxAverage(vector<int>& nums, int k) {
        double left = INT_MIN, right = INT_MAX;
        while (right - left > 0.00004) {
            double mid = left + (right-left)/2;
            if (isValid(nums, k, mid)) left = mid;
            else right = mid;
        }
        return right;
    }
    
private:
    bool isValid(vector<int>& nums, int k, double x) {
        int len = nums.size();
        vector<double> cums;
        for (auto num : nums) {
            cums.push_back(num-x);
        }
        
        double curr = 0, last = 0;
        for (int i = 0; i < k; ++i) {
            curr += cums[i];
        }
        if (curr >= 0) return true;
        
        for (int i = k; i < len; ++i) {
            curr += cums[i];
            last += cums[i-k];
            if (last < 0) {
                curr -= last;
                last = 0;
            }
            if (curr >= 0) return true;
        }
        return false;
    }
};
