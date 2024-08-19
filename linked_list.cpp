#include<iostream>
#include<ios>
#include<iomanip>
using namespace std;

// Data Elements in the list

struct Node {
    int data;
    int count;
    struct Node* nextNode;
};

struct Node* headPointer = NULL;
struct Node* tailPointer = NULL;
struct Node* curPointer = NULL;

void printHorizontalLine() {
    cout << "---------------------------------------------------------\n";
}

// Printing the Data in the List and counting number of elements in the list

void printList(struct Node* head) {
    if (head == NULL) {
        cout << "There are no numbers in the list\n";
        return;
    }
    struct Node* t = head;
    while (t != NULL) {
        cout << t->data << " -> ";
        t = t->nextNode;
    }
    cout << "END\n";
    printHorizontalLine();
}

// Dynamically creating a new node and returning it

struct Node* createNode(int data) {
    struct Node* newNode = new Node;
    newNode->data = data;
    newNode->count = 1;
    newNode->nextNode = NULL;
    return newNode;
}

// Placing new node into the linked list in the correct position

void insertNode(int data) {

    if (tailPointer->data < data) {
        struct Node* newNode = createNode(data);
        tailPointer->nextNode = newNode;
        tailPointer = tailPointer->nextNode;
        return;
    }

    if (headPointer->data > data) {
        struct Node* newNode = createNode(data);
        newNode->nextNode = headPointer;
        headPointer = newNode;
        return;
    }

    curPointer = headPointer;
    while (curPointer != NULL) {
        if (curPointer->data == data) {
            curPointer->count += 1;
            return;
        }

        if (curPointer->nextNode->data > data) {
            struct Node* temp = createNode(data);
            temp->nextNode = curPointer->nextNode;
            curPointer->nextNode = temp;
            return;
        }

        curPointer = curPointer->nextNode;
    }

}

// Creating the List & Generating random numbers 

void initializeLinkedList(int numberOfNodes) {
    int MAX_VALUE = 100; // Adjust the range here

    if (numberOfNodes < 40) {
        cout << "The number of nodes should be at least 40" << endl;
        return;
    }

    for (int n = 1; n <= numberOfNodes; n++) {
        int data = rand() % MAX_VALUE + 1;
        if (n == 1) {
            headPointer = createNode(data);
            tailPointer = headPointer;
        }
        else {
            insertNode(data);
        }
    }
}

// Count and return number of nodes in the List 

int getNumberOfNodes() {
    int count = 0;
    struct Node* t = headPointer;
    while (t != NULL) {
        count += 1;
        t = t->nextNode;
    }
    return count;
}

// Output function 

void show() {
    int n = getNumberOfNodes();
    struct Node* t = headPointer;
    while (t != NULL) {
        for (int i = 0; i < 5; i++) {
            if (t == NULL)
                break;
            cout << setw(5) << t->data << "(" << t->count << ")";
            t = t->nextNode;
        }
        cout << endl;
    }
}

// Node with maximum frequency 

void getFrequentElement() {
    struct Node* t = headPointer;
    int maxCount = -1;
    int frequentElement = -1;
    while (t != NULL) {
        if (t->count > maxCount) {
            maxCount = t->count;
            frequentElement = t->data;
        }
        t = t->nextNode;
    }
    cout << "Most frequent element is " << frequentElement << " and the count is " << maxCount << endl;
}

// Searching for a number in the List 

void searchForNode(int data) {
    struct Node* t = headPointer;
    int count = 0;
    while (t != NULL) {
        if (t->data == data) {
            count = t->count;
            break;
        }
        t = t->nextNode;
    }
    if (count == 0) {
        cout << "Sorry, I couldn't find the Number: " << data << endl;
    }
    else {
        cout << "I found the Number: " << data << "; it occured " << count << " times" << endl;
    }
}

int main() {
    initializeLinkedList(40);
    if (headPointer != NULL) {
        int numberOfNodes = getNumberOfNodes();
        if (numberOfNodes == 0) {
            cout << "There are no numbers in the list";
        }
        else {
            cout << "Number of nodes (unique numbers) in the list = " << numberOfNodes << endl;
            cout << "Total number of elements in the list (including duplicates) = 40" << endl;
        }
        printHorizontalLine();

        show();
        printHorizontalLine();

        getFrequentElement();
        cout << "The smallest number is " << (headPointer->data) << " and its count is " << (headPointer->count) << ".\n";
        cout << "The largest number is " << (tailPointer->data) << " and its count is " << (tailPointer->count) << ".\n";
        printHorizontalLine();

        // Ask the user which numbers they want to search for in a loop
        while (true) {
            int searchNumber;
            cout << "Enter a number to search for (or -1 to quit): ";
            cin >> searchNumber;

            if (searchNumber == -1) {
                break; // Exit the loop if the user enters -1
            }

            searchForNode(searchNumber);
            printHorizontalLine();
        }

        cout << "Exiting search. Thank you!" << endl;
    }
}
