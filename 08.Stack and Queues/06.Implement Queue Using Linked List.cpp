// problem link - https://www.naukri.com/code360/problems/implement-queue-using-linked-list_8161235?leftPanelTabValue=PROBLEM



/**
 * Definition of linked list
 * class Node {
 * 
 * public:
 *     int data;
 *     Node* next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node* next) : data(x), next(next) {}
 * };
 * 
 * Definition of Queue
 * struct Queue {
 *   Node* front;
 *   Node* rear;
 *   void push(int);
 *   int pop();
 *   
 *   Queue() {
 *       front = rear = NULL;
 *   }
 * };
 */

 int size = 0;  // Global variable since we can't modify Queue structure

 bool isEmpty() {
     return size == 0;
 }
 
 void Queue::push(int x) {
     Node* temp = new Node(x);
     if (isEmpty()) {
         front = rear = temp;
     } else {
         rear->next = temp;
         rear = temp;
     }
     size++;
 }
 
 int Queue::pop() {
     if (isEmpty()) {
         return -1;
     }
 
     Node* temp = front;
     int value = temp->data;
 
     front = front->next;
     if (front == nullptr) {
         rear = nullptr;  // Queue is now empty
     }
 
     delete temp;
     size--;
     return value;
 }
 