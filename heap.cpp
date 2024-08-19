#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

class MinHeap {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    unordered_map<int, int> frequencyMap;
    vector<int> elements;  // To store elements for sorting and printing

public:
    void insertNode(int data) {
        // Increase frequency count in the map
        frequencyMap[data]++;
        // Insert element into the heap only if it's not already there
        if (frequencyMap[data] == 1) {
            minHeap.push(data);
            elements.push_back(data);
        }
    }

    void printList() {
        if (elements.empty()) {
            cout << "There are no numbers in the list\n";
            return;
        }

        // Sort elements for consistent output
        sort(elements.begin(), elements.end());

        int count = 0;
        for (int data : elements) {
            cout << setw(5) << data << "(" << frequencyMap[data] << ")";
            count++;
            if (count % 5 == 0) {
                cout << endl;
            }
        }
        if (count % 5 != 0) {
            cout << endl; // Ensure a newline at the end if not a multiple of 5
        }
    }

    void getFrequentElement() {
        int maxCount = 0;
        int mostFrequent = -1;
        for (auto& pair : frequencyMap) {
            if (pair.second > maxCount) {
                maxCount = pair.second;
                mostFrequent = pair.first;
            }
        }
        if (mostFrequent != -1) {
            cout << "Most frequent element is " << mostFrequent << " and the count is " << maxCount << endl;
        }
    }

    void searchForNode(int data) {
        if (frequencyMap.find(data) != frequencyMap.end()) {
            cout << "I found the Number: " << data << "; it occurred " << frequencyMap[data] << " times" << endl;
        } else {
            cout << "Sorry, I couldn't find the Number: " << data << endl;
        }
    }

    int getSmallestElement() {
        return *min_element(elements.begin(), elements.end());
    }

    int getLargestElement() {
        return *max_element(elements.begin(), elements.end());
    }

    int getCountOfSmallestElement() {
        int smallest = getSmallestElement();
        return frequencyMap[smallest];
    }

    int getCountOfLargestElement() {
        int largest = getLargestElement();
        return frequencyMap[largest];
    }

    int getNumberOfNodes() {
        return elements.size();  // The number of unique nodes (unique elements)
    }
};

int main() {
    MinHeap minHeap;
    int numberOfNodes = 40;
    for (int i = 0; i < numberOfNodes; i++) {
        int data = rand() % 100 + 1;
        minHeap.insertNode(data);
    }

    int totalElements = 40;
    int uniqueNodes = minHeap.getNumberOfNodes();
    if (uniqueNodes == 0) {
        cout << "There are no numbers in the list";
    } else {
        cout << "Number of nodes (unique numbers) in the list = " << uniqueNodes << endl;
        cout << "Total number of elements in the list (including duplicates) = " << totalElements << endl;
    }
    cout << "---------------------------------------------------------" << endl;

    minHeap.printList();
    cout << "---------------------------------------------------------" << endl;

    minHeap.getFrequentElement();
    cout << "The smallest number is " << minHeap.getSmallestElement() << " and its count is " << minHeap.getCountOfSmallestElement() << ".\n";
    cout << "The largest number is " << minHeap.getLargestElement() << " and its count is " << minHeap.getCountOfLargestElement() << ".\n";
    cout << "---------------------------------------------------------" << endl;

    while (true) {
        int searchNumber;
        cout << "Enter a number to search for (or -1 to quit): ";
        cin >> searchNumber;

        if (searchNumber == -1) {
            break;
        }

        minHeap.searchForNode(searchNumber);
        cout << "---------------------------------------------------------" << endl;
    }

    cout << "Exiting search. Thank you!" << endl;
    return 0;
}
