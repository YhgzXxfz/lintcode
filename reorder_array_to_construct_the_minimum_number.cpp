class Solution {
public:
    /**
     * @param nums n non-negative integer array
     * @return a string
     */
    string minNumber(vector<int>& nums) {
        // Write your code here
        auto comp = [](int a, int b) { 
            string string_a = to_string(a);
            string string_b = to_string(b);
            return string_a+string_b < string_b+string_a;
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
