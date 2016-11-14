class Solution {
public:
    /**
     * @param nums n non-negative integer array
     * @return a string
     */
    string minNumber(vector<int>& nums) {
        // Write your code here
        auto comp = [](int i1, int i2) { 
            return to_string(i1) + to_string(i2) < to_string(i2) + to_string(i1);
        };
	sort(nums.begin(), nums.end(), comp);
        
        string result = "";
        for (auto num : nums) {
            result += to_string(num);
        }
        
        while (result.size() > 1 && result[0] == '0') result.erase(0, 1);
        return result;
    }
};
