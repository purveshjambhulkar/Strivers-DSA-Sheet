// problem link - https://www.naukri.com/code360/problems/implement-stack-with-linked-list_630475?leftPanelTabValue=PROBLEM

class Stack
{
private:
    Node *top;
    int size;

public:
    Stack()
    {
        top = nullptr;
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void push(int data)
    {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
        size++;
    }

    void pop()
    {
        if (isEmpty())
            return;

        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
    }

    int getTop()
    {
        if (isEmpty())
            return -1;
        return top->data;
    }
};
