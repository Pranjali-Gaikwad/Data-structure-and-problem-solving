#include<iostream>
using namespace std;

class palindrome {
    char s1[100], s2[100]; // Two strings s1 and s2
    
    public:
    void accept() {
        cout << "Enter 1st string: ";
        cin >> s1;
        cout << "Enter 2nd string: ";
        cin >> s2;
    }
    
    void length() {
        int len1 = 0, len2 = 0;
        for (int i = 0; s1[i] != '\0'; i++) {
            len1++;
        }
        cout << "Length of 1st string: " << len1 << endl;
        
        for (int i = 0; s2[i] != '\0'; i++) {
            len2++;
        }
        cout << "Length of 2nd string: " << len2 << endl;
    }
    
    void copy() {
        int i = 0;
        for (i = 0; s2[i] != '\0'; i++) {
            s1[i] = s2[i];
        }
        s1[i] = '\0';
        
        cout << "1st string after copy: " << s1 << endl;
        cout << "2nd string: " << s2 << endl;
    }
    
    void compare() {
        int flag = 0;
        int i = 0;
        for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
            if (s1[i] != s2[i]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0 && s1[i] == '\0' && s2[i] == '\0') {
            cout << "Strings are equal." << endl;
        } else {
            cout << "Strings are not equal." << endl;
        }
    }
    
    void reverse() {
        char t;
        int len = 0;
        
        // Corrected while loop condition
        while (s1[len] != '\0') {
            len++;
        }
        
        for (int i = 0; i < len / 2; i++) {
            t = s1[i];
            s1[i] = s1[len - i - 1];
            s1[len - i - 1] = t;
        }
        
        cout << "Reversed 1st string: " << s1 << endl;
    }
    
    void concatenate() {
        int i = 0, j = 0;
        while (s1[i] != '\0') {
            i++;
        }
        while (s2[j] != '\0') {
            s1[i] = s2[j];
            i++;
            j++;
        }
        s1[i] = '\0';
        cout << "Concatenated string: " << s1 << endl;
    }
    
    void pal() {
        int len = 0;
        while (s1[len] != '\0') {
            len++;
        }
        
        int flag = 1;
        for (int i = 0; i < len / 2; i++) {
            if (s1[i] != s1[len - i - 1]) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            cout << "1st String is a palindrome." << endl;
        } else {
            cout << "1st String is not a palindrome." << endl;
        }
    }
    
    void count() {
        int F[256] = {0}; // Frequency array to count character occurrences
        
        for (int i = 0; s1[i] != '\0'; i++) {
            F[(unsigned char)s1[i]]++;
        }
        
        cout << "Character count in 1st String:\n";
        for (int i = 0; i < 256; i++) {
            if (F[i] > 0) {
                cout << (char)i << ": " << F[i] << endl;
            }
        }
    }
};

int main() {
    palindrome str;
    int choice;

    do {
        cout << "\nString Operations Menu:\n";
        cout << "1. Accept Strings\n";
        cout << "2. Length of Strings\n";
        cout << "3. Copy 2nd String to 1st String\n";
        cout << "4. Compare Strings\n";
        cout << "5. Reverse 1st String\n";
        cout << "6. Concatenate Strings\n";
        cout << "7. Check Palindrome of 1st String\n";
        cout << "8. Count Character Frequencies in 1st String\n";
        cout << "9. Exit\n";
        cout << "Enter your choice (1-9): ";
        cin >> choice;

        switch (choice) {
            case 1:
                str.accept();
                break;
            case 2:
                str.length();
                break;
            case 3:
                str.copy();
                break;
            case 4:
                str.compare();
                break;
            case 5:
                str.reverse();
                break;
            case 6:
                str.concatenate();
                break;
            case 7:
                str.pal();
                break;
            case 8:
                str.count();
                break;
            case 9:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 9.\n";
                break;
        }
    } while (choice != 9);

    return 0;
}