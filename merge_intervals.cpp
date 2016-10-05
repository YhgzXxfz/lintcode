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
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        // write your code here
        vector<Interval> result;
        if (intervals.empty()) return result;
        
        int len = intervals.size();
        sort(intervals.begin(), intervals.end(), compare);
        result.push_back(intervals[0]);
        
        for (int i = 1; i < len; ++i) {
            if (intervals[i].start <= result.back().end) {
                Interval temp (result.back().start, max(result.back().end, intervals[i].end));
                result.pop_back();
                result.push_back(temp);
            }
            else result.push_back(intervals[i]);
        }
        return result;
    }
    
    static bool compare(const Interval & a, const Interval & b)
    {
        return a.start < b.start;
    }
};

