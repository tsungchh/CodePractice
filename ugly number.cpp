class Solution {
public:
    /*
     * @param k: The number k.
     * @return: The kth prime number as description.
     */
    
    class myComparison
    {
    public:
        bool operator()(const long long& a, const long long& b)
        {
            return a > b;
        }
    };
    
    long long kthPrimeNumber(int k) {
        // write your code here
        
        typedef priority_queue<long long, vector<long long>, myComparison> MyQueue;
        MyQueue q;
        unordered_set<long long> set;
        
        int ugly[3];
        ugly[0] = 3; ugly[1] = 5; ugly[2] = 7;
        for(int i = 0; i < 3; i++)
        {
            q.push(ugly[i]);
            set.insert(ugly[i]);
        }
        
        int idx = 0;
        long long val = 0;
        
        while( !q.empty() && idx < k)
        {
            val = q.top();
            idx++;
            q.pop();
            
            for(int i = 0; i < 3; i++)
            {
                long long addVal = val*ugly[i];
                if( set.find(addVal) == set.end() )
                {
                    set.insert(addVal);
                    q.push(addVal);
                }
            }
            
        }
        
        return val;
    }
};
