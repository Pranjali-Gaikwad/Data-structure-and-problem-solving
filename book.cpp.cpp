#include<iostream>
#include<string.h>
using namespace std;

int i, j, n;

class book {
    char title[10], author[10];
    int cost;

public:
    void accept();
    void display();
    void displayA();
    void displayD();
    void copyL();
    void deleteT();
    void deleteW();
    void count();
} b[100], c[100];

void book::accept() {
    cout << "Enter number of books: ";
    cin >> n;
    for (i = 0; i < n; i++) {
        cout << "Enter title, author, and cost of book: \n";
        cin >> b[i].title >> b[i].author >> b[i].cost;
    }
}

void book::display() {
    cout << "\n" << "Title" << "\t" << "Author" << "\t" << "Cost";
    for (i = 0; i < n; i++) {
        cout << "\n" << b[i].title << "\t" << b[i].author << "\t" << b[i].cost;
    }
}

void book::displayA() {
    book temp;
    cout << "\n Record in ascending order: ";
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (b[i].cost > b[j].cost) {
                temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }
    cout << "\n" << "Title" << "\t" << "Author" << "\t" << "Cost";
    for (i = 0; i < n; i++) {
        cout << "\n" << b[i].title << "\t" << b[i].author << "\t" << b[i].cost;
    }
}

void book::displayD() {
    book temp;
    cout << "\n Record in descending order: ";
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (b[i].cost < b[j].cost) {
                temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }
    cout << "\n" << "Title" << "\t" << "Author" << "\t" << "Cost";
    for (i = 0; i < n; i++) {
        cout << "\n" << b[i].title << "\t" << b[i].author << "\t" << b[i].cost;
    }
}

void book::copyL() {
    j = 0;
    for (i = 0; i < n; i++) {
        if (b[i].cost < 500) {
            c[j] = b[i];
            j++;
        }
    }
    cout << "\n Books cost less than 500: ";
    cout << "\n" << "Title" << "\t" << "Author" << "\t" << "Cost";
    for (i = 0; i < j; i++) {
        cout << "\n" << c[i].title << "\t" << c[i].author << "\t" << c[i].cost;
    }
}

void book::count() {
    int count = 0;
    for (i = 0; i < n; i++) {
        if (b[i].cost > 500) {
            count++;
        }
    }
    cout << "\nBooks having price more than 500: " << count;
}

void book::deleteT() {
    j = 0;
    c[0] = b[0];
    for (i = 0; i < n; i++) {
        if (strcmp(b[i].title, c[j].title) != 0 && (strcmp(b[i].author, c[j].author) != 0)) {
            j++;
            c[j] = b[i];
        }
    }
    cout << "\n" << "Title" << "\t" << "Author" << "\t" << "Cost";
    for (i = 0; i <= j; i++) {
        cout << "\n" << c[i].title << "\t" << c[i].author << "\t" << c[i].cost;
    }
}

void book::deleteW() {
    int k = 0;
    for (i = 0; i < n; i++) {
        if (b[i].cost <= 500) {
            c[k] = b[i];
            k++;
        }
    }
    n = k;
    cout << "\nBooks with price 500 or less:";
    cout << "\n" << "Title" << "\t" << "Author" << "\t" << "Cost";
    for (i = 0; i < n; i++) {
        cout << "\n" << c[i].title << "\t" << c[i].author << "\t" << c[i].cost;
    }
}

int main() {
    book b1;
    b1.accept();
    b1.display();
    b1.displayA();
    b1.displayD();
    b1.copyL();
    b1.deleteT();
    b1.deleteW();
    b1.count();
    return 0;
}
