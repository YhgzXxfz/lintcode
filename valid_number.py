class Solution:
    # @param {string} s the string that represents a number
    # @return {boolean} whether the string is a valid number
    def isNumber(self, s):
        # Write your code here
        try:
            float(s)
            return True
        except ValueError:
            return False

