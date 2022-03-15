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

/*
设计一个支持在平均 时间复杂度 O(1) 下，执行以下操作的数据结构：
insert(val)：当元素 val 不存在时返回 true ，并向集合中插入该项，否则返回 false 。
remove(val)：当元素 val 存在时返回 true ，并从集合中移除该项，否则返回 false 。
getRandom：随机返回现有集合中的一项。每个元素应该有 相同的概率 被返回。
*/
class RandomizedSet {
  public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        size = 0;
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified
     * element. */
    bool insert(int val) {
        if (m.count(val)) {
            return false;
        } else {
            m[val] = true;
            size++;
            return true;
        }
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (m.count(val)) {
            m.erase(m.find(val));
            size--;
            return true;
        } else {
            return false;
        }
    }

    /** Get a random element from the set. */
    int getRandom() {
        int n = rand() % size;
        auto it = m.begin();
        for (int i = 0; i < n; i++) {
            it++;
        }
        return it->first;
    }

  private:
    map<int, bool> m;
    int size;
};