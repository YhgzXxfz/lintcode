class Solution {
public:
    /**
     * @param str: a string
     * @param offset: an integer
     * @return: nothing
     */
    void rotateString(string &str,int offset){
        //wirte your code here
        int len = str.length();
        if (len == 0) return;
        
        offset %= len;
        if (offset == 0) return;
        
        // 1
        //string s1 = str.substr(0, len-offset);
        //string s2 = str.substr(len-offset);
        
        //str = s2+s1;
        
        // 2
        Reverse(str, 0, len-1);
        Reverse(str, 0, offset-1);
        Reverse(str, offset, len-1);
    }
    
    void Reverse(string & str, int start, int end) {
        int len = end+1 - start;
        if (len == 0 || len > str.size() || start < 0 || end > str.size()-1) return;
        
        for (int i = start; i < (end+1+start)/2; ++i)
        {
            int temp = str[i];
            str[i] = str[end+start-i];
            str[end+start-i] = temp;
        }
    }
};


