// Top Interview 150
// https://leetcode.com/studyplan/top-interview-150/

// 1. Two Sum
// https://leetcode.com/problems/remove-element/description/

/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
*/

#include <vector>
#include <unordered_map>

class Solution
{
public:
    Solution() {};
    ~Solution() = default;

    std::vector<int> twoSum(std::vector<int> &array, int target)
    {
        int size{static_cast<int>(array.size())};
        if (array.size() == 2)
            return {0, 1};

        std::unordered_map<int, int> map{};
        int complement{0};

        for (int index{0}; index != size; ++index)
        {
            complement = target - array[index];
            if (map.find(complement) != map.end())
                return {map[complement], index};
            map[array[index]] = index;
        }
        return {-1};
    };
};

// Time complexity: O(n)
// Spatial complexity: O(n)