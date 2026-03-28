Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz



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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int count = 0;
        ListNode *curr = head;

        while(curr) {
            count++;
            curr = curr->next;
        }

        count -= n;
        curr = head;

        ListNode *prev = NULL;

        if (count == 0) 
        {
            ListNode *temp = head;
            head = head->next;
            delete temp;
            
            return head;
        }

        while(count--) {
            prev = curr;
            curr=curr->next;
        }
        prev->next = curr->next;
        delete curr;

        return head;
    }
};


--------------------------------------------------

🧠 Idea in One Line
Count total nodes
Convert it to (from start)
Remove that node
📦 Example
head
 ↓
[1] → [2] → [3] → [4] → [5] → NULL

👉 Remove n = 2 (2nd from end)

🔢 Step 1: Count Nodes
count = 5
🔄 Step 2: Convert Position
count = count - n
count = 5 - 2 = 3

👉 Remove 3rd index (0-based movement from head)

🚶 Step 3: Traverse to Node

We move count times:

Iteration 1:
prev = 1
curr = 2
Iteration 2:
prev = 2
curr = 3
Iteration 3:
prev = 3
curr = 4   ❌ (node to delete)
✂️ Step 4: Remove Node
prev->next = curr->next
Visual:
Before:
[1] → [2] → [3] → [4] → [5]

After:
[1] → [2] → [3] → [5]
⚠️ Special Case (Important)
When deleting the head:

Example:

[1] → [2] → [3], n = 3
count = 3
count - n = 0

👉 Means: delete head

Your code handles this correctly:

head = head->next
🔁 Full Flow Summary
1. Count total nodes
2. Calculate position: count - n
3. Traverse to that node
4. Remove it
⏱️ Complexity
Time: O(n) + O(n) = O(n)
Space: O(1)
🚀 Better Approach (Interview Favorite)

👉 Two Pointer Technique (One Pass)

Idea:
Move fast pointer n steps ahead
Then move both slow & fast
When fast hits NULL → slow is just before the node to delete
Visual:
[1] → [2] → [3] → [4] → [5]
             ↑
           delete (n=2)
Step 1:
fast moves 2 steps → at 3
slow at 1
Step 2:

Move both:

slow → 2 → 3
fast → 4 → 5 → NULL

👉 slow is before target → delete next node

🔥 Pro Insight

Your solution is:

✅ Correct
✅ Safe (handles head deletion)
❌ Slightly inefficient (2 passes)

Two-pointer method is:

✅ Optimal (1 pass)
✅ Most expected in interviews