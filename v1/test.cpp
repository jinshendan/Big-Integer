#include <bits/stdc++.h>
#include "big_integer.h"
using namespace std;

void test_assign_by_integer() {
	BI x = 0;
	cout << "Input: x = 0;  Output: ";
	cout << x << endl;

	BI y = -124;
	cout << "Input: x = -124;  Output: ";
	cout << y <<  endl;

	BI z = 12345;
	cout << "Input: x = 12345;  Output: ";
	cout << z << endl;

	cout << endl << endl;
}

void test_assign_by_C_string() {
	BI x = "0";
	cout << "Input: x = \"0\";  Output: ";
	cout << x << endl;

	BI y = "-1234567890123456789";
	cout << "Input: x = \"-1234567890123456789\";  Output: ";
	cout << y << endl;

	BI z = "123456789123456789";
	cout << "Input: x = \"123456789123456789\";  Output: ";
	cout << z << endl;

	cout << endl << endl;
}


void test_assign_by_string() {
	
	BI x = string("0");
	cout << "Input: x = string(\"0\");  Output: ";
	cout << x << endl;

	BI y = string("-1234567890123456789");
	cout << "Input: x = string(\"-1234567890123456789\");  Output: ";
	cout << y << endl;

	BI z = string("123456789123456789");
	cout << "Input: x = string(\"123456789123456789\");  Output: ";
	cout << z << endl;

	cout << endl << endl;
}

void test_comparaison(){
	BI x = "1235";
	BI y = "123";
	cout << "Input: 1235 > 123;  Output: ";
	cout << (x > y) << endl;

	cout << "Input: 1235 >= 123;  Output: ";
	cout << (x >= y) << endl;


	cout << "Input: 1235 < 123;  Output: ";
	cout << (x < y) << endl;

	cout << "Input: 1235 <= 123;  Output: ";
	cout << (x <= y) << endl;


	cout << "Input: 1235 == 123;  Output: ";
	cout << (x == y) << endl;

	cout << "Input: 1235 != 123;  Output: ";
	cout << (x != y) << endl;

	cout << endl;

	x = "-1235";
	y = "123";
	cout << "Input: -1235 > 123;  Output: ";
	cout << (x > y) << endl;

	cout << "Input: -1235 >= 123;  Output: ";
	cout << (x >= y) << endl;


	cout << "Input: -1235 < 123;  Output: ";
	cout << (x < y) << endl;

	cout << "Input: -1235 <= 123;  Output: ";
	cout << (x <= y) << endl;


	cout << "Input: -1235 == 123;  Output: ";
	cout << (x == y) << endl;

	cout << "Input: -1235 != 123;  Output: ";
	cout << (x != y) << endl;

	cout << endl;


	x = "-1234";
	y = "-1234";
	cout << "Input: -1234 > -1234;  Output: ";
	cout << (x > y) << endl;

	cout << "Input: -1234 >= -1234;  Output: ";
	cout << (x >= y) << endl;


	cout << "Input: -1234 < -1234;  Output: ";
	cout << (x < y) << endl;

	cout << "Input: -1234 <= -1234;  Output: ";
	cout << (x <= y) << endl;


	cout << "Input: -1234 == -1234;  Output: ";
	cout << (x == y) << endl;

	cout << "Input: -1234 != -1234;  Output: ";
	cout << (x != y) << endl;

	cout << endl << endl;
}

void test_add(){


	BI x = "123";
	BI y = "10000";
	cout << "Input: 123 + 10000;   Output:   ";
	cout << x + y << endl;


	x = "-1111";
	y = "-8889";
	cout << "Input: -1111 + -8889;   Output:   ";
	cout << x + y << endl;

	x = "123456789123456789";
	y = "123456789123456789123456789";
	cout << "Input: 123456789123456789 + 123456789123456789123456789;   Output:   ";
	cout << x + y << endl;


	x = "-1000";
	y = "3000";
	cout << "Input: -1000 + (3000);   Output:   ";
	cout << x + y << endl;

	cout << endl << endl;
}

void test_minus(){
	BI x = "10000";
	BI y = "-20000";
	
	cout << "Input: 10000 - (-20000);   Output:   ";
	cout << x - y << endl;


	x = "10000";
	y = "20000";
	
	cout << "Input: 10000 - (20000);   Output:   ";
	cout << x - y << endl;

	x = "-10000";
	y = "-20000";
	
	cout << "Input: -10000 - (-20000);   Output:   ";
	cout << x - y << endl;


	x = "-10000";
	y = "20000";
	
	cout << "Input: -10000 - (20000);   Output:   ";
	cout << x - y << endl;

	x = "-10000";
	y = "-10000";
	
	cout << "Input: -10000 - (-10000);   Output:   ";
	cout << x - y << endl;


	cout << endl << endl;


}

void test_multiply(){
	BI x = "-123";
	BI y = "-200";

	cout << "Input: -123 * (-200);   Output:   ";
	cout << x * y << endl;

	x = "0";
	y = "-200";

	cout << "Input: 0 * (-200);   Output:   ";
	cout << x * y << endl;


	cout << endl << endl;
}
void do_test() {

	cout << "-------------------------  Debug Test Cases -------------------------------- " << endl;
	test_assign_by_integer();
	test_assign_by_C_string();
	test_assign_by_string();

	test_comparaison();

	test_add();
	test_minus();
	test_multiply();
}