#include <iostream>
using namespace std;

// Struct untuk SIM
struct SIM {
    string nama;
    string alamat;
    int tahunLahir;
    int tinggi;
    string pekerjaan;
    string nomorSIM;
    string masaBerlaku;
};

int main() {
    SIM dataSIM;

    dataSIM.nama = "Karel Abimanyu";
    dataSIM.alamat = "Pasar Tanah Tinggi";
    dataSIM.tahunLahir = 2005;
    dataSIM.tinggi = 170;
    dataSIM.pekerjaan = "Mahasiswa";
    dataSIM.nomorSIM = "1234567890";
    dataSIM.masaBerlaku = "2029";

    cout << "==================================" << endl;
    cout << "           DATA SIM               " << endl;
    cout << "==================================" << endl;
    cout << "Nama            : " << dataSIM.nama << endl;
    cout << "Alamat          : " << dataSIM.alamat << endl;
    cout << "Tahun Lahir     : " << dataSIM.tahunLahir << endl;
    cout << "Tinggi          : " << dataSIM.tinggi << " cm" << endl;
    cout << "Pekerjaan       : " << dataSIM.pekerjaan << endl;
    cout << "Nomor SIM       : " << dataSIM.nomorSIM << endl;
    cout << "Masa Berlaku    : " << dataSIM.masaBerlaku << endl;
    cout << "==================================" << endl;

    cin.get();
}