//Include all neccessary libraries and namespaces.
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

//LinkedList structure taken from example video.
struct Node{
    int data;
    Node * next = nullptr;

};

class LinkedList {
    Node * head;
    
public:
    LinkedList(){
        //head is pointing to a null pointer in the beginning
        head = nullptr;
    }
    
    void addNodeToBeginning(Node & node){
        node.next = head;
        head = &node;
    }

    int searchNode(int data){
        int index = 0;
        Node *currentPointer = head;
        while(currentPointer != nullptr){
            if (currentPointer-> data == data)
            {
                return index;
            }
            currentPointer = currentPointer->next;
            index++;
        }
        return -1;
    }

    void deleteNode(int data){
        if (head == nullptr) //the list is empty, nothing to delete
        {
            return;
        }

        if (head->data == data)
        {
            head = head->next;
            return;
        }

        Node *currentPointer = head;

        while(currentPointer != nullptr){
            Node *nextNode = currentPointer->next;
            if (nextNode != nullptr)
            {
                if (nextNode->data == data)
                {
                    //found the node!
                    currentPointer->next = nextNode->next;
                    return;
                }
            }
            currentPointer = currentPointer->next;
        }
    }
    
    void printList(){
        Node *currentPointer = head;
        while (currentPointer != nullptr) {
            cout << currentPointer->data << " ";
            currentPointer = currentPointer->next;
        }
        cout << endl;
    }
};

int main(){
    
    //Variables needed for the program. 
    int numberOfHROperations;
    //Vectors needed for holding ID and operations.
    vector<int> ids;
    vector<char> operations;

    //Prompt user input for number of HR operations.
    cout << "Enter the number of HR operations:" << endl;
    cin >> numberOfHROperations;
    
    //Prompt for user input for the operations and ID numbers, and read inputted operations.
    cout << "Input the operations and IDs:" << endl;
    for (int i = 0; i < numberOfHROperations; i++){
        char operation;
        int id;
        scanf(" %c%d", &operation, &id);
        operations.push_back(operation);
        ids.push_back(id);
    }

    

}
