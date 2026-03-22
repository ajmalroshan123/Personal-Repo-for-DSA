//  delete particular node
#include <iostream>
using namespace std;


Delete in a Singly Linked List
You are given the head of a singly linked list and an integer x. Delete the xth node (1-based indexing) from the singly linked list.

Examples:

Input: x = 1,
    
Output: 2 -> 3 -> 1 -> 7
Explanation: After deleting the node at the 1st position (1-base indexing), the linked list is as
    
Input: x = 5,
    
Output: 2 -> 3 -> 4 -> 5
Explanation: After deleting the node at 5th position (1-based indexing), the linked list is as
    
Constraints:
1 ≤ size of linked list ≤ 105
1 ≤ x ≤ size of linked list




class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        // code here
        
        if (x == 1) 
        {
            Node* temp = head;
            head       = head->next;
            delete temp;
            
            return head;
        }
        
        x--;
        Node* curr = head;
        Node* prev = NULL;
        
        while(x--) 
        {
            prev = curr;
            curr = curr->next;
        }
        
        prev->next = curr->next;
        delete curr;
        
        return head;
    }
};