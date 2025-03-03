// Top Interview 150
// https://leetcode.com/studyplan/top-interview-150/

// 3. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

/*
Given a string s, find the length of the longest substring without duplicate characters.
*/

#include <string_view>
#include <unordered_map>

class Solution
{
public:
    Solution() {};
    ~Solution() = default;

    int lengthOfLongestSubstring(std::string_view string)
    {
        int size{static_cast<int>(string.size())};
        if (size == 0)
            return 0;
        else if (size == 1)
            return 1;
        else
        {
            int windowStartFrom{0}, windowEndingIn{0}, result{0};
            std::unordered_map<char, int> lastIndex;
            std::unordered_map<char, int>::const_iterator end{lastIndex.end()};

            while (windowEndingIn != size)
            {
                char currentSymbol{string[windowEndingIn]};
                if (lastIndex.find(currentSymbol) != end and lastIndex[currentSymbol] >= windowStartFrom)
                    windowStartFrom = lastIndex[currentSymbol] + 1;
                lastIndex[currentSymbol] = windowEndingIn;
                result = std::max(result, windowEndingIn - windowStartFrom + 1);
                ++windowEndingIn;
            }
            return result;
        }
    };
};

// Temporal complexity: 0(n)
// Spatial complexity: O(min(n, m))