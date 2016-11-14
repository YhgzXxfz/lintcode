class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndexII(vector<int>& A) {
        // Write your code here
        int len = A.size();
        
        long long factor = 1, index = 1;
        for (int i = len-1; i >= 0; --i) {
            int rank = 0;
            unordered_map<int,int> mp;
            ++mp[A[i]];
            for (int j = i+1; j < len; ++j) {
                ++mp[A[j]];
                if (A[i] > A[j]) ++rank;
            }
            index += factor*rank/dup(mp);
            factor *= (len-i);
        }
        return index;
    }
    
    long long dup (unordered_map<int,int> mp) {
        if (mp.empty()) return 1;
        long long dup = 1;
        auto it = mp.begin();
        for (; it != mp.end(); ++it) {
            dup *= factor(it->second);
        }
        return dup;
    }
    
    long long factor(int n) {
        if (n == 0 || n == 1) return 1;
        long long val = 1;
        for (int i = 2; i <= n; ++i) {
            val *= i;
        }
        return val;
    }
};

