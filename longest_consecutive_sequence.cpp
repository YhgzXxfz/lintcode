class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return an integer
     */
    int longestConsecutive(vector<int> &num) {
        // write you code here
        unordered_set<int> st;
        for (auto i : num) {
            st.insert(i);
        }
        
        int max_len = 0;
        while(!st.empty()) {
            int i = *st.begin();
            st.erase(i);
            
            int upper = i+1;
            while (st.count(upper)) {
                st.erase(upper);
                ++upper;
            }
            
            int lower = i-1;
            while (st.count(lower)) {
                st.erase(lower);
                --lower;
            }
            
            max_len = max(max_len, upper-lower -1);
        }
        return max_len;
    }
};

