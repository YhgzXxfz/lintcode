class Solution {
public:
    /**
     * @param path the original path
     * @return the simplified path
     */
    string simplifyPath(string& path) {
        // Write your code here
        vector<string> stack;
        string result = "", temp;
        stringstream ss(path);
        
        while(getline(ss, temp, '/')) {
            if (temp == "" || temp == ".") continue;
            else if (temp == ".." && !stack.empty()) stack.pop_back();
            else if (temp != "..") stack.push_back(temp);
        }
        
        for (auto str : stack) {
            result += "/"+str;
        }
        return result.empty() ? "/" : result;
    }
};

