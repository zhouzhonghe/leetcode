#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
using namespace std;
void Swap1(int a, int b);

class Person {
  public:
    Person() {}
    Person(int age) {
        this->age = age;
        this->age2 = &this->age;
    }
    // Person(const Person &p2) {}

    int age;
    int *age2;
};

int &back() {
    static int a = 10;
    return a;
}

int main() {
    int i = 35;
    double x = i / 36.0;
    if (x < 1) {
        cout << x << endl;
    }
    int y = 372 * 3 / 13.2;
    cout << y << endl;
}

void Swap1(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}
