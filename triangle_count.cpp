class Solution {
public:
    /**
     * @param S: A list of integers
     * @return: An integer
     */
    int triangleCount(vector<int> &nums) {
        int len = nums.size();
        if (len < 3) return 0;
        
        sort(nums.begin(), nums.end());
        
        int result = 0;
        for (int i = 0; i < len-2; ++i) {
            int a = nums[i];
            for (int j = i+1; j < len-1; ++j) {
                int b = nums[j];
                auto low = lower_bound(nums.begin()+j, nums.end(), a+b);
                result += prev(low)-nums.begin()-j;
            }
        }
        return result;
    }
};
