#include <iostream>
using namespace std;

typedef long long ll;

ll nMax,f = 1, f_old = 0, f_number = 0;
string digits[10] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };

bool esPrimo(ll x) {
	for (ll i = 2; i * i <= x; i++) {
		if (x % i == 0) return false;
	}
	return true;
}


string separate_digits(ll x) {
	string result = "";
	while (x != 0) {
		int digit = x % 10;
		result = digits[digit] + result;
		x /= 10;
		if (x != 0) result = "," + result;

	}
	return result;
}

int main() {
	cout << "Numero de elementos: ";
	cin >> nMax;

	for (int i = 0; i <= nMax; i++) {
		string dosPuntos = " : ";
		if (f % 2 == 0) dosPuntos += "Par, ";
		else dosPuntos += "Impar, ";
		if (esPrimo(f)) dosPuntos += "Primo, ";
		else dosPuntos += "No primo, ";
		dosPuntos += "\'" + separate_digits(f) + "\'";
		cout << f_number << ". " << f << dosPuntos << '\n';
		f_number++;


		ll temp = f;
		f = f + f_old;
		f_old = temp;

	}
	return 0;
}