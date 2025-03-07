// Top Interview 150
// https://leetcode.com/studyplan/top-interview-150/

// 125. Valid Palindrome
// https://leetcode.com/problems/valid-palindrome/description/

/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all
non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include
letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.
*/

#include <string_view>
#include <cctype>

class Solution
{
public:
    Solution() {};
    ~Solution() = default;

    bool isPalindrome(std::string_view string)
    {
        int forward_shift{0}, backward_shift{static_cast<int>(string.size()) - 1};
        while (forward_shift < backward_shift)
        {
            if (not std::isalnum(string[forward_shift]))
            {
                ++forward_shift;
                continue;
            }
            if (not std::isalnum(string[backward_shift]))
            {
                --backward_shift;
                continue;
            }
            if (comparising(string[forward_shift], string[backward_shift]))
                return false;
            ++forward_shift;
            --backward_shift;
        }
        return true;
    }

    inline char processing(char symbol)
    {
        if (std::isupper(static_cast<int>(symbol)))
            return static_cast<char>(std::tolower(static_cast<int>(symbol)));
        return symbol;
    }

    inline bool comparising(char left, char right)
    {
        return processing(left) != processing(right);
    }
};

// Temporal complexity: O(n) # n is count of non-alphanumerical symbols in string
// Spatial complexity: O(1)