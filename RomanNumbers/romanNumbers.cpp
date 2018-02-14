#include <iostream>
#include <math.h>
#include <string>
#include <cstdlib>

using namespace std;

char roman_strings[] = "IVXLCDM";
int roman_values[] = { 1, 5, 10, 50, 100, 500, 1000 };

void romanToArabic();
void arabicToRoman();
int getIndis(char);

//M C X I where to start
int startOfMCXI(string, char);
// returns end minus start
int endOfMCXI(string, int, char);


int main(){
	int x = 0;
	char ch;
	while(x != -1){
		cout << "1) Roman to Arabic" << endl << "2) Arabic to Roman" << endl << "anything else for exit" <<  endl << endl << ": ";
		cin >> x;
		switch(x){
			case 1:
				romanToArabic();
				break;
			case 2:
				arabicToRoman();
				break;
			default:
				return 0;
		}

		cout << endl << "Press enter to continue..";
		cin.clear();
		cin.ignore();
		cin.get();
		system("clear");
	}
	
	return 0;
}


int getIndis(char c){
	for(int i = 0; i < 7; i++){
		if(roman_strings[i] == c){
			return i;
		}
	}
	return -1;
}

int startOfMCXI(string s, char c){
	for(int i = 0; i < s.length(); i++){
		if(c == s[i]){
			return i;
		}
	}
	return -1;
}

int endOfMCXI(string s, int b, char c){
	int counter = 0;
	for(int i = b; i < s.length(); i++){
		if(c != s[i]){
			break;
		}
		counter++;
	}
	return counter;
}

void romanToArabic(){
	system("clear");
	
	string str;
	int toplam = 0;
	bool enter_failed = 1;

	while(enter_failed){
		cout << "Please enter the roman number: ";
		str = "";
		cin >> str;
		
		enter_failed = 0;

		for(int i = 0; i < str.length(); i++){
			if(str[i] == str[i + 1]){
				if(getIndis(str[i]) ==  1 || getIndis(str[i]) == 3 || getIndis(str[i]) == 5){ // VLD 135
					cout << "V L D cant repeat!" << endl;
					enter_failed = 1;
					break;
				}
			}
			if ((i < str.length() - 3) && (str[i] == str[i + 1]) && 
					(str[i + 2] == str[i + 3]) && (str[i + 2] == str[i + 1])){
				cout << "Repeat over 3!" << endl;
				enter_failed = 1;
				break;
			}
			if(getIndis(str[i]) == -1){
				cout << "Use only these chars: I-V-X-L-C-D-M" << endl;
				enter_failed = 1;
				break;
			}
		}
	}

	for(int i = 0; i < str.length(); i++){
		if(getIndis(str[i]) >= getIndis(str[i + 1])){ // order control
			toplam = toplam + roman_values[getIndis(str[i])];
		} else{
			toplam = toplam - roman_values[getIndis(str[i])];
		}
	}

	cout << toplam << endl;
	return;
}

void arabicToRoman(){
	system("clear");

	string result = "";
	int number;
	cout << "Please enter the number: ";
	cin >> number;
	
	while(number > 3999){
		cout << "Please enter the number which is lower than 4000: ";
		cin >> number;
	}
	
	int indis = 0;

	// write number in order
	while(number > 0){
		for(int i = 0; i < (number % 10); i++){
			result = roman_strings[indis] + result;
		}

		indis = indis + 2;
		number = number / 10;
	}

	// combining
	indis = indis - 2;
	string combined = "";
	while(indis >= 0){
		if(endOfMCXI(result,startOfMCXI(result, roman_strings[indis]), roman_strings[indis]) == 9){ // how many repeat
			combined = combined + roman_strings[indis] + roman_strings[indis + 2];
		} else if(endOfMCXI(result, startOfMCXI(result, roman_strings[indis]), roman_strings[indis]) >= 5){
			combined = combined + roman_strings[indis + 1];
			for(int i = 0; i < endOfMCXI(result, startOfMCXI(result, roman_strings[indis]), roman_strings[indis])-5; i++){
				combined = combined + roman_strings[indis];
			}
		} else if(endOfMCXI(result, startOfMCXI(result, roman_strings[indis]), roman_strings[indis]) >= 4){
			combined = combined + roman_strings[indis] + roman_strings[indis + 1];
			for(int i = 0; i < endOfMCXI(result, startOfMCXI(result, roman_strings[indis]), roman_strings[indis])-4; i++){
				combined = combined + roman_strings[indis];
			}
		} else{
			for(int i = 0; i < endOfMCXI(result, startOfMCXI(result, roman_strings[indis]), roman_strings[indis]); i++){
				combined = combined + roman_strings[indis];
			}
		}
		indis = indis - 2;
	}
	cout << combined << endl;
	return;
}