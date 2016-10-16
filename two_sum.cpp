class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        vector<int> backup = nums;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        
        int left = 0, right = len-1;
        while (left < right) {
            int sum = nums[left]+nums[right];
            if (sum == target) break;
            if (sum < target) ++left;
            else --right;
        }
        
        for (int i = 0; i < len; ++i) {
            if (backup[i] == nums[left]) {
                left = i+1;
                break;
            }
        }
        for (int i = len-1; i >= 0; --i) {
            if (backup[i] == nums[right]) {
                right = i+1;
                break;
            }
        }
        
        if (left > right) swap (left,right);
        vector<int> result;
        result.push_back(left);
        result.push_back(right);
        return result;
    }
};


