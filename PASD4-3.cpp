#include<iostream>
#include<string>
using namespace std;

typedef struct{
	string ka_npm;
	string ka_nama_mhs;
	double ka_nilai;
} NilaiMK;

typedef struct{
	int ka_first;
	int ka_last;
	NilaiMK ka_Dat[10];
} queue;

void buatQUkosong(queue *Q){
	(*Q).ka_first = -1;
	(*Q).ka_last = -1;
}
	
bool isKosong(queue Q){
	bool ka_hasil = false;
	if(Q.ka_first == -1){
		ka_hasil = true;
	}
	return ka_hasil;
}
	
bool isPenuh(queue Q){
	bool ka_hasil = false;
	if(Q.ka_last == 9){
		ka_hasil = true;
	}
	return ka_hasil;
}
	
void ADD(string ka_npm, string ka_nama_mhs, double ka_nilai, queue *Q){
	if(isKosong(*Q) == 1){
		(*Q).ka_first = 0;
		(*Q).ka_last = 0;
		(*Q).ka_Dat[0].ka_npm = ka_npm;
		(*Q).ka_Dat[0].ka_nama_mhs = ka_nama_mhs;
		(*Q).ka_Dat[0].ka_nilai = ka_nilai;
	}
	else{
		if(isPenuh(*Q) != 1){
			(*Q).ka_last = (*Q).ka_last + 1;
			(*Q).ka_Dat[(*Q).ka_last].ka_npm = ka_npm;
			(*Q).ka_Dat[(*Q).ka_last].ka_nama_mhs = ka_nama_mhs;
			(*Q).ka_Dat[(*Q).ka_last].ka_nilai = ka_nilai;
		}
		else{
			cout << "QUEUE PENUH" << endl;
		}
	}
}
			
void DEL(queue *Q){
	if((*Q).ka_last == 0){
		(*Q).ka_first = -1;
		(*Q).ka_last = -1;
	}
	else{
		int k;
		for(k = ((*Q).ka_first + 1); k <= (*Q).ka_last; k++){
			(*Q).ka_Dat[k-1].ka_npm = (*Q).ka_Dat[k].ka_npm;
			(*Q).ka_Dat[k-1].ka_nama_mhs = (*Q).ka_Dat[k].ka_nama_mhs;
			(*Q).ka_Dat[k-1].ka_nilai = (*Q).ka_Dat[k].ka_nilai;
		}
		(*Q).ka_last = (*Q).ka_last - 1;
	}
}
		
void CetakQueue(queue Q){
	if(Q.ka_first != -1){
		cout << "Menampilkan Queue" << endl;
		cout << "~~~~~~~~~~~~~~~~~" << endl;
		int k;
		for (k = Q.ka_last; k >= Q.ka_first; k--){
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "Elemen ke             : " << k << endl;
			cout << "Nomor Pokok Mahasiswa : " << Q.ka_Dat[k].ka_npm << endl;
			cout << "Nama Mahasiswa        : " << Q.ka_Dat[k].ka_nama_mhs << endl;
			cout << "Nilai Mahasiswa       : " << Q.ka_Dat[k].ka_nilai << endl;
		}
	}
	else{
		cout << "Queue Kosong" << endl;
	}
}

int main(){
	queue Q;
	buatQUkosong(&Q);

	CetakQueue(Q);
	cout << endl;
	cout << endl;

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	ADD("4523210031","Karel",96.69,&Q);
	ADD("4523210033","Kevin",69.96,&Q);
	ADD("4523210035","Adam",66.99,&Q);
	ADD("4523210919","Daffa",98.95,&Q);
	ADD("4523210022","Domi",99.95,&Q);
	ADD("4523210002","Ian",89.59,&Q);
	ADD("4523210003","Dita",93.10,&Q);

	CetakQueue(Q);

	cout << "========================================" << endl;
	cout << endl;
	cout << endl;

	DEL(&Q);
	CetakQueue(Q);

	cout << endl;
	cout << endl;

	DEL(&Q);
	CetakQueue(Q);

	cout << "========================================" << endl;

	return 0;
}