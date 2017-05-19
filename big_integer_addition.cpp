class Solution {
public:
    /**
     * @param num1 a non-negative integers
     * @param num2 a non-negative integers
     * @return return sum of num1 and num2
     */
    string addStrings(string& num1, string& num2) {
        string result = "";
        
        int p1 = num1.size()-1, p2 = num2.size()-1, sum, carry = 0;
        while (p1 >= 0 && p2 >= 0) {
            sum = (num1[p1]-'0') + (num2[p2]-'0') + carry;
            result += to_string(sum%10);
            carry = sum/10;
            
            p1--; p2--;
        }
        
        while (p1 >= 0) {
            sum = (num1[p1]-'0') + carry;
            result += to_string(sum%10);
            carry = sum/10;
            
            p1--;
        }
        
        while (p2 >= 0) {
            sum = (num2[p2]-'0') + carry;
            result += to_string(sum%10);
            carry = sum/10;
            
            p2--;
        }
        if (carry) result += to_string(carry);
        reverse(result.begin(), result.end());
        return result;
    }
};
