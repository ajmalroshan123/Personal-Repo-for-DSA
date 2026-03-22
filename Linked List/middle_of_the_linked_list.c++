Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
Example 2:


Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
 

Constraints:

The number of nodes in the list is in the range [1, 100].
1 <= Node.val <= 100


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
    ListNode* middleNode(ListNode* head) {
        
        ListNode *temp = head;
        int count = 0;

        while(temp) 
        {
            count++;
            temp = temp->next;
        }

        count /= 2;

        temp = head;

        while(count--){
            temp = temp->next;
        }

        return temp;
    }
};



🧠 Idea in One Line

You:

Count total nodes
Go to halfway point
📦 Example Linked List
head
 ↓
[1] → [2] → [3] → [4] → [5] → NULL
🔢 Step 1: Count Nodes

You traverse once:

temp moves → 1 → 2 → 3 → 4 → 5 → NULL
count = 5
➗ Step 2: Find Middle Index
count = count / 2
count = 5 / 2 = 2

👉 This means: move 2 steps from head

🚶 Step 3: Move to Middle

Start again:

temp = head (1)
Move 1 step:
[1] → [2]
        ↑ temp
Move 2 steps:
[1] → [2] → [3]
               ↑ temp
✅ Final Answer
Middle Node = [3]
📊 Even Length Case

Example:

[1] → [2] → [3] → [4] → [5] → [6]
Step 1:
count = 6
Step 2:
count = 6 / 2 = 3
Step 3 (move 3 steps):
[1] → [2] → [3] → [4]
                      ↑ temp
✅ Result
Middle Node = [4]

👉 This matches the problem rule:

If 2 middle nodes → return the second middle

🔁 Full Flow Summary
1st pass → count nodes
2nd pass → move count/2 steps
return node
⚠️ Important Insight

Your solution works perfectly, but:

Time Complexity: O(n) + O(n) = O(n)
Space Complexity: O(1)
🚀 Pro Tip (Better Approach)

There’s a more optimal one-pass method:

👉 Slow & Fast Pointer

slow → moves 1 step
fast → moves 2 steps

When fast reaches end → slow is at middle

Visual:
[1] → [2] → [3] → [4] → [5]

slow: 1 → 2 → 3
fast: 1 → 3 → 5 → NULL

👉 slow = middle (3)