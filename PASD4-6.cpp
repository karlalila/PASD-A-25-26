#include <iostream>
#include <string>
using namespace std;

#define ka_MAX 20

string ka_antrian[ka_MAX];
int ka_first = -1;
int ka_last  = -1;

bool isEmpty() {
    return ka_first == -1;
}

bool isFull() {
    return ka_last == ka_MAX - 1;
}

void enqueue(string ka_data) {
    if (isFull()) {
        cout << "  [!] Queue penuh!" << endl;
        return;
    }
    if (isEmpty()) ka_first = 0;
    ka_antrian[++ka_last] = ka_data;
}

bool hapusElemen(string ka_data) {
    if (isEmpty()) {
        cout << "  [!] Queue kosong!" << endl;
        return false;
    }

    for (int k = ka_first; k <= ka_last; k++) {
        if (ka_antrian[k] == ka_data) {
            for (int l = k; l < ka_last; l++) {
                ka_antrian[l] = ka_antrian[l + 1];
            }
            ka_last--;

            if (ka_last < ka_first)
                ka_first = ka_last = -1;

            return true;
        }
    }
    return false;
}

bool sisipSetelah(string ka_target, string ka_dataBaru) {
    if (isEmpty()) return false;

    for (int k = ka_first; k <= ka_last; k++) {
        if (ka_antrian[k] == ka_target) {
            for (int l = ka_last; l > k; l--) {
                ka_antrian[l + 1] = ka_antrian[l];
            }
            ka_antrian[k + 1] = ka_dataBaru;
            ka_last++;
            return true;
        }
    }
    return false;
}

void tampilQueue() {
    if (isEmpty()) {
        cout << "   Queue: [kosong]" << endl;
        return;
    }

    cout << "   Queue: ";
    for (int k = ka_first; k <= ka_last; k++) {
        cout << "[" << ka_antrian[k] << "]";
        if (k < ka_last) cout << " -> ";
    }
    cout << endl;
}

void resetQueue() {
    ka_first = -1;
    ka_last  = -1;

    enqueue("Maemo");
    enqueue("Symbian");
    enqueue("Mac");
    enqueue("Windows");
    enqueue("Iphone");
}

int main() {
    cout << "============================================" << endl;
    cout << "     PROGRAM QUEUE OS - PASD4-6             " << endl;
    cout << "============================================" << endl;

    cout << "[0] Queue Awal" << endl;
    resetQueue();
    tampilQueue();

    cout << "[a] Tambah 'Maemo 4', Hapus 'Mac'" << endl;
    resetQueue();
    enqueue("Maemo 4");
    hapusElemen("Mac");
    tampilQueue();

    cout << "[b] Tambah 'Windows Mobile' setelah 'Windows', Hapus 'Iphone'" << endl;
    resetQueue();
    sisipSetelah("Windows", "Windows Mobile");
    hapusElemen("Iphone");
    tampilQueue();

    cout << "[c] Tambah 'Java Midlet' setelah 'Symbian', Hapus 'Maemo'" << endl;
    resetQueue();
    sisipSetelah("Symbian", "Java Midlet");
    hapusElemen("Maemo");
    tampilQueue();

    cout << "[d] Tambah 'Lion OS X' setelah 'Mac', Hapus 'Maemo'" << endl;
    resetQueue();
    sisipSetelah("Mac", "Lion OS X");
    hapusElemen("Maemo");
    tampilQueue();

    cout << "[e] Tambah 'Android' setelah 'Iphone', Hapus 'Maemo'" << endl;
    resetQueue();
    sisipSetelah("Iphone", "Android");
    hapusElemen("Maemo");
    tampilQueue();

    cout << "============================================" << endl;
    cout << "                 SELESAI                    " << endl;
    cout << "============================================" << endl;

    return 0;
}