class Solution {
public:
    string gcdOfStrings(string str1, string str2) {

        // If they don't share the same repeating pattern
        if (str1 + str2 != str2 + str1)
            return "";

        // Find GCD of lengths
        int len = gcd(str1.length(), str2.length());

        // Return the common divisor string
        return str1.substr(0, len);
    }
};