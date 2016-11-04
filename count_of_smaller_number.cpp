class Solution {
public:
   /**
     * @param A: An integer array
     * @return: The number of element in the array that 
     *          are smaller that the given integer
     */
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        // write your code here
        vector<int> result;
        sort(A.begin(), A.end());
        for (int i = 0; i < queries.size(); ++i) {
            const auto it = lower_bound(A.cbegin(), A.cend(), queries[i]);
            result.emplace_back(it - A.cbegin());
        }
        return result;
    }
};

