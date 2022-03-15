#include <cmath>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <stack>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
void Swap1(int a, int b);

class animal {
  public:
    animal() {}
    animal(int age) {
        this->age = age;
    }
    virtual void func() = 0;
    virtual void speak() = 0;
    virtual void run() = 0;

    int age;
};

class cat : public animal {
    void speak() {
        cout << "cat" << endl;
    }
    void run() {
        cout << "cat run" << endl;
    }
    void func() {
        age = 10;
    }
};

class catA : public cat {
  public:
};

struct person {
    char name[20];
    int age;
    float high;
};

unsigned int f(unsigned int n) {
    if (n == 0 | n == 1) {
        return 1;
    }

    return f(n - 1) + f(n - 2);
}

int main(void) {

    return 0;
}