// Top Interview 150
// https://leetcode.com/studyplan/top-interview-150/

// 2. Add Two Numbers
// https://leetcode.com/problems/add-two-numbers/description/

/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order,
and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    Solution() {};
    ~Solution() = default;
    
    ListNode *addTwoNumbers(ListNode *list1, ListNode *list2)
    {
        ListNode *temporary = new ListNode();
        ListNode *result = temporary;

        int carry{0};
        while (list1 != nullptr or list2 != nullptr or carry != 0)
        {
            int amount = carry;
            if (list1 != nullptr)
            {
                amount += list1->val;
                list1 = list1->next;
            }
            if (list2 != nullptr)
            {
                amount += list2->val;
                list2 = list2->next;
            }
            carry = amount / 10;
            result->next = new ListNode(amount % 10);
            result = result->next;
        }
        return temporary->next;
    }
};

// Temporal complexity: O(n)
// Spatial complexity: O(1)