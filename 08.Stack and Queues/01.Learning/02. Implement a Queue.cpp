// problem link - https://www.naukri.com/code360/problems/queue-using-array-or-singly-linked-list_2099908?leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 
class Queue {
public:
    int *arr;
    int frontx; 
    int rear;

    Queue() {
        // Implement the Constructor
        arr = new int [10001];
        this->frontx = -1;
        this->rear = -1;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(frontx == -1 && rear == -1){
          return true;
        }else{
          return false;
        }
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(isEmpty()){
          arr[0] = data;
          frontx = 0; 
          rear = 0;
        }else{
          rear++;
          arr[rear] = data;
        }
        
    }

    int dequeue() {
        // Implement the dequeue() function
        if(isEmpty()){
          return -1;
        }

        //removing the only element in the Q
        if(frontx == rear){
          int temp = arr[frontx];
          frontx = -1;
          rear = -1;
          return temp;
        }

        //otherwise
        int temp = arr[frontx];
        frontx++;
        return temp;
    }

    int front() {
        // Implement the front() function
        if(isEmpty()){
          return -1;
        }else{
          return arr[frontx];
        }
    }
};