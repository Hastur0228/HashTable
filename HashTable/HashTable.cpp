#include <iostream>
#include <iomanip>
#include "closeHashTable.h"
using namespace std;
template<class KEY, class OTHER>
void display(SET<KEY, OTHER>* p) {
    if (p != NULL) cout << p->key << ", " << p->other << endl;
    else cout << "Not found." << endl;
}
int main() {
    srand(time(NULL));
    closeHashTable<int, int> hash{};
    int counter = 0;
    int logger[10] = { 1165347578, 945882806, 1778365348, 309004890, 829727784,
                      1623545717, 1005646837, 1210087569, 1271635093, 613753107 };
    for (int i = 0; i < 10; ++i) {
        counter += hash.insert({ logger[i], logger[i] });
    }
    for (int i = 0; i < 10000; ++i) {
        int t = (rand() % 2147483647);
        counter += hash.insert({ t,t });
    }
    cout << "Average move time: " << setprecision(3) << counter / 10000.0 << endl;
    for (int i = 0; i < 10; ++i) {
        display(hash.find(logger[i]));
    }
    return 0;
}