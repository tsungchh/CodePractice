class Solution {
public:
    /**
     * @param n an integer
     * @return true if this is a happy number or false
     */
    bool isHappy(int n) {
        // Write your code here
        unordered_set<int> set;
        while(true)
        {
            if(n == 1)
                return true;
                
            if(set.find(n) != set.end())
                return false;
            else
                set.insert(n);
            
            n = getHappyNum(n);
        }
        
        return false;
        
    }
    
    int getHappyNum(int n)
    {
        int ret = 0;
        while(n != 0)
        {
            ret += (n%10) * (n%10);
            n /= 10;
        }
        
        return ret;
    }
};