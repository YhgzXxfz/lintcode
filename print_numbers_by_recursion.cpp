class Solution {
public:
    /**
     * @param n: An integer.
     * return : An array storing 1 to the largest number with n digits.
     */
    vector<int> numbersByRecursion(int n) {
        // write your code here
        vector<int> result;
        print(result, 0, n);
        return result;
    }
    
    void print(vector<int>& result, int depth, int n) {
        if (depth == n) return ;
        
        if (depth == 0) {
            for (int i = 1; i <= 9; ++i) {
                result.push_back(i);
            }
        } else {
            int count = result.size();
            for (int d = 1; d <= 9; ++d) {
                result.push_back(d * pow(10, depth));
                for (int i = 0; i < count; ++i) {
                    result.push_back(result[i] + d*pow(10,depth));
                }
            }
        }
        
        print(result, depth+1, n);
    }
};

