//Include all neccessary libraries and namespaces.
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

#define ARRAYSIZE 10

//Stack structure taken from example video.
class Stack
{
    int stackArray[ARRAYSIZE];
    int top;
    
public:
    //Stack constructor.
    Stack()
    {
        top = 0;
    }
    
    //Checks if stack is empty.
    bool isEmpty(){
        if (top == 0)
        {
            return true;
        }
        return false;
    }
    
    //Pushes an element into the stack.
    void push(int element)
    {
        if (top == ARRAYSIZE)
        {
            std::cout << "overflow" << std::endl;
        }
        else
        {
            stackArray[top] = element;
            top++;
        }
    }
    
    //Pops an element out from the stack.
    int pop()
    {
        if(isEmpty()){
            std::cout << "underflow" << std::endl;
        }else{
            top--;
            return stackArray[top];
        }
        return -1;
    }
    
    //Prints out all data that is in the stack.
    void printStack()
    {
        for(int i = 0; i < top; i++){
            std::cout << stackArray[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main()
{
    //Variables needed for the program. 
    int numOps,numHire,numFire;
    bool approved = true;

    //Vectors needed for holding ID and operations.
    vector<int> ids;
    vector<char> operations;
    
    //Create new stack to hold IDs.
    Stack employeeCheck;
    
    //Prompt user input for number of HR operations.
    cout << "Enter the number of HR operations:" << endl;
    cin >> numOps;

    //Set array length.
    
    //Prompt user input for the operations and ID numbers, and read inputted operations.
    cout << "Input the operations and IDs:" << endl;
    for (int i = 0; i < numOps; i++)
    {
        char operation;
        int id;
        scanf(" %c%d", &operation, &id);
        operations.push_back(operation);
        ids.push_back(id);
    }

    //Push all actions IDs into a stack.
    for(int i = 0; i < numOps; i++)
    {
        employeeCheck.push(ids[i]);
    }

    employeeCheck.printStack();
    
    //Verify the IDs are being fired in the correct order.
    int counter = numOps-1;
    while(operations[counter] == '-' && operations[counter - 1] == '-')
    {
        if(ids[counter] >= ids[counter - 1])
        {
            approved = false;
        }
        counter--;
    }
    counter--;

    //Verify the IDs are being hired in ascending order.
    while(operations[counter] == '+' && operations[counter - 1] == '+')
    {
        if (ids[counter] <= ids[counter-1])
        {
            approved = false;
        }
        counter--;        
    }
    
    //Print out appropriate status message based on tests.
    if(approved)
        printf("PASS\n");
    else
        printf("FAIL\n");
    
}
