class Solution {
public:
    /**
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        // Write your code here
        
        int spaceCt = 0;
        
        for(int i = 0; i < length; i++)
        {
            if(string[i] == ' ')
                spaceCt++;
        }
        
        int totalLength = length - spaceCt + spaceCt*3 - 1;
        
        for(int i = length-1; i >= 0; i--)
        {
            if(string[i] == ' ')
            {
                string[totalLength] = '0';
                totalLength--;
                string[totalLength] = '2';
                totalLength--;
                string[totalLength] = '%';
                totalLength--;
            }
            else
            {
                string[totalLength] = string[i];
                totalLength--;
            }
        }
        
        return length - spaceCt + spaceCt*3;
    }
};  