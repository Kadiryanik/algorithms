#include <iostream>
#include <iomanip>

using namespace std;

int size;
int** _array;

void odd(int, int);
void evenOdd();
void evenEven();
void swap(int, int, int, int);

int main(){
	cout << "Enter the column or row size: ";
	cin >> size;

	_array = new int*[size];
	for (int i = 0; i < size; i++){
		_array[i] = new int[size];
	}

	if (size % 2 == 0){
		if ((size / 2) % 2 == 0){
			evenEven();
		}
		else{
			evenOdd();
			return 0;
		}
	}
	else{
		int a, b;
		a = size / 2;
		b = size - 1;
		odd(a, b);
	}

	cout << endl << endl;
	int sum = 0;

	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			sum = sum + _array[i][j];
		}
		cout << i + 1 << ". row = " << sum << endl;
		sum = 0;
	}

	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			sum = sum + _array[j][i];
		}
		cout << i + 1 << ". column = " << sum << endl;
		sum = 0;
	}

	return 0;
}

void odd(int x, int y){
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			_array[i][j] = 0;
		}
	}

	_array[x][y] = 1;
	int counter = 2;
	while (counter != size * size + 1){
		if (x == size){
			x = 0;
		}
		if (y == size){
			y = 0;
		}

		if (x == size - 1){
			if (y == size - 1){
				if (_array[0][0] == 0){
					_array[0][0] = counter;
					x = 0;
					y = 0;
				}
				else{
					_array[x][y - 1] = counter;
					y--;
				}
			}
			else if (_array[0][y + 1] == 0)
			{
				_array[0][y + 1] = counter;
				x = 0;
				y++;
			}
			else{
				y--;
			}
		}
		else if (y == size - 1){
			if (_array[x + 1][0] == 0)
			{
				_array[x + 1][0] = counter;
				y = 0;
				x++;
			}
			else{
				y--;
			}
		}
		else{
			if (_array[x + 1][y + 1] == 0){
				_array[x + 1][y + 1] = counter;
				x++;
				y++;
			}
			else{
				_array[x][y-1] = counter;
				y--;
			}
		}
		counter++;
	}
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			cout << setw(5) << setiosflags(ios::left) << _array[i][j];
		}
		cout << endl;
	}
}

void evenOdd(){
	// TODO: will code!
	cout << "Will be here next commit, sorry!" << endl;
}

void evenEven(){
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			_array[i][j] = i*size + j + 1;
		}
	}

	int swappingRowUp = 0;
	int swappingRowDown = size - 1;

	while (swappingRowUp != size / 4){ // 4 means divide two times 2
		for (int i = size / 4, j = size - size / 4 - 1; i <= size - size / 4 - 1; i++, j--){
				swap(swappingRowUp,i,swappingRowDown,j);
		}
		swappingRowDown--;
		swappingRowUp++;
	}

	int swappingColumnLeft = 0;
	int swappingColumnRight = size - 1;
	
	while (swappingColumnLeft != size / 4){
		for (int i = size / 4, j = size - size / 4 - 1; i <= size - size / 4 - 1; i++, j--){
			swap(i,swappingColumnLeft,j, swappingColumnRight);
		}
		swappingColumnRight--;
		swappingColumnLeft++;
	}

	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
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

