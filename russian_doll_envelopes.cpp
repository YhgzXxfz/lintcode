class Solution {
public:
    /**
     * @param envelopes a number of envelopes with widths and heights
     * @return the maximum number of envelopes
     */
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int len = envelopes.size();
        if (len == 0) return 0;
        if (len == 1) return 1;
        
        auto comp = [&](pair<int,int> p1, pair<int,int> p2) {
            if (p1.first == p2.first) return p1.second < p2.second;
            return p1.first < p2.first;
        };
        sort(envelopes.begin(), envelopes.end(), comp);
        
        vector<int> dp(len, 1);
        int max_count = 0;
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < i; ++j) {
                auto before = envelopes[j], after = envelopes[i];
                if (before.first < after.first && before.second < after.second) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            max_count = max(max_count, dp[i]);
        }
        return max_count;
    }
};
