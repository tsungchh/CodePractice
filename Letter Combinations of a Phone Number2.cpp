class Solution {
public:
    /**
     * @param digits A digital string
     * @return all posible letter combinations
     */
    vector<string> letterCombinations(string& digits) {
        // Write your code here
        unordered_map<char, vector<string>> map;
        string ans;
        vector<string> result;
        vector<string> tmp;
        tmp.push_back("a");
        tmp.push_back("b");
        tmp.push_back("c");
        map['2'] = tmp;
        
        tmp.resize(0);
        tmp.push_back("d");
        tmp.push_back("e");
        tmp.push_back("f");
        map['3'] = tmp;
        
        tmp.resize(0);
        tmp.push_back("g");
        tmp.push_back("h");
        tmp.push_back("i");
        map['4'] = tmp;
        
        tmp.resize(0);
        tmp.push_back("j");
        tmp.push_back("k");
        tmp.push_back("l");
        map['5'] = tmp;
        
        tmp.resize(0);
        tmp.push_back("m");
        tmp.push_back("n");
        tmp.push_back("o");
        map['6'] = tmp;
        
        tmp.resize(0);
        tmp.push_back("p");
        tmp.push_back("q");
        tmp.push_back("r");
        tmp.push_back("s");
        map['7'] = tmp;
        
        tmp.resize(0);
        tmp.push_back("t");
        tmp.push_back("u");
        tmp.push_back("v");
        map['8'] = tmp;
        
        tmp.resize(0);
        tmp.push_back("w");
        tmp.push_back("x");
        tmp.push_back("y");
        tmp.push_back("z");
        map['9'] = tmp;
        
        dfshelper(0, digits, result, ans, map);
        
        return result;
    }
    
    void dfshelper(int idx, string& digit, vector<string>& result, string ans, 
                   unordered_map<char, vector<string>>& map)
    {
        if(idx == digit.size())
        {
            if(ans.size() > 0)
                result.push_back(ans);
            return;
        }
        
        vector<string> words = map[digit[idx]]; 
        for(int i = 0; i < words.size(); i++)
        {
            ans = ans + words[i];
            dfshelper(idx+1, digit, result, ans, map);
            ans = ans.substr(0, ans.size()-1);
        }
    }
};