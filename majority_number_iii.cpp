class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: As described
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums, int k) {
        // write your code here
        int len = nums.size();
        unordered_map<int, int> map;
        
        for (int i = 0; i < len; ++i) {
            if (map.find(nums[i]) != map.end()) {
                map[nums[i]]++;
            } else {
                map[nums[i]] = 1;
            }
        }
        
        for (int i = 0; i < len; ++i) {
            if (map[nums[i]] > len/k) return nums[i];
        }
        
        return -1;
    }
};


