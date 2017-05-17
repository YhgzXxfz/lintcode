class Solution {
public:
    /*
     * @param nums an array of Integer
     * @param target = nums[index1] + nums[index2]
     * @return [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int sum = nums[left]+nums[right];
            if (sum == target) return vector<int>({left+1, right+1});
            else if (sum < target) left++;
            else right--;
        }
        return vector<int>({-1, -1});
    }
};

