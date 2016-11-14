class Solution {
public:
    /**
     *@param num: A list of non negative integers
     *@return: A string
     */
    string largestNumber(vector<int> &num) {
        // write your code here
        auto comp = [](const int& i1, const int& i2) { 
            return to_string(i1)+to_string(i2) > to_string(i2)+to_string(i1); };
        sort(num.begin(), num.end(), comp);
            
        string result;
        for (auto& i : num) {
            result.append(to_string(i));
        }
        
        if (result[0] == '0') return "0";
        return result;
    }
};

