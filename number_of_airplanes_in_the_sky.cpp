/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution {
public:
    /**
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        // write your code here
        vector<int> starts, ends;
        for (auto i : airplanes) {
            starts.push_back(i.start);
            ends.push_back(i.end);
        }
        
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        
        int max_planes = 0, planes = 0;
        int s = 0, e = 0;
        while (s < starts.size()) {
            if (starts[s] < ends[e]) {
                ++planes;
                max_planes = max(max_planes, planes);
                ++s;
            } else {
                --planes;
                ++e;
            }
        }
        return max_planes;
    }
};
