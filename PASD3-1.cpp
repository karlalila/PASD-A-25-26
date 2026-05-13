#include<iostream>
using namespace std;

typedef struct{
	string ka_npm;
	string ka_nama_mhs;
	double ka_nilai;
} NilaiMK;

typedef struct elm *alamatelm;
typedef struct elm{
	NilaiMK ka_Kontainer;
	alamatelm ka_next;
} elemen;

typedef struct{
	elemen* ka_top;
} stack;

void buatSTkosong(stack *ka_S){
	(*ka_S).ka_top = NULL;
}

int isKosong(stack ka_S){
	return (ka_S.ka_top == NULL);
}

int jmlElemen(stack ka_S){
	int ka_hasil = 0;
	elemen *ka_bantu = ka_S.ka_top;
	while(ka_bantu != NULL){
		ka_hasil++;
		ka_bantu = ka_bantu->ka_next;
	}
	return ka_hasil;
}

void push(string ka_npm, string ka_nama_mhs, double ka_nilai, stack *ka_S){
	elemen *ka_info = new elemen;
	ka_info->ka_Kontainer.ka_npm = ka_npm;
	ka_info->ka_Kontainer.ka_nama_mhs = ka_nama_mhs;
	ka_info->ka_Kontainer.ka_nilai = ka_nilai;

	ka_info->ka_next = (*ka_S).ka_top;
	(*ka_S).ka_top = ka_info;
}

void Pop(stack *ka_S){
	if((*ka_S).ka_top != NULL){
		elemen *ka_hapus = (*ka_S).ka_top;
		(*ka_S).ka_top = (*ka_S).ka_top->ka_next;
		delete ka_hapus;
	} else {
		cout<<"Stack kosong!"<<endl;
	}
}

void CetakStack(stack ka_S){
	if(ka_S.ka_top != NULL){
		cout<<"Menampilkan Stack"<<endl;
		elemen *ka_bantu = ka_S.ka_top;
		int ka_k = 1;
		while(ka_bantu != NULL){
			cout<<"===================================="<<endl;
			cout<<"Elemen ke            : "<<ka_k<<endl;
			cout<<"NPM                  : "<<ka_bantu->ka_Kontainer.ka_npm<<endl;
			cout<<"Nama Mahasiswa       : "<<ka_bantu->ka_Kontainer.ka_nama_mhs<<endl;
			cout<<"Nilai                : "<<ka_bantu->ka_Kontainer.ka_nilai<<endl;
			ka_bantu = ka_bantu->ka_next;
			ka_k++;
		}
		cout<<"===================================="<<endl;
	} else {
		cout<<"Stack Kosong!"<<endl;
	}
}

int main(){
	stack ka_S;
	buatSTkosong(&ka_S);

	int ka_a;
	cout<<"Masukkan jumlah data: ";
	cin>>ka_a;

	for(int ka_k = 0; ka_k < ka_a; ka_k++){
		string ka_npm, ka_nama;
		double ka_nilai;

		cout<<endl<<"Data ke-" << ka_k+1 << endl;
		cout<<"NPM   : ";
		cin>>ka_npm;
		cout<<"Nama  : ";
		cin.ignore();
		getline(cin, ka_nama);
		cout<<"Nilai : ";
		cin>>ka_nilai;

		push(ka_npm, ka_nama, ka_nilai, &ka_S);
	}

	cout<<endl<<"=== Isi Stack ==="<<endl;
	CetakStack(ka_S);

	cout<<endl<<"=== Pop 1x ==="<<endl;
	Pop(&ka_S);
	CetakStack(ka_S);

	cout<<endl<<"=== Pop 1x lagi ==="<<endl;
	Pop(&ka_S);
	CetakStack(ka_S);

	return 0;
}