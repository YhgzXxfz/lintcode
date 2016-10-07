class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        // write your code here
        int len = nums.size();
        
        int sum = 0;
        int first, last;
        unordered_map<int, int> mp;
        mp[0] = -1;
        
        for (int i = 0; i < len; ++i) {
            sum += nums[i];
            if (mp.find(sum) != mp.end()) {
                first = mp[sum]+1;
                last = i;
                break;
            } else {
                mp[sum] = i;
            }
        }
        vector<int> result;
        result.push_back(first);
        result.push_back(last);
        return result;
    }
};

