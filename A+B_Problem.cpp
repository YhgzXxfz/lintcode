class Solution {
    /*
     * param a: The first integer
     * param b: The second integer
     * return: The sum of a and b
     */
    public int aplusb(int a, int b) {
        // write your code here, try to do it without arithmetic operators.
        int sum = a^b, carry = a&b;
        while (carry != 0) {
            a = sum;
            b = carry << 1;
            sum = a^b;
            carry = a&b;
        }
        return sum;
    }
};