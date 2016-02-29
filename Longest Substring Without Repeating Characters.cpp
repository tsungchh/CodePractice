//wrong
class Solution {
public:
    /**
     * @param s: a string
     * @return: an integer 
     */
    int lengthOfLongestSubstring(string s) {
        // write your code here
        unordered_map<char, int> map;
        int startIdx = 0;
        int maxLen = 0;
        for(int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if(map.find(c) != map.end())
            {
                startIdx = map[c]+1;
                map[c] = i;
            }
            else
            {
                map[c] = i;
            }
            maxLen = i - startIdx + 1 > maxLen ? i - startIdx + 1 : maxLen;
        }
        
        return maxLen;
    }
};


//right
class Solution {
public:
    /**
     * @param s: a string
     * @return: an integer 
     */
    int lengthOfLongestSubstring(string s) {
        // write your code here
        int startIdx = 0;
        unordered_set<char> set;
        int len = 0;
        int maxLen = 0;
        
        for(int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            
            len++;
            if(set.find(c) != set.end())
            {
                // move startIdx
                while(true)
                {
                    if(s[startIdx] != c && startIdx < i)
                    {
                        
                        len--;
                        set.erase(s[startIdx]);
                        startIdx++;
                    }
                    else
                        break;
                }
                len--;
                startIdx++;
            }
            else
            {
                set.insert(c);
            }
            maxLen = len > maxLen ? len : maxLen;
        }
        
        return maxLen;
    }
};