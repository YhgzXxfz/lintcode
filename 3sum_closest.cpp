class Solution {
public:    
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> nums, int target) {
        // write your code here
        int len = nums.size();
        sort(nums.begin(), nums.end());
        
        int minAbs = INT_MAX;
        int result;
        for (int i = 0; i < len -2; ++i) {
            if (i == 0 || i > 0 && nums[i] != nums[i-1]) {
                int left = i+1, right = len-1, target2 = target-nums[i];
                while (left < right) {
                    int sum = nums[left] + nums[right];
                    if (sum == target2) return target;
                    
                    int sub = abs(sum-target2);
                    if (sub < minAbs) {
                        minAbs = sub;
                        result = sum+nums[i];
                    }
                    
                    if (sum < target2) ++left;
                    else --right;
                }
            }
        }
        return result;
    }
};



