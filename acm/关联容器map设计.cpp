#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

int main() {
    int size;
    cin >> size;
    unordered_map<string, list<pair<string, unsigned int>>::iterator> mp;
    list<pair<string, unsigned int>> l;
    string key;
    unsigned int val;
    while (cin >> key >> val) {
        if (mp.count(key) == 0) {
            if (mp.size() == size) {
                cout << l.back().first << " " << l.back().second << "\n";
                mp.erase(l.back().first);
                l.pop_back();
            }
            l.push_front({key, val});
            mp[key] = l.begin();
        } else {
            if (mp[key]->second < val) {
                mp[key]->second = val;
                l.erase(mp[key]);
                l.push_front({key, val});
                mp[key] = l.begin();
            }
        }
    }
    return 0;
}