class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: Cosine similarity.
     */
    double cosineSimilarity(vector<int> A, vector<int> B) {
        // write your code here
        int lenA = A.size();
        int lenB = B.size();
        if (lenA != lenB) return 2.0000;
        
        double ab = product(A, B);
        double aa = product(A, A);
        double bb = product(B, B);
        if (aa <= 0 || bb <= 0) return 2.0000;
        
        return ab / (sqrt(aa) * sqrt(bb));
    }
    
    double product (vector<int> A, vector<int> B)
    {
        int len = A.size();
        double sum = 0;
        for (int i = 0; i < len; ++i)
        {
            sum += A[i]*B[i];
        }
        return sum;
    }
};


