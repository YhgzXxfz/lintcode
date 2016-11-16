class Solution {
private:
    priority_queue<long> small, large;
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    vector<int> medianII(vector<int>& nums) {
        // write your code here
        int len = nums.size();
        vector<int> result(len, 0);
        
        for (int i = 0; i < len; ++i) {
            addNums(nums[i]);
            result[i] = getMedian();
        }
        return result;
    }
    
    void addNums(int num) {
        small.push(num);
        large.push(-small.top());
        small.pop();
        if (small.size() < large.size()) {
            small.push(-large.top());
            large.pop();
        }
    }
    
    int getMedian() {
        return small.top();
    }
};


