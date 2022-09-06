#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#define ARRAYSIZE 10

class Stack {
    int stackArray[ARRAYSIZE];
    int top;
public:
    Stack(){
        top = 0;
    }
    
    bool isEmpty(){
        if (top == 0) {
            return true;
        }
        return false;
    }
    
    void push(int element){
        if (top == ARRAYSIZE) {
            //std::cout<< "overflow" << std::endl;
        }else{
            stackArray[top] = element;
            top++;
        }
    }
    
    int pop(){
        if (isEmpty()) {
            //std::cout << "underflow" << std::endl;
        }else{
            top--;
            return stackArray[top];
        }
        return -1;
    }
    
    int checkTop(){
        if (isEmpty()){
            //std::cout << "there are no elements in the stack" << std::endl;
        }else{
            return stackArray[top-1];
        }
        return -1;
    }
    
    void printStack(){
        for (int i = 0; i < top; i++) {
            std::cout << stackArray[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main(int argc, const char * argv[]) {
    
    std::cout << "Enter the number of HR operations:" << std::endl;
    int numberOfHROperations;
    std::cin >> numberOfHROperations;
    
    std::cout << "Input the operations and IDs:" <<std::endl;
    std::vector<char> operations;
    std::vector<int> ids;
    
    //reading from stdin
    for (int i = 0; i < numberOfHROperations; i++){
        char operation;
        int id;
        scanf(" %c%d", &operation, &id);
        operations.push_back(operation);
        ids.push_back(id);
    }
    
    Stack s;
    for(int i = 0; i < numberOfHROperations; i++){
        if(operations[i] == '+'){
            s.push(ids[i]);
        }else{
            int lastFired = ids[i];
            if(lastFired != s.checkTop()){
                //alert! An experienced employee was fired first.
                std::cout << "FAIL" << std::endl;
                return 0;
            }else{
                //the last hired person was fired. take them off the list
                s.pop();
            }
        }
    }
    
    std::cout << "PASS" << std::endl;
    
    return 0;
}
