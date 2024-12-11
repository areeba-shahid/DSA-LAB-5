#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> vec = {5, 2, 9, 1, 5, 6, 3, 2, 6};

    // reverse elements
    reverse(vec.begin(), vec.end());
    cout << "Reversed: ";
    for (int i : vec) cout << i << " ";
    cout << endl;

    // sort in ascending order
    sort(vec.begin(), vec.end());
    cout << "Sorted: ";
    for (int i : vec) cout << i << " ";
    cout << endl;

    // remove duplicates
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    cout << "Without duplicates: ";
    for (int i : vec) cout << i << " ";
    cout << endl;

    return 0;
}
