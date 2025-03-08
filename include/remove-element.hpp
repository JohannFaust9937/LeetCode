// Top Interview 150
// https://leetcode.com/studyplan/top-interview-150/

// 27. Remove Element
// https://leetcode.com/problems/remove-element/description/

/*
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of
the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the
following things:

    · Change the array nums such that the first k elements of nums contain the elements which are not equal to val.
        The remaining elements of nums are not important as well as the size of nums.
    · Return k.
*/

#include <vector>
#include <utility>

bool infinity_loop{true};

class Solution
{
public:
    Solution() {};
    ~Solution() = default;

    int removeElement(std::vector<int> &array, int removal)
    {
        int end{static_cast<int>(array.size())};
        if (array.size() == 0)
            return 0;
        int forward_caret{0}, backward_caret{end - 1};
        while (infinity_loop)
        {
            while (array[backward_caret] == removal and backward_caret != forward_caret)
                --backward_caret;
            while (array[forward_caret] != removal and forward_caret != backward_caret)
                ++forward_caret;
            if (forward_caret != backward_caret)
                std::swap(array[forward_caret], array[backward_caret]);
            else
                break;
        }
        if (array[0] == removal) return 0; 
        return forward_caret;
    }
};

// Time complexity: O(n)
// Spatial complexity: O(1)