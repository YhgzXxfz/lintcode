class Solution {
public:
    /**
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        // Write your code here
        if (string == NULL || length == 0) return 0;
        
        int count = 0;
        for (int i = 0 ; i < length; ++i)
        {
            if (string[i] == ' ') ++count;
        }
        
        int newLength = length + 2*count;
        string[newLength] = '\0';
        for (int i = length-1; i >= 0; --i)
        {
            if (string[i] == ' ')
            {
                string[i +count*2] = '0';
                string[i +count*2-1] = '2';
                string[i +count*2-2] = '%';
                --count;
            }
            else
            {
                string[i + count*2] = string[i];
            }
        }
        return newLength;
    }
};  

