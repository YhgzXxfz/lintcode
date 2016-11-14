/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    /**
     * @param points an array of point
     * @return an integer
     */
    int maxPoints(vector<Point>& points) {
        // Write your code here
        if (points.size() <= 2) return points.size();
        
        unordered_map<double, int> lines;
        int total_max = 0;
        for (int i = 0; i< points.size(); ++i) {
            int max_from_this = 1;
            int same_point = 0;
            lines.clear();
            
            for (int j = i+1 ; j < points.size(); ++j) {
                int dx = points[j].x - points[i].x;
                int dy = points[j].y - points[i].y;
                double slope = numeric_limits<double>::infinity();
                
                if (dx == 0 && dy == 0) ++same_point;
                else {
                    if (dx != 0) slope = double(dy)/double(dx);
                    
                    int count = (lines.find(slope) != lines.end()) ? lines[slope] + 1: 2;
                    
                    lines[slope] = count;
                
                    if (count > max_from_this) max_from_this = count;
                }
            }
        
            if (total_max < max_from_this + same_point) 
                total_max = max_from_this + same_point;
            
        }
        return total_max;
    }
};

