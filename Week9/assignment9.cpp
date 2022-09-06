//Include all neccessary libraries and namespaces.
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

//Maximum 100 employees can be checked using this function.
#define ARRAYSIZE 100

//Stack structure taken from class example video.
class Stack {
    int stackArray[ARRAYSIZE];
    int top;
    
public:
    //Stack constructor.
    Stack() {
        top = 0;
    }
    
    //Checks if stack is empty.
    bool isEmpty() {
        if (top == 0)
            return true;
        return false;
    }
    
    //Pushes an element into the stack.
    void push(int element) {
        if (top == ARRAYSIZE) {
            std::cout << "overflow" << std::endl;
        } else {
            stackArray[top] = element;
            top++;
        }
    }
    
    //Pops an element out from the stack.
    int pop() {
        if(isEmpty()) {
            std::cout << "underflow" << std::endl;
        } else {
            top--;
            return stackArray[top];
        }
        return -1;
    }
};

//Queue structure taken from class example video.
class Queue {
    int queueArray[ARRAYSIZE];
    int head;
    int tail;
    
public:
    //Queue constructor.
    Queue() {
        head = 0;
        tail = 0;
    }
    
    //Checks if Queue is empty.
    bool isEmpty() {
        if (head == tail)
            return true;
        return false;
    }
    
    //Adds an element into line to be dequeued from the queue.
    void enqueue(int element ){
        queueArray[tail] = element;
        if (tail == ARRAYSIZE) {
            //wrap around
            tail = 0;
        } else {
            tail++;
        }
    }

    //Returns the earliest inputted element from the queue.    
    int dequeue() {
        int element = queueArray[head];
        if (head == ARRAYSIZE)
            head = 0;
        else
            head++;
        return element;
    }
};

int main() {
    //Variables needed for the program. 
    int numOps;
    bool approved = true;

    //Vectors needed for holding ID and operations from input.
    vector<int> ids;
    vector<char> operations;
    
    //Create new stack and queue to hold IDs for verification.
    Stack hireStack;
    Queue fireQueue;
    
    //Prompt user input for number of HR operations.
    cout << "Enter the number of HR operations:" << endl;
    cin >> numOps;
    
    //Prompt user input for the operations and ID numbers, and read inputted operations.
    cout << "Input the operations and IDs:" << endl;
    for (int i = 0; i < numOps; i++) {
        char operation;
        int id;
        scanf(" %c%d", &operation, &id);
        operations.push_back(operation);
        ids.push_back(id);
    }

    //Adds hiring actions into a stack and firing actions into a queue.
    for(int i = 0; i < numOps; i++) {
        if(operations[i] == '+')
            hireStack.push(ids[i]);
        if(operations[i] == '-')
            fireQueue.enqueue(ids[i]);
    }

    //Check both data structures until either one is empty.
    while(!fireQueue.isEmpty() && !hireStack.isEmpty()) {
        
        //Queue is the IDs in the order that they are fired by HR.
        //Stack is the order that HR should be firing in (last in first out).
        
        //Each firing action in the queue is evaluated against the reverse order of hiring.
        //If ID# of fired worker (from action queue) is lower than ID# that SHOULD be fired (from stack), it fails the test as there is a less experienced worker still employed.  
        if(fireQueue.dequeue() < hireStack.pop())
            printf("FAIL\n");
    }

    //Print PASS if there is no problem.
    printf("PASS\n");
        
}