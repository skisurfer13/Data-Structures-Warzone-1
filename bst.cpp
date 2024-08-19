#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

struct TreeNode {
    int data;
    int count;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), count(1), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

    void inOrderTraversal(TreeNode* node, int& count) {
        if (node == nullptr) return;
        inOrderTraversal(node->left, count);
        
        // Print 5 numbers per line with indentation
        cout << setw(5) << node->data << "(" << node->count << ")";
        count++;
        if (count % 5 == 0) {
            cout << endl;
        }
        
        inOrderTraversal(node->right, count);
    }

    void insert(TreeNode*& node, int data) {
        if (node == nullptr) {
            node = new TreeNode(data);
            return;
        }
        if (data == node->data) {
            node->count++;
        } else if (data < node->data) {
            insert(node->left, data);
        } else {
            insert(node->right, data);
        }
    }

    int getMostFrequentElement(TreeNode* node, int &maxCount) {
        if (node == nullptr) return -1;
        int left = getMostFrequentElement(node->left, maxCount);
        if (node->count > maxCount) {
            maxCount = node->count;
        }
        int right = getMostFrequentElement(node->right, maxCount);
        return (node->count == maxCount) ? node->data : (left > right ? left : right);
    }

    TreeNode* search(TreeNode* node, int data) {
        if (node == nullptr || node->data == data) return node;
        if (data < node->data) return search(node->left, data);
        return search(node->right, data);
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insertNode(int data) {
        insert(root, data);
    }

    void printList() {
        if (root == nullptr) {
            cout << "There are no numbers in the list\n";
            return;
        }
        int count = 0;
        inOrderTraversal(root, count);
        if (count % 5 != 0) {
            cout << endl; // Ensure a newline at the end if not a multiple of 5
        }
    }

    void getFrequentElement() {
        int maxCount = 0;
        int mostFrequent = getMostFrequentElement(root, maxCount);
        if (mostFrequent != -1) {
            cout << "Most frequent element is " << mostFrequent << " and the count is " << maxCount << endl;
        }
    }

    void searchForNode(int data) {
        TreeNode* result = search(root, data);
        if (result != nullptr) {
            cout << "I found the Number: " << data << "; it occurred " << result->count << " times" << endl;
        } else {
            cout << "Sorry, I couldn't find the Number: " << data << endl;
        }
    }

    int getSmallestElement() {
        TreeNode* node = root;
        while (node && node->left != nullptr) {
            node = node->left;
        }
        return node->data;
    }

    int getLargestElement() {
        TreeNode* node = root;
        while (node && node->right != nullptr) {
            node = node->right;
        }
        return node->data;
    }

    int getCountOfSmallestElement() {
        TreeNode* node = root;
        while (node && node->left != nullptr) {
            node = node->left;
        }
        return node->count;
    }

    int getCountOfLargestElement() {
        TreeNode* node = root;
        while (node && node->right != nullptr) {
            node = node->right;
        }
        return node->count;
    }

    int getNumberOfNodes() {
        return getNumberOfNodes(root);
    }

private:
    int getNumberOfNodes(TreeNode* node) {
        if (node == nullptr) return 0;
        return 1 + getNumberOfNodes(node->left) + getNumberOfNodes(node->right);
    }
};

int main() {
    BinarySearchTree bst;
    int numberOfNodes = 40;
    for (int i = 0; i < numberOfNodes; i++) {
        int data = rand() % 100 + 1;
        bst.insertNode(data);
    }

    int totalElements = 40;
    int uniqueNodes = bst.getNumberOfNodes();
    if (uniqueNodes == 0) {
        cout << "There are no numbers in the list";
    } else {
        cout << "Number of nodes (unique numbers) in the list = " << uniqueNodes << endl;
        cout << "Total number of elements in the list (including duplicates) = " << totalElements << endl;
    }
    cout << "---------------------------------------------------------" << endl;

    bst.printList();
    cout << "---------------------------------------------------------" << endl;

    bst.getFrequentElement();
    cout << "The smallest number is " << bst.getSmallestElement() << " and its count is " << bst.getCountOfSmallestElement() << ".\n";
    cout << "The largest number is " << bst.getLargestElement() << " and its count is " << bst.getCountOfLargestElement() << ".\n";
    cout << "---------------------------------------------------------" << endl;

    while (true) {
        int searchNumber;
        cout << "Enter a number to search for (or -1 to quit): ";
        cin >> searchNumber;

        if (searchNumber == -1) {
            break;
        }

        bst.searchForNode(searchNumber);
        cout << "---------------------------------------------------------" << endl;
    }

    cout << "Exiting search. Thank you!" << endl;
    return 0;
}
