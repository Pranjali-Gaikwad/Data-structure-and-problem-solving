#include <iostream>
using namespace std;

class LinearSearch {
private:
    int size;
    int arr[100];
    int target; 

public:
    void accept();
    void display();
    void count();
    void search();
    void setTarget(); 
};

void LinearSearch::accept() {
    cout << "Enter the size of the array: ";
    cin >> size;

    if (size > 100) {
        cout << "Size exceeds the maximum limit of 100. Setting size to 100." << endl;
        size = 100;
    }

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void LinearSearch::display() {
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void LinearSearch::setTarget() {
    cout << "Enter the target value: ";
    cin >> target;
}

void LinearSearch::count() {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            count++;
        }
    }
    cout << "Target found " << count << " times." << endl;
}

void LinearSearch::search() {
    bool found = false;
    int firstOccurrence = -1;
    int lastOccurrence = -1;
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            if (firstOccurrence == -1) {
                firstOccurrence = i;
            }
            lastOccurrence = i;
            count++;
        }
    }

    if (count > 0) {
        cout << "Target found " << count << " times." << endl;
        cout << "First occurrence: " << firstOccurrence << endl;
        cout << "Last occurrence: " << lastOccurrence << endl;
    } else {
        cout << "Target not found in the array." << endl;
    }
}

int main() {
    LinearSearch ls;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Accept Array\n";
        cout << "2. Display Array\n";
        cout << "3. Set Target\n";
        cout << "4. Search for Target\n";
        cout << "5. Count Target Occurrences\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                ls.accept();
                break;
            case 2:
                ls.display();
                break;
            case 3:
                ls.setTarget();
                break;
            case 4:
                ls.search();
                break;
            case 5:
                ls.count();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 6);

    return 0;
}