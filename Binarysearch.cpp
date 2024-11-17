#include <iostream>
using namespace std;

int n, i,r;

class training
{
public:
    int rollno;
    string name, address;
    int feedbackScore[5];

public:
    void accept();
    void display();
    void linearsearch();
    void binarysearch();
    void feedback();
    int calculateFeedbackScore();
} a[100];

void training::accept()
{
    cout << "Enter the roll no: ";
    cin >> rollno;
    cout << "Enter the name: ";
    cin >> name;
    cout << "Enter the address: ";
    cin >> address;
}

void training::display()
{
    cout << "\n"
         << name << "\t" << rollno << "\t" << address << "\n";
}

void training::linearsearch()
{
    int flag = 0;
    cout << "Enter the roll no which you want to search: ";
    cin >> r;
    for (int i = 0; i < n; i++)
    {
        if (a[i].rollno == r)
        {
            cout << "Roll no " << r << " was present for the training program.\n";
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        cout << "Roll no " << r << " was not present for the training.\n";
    }
}

void training::binarysearch()
{
    training t;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j].rollno > a[j + 1].rollno)
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }

    int flag = 0;
    cout << "Enter the roll no which you want to search: ";
    cin >> r;
    int low = 0, high = n - 1;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid].rollno == r)
        {
            cout << "Roll no " << r << " was present for the program.\n";
            flag = 1;
            break;
        }
        else if (a[mid].rollno > r)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    if (flag == 0)
    {
        cout << "Roll no " << r << " was not present for the training.\n";
    }
}

void training::feedback()
{
    cout << "Fill the feedback form for (Enter 1 for Yes, 0 for No):\n";
    cout << "1. Did you enjoy the session? ";
    cin >> feedbackScore[0];
    cout << "2. Are you satisfied with this training? ";
    cin >> feedbackScore[1];
    cout << "3. Was it helpful? ";
    cin >> feedbackScore[2];
    cout << "4. Do you want this session again? ";
    cin >> feedbackScore[3];
    cout << "5. Did the trainer explain all the points clearly? ";
    cin >> feedbackScore[4];
}

int training::calculateFeedbackScore()
{
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += feedbackScore[i];
    }
    return sum;
}

int main()
{
    int ch, i;
    cout << "How many records do you want to insert? ";
    cin >> n;

    int totalFeedbackScore = 0;
    int averageFeedback = 0;

    do
    {
        cout << "\n1. Accept\n2. Display\n3. Linear Search\n4. Binary Search\n5. Feedback\n6. End\n";
        cout << "What do you want to do? ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            for (int i = 0; i < n; i++)
                a[i].accept();
            break;
        case 2:
            cout << "\nName\tRoll No\tAddress\n";
            for (int i = 0; i < n; i++)
                a[i].display();
            break;
        case 3:
            a[0].linearsearch();
            break;
        case 4:
            a[0].binarysearch();
            break;
        case 5:
            totalFeedbackScore = 0;
            for (int i = 0; i < n; i++)
            {
                a[i].feedback();
                totalFeedbackScore += a[i].calculateFeedbackScore();
            }
            averageFeedback = (totalFeedbackScore * 100) / (n * 5);
            if (averageFeedback > 80)
            {
                cout << "The training was good.\n";
            }
            else
            {
                cout << "The training needs improvement.\n";
            }
            break;
        case 6:
            cout << "End\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (ch != 6);

    return 0;
}