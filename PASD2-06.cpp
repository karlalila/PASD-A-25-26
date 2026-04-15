#include <iostream>
#include <iomanip>
using namespace std;

class Pelanggan {
public:
    string ka_nama, ka_alamat, ka_telp;
    int ka_umur;
    char ka_kelamin;

    void input() {
        cin.ignore();

        cout << "Nama Pelanggan Toko      : ";
        getline(cin, ka_nama);

        cout << "Alamat Pelanggan Toko    : ";
        getline(cin, ka_alamat);

        cout << "Umur Pelanggan Toko      : ";
        cin >> ka_umur;

        cout << "Jenis Kelamin (L/P)      : ";
        cin >> ka_kelamin;

        cout << "No telp Pelanggan        : ";
        cin >> ka_telp;

        cout << endl;
    }

    void tampil() {
        cout << left
             << setw(15) << ka_nama
             << setw(20) << ka_alamat
             << setw(8)  << ka_umur
             << setw(10) << ka_kelamin
             << setw(15) << ka_telp
             << endl;
    }
};

int main() {
    int ka_jumlah;

    cout << "INPUT DATA PELANGGAN" << endl;
    cout << "Jumlah pelanggan : ";
    cin >> ka_jumlah;

    Pelanggan ka_p[ka_jumlah];

    cout << endl;
    for(int ka_i = 0; ka_i < ka_jumlah; ka_i++) {
        ka_p[ka_i].input();
    }

    cout << "============================================================" << endl;
    cout << left
         << setw(15) << "Nama"
         << setw(20) << "Alamat"
         << setw(8)  << "Umur"
         << setw(10) << "Kelamin"
         << setw(15) << "No Telp" << endl;
    cout << "============================================================" << endl;

    for(int ka_i = 0; ka_i < ka_jumlah; ka_i++) {
        ka_p[ka_i].tampil();
    }

    cout << "============================================================" << endl;

    return 0;
}