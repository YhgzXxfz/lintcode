class Solution {
public:
    /**
     * @param gas: a vector of integers
     * @param cost: a vector of integers
     * @return: an integer 
     */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // write your code here
        int len = gas.size();
        
        int total_sum = 0, curr_sum = 0;
        int start = 0;
        for (int i = 0; i < len; ++i) {
            total_sum += gas[i]-cost[i];
            curr_sum += gas[i]-cost[i];
            if (curr_sum < 0) {
                curr_sum = 0;
                start = i+1;
            }
        }
        
        if (total_sum >= 0) return start;
        return -1;
    }
};

