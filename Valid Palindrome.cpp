class Solution {
public:
    /**
     * @param s A string
     * @return Whether the string is a valid palindrome
     */
    bool isPalindrome(string& s) {
        // Write your code here
        int start = 0;
        int end = s.size()-1;
        
        while(start < end)
        {
            while( !isAlpha(s[start]) )
            {
                start++;
            }
            
            while( !isAlpha(s[end]) )
            {
                end--;
            }
            
            if(start > end)
                break;
            
            if( isSame(s[start], s[end]) )
            {
                start++;
                end--;
            }
            else
            {
                return false;
            }
            
        }
        
        return true;
    }
    
    bool isSame(char a, char b)
    {
        if( a == b)
            return true;
        if(a + 'A'-'a' == b)
            return true;
        if(a + 'a'-'A' == b)
            return true;
            
        return false;
    }
    
    bool isAlpha(char c)
    {
        if( c <= 'z' && c >= 'a')
            return true;
        if( c <= 'Z' && c >= 'A')
            return true;
        if( c <= '9' && c >= '0')
            return true;
        return false;
    }
};
