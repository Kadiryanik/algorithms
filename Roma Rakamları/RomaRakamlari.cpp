#include <iostream>
#include <math.h>
#include <string>

using namespace std;

char romas[] = "IVXLCDM";
int romas_i[] = { 1, 5, 10, 50, 100, 500, 1000 };

void R_A();
void A_R();
int _MCXI(string, char);//karakter nerden baslar
int _MCXI_sonu(string, int, char);//sonundan baslangici cikaririp geriye kac tane oldugunu dondurur
int _indis(char);
void RplusR();
void RminusR();


int main()
{
	int x = 0;
	while (x != -1){
		cout << "1) R to A" << endl << "2) A to R " << endl << "3) R + R" << endl << "4) R - R" << endl;
		cin >> x;
		switch (x)
		{
		case 1:
			R_A();
			break;
		case 2:
			A_R();
			break;
		case 3:
			break;
		case 4:
			break;
		default:
			break;
		}

		system("cls");
	}
	

	system("pause");
	return 0;
}


int _indis(char c){
	for (int i = 0; i < 7; i++){
		if (romas[i] == c){
			return i;
		}
	}
	return -1;
}
//M C X I nerde basladigini dondurur
int _MCXI(string s, char c){
	for (int i = 0; i < s.length(); i++){
		if (c == s[i]){
			return i;
		}
	}
	return -1;
}
int _MCXI_sonu(string s, int b, char c){
	int sayac = 0;
	for (int i = b; i < s.length(); i++){
		if (c != s[i]){
			break;
		}
		sayac++;
	}
	return sayac;
}
void R_A(){
	system("cls");
	
	string giris;
	int toplam = 0;
	bool giris_basarisiz = 1;

	while (giris_basarisiz){
		cout << "Roma rakami giriniz : ";
		giris = "";
		cin >> giris;
		
		giris_basarisiz = 0;

		for (int i = 0; i < giris.length(); i++){
			if (giris[i] == giris[i + 1]){
				if (_indis(giris[i]) ==  1 || _indis(giris[i]) == 3 || _indis(giris[i]) == 5){ // VLD 135
					cout << "Hatali giris V L D tekrarlanamaz." << endl;
					giris_basarisiz = 1;
					break;
				}
			}
			if ((i < giris.length() - 3) && (giris[i] == giris[i + 1]) && (giris[i + 2] == giris[i + 3]) && (giris[i + 2] == giris[i + 1])){
				cout << "Hatali giris 3ten fazla tekrar." << endl;
				giris_basarisiz = 1;
				break;
			}
			if (_indis(giris[i]) == -1){
				cout << "I-V-X-L-C-D-M haric harf girmeyiniz." << endl;
				giris_basarisiz = 1;
				break;
			}
		}
	}

	for (int i = 0; i < giris.length(); i++){
		if (_indis(giris[i]) >= _indis(giris[i + 1])){//romas dizisinde karakter sira kontrolu 
			toplam = toplam + romas_i[_indis(giris[i])];
		}
		else{
			toplam = toplam - romas_i[_indis(giris[i])];
		}
	}

	cout << toplam << endl;


	system("pause");
	return;
}
void A_R(){
	system("cls");

	string sonuc = "";
	int sayi;
	cout << "Sayi giriniz : ";
	cin >> sayi;
	while (sayi > 3999){
		cout << "3999 dan kucuk sayi giriniz : ";
		cin >> sayi;
	}
	
	int indis = 0;
	//Sirali olarak yazma
	while (sayi > 0){
		for (int i = 0; i < (sayi % 10); i++){
			sonuc = romas[indis] + sonuc;
		}

		indis = indis + 2;
		sayi = sayi / 10;
	}
	//Birlestirme
	indis = indis - 2;
	string birlesmis = "";
	while (indis >= 0){		//M 						//C
		//cout << "-" << _MCXI_sonu(sonuc, _MCXI(sonuc, romas[indis]), romas[indis]) << "-" <<indis << "-" << endl; // hangisinden kac tane var dogrulama
		if (_MCXI_sonu(sonuc,_MCXI(sonuc, romas[indis]), romas[indis]) == 9){// kac tane tekrar var _MCXI_sonu onu hesaplar
			birlesmis = birlesmis + romas[indis] + romas[indis + 2];
		}
		else if (_MCXI_sonu(sonuc, _MCXI(sonuc, romas[indis]), romas[indis]) >= 5){
			birlesmis = birlesmis + romas[indis + 1];
			for (int i = 0; i < _MCXI_sonu(sonuc, _MCXI(sonuc, romas[indis]), romas[indis])-5; i++){
				birlesmis = birlesmis + romas[indis];
			}
		}
		else if (_MCXI_sonu(sonuc, _MCXI(sonuc, romas[indis]), romas[indis]) >= 4){
			birlesmis = birlesmis + romas[indis] + romas[indis + 1];
			for (int i = 0; i < _MCXI_sonu(sonuc, _MCXI(sonuc, romas[indis]), romas[indis])-4; i++){
				birlesmis = birlesmis + romas[indis];
			}
		}
		else{
			for (int i = 0; i < _MCXI_sonu(sonuc, _MCXI(sonuc, romas[indis]), romas[indis]); i++){
				birlesmis = birlesmis + romas[indis];
			}
		}
		indis = indis - 2;
	}

	//cout << sonuc << endl;
	cout << birlesmis << endl;

	system("pause");
	return;
}
void RplusR(){

}
void RminusR(){

}
