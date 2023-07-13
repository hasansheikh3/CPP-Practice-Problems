/*

Given a singly-linked list of integers, which may contain a cycle, detect and report the cycle if present.

Input: 1 → 2 → 3 → 4 ─┐
		   └──────────┘
Output: true

Input: 1 → 2 → 3 → 4 → nullptr
Output: false

Link : https://leetcode.com/problems/linked-list-cycle/

*/

#include <iostream>
#include <unordered_set>

using namespace std;

bool hasCycle(ListNode *head) {
        /*
        My Approach:
        1. create two pointers, slow and fast
        2. slow moves one node at a time, fast moves two nodes at a time
        3. if there is a cycle, slow and fast will eventually meet
        4. if there is no cycle, fast will reach the end of the list

        Time complexity: O(n)
        Space complexity: O(1)
        */

        if (!head)
        {
            return false;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                return true;
            }
        }

        return false;
        
    }
