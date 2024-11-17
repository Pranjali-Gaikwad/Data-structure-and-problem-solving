#include <iostream>
#include <string>
using namespace std;

int f = -1, r = -1, n = 5;

class Pizza {
public:
    string name, add;
    int q; 
    Pizza queue[100]; 

    void acceptOrder();
    void serveOrder();
    void displayOrder();
    void peak();
};

void Pizza::acceptOrder() {
    if ((f == r + 1) || (f == 0 && r == n - 1)) {
        cout << "Orders are full. Please wait for a while." << endl;
    } else if (f == -1 && r == -1) {
        f = r = 0;
        cout << "Enter your name: ";
        cin >> queue[r].name;
        cout << "Enter your address: ";
        cin >> queue[r].add;
        cout << "Enter your quantity of order: ";
        cin >> queue[r].q;
        r = (r + 1) % n;
    } else {
        r = (r + 1) % n;
        cout << "Enter your name: ";
        cin >> queue[r].name;
        cout << "Enter your address: ";
        cin >> queue[r].add;
        cout << "Enter your quantity of order: ";
        cin >> queue[r].q;
    }
}

void Pizza::serveOrder() {
    if (f == -1 && r == -1) {
        cout << "No orders to serve." << endl;
    } else if (f == r) {
        cout << "Serving order from: " << queue[f].name << endl;
        f = r = -1;  
    } else {
        cout << "Serving order from: " << queue[f].name << endl;
        f = (f + 1) % n;
    }
}

void Pizza::displayOrder() {
    if (f == -1) {
        cout << "No orders to display." << endl;
        return;
    }
    cout << "Current Orders:" << endl;
    for (int i = f; i != r; i = (i + 1) % n) {
        cout << "Name: " << queue[i].name << ", Address: " << queue[i].add << ", Quantity: " << queue[i].q << endl;
    }
   
    cout << "Name: " << queue[r].name << ", Address: " << queue[r].add << ", Quantity: " << queue[r].q << endl;
}

int main() {
    Pizza p;
    int choice;

    do {
        cout << "\n1. Accept Order\n2. Serve Order\n3. Display Orders\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                p.acceptOrder();
                break;
            case 2:
                p.serveOrder();
                break;
            case 3:
                p.displayOrder();
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}