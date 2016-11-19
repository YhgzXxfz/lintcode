class Solution {
public:
    /**
     * @param pages: a vector of integers
     * @param k: an integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        // write your code here
        if (k > pages.size()) return *max_element(pages.cbegin(), pages.cend());
        
        int sum = accumulate(pages.begin(), pages.end(), 0);
        int lowerBound = sum / k;
        return binarySearch(pages, k, lowerBound, sum);
    }
    
    int binarySearch(vector<int>& pages, int k, int left, int right) {
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (isValid(pages, k, mid)) right = mid -1;
            else left = mid+1;
        }
        return left;
    }
    
    bool isValid(vector<int>& pages, int k , int each) {
        int people = 0;
        int sum = 0;
        for (int i = 0; i < pages.size() && people < k; ++i) {
            if (sum + pages[i] > each) {
                sum = 0;
                ++people;
            }
            sum += pages[i];
        }
        return people < k && sum <= each;
    }
};

