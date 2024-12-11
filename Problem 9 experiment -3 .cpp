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
class Vector {
    T* arr;
    int size;
    int capacity;

public:
    Vector() : size(0), capacity(1) {
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
            capacity *= 2;
            T* temp = new T[capacity];
            for (int i = 0; i < size; i++) temp[i] = arr[i];
            delete[] arr;
            arr = temp;
        }
        arr[size++] = value;
    }

    friend ostream& operator<<(ostream& out, const Vector& v) {
        for (int i = 0; i < v.size; i++) out << v.arr[i] << " ";
        return out;
    }

    ~Vector() {
        delete[] arr;
    }
};

int main() {
    CreateRandomFile("RandomFile.txt", 2);

    ifstream infile("RandomFile.txt");
    int x;
    time_t start, end;

  

    // Vector test
    Vector<int> vec;
    start = time(0);
    while (infile >> x) vec.PushBack(x);
    end = time(0);
    cout << "Vector time: " << end - start << " seconds" << endl;
    ofstream out2("OutputVector.txt");
    out2 << vec;

    infile.clear();
    infile.seekg(0, ios::beg);

   

    return 0;
}
