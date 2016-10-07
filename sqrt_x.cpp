class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        // write your code here
        if (x <= 1) return x;
        
        int min = 0, max = x, result, square;
        
        while (min <= max) {
            result = (min+max) / 2;
            square = result * result;
            
            if (isOverflow(square, result, result)) {
                max = result -1;
                continue;
            }
            
            if (square == x) return result;
            
            else if (square < x) min = result+1;
            
            else max = result-1;
        }
        return square > x ? result-1 : result;
    }
    
    bool isOverflow(int dividend, int divisor, int result) {
        return (dividend / divisor) != result;
    }
};

