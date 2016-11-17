class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     */
    int kSum(vector<int> A, int k, int target) {
        // wirte your code here
        const int n = A.size();

        // table[i][j][t] denotes the number of ways to select,
        // from first i elements, j elements whose sum equals to t
        vector<vector<vector<int>>> 
            table(n+1, vector<vector<int>>(k+1, vector<int>(target+1, 0)));

        for (int i = 1; i <= n; ++i) {
            if (A[i-1] <= target) {
                for (int j = i; j <= n; ++j) {
                    table[j][1][A[i-1]] = 1;
                }
            }
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = min(i, k); j > 1; --j) {
                for (int p = 1; p <= target; ++p) {
                    table[i][j][p] = table[i-1][j][p];
                    if (p - A[i-1] >= 0) {
                        table[i][j][p] += table[i-1][j-1][p-A[i-1]];
                    }
                }
            }
        }

        return table[n][k][target];
    }
};

