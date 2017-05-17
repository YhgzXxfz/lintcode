class Solution {
public:
    /**
     * @param nums a list of n integers
     * @return true if there is a 132 pattern or false
     */
    bool find132pattern(vector<int>& nums) {
        int len = nums.size();
        if (len < 3) return false;
        
        int second = INT_MIN;
        stack<int> s;
        for (int i = len-1; i >= 0; --i) {
            if (nums[i] < second) return true;
            else {
                while (!s.empty() && s.top() < nums[i]) {
                    second = max(second, s.top());
                    s.pop();
                }
            }
            
            s.push(nums[i]);
        }
        return false;
    }
};
