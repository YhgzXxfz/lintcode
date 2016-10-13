class Solution {
public:
    /** 
     * @param chars: The letters array you should sort.
     */
    void sortLetters(string &letters) {
        // write your code here
        int len = letters.size();
        int left = 0, right = len-1;
        while (left < right) {
            while (letters[left] >= 'a') ++left;
            while (letters[right] <= 'Z') --right;
            if (left < right) {
                swap(letters[left], letters[right]);
                ++left; --right;
            }
        }
    }
};


