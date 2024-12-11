#include <iostream>
#include <vector>

using namespace std;

void displayMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

void transposeMatrix(vector<vector<int>>& matrix) {
    vector<vector<int>> transposed(matrix[0].size(), vector<int>(matrix.size()));
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }
    matrix = transposed;
}

int main() {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // add a row
    matrix.push_back({10, 11, 12});
    cout << "Matrix after adding a row:\n";
    displayMatrix(matrix);

    // add a column
    for (auto& row : matrix) {
        row.push_back(row.size() + 1); // just adding some value for example
    }
    cout << "Matrix after adding a column:\n";
    displayMatrix(matrix);

    // transpose matrix
    transposeMatrix(matrix);
    cout << "Matrix after transpose:\n";
    displayMatrix(matrix);

    return 0;
}
