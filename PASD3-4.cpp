#include<iostream>
using namespace std;

int main(){
	string ka_nama[100];
	int ka_umur[100];
	int ka_jumlah;

	cout<<"Masukkan jumlah data: ";
	cin>>ka_jumlah;

	for(int k = 0; k < ka_jumlah; k++){
		cout<<"Nama & Umur ke-" << k+1 << endl;
		cout<<"Nama : ";
		cin>>ka_nama[k];
		cout<<"Umur : ";
		cin>>ka_umur[k];
		cout<<endl;
	}

	for(int k = 0; k < ka_jumlah; k++){
		cout<<"Nama & Umur : "
			<<ka_nama[k]<<" - "
			<<ka_umur[k]<<endl;
	}

	cout<<"===================================================="<<endl;

	
	cout<<"Nama : ";
	for(int k = 0; k < ka_jumlah; k++){
		cout<<ka_nama[k]<<" --"<<ka_umur[k]<<"   ";
	}

	cout<<endl;

	return 0;
}