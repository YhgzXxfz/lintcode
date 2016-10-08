class Solution {
public:
    /**
     * @param s : A string
     * @return : A string
     */
    string reverseWords(string s) {
        // write your code here
        int len = s.size(), i = 0, trimed_size = 0, begin = 0, word = 0;
        while (true) {
            while (i < len && s[i] == ' ') i++;
            if (i == len) break;
            
            if (word) s[trimed_size++] = ' ';
            
            begin = trimed_size;
            while (i < len && s[i] != ' ') {
                s[trimed_size] = s[i];
                trimed_size++; i++;
            }
            
            reverseWords(s, begin, trimed_size-1);
            word++;
        }
        
        s.resize(trimed_size);
        reverseWords(s, 0, trimed_size-1);
        return s;
    }
    
    void reverseWords(string& s, int left, int right) {
        while (left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++; right--;
        }
    }
};

