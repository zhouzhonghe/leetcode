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
运用所掌握的数据结构，设计和实现一个  LRU (Least Recently Used，最近最少使用) 缓存机制 。
实现 LRUCache 类：
LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字已经存在，则变更其数据值；如果关键字不存在，
则插入该组「关键字-值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，
从而为新的数据值留出空间。
*/
class LRUCache {
    class Node { //双向链表
      public:
        int val;
        int key;
        Node *prev;
        Node *next;
    };

  public:
    LRUCache(int capacity) {
        head = new Node(); //头尾结点
        tail = new Node();
        head->next = tail;
        tail->prev = head;
        cap = capacity;
        size = 0;
    }

    int get(int key) {
        if (m.count(key)) {
            Node *tmp = m[key];
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            tmp->next = head->next;
            head->next->prev = tmp;
            head->next = tmp;
            tmp->prev = head;
            return tmp->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (m.count(key)) {
            Node *tmp = m[key];
            tmp->val = value;
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            tmp->next = head->next;
            head->next->prev = tmp;
            head->next = tmp;
            tmp->prev = head;
        } else {
            if (size == cap) {
                m.erase(tail->prev->key);
                size--;
                tail->prev->prev->next = tail;
                tail->prev = tail->prev->prev;
            }
            Node *tmp = new Node();
            m[key] = tmp;
            tmp->val = value;
            tmp->key = key;
            tmp->next = head->next;
            head->next->prev = tmp;
            head->next = tmp;
            tmp->prev = head;
            size++;
        }
    }

  private:
    unordered_map<int, Node *> m;
    Node *head, *tail; //*****
    int cap;
    int size;
};