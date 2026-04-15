#include <iostream>
#include <string>
using namespace std;

typedef struct {
    string ka_npm;
    string ka_nama_mhs;
    double ka_nilai;
} NilaiMK;

typedef struct {
    int ka_top;
    NilaiMK ka_Dat[10];
} stack;

void buatStkosong(stack *ka_S) {
    ka_S->ka_top = -1;
}

bool isKosong(stack ka_S) {
    return (ka_S.ka_top == -1);
}

bool isPenuh(stack ka_S) {
    return (ka_S.ka_top == 9);
}

void push(string ka_npm, string ka_nama_mhs, double ka_nilai, stack *ka_S) {
    if (isPenuh(*ka_S)) {
        cout << "Stack Penuh!" << endl;
    } else {
        ka_S->ka_top++;
        ka_S->ka_Dat[ka_S->ka_top].ka_npm = ka_npm;
        ka_S->ka_Dat[ka_S->ka_top].ka_nama_mhs = ka_nama_mhs;
        ka_S->ka_Dat[ka_S->ka_top].ka_nilai = ka_nilai;
    }
}

void Pop(stack *ka_S) {
    if (isKosong(*ka_S)) {
        cout << "Stack Kosong!" << endl;
    } else {
        ka_S->ka_top--;
    }
}

void CetakStack(stack ka_S) {
    if (!isKosong(ka_S)) {
        cout << endl << "=== ISI STACK ===" << endl;
        for (int ka_k = ka_S.ka_top; ka_k >= 0; ka_k--) {
            cout << "--------------------------" << endl;
            cout << "NPM   : " << ka_S.ka_Dat[ka_k].ka_npm << endl;
            cout << "Nama  : " << ka_S.ka_Dat[ka_k].ka_nama_mhs << endl;
            cout << "Nilai : " << ka_S.ka_Dat[ka_k].ka_nilai << endl;
        }
        cout << "--------------------------" << endl;
    } else {
        cout << "Stack Kosong" << endl;
    }
}

int main() {
    stack ka_S;
    buatStkosong(&ka_S);

    int ka_pilihan, ka_jumlah;
    string ka_npm, ka_nama;
    double ka_nilai;

    do {
        cout << endl << "=== MENU STACK ===" << endl;
        cout << "1. Push (Tambah Data)" << endl;
        cout << "2. Pop (Hapus Data)" << endl;
        cout << "3. Tampilkan Stack" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih: ";
        cin >> ka_pilihan;

        switch (ka_pilihan) {
        case 1:
            cout << "Berapa data mau dimasukin: ";
            cin >> ka_jumlah;

            for (int ka_k = 0; ka_k < ka_jumlah; ka_k++) {
                cout << endl << "Data ke-" << ka_k + 1 << endl;
                cout << "NPM   : ";
                cin >> ka_npm;
                cout << "Nama  : ";
                cin >> ka_nama;
                cout << "Nilai : ";
                cin >> ka_nilai;

                push(ka_npm, ka_nama, ka_nilai, &ka_S);
            }
            break;

        case 2:
            Pop(&ka_S);
            cout << "1 data di-pop!" << endl;
            break;

        case 3:
            CetakStack(ka_S);
            break;

        case 4:
            cout << "Keluar..." << endl;
            break;

        default:
            cout << "Pilihan tidak valid!" << endl;
        }

    } while (ka_pilihan != 4);

    return 0;
}