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
     * Insert newInterval into intervals.
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // write your code here
        vector<Interval> result;
        
        if (intervals.empty()) {
            result.push_back(newInterval);
            return result;
        }
        
        auto it = intervals.begin();
        for (; it != intervals.end(); ++it) {
            if (newInterval.end < (*it).start) break;
            else if (newInterval.start > (*it).end) result.push_back(*it);
            else {
                newInterval.start = min((*it).start, newInterval.start);
                newInterval.end = max((*it).end, newInterval.end);
            }
        }
        
        result.push_back(newInterval);
        for (; it != intervals.end(); ++it) {
            result.push_back(*it);
        }
        return result;
    }
};

