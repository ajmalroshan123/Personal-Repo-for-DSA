
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

    int arr = {1,2,3,4,5};

    Head = createLinkedList(arr, 0, 5);

    Node *temp = Head;
    Head = Head->next;
    delete temp;




    while (Head) {
        cout<<Head->data<<" ";
        Head = Head->next;
    }

}