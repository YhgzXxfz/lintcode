class Solution {
public:    
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        // write your code here
        int len = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<vector<int> > result;
        vector<int> triplet(3, 0);
        for (int i = 0; i < len-2; ++i) {
            if (i == 0 || i>0 && nums[i] != nums[i-1]) {
                int left = i+1, right = len-1, target = 0 - nums[i];
                while (left < right) {
                    int sum = nums[left]+nums[right];
                    if (sum == target) {
                        triplet[0] = nums[i];
                        triplet[1] = nums[left];
                        triplet[2] = nums[right];
                        result.push_back(triplet);
                        
                        while (left < right && nums[left] == nums[left+1]) ++left;
                        while (left < right && nums[right] == nums[right-1]) --right;
                        
                        ++left;--right;
                    }
                    else if (sum < target) ++left;
                    else -- right;
                }
            }
        }
        return result;
    }
};



