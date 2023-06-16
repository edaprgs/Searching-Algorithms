/* Nancy M. Sayson 2021-0622
Eda Grace J. Paragoso 2021-1574 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Table/Array Size
const int N = 17;

// Hash Function
int h(int k) {
    return k % N;
}

int d(int k) {
    return 13 - k % 13;
}

int main() {
    vector<int> keys = {25, 88, 3, 38, 20, 71, 55, 56, 50, 105};

    // Linear Probing
    cout << "(a) h(k) = k mod 17, with linear probing" << endl;
    vector<int> table(N, -1);
    int probes = 0;
    for (int key : keys) { //range-based to iterate over the elements of the keys
        int index = h(key);
        while (table[index] != -1) {
            index = (index + 1) % N;
            probes++;
    }
    table[index] = key;

    }
    for (int i = 0; i < N; i++) {
        cout << table[i] << " ";
    }
    cout << endl;
    cout << "Probes: " << probes << endl;
    cout << endl;

    // Quadratic Probing
    cout << "(b) h(k) = k mod 17, with quadratic probing" << endl;
    table.assign(N, -1);
    probes = 0;
    for (int key : keys) {
        int index = h(key);
        int j = 1;
        while (table[index] != -1) {
            index = (index + j * j) % N;
            probes++;
            j++;
        }
    table[index] = key;
    }
    for (int i = 0; i < N; i++) {
        cout << table[i] << " ";
    }
    cout << endl;
    cout << "Probes: " << probes << endl;
    cout << endl;

    // Double Hashing
    cout << "(c) double hashing, with primary hash function h(k) = k mod 17, and secondary hash function d(k) = 13 - k mod 13." << endl;
    table.assign(N, -1);
    probes = 0;
    for (int key : keys) {
        int index = h(key);
        while (table[index] != -1) {
            index = (index + d(key)) % N;
            probes++;
        }
        table[index] = key;
    }

    for (int i = 0; i < N; i++) {
        cout << table[i] << " ";
    }
    cout << endl;
    cout << "Probes: " << probes << endl;

    return 0;
}
