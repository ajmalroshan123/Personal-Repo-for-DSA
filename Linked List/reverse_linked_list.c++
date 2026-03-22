Given the head of a singly linked list, reverse the list, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:


Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
 

Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?




/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode *curr = head, *prev = NULL, *fut = NULL;

        while(curr)
        {
            fut = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fut;
        }

        head = prev;
        return head;
    }
};


📦 Initial Linked List
head
 ↓
[1] → [2] → [3] → [4] → NULL
Pointers:

prev = NULL
curr = head (1)
fut  = NULL

🔁 Iteration 1
Step-by-step:
fut = curr->next → fut = 2

curr->next = prev → 1 → NULL

prev = curr → prev = 1

curr = fut → curr = 2

Visual:
prev      curr
 ↓          ↓
[1] → NULL   [2] → [3] → [4] → NULL

🔁 Iteration 2
fut = 3

Reverse link: 2 → 1

Move pointers

Visual:
prev           curr
 ↓               ↓
[2] → [1] → NULL   [3] → [4] → NULL

🔁 Iteration 3
fut = 4

Reverse link: 3 → 2

Visual:
prev                curr
 ↓                    ↓
[3] → [2] → [1] → NULL   [4] → NULL

🔁 Iteration 4
fut = NULL

Reverse link: 4 → 3

Visual:
prev
 ↓
[4] → [3] → [2] → [1] → NULL

curr = NULL ❌ (loop stops)

✅ Final Step
head = prev
Final Result:
head
 ↓
[4] → [3] → [2] → [1] → NULL

🔑 Key Insight
At every step:

You break the forward link

Then reverse it

And move forward safely using fut

🧩 Why 3 pointers?
Pointer	Purpose
curr	Current node you're reversing
prev	Previous node (new link direction)
fut	Save next node before breaking link
Without fut, you'd lose the rest of the list 😅





