/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

Link : https://leetcode.com/problems/roman-to-integer/


***************************PLEASE SOLVE ON YOUR OWN BEFORE LOOKING AT THE SOLUTION BELOW***************************

*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Using initializer syntax to create a map of roman numerals to their integer values
unordered_map<char, int> romanToValue {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
};

int romanToInt(string s) {
    /**
     * MY APPROACH :
     * 1. Create a map of roman numerals to integer values
     * 2. Initialize result to 0 and n to the size of the string (for example if input is XXVI then n=4)
     * 3. Iterate over the string
     * 4. If the current value is smaller than the next value then subtract the current value from the result
     * 5. Otherwise add the current value to the result
     * 6. Return the result
     * 
     * Time complexity: O(n) (Because we are iterating over the string, lookups in the map are O(1), so O(n) + O(1) = O(n))
     * Space complexity: O(1) (We are using a fixed size map, so space complexity is O(1))
     * 
     * BRAIN TEASER : 
     * 1. Can you solve this problem without using a map?
     */
    int result = 0;
    int n = s.size();
    
    for (int i = 0; i < n; i++) {
        // Check if current value is smaller than the next value (if i is not the last index)
        if (i < n - 1 && romanToValue[s[i]] < romanToValue[s[i + 1]]) {
            result -= romanToValue[s[i]];  // Subtract if smaller
        } else {
            result += romanToValue[s[i]];  // Add otherwise
        }
    }

    return result;
}

int main() {
    // Example usage
    string roman;
    cout << "Enter a roman numeral: ";
    cin >> roman; // eg. XXIV
    cout << "Integer value: " << romanToInt(roman) << '\n'; // eg. 24

    return 0;
}
