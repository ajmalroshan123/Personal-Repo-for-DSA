
class Node {

    public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
}


Node* createLinkedList( int arr[], int index, int size) 
{
    if (index == size) 
    return 

    Node *temp = new Node(arr[index]);
    temp->next = createLinkedList(arr, index+1, size);
    return temp;
}



int main() {
    Node *Head;
    Head = NULL;

    int arr = {1,2,3,4,5}

    Head = createLinkedList(arr, 0, 5);


    // Delete the last Node

    if (Head != NULL) 
    {
        // if only one node present
        if (Head->next == NULL)
        {
            Node *temp = Head;
            delete temp;
            Head = NULL; 
        }
        // More than one node present
        else 
        {
            Node *curr = Head;
            Node *prev = NULL;

            // Move until curr->next != NULL

            while (curr->next != NULL) {
                prev = curr;
                curr = curr->next;
            }

            prev->next = curr->next;
            delete curr;
        }
    }

    while (Head) {
        cout<<Head->data<<" ";
        Head = Head->next;
    }

}