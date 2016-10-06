class Solution {
public:
    /**
     * @param digits a number represented as an array of digits
     * @return the result
     */
    vector<int> plusOne(vector<int>& digits) {
        // Write your code here
        vector<int> result;
        int sum = 0;
        int flag = 1;
        int len = digits.size();
        
        for (int i = len-1; i >= 0; --i)
        {
            sum = digits[i] + flag;
            result.push_back(sum%10);
            flag = sum/10;
        }
        
        if (flag) result.push_back(1);
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};

