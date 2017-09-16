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
    /*
     * @param points: a list of points
     * @param origin: a point
     * @param k: An integer
     * @return: the k closest points
     */
    vector<Point> kClosest(vector<Point> points, Point origin, int k) {
        // write your code here
        auto comp = [&](pair<double, Point> p1, pair<double, Point> p2) {
            if (p1.first == p2.first) {
                return p1.second.x == p2.second.x ? 
                    p1.second.y < p2.second.y : 
                    p1.second.x < p2.second.x;
            }
            return p1.first < p2.first;
        };
        priority_queue<pair<double,Point>, vector<pair<double, Point>>, decltype(comp)> pq(comp);
        for (auto p : points) {
            double dist = (p.x-origin.x)*(p.x-origin.x) + (p.y-origin.y) *(p.y-origin.y);
            pq.push(make_pair(dist, p));
            if (pq.size() > k) pq.pop();
        }
        
        vector<Point> result(k);
        for (int i = k-1; i >= 0; --i) {
            result[i] = pq.top().second;
            pq.pop();
        }
        return result;
    }
};
