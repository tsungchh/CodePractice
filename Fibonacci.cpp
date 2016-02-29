class Solution{
public:
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) {
        // write your code here
        
        // dp solution, bottom-up
        int f[n];
        f[0] = 0;
        f[1] = 1;
        for(int i = 2; i < n; i++)
        {
            f[i] = f[i-1] + f[i-2];
        }
        
        return f[n-1];
    }
};
