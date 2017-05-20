// dp, t-O(N^2)
class Solution {
public:
    /**
     * @param stones a list of stones' positions in sorted ascending order
     * @return true if the frog is able to cross the river or false
     */
    bool canCross(vector<int>& stones) {
        if (stones.empty()) return true;
        
        int len = stones.size(), curr, next;
        unordered_set<int> st(stones.begin(), stones.end());
        unordered_map<int, unordered_set<int>> dp;
        dp[0].insert(1);
        
        for (int i = 0; i < len; ++i) {
            curr = stones[i];
            if (curr == stones[len-1]) break;
            
            for (const auto& jump : dp[curr]) {
                next = curr+jump;
                if (st.count(next) && next > curr) {
                    dp[next].insert(jump-1);
                    dp[next].insert(jump);
                    dp[next].insert(jump+1);
                }
            }
        }
        return dp.count(curr) && dp[curr].size() > 0;
    }
};



// dfs, t-O(N^3)
class Solution {
public:
    /**
     * @param stones a list of stones' positions in sorted ascending order
     * @return true if the frog is able to cross the river or false
     */
    bool canCross(vector<int>& stones) {
        int len = stones.size();
        vector<vector<int>> cache(len, vector<int>(len, 0));
        return dfs(stones, 0, 0, cache);
    }
    
private:
    bool dfs(vector<int>& stones, int start, int last_jump, vector<vector<int>>& cache) {
        if (cache[start][last_jump]) return cache[start][last_jump];
        
        for (int i = start+1; i < stones.size(); ++i) {
            int gap = stones[i]-stones[start];
            if (gap >= last_jump-1 && gap <= last_jump+1) {
                if (dfs(stones, i, gap, cache)) {
                    cache[i][gap] = true;
                    return true;
                }
            }
        }
        
        cache[start][last_jump] = start == stones.size()-1;
        return cache[start][last_jump];
    }
};
