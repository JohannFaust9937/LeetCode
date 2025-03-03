// Top Interview 150
// https://leetcode.com/studyplan/top-interview-150/

// 88. Merge Sorted Array
// https://leetcode.com/problems/merge-sorted-array/description/

/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers sz_nums1 and sz_nums2,
representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1.
To accommodate this, nums1 has a length of sz_nums1 + sz_nums2, where the first sz_nums1 elements denote the elements that should be merged,
and the last sz_nums2 elements are set to 0 and should be ignored. nums2 has a length of sz_nums2.
*/

#include <vector>

class Solution
{
public:
    Solution() {};
    ~Solution() = default;

    void merge(std::vector<int> &nums1, int sz_nums1, std::vector<int> &nums2, int sz_nums2)
    {
        if (!(sz_nums1 | sz_nums2))
            return;

        int result{sz_nums1 + sz_nums2 - 1};
        --sz_nums1; --sz_nums2;
        while (sz_nums1 >= 0 and sz_nums2 >= 0)
        {
            if (nums1[sz_nums1] > nums2[sz_nums2])
                nums1[result--] = nums1[sz_nums1--];
            else
                nums1[result--] = nums2[sz_nums2--];
        }
        while (sz_nums2 >= 0)
        {
            nums1[result--] = nums2[sz_nums2--];
        }
        return;
    }
};

// Time complexity: O(m + n)
// Spatial complexity: O(1)