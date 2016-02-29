#include "vector"
#include "string"

using namespace std;

class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        // write your code here
        int max = 0;
        vector<string> ret;
        
        for(int i = 0; i < dictionary.size(); i++){
            if(dictionary[i].size() > max)
            {
                max = dictionary[i].size();
                ret.resize(0);
                ret.push_back(dictionary[i]);
            }
            else if(dictionary[i].size() == max)
            {
                ret.push_back(dictionary[i]);
            }
        }

        return ret;
    }
};


int main()
{
    Solution test;
    vector<string> testCases;
    testCases.push_back("dog");
    testCases.push_back("google");
    testCases.push_back("facebook");
    testCases.push_back("internationalization");
    testCases.push_back("blabla");

    vector<string> ret = test.longestWords(testCases);

    for(int i = 0; i < ret.size(); i++)
        printf("%s\n", ret[i].c_str());
    
    return 0;
}