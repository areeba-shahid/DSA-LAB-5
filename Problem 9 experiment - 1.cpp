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
class ArrayList {
    T* arr;
    int size;
    int capacity;

public:
    ArrayList() : size(0), capacity(2) {
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
            capacity = static_cast<int>(capacity * 1.5);
            T* temp = new T[capacity];
            for (int i = 0; i < size; i++) temp[i] = arr[i];
            delete[] arr;
            arr = temp;
        }
        arr[size++] = value;
    }

    friend ostream& operator<<(ostream& out, const ArrayList& a) {
        for (int i = 0; i < a.size; i++) out << a.arr[i] << " ";
        return out;
    }

    ~ArrayList() {
        delete[] arr;
    }
};

int main() {
    CreateRandomFile("RandomFile.txt", 2);

    ifstream infile("RandomFile.txt");
    int x;
    time_t start, end;


    // ArrayList test
    ArrayList<int> arrList;
    start = time(0);
    while (infile >> x) arrList.PushBack(x);
    end = time(0);
    cout << "ArrayList time: " << end - start << " seconds" << endl;
    ofstream out3("OutputArraylist.txt");
    out3 << arrList;

    return 0;
}
