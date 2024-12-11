#include <iostream>
using namespace std;

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
