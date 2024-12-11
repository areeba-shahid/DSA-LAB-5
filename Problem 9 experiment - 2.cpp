#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

void CreateRandomFile(string fn, int Size, int RN = 100) {
    srand(time(0));
    ofstream Writer(fn);
    for (int i = 0; i < Size * 1024 * 1024; i++) {
        Writer << rand() % RN << " ";
    }
}
template <typename T>
class AutoGrowingArray {
    T* arr;
    int size;
    int capacity;

public:
    AutoGrowingArray() : size(0), capacity(1) {
        arr = new T[capacity];
    }

    T operator[](int index) const {
        return arr[index];
    }

    T& operator[](int index) {
        return arr[index];
    }

    void PushBack(T value) {
        if (size == capacity) {
            capacity++;
            T* temp = new T[capacity];
            for (int i = 0; i < size; i++) temp[i] = arr[i];
            delete[] arr;
            arr = temp;
        }
        arr[size++] = value;
    }

    friend ostream& operator<<(ostream& out, const AutoGrowingArray& a) {
        for (int i = 0; i < a.size; i++) out << a.arr[i] << " ";
        return out;
    }

    ~AutoGrowingArray() {
        delete[] arr;
    }
};

int main() {
    CreateRandomFile("RandomFile.txt", 2);

    ifstream infile("RandomFile.txt");
    int x;
    time_t start, end;

    // AutoGrowingArray test
    AutoGrowingArray<int> agArray;
    start = time(0);
    while (infile >> x) agArray.PushBack(x);
    end = time(0);
    cout << "AutoGrowingArray time: " << end - start << " seconds" << endl;
    ofstream out1("OutputGA.txt");
    out1 << agArray;

    infile.clear();
    infile.seekg(0, ios::beg);

  


    return 0;
}
