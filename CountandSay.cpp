#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /**
     * @param n the nth
     * @return the nth sequence
     */
    string countAndSay(int n) {
        // Write your code here
        
        // The pattern "count" + "number"
        // Base case, n = 1, 11
        
        if(n <= 0)
            return "";
            
        string str = "1";
        int i = 1;
        while(i < n)
        {
            int size = str.size();
            int i_str = 1;
            string strTmp = "";
            int ct = 1;
            int val = str[0] - '0';
            while(i_str < size)
            {
                if(str[i_str] == str[i_str-1])
                {
                    ct++;
                }
                else
                {
                    strTmp = strTmp + to_string(ct) + to_string(val);
                    val = str[i_str]-'0';
                    ct = 1;
                }
                i_str++;
            }
            
            str = strTmp + to_string(ct) + to_string(val);
            printf("%s %d %d\n", str.c_str(), ct, val);
            i++;
        }
        
        return str;
        
    }
};

int main()
{
    Solution sln;
    string ret = sln.countAndSay(2);
    printf("%s", ret.c_str());

    return 0;
}