class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: Cosine similarity.
     */
    double cosineSimilarity(vector<int> A, vector<int> B) {
        // write your code here
        double nA = norm(A), nB = norm(B), m = 0;
        if (nA == 0 || nB == 0) return 2.0;
        for (int i = 0; i < A.size(); ++i) {
            m += A[i] * B[i];
        }
        return m / (nA * nB);
    }
    double norm(vector<int> V) {
        int res = 0;
        for (int i = 0; i < V.size(); ++i) {
            res += V[i] * V[i];
        }
        return sqrt(res);
    }
};
