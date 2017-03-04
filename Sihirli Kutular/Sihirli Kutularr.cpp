#include <iostream>
#include <iomanip>

using namespace std;

int Size;
int** _array;

void Tek(int , int );
void Cift_Tek();
void Cift_Cift();
void swap(int, int, int, int);

int main()
{
	cout << "Kare matrisin satir veya sutun sayisini giriniz : ";
	cin >> Size;

	_array = new int*[Size];
	for (int i = 0; i < Size; i++){
		_array[i] = new int[Size];
	}

	if (Size % 2 == 0){//Ç
		if ((Size / 2) % 2 == 0){//Ç-Ç
			Cift_Cift();
		}
		else{//Ç-T
			Cift_Tek();
		}
	}
	else{//T
		int a, b;
		cout << "1 Nerden baslatilsin (format: satir bosluk sutun): ";
		cin >> a >> b;

		Tek(a,b);
	}

	cout << endl << endl;
	int toplam = 0;

	for (int i = 0; i < Size; i++){
		for (int j = 0; j < Size; j++){
			toplam = toplam + _array[i][j];
		}
		cout << i + 1 << ". satir = " << toplam << endl;
		toplam = 0;
	}

	for (int i = 0; i < Size; i++){
		for (int j = 0; j < Size; j++){
			toplam = toplam + _array[j][i];
		}
		cout << i + 1 << ". sutun = " << toplam << endl;
		toplam = 0;
	}

	system("pause");
	return 0;
}

void Tek(int x, int y){
	for (int i = 0; i < Size; i++){
		for (int j = 0; j < Size; j++){
			_array[i][j] = 0;
		}
	}

	_array[x][y] = 1;
	int sayac = 2;
	while (sayac != Size*Size + 1){
		if (x == Size){
			x = 0;
		}
		if (y == Size){
			y = 0;
		}

		if (x == Size - 1){
			if (y == Size - 1){
				if (_array[0][0] == 0){
					_array[0][0] = sayac;
					x = 0;
					y = 0;
				}
				else{
					_array[x][y - 1] = sayac;
					y--;
				}
			}
			else if (_array[0][y + 1] == 0)
			{
				_array[0][y + 1] = sayac;
				x = 0;
				y++;
			}
			else{
				y--;
			}
		}
		else if (y == Size - 1){
			if (_array[x + 1][0] == 0)
			{
				_array[x + 1][0] = sayac;
				y = 0;
				x++;
			}
			else{
				y--;
			}
		}
		else{
			if (_array[x + 1][y + 1] == 0){
				_array[x + 1][y + 1] = sayac;
				x++;
				y++;
			}
			else{
				_array[x][y-1] = sayac;
				y--;
			}
		}
		sayac++;
	}
	for (int i = 0; i < Size; i++){
		for (int j = 0; j < Size; j++){
			cout << setw(5) << setiosflags(ios::left) << _array[i][j];
		}
		cout << endl;
	}
}
void Cift_Tek(){

}
void Cift_Cift(){
	for (int i = 0; i < Size; i++){
		for (int j = 0; j < Size; j++){
			_array[i][j] = i*Size + j + 1;
		}
	}

	int swap_yapilcak_satir_ust = 0;
	int swap_yapilcak_satir_alt = Size - 1;

	while (swap_yapilcak_satir_ust != Size / 4){// aradaki korunakli sayilara gelinceye kadar		/4, iki kez 2 ye bolmeden geliyor
		for (int i = Size / 4, j = Size - Size/4 - 1; i <= Size - Size/4 -1; i++, j--){
				swap(swap_yapilcak_satir_ust,i,swap_yapilcak_satir_alt,j);
		}
		swap_yapilcak_satir_alt--;
		swap_yapilcak_satir_ust++;
	}

	int swap_yapilcak_sutun_sol = 0;
	int swap_yapilcak_sutun_sag = Size - 1;
	
	while (swap_yapilcak_sutun_sol != Size / 4){
		for (int i = Size / 4, j = Size - Size / 4 - 1; i <= Size - Size / 4 - 1; i++, j--){
			swap(i,swap_yapilcak_sutun_sol,j, swap_yapilcak_sutun_sag);
		}
		swap_yapilcak_sutun_sag--;
		swap_yapilcak_sutun_sol++;
	}

	for (int i = 0; i < Size; i++){
		for (int j = 0; j < Size; j++){
				cout << setw(5) << setiosflags(ios::left) << _array[i][j];
		}
		cout << endl;
	}
}

void swap(int i, int j, int i2, int j2){
	int temp = _array[i][j];
	_array[i][j] = _array[i2][j2];
	_array[i2][j2] = temp;

	return;
}

