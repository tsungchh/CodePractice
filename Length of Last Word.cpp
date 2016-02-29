class Solution {
public:
    /**
     * @param s A string
     * @return the length of last word
     */
    int lengthOfLastWord(string& s) {
        // Write your code here
        vector<string> strs;
        getTokens(s, strs);
        if(strs.size() == 0)
            return 0;
        return strs[strs.size()-1].size();
    }
    
    void getTokens(string s, vector<string>& strs)
    {
        string str = "";
        int status;
        for(int i = 0; i < s.size(); i++)
        {
            status = s[i] == ' ' ? 1 : 0;
            
            switch ( status )
            {
                case 0 :
                {
                    // word
                    str = str + s[i];
                    break;
                }
                case 1:
                {
                    // ' '
                    if(i+1 < s.size() && s[i+1] != ' ' && str.size() != 0)
                    {
                        // fprintf(stderr, "push: %s\n", str.c_str());
                        strs.push_back(str);
                        str = "";
                    }
                    break;
                }
            }
            
        }
        
        if(str.size() != 0)
        {
            strs.push_back(str);
        }
        
    }
};
