#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target;
    
    cout << "Enter an integer to search: ";
    cin >> target;

    bool found = false;
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] == target) {
            cout << "Found at index: " << i << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Integer not found" << endl;
    }

    return 0;
}
