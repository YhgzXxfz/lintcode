class Solution {
public:
    /**
     * @param a a number
     * @param b a number
     * @return the result
     */
    string addBinary(string& a, string& b) {
        // Write your code here
        int lenA = a.size();
        int lenB = b.size();
        
        int pA = lenA-1, pB = lenB-1;
        int carry = 0;
        string result;
        while (pA >= 0 || pB >= 0) {
            int ai = pA >= 0 ? a[pA]-'0' : 0;
            int bi = pB >= 0 ? b[pB]-'0' : 0;
            int val = (ai+bi+carry)%2;
            carry = (ai+bi+carry)/2;
            result.insert(result.begin(), val+'0');
            
            pA--;
            pB--;
        }
        
        if (carry) {
            result.insert(result.begin(), '1');
        }
        
        return result;
    }
};

