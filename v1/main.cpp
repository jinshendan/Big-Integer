#include <bits/stdc++.h>
#include "big_integer.h"
#include "test.h"
using namespace std;


int main() {
	
	cout << "Debug Mode? (y/n) " << endl;
	char c;
	do {
		cin >> c;
	} while (c != 'y' and c != 'n');
	cout << endl << endl;

	if (c == 'y') {
		do_test();
		return 0;
	}


	ifstream in("input.in");

	char op;
	BI x, y;
	while (in >> x >> op >> y){
		cout << x << " " << op << " " << y << " = ";
		if (op == '+') cout << x + y;
		if (op == '-') cout << x - y;
		if (op == '*') cout << x * y;
		cout << endl;
	}
	in.close();
	return 0;
}