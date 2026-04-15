#include <iostream>
using namespace std;

int konversiNilai(char huruf) {
    switch(huruf) {
        case 'A': return 4;
        case 'B': return 3;
        case 'C': return 2;
        case 'D': return 1;
        case 'E': return 0;
        default: return 0;
    }
}

int main() {
    int jumlahMahasiswa;
    cout << "Jumlah Mahasiswa: ";
    cin >> jumlahMahasiswa;

    for(int i = 0; i < jumlahMahasiswa; i++) {
        string nama, nim;
        int jumlahMK;

        cout << "\nNama Mahasiswa: ";
        cin.ignore();
        getline(cin, nama);

        cout << "NIM: ";
        getline(cin, nim);

        cout << "Jumlah Mata Kuliah: ";
        cin >> jumlahMK;

        string matkul[jumlahMK];
        int sks[jumlahMK];
        char nilaiHuruf[jumlahMK];
        int nilaiAngka[jumlahMK];

        int totalSKS = 0;
        float totalNilai = 0;

        for(int j = 0; j < jumlahMK; j++) {
            cout << "\nMata Kuliah ke-" << j+1 << endl;

            cout << "Nama MK: ";
            cin.ignore();
            getline(cin, matkul[j]);

            cout << "SKS: ";
            cin >> sks[j];

            cout << "Nilai Huruf (A-E): ";
            cin >> nilaiHuruf[j];

            nilaiAngka[j] = konversiNilai(nilaiHuruf[j]);

            totalSKS += sks[j];
            totalNilai += nilaiAngka[j] * sks[j];
        }

        float ipk = totalNilai / totalSKS;

        cout << "\n====================================" << endl;
        cout << "        KARTU HASIL STUDI (KHS)     " << endl;
        cout << "====================================" << endl;
        cout << "Nama  : " << nama << endl;
        cout << "NIM   : " << nim << endl;

        cout << "\nMata Kuliah:" << endl;
        cout << "No\tMK\t\tSKS\tNilai\tAngka" << endl;

        for(int j = 0; j < jumlahMK; j++) {
            cout << j+1 << "\t" << matkul[j]
                 << "\t" << sks[j]
                 << "\t" << nilaiHuruf[j]
                 << "\t" << nilaiAngka[j] << endl;
        }

        cout << "\nTotal SKS  : " << totalSKS << endl;
        cout << "IPK        : " << ipk << endl;
        cout << "====================================\n" << endl;
    }

    cin.get();
}