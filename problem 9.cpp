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
