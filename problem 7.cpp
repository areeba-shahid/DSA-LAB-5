#include <iostream>
using namespace std;

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
