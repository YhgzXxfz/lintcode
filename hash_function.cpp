class Solution {
public:
    /**
     * @param key: A String you should hash
     * @param HASH_SIZE: An integer
     * @return an integer
     */
    int hashCode(string key,int HASH_SIZE) {
        // write your code here
        long result = 0;
        int len = key.size();
        
        for (int i = 0; i < len; ++i) {
            result = result * 33 + (int)key[i];
            result %= HASH_SIZE;
        }
        return result;
    }
};

