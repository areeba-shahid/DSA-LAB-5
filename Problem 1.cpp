#include <iostream>
#include <vector>

using namespace std;

void displayVector(const vector<string>& vec) {
    cout << "Vector contents: ";
    for (const string& str : vec) {
        cout << str << " ";
    }
    cout << endl;
    cout << "Size: " << vec.size() << endl;
    cout << "Capacity: " << vec.capacity() << endl;
    cout << "------------------------" << endl;
}

int main() {
    vector<string> vec;
    int choice;
    string input;

    do {
        cout << "Menu:\n1. Add string\n2. Remove last string\n3. Display vector\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a string to add: ";
                cin.ignore();
                getline(cin, input);
                vec.push_back(input);
                displayVector(vec);
                break;

            case 2:
                if (!vec.empty()) {
                    vec.pop_back();
                    cout << "Last string removed.\n";
                } else {
                    cout << "Vector is empty. Nothing to remove.\n";
                }
                displayVector(vec);
                break;

            case 3:
                displayVector(vec);
                break;

            case 4:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
