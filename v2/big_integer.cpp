#include "big_integer.h"
typedef long long ll ;
const int p = 4;
const int M = 10000;
istream& operator>> (istream& in, BI& x){
	string str;
	in >> str;
	int len = str.length();
	if (str[len-1] == ')') str = str.substr(0, len - 1);
	if (str[0] == '(') str = str.substr(1, len);
	x = str;
	return in;
}

ostream& operator<< (ostream& os, const BI& x) {
	if (x.sign) cout << "-";
	if (x.v[x.v.size() - 1] == 0) 
		os << 0;
	else os << x.v[x.v.size()-1];

	for (int i = x.v.size() - 2; i >= 0; i--) {
		string s = to_string(x.v[i]);
		for (int j = 0; j < p-s.length(); j++)
			os << 0;
		os << x.v[i];
	}
		
	return os;
}

void BI::init(){
	v.resize(0);
	sign = false;
}

void check_zero(BI& x){
	if (x.v.size() == 1 and x.v[0] == 0)
		x.sign = 0;
}

BI BI::operator = (int n) {
	init();
	if (n == 0) {
		sign = false;
		v.resize(1);
		v[0] = 0;
	}
	else {
		sign = (n < 0);
		n = abs(n); 
		while (n) {
			v.push_back(n % M);
			n /= M;
		}
	}
	return (*this);
}

BI BI::operator = (const char* str) {
	init();
	int b;
	int n = strlen(str);
	if (str[0] == '-'){
		b = 1;
		sign = true;
	}
	else {
		b = 0;
		sign = false;
	}
	for (int i = n-1; i >= b; i-=p) {
		int tmp = 0;
		int j = max(b, i-p+1);
		for (int k = j; k <= i; k++)
			tmp = tmp * 10 + str[k] - '0';
		v.push_back(tmp);
	}
	check_zero(*this);
	return (*this);
}

BI BI::operator = (string str){
	init();
	int b;
	int n = str.length();
	if (str[0] == '-'){
		b = 1;
		sign = true;
	}
	else {
		b = 0;
		sign = false;
	}
	for (int i = n-1; i >= b; i-=p) {
		int tmp = 0;
		int j = max(b, i-p+1);
		for (int k = j; k <= i; k++)
			tmp = tmp * 10 + str[k] - '0';
		v.push_back(tmp);
	}
	check_zero(*this);
	return (*this);
}

BI BI::operator = (const BI& x){
	init();
	sign = x.sign;
	v.resize(x.v.size());
	int n = x.v.size();
	for (int i = 0; i < n; i++){
		v[i] = x.v[i];
	}
	check_zero(*this);
	return (*this);
}

bool BI::operator < (const BI& b) const{
	if (!b.sign and sign) return true;    //  neg < pos  return true
	if (b.sign and !sign) return false;	  //  pos  < neg  return false


	if (v.size() !=  b.v.size()) {  
		if (!sign) return v.size() < b.v.size();
		else return v.size() > b.v.size();
	}

	for (int i = v.size() - 1; i >= 0; i--){
			if (v[i] != b.v[i]){
				if (!sign) return v[i] < b.v[i];
				else return b.v[i] < v[i];
			}
	}

	//Equal 
	return false;
}


bool BI::operator > (const BI& b) const{
	return b < (*this);
}

bool BI::operator <= (const BI& b) const{
	return !(*this > b);
}

bool BI::operator >= (const BI& b) const{
	return !(*this < b);
}

bool BI::operator != (const BI& b) const{
	return (*this < b) or (*this > b);
}

bool BI::operator == (const BI& b) const{
	return !(*this != b);
}


BI BI::operator + (const BI& b) const {
	BI c;
	if (b.sign == sign) {   // + + or - -
		c.sign = sign;
	}
	else if (sign) {   // left -  right +
		c = b - (-(*this));
		return c;
	}
	else if (b.sign){ //  left +   right -
		c = (*this) - (-b);
		return c;
	} 

	int na = v.size(), nb = b.v.size();
	int n = max(na, nb) + 1;
	c.v.resize(n);

	for (int i = 0; i < n; i++){
		if (i < na) c.v[i] += v[i];
		if (i < nb) c.v[i] += b.v[i];
		c.v[i+1] = c.v[i] / M;
		c.v[i] %= M;
	}
	
	while(c.v.size() > 1 and c.v[c.v.size() - 1] == 0) c.v.pop_back();
	check_zero(c);
	return c;
}

void aux_minus(BI& a, BI& b, BI& c){
	int na = a.v.size(), nb = b.v.size();
	int min_len = min(na, nb), max_len = max(na, nb);

	int t = 0;
	for (int i = 0; i < max_len; i++){
		c.v.push_back(a.v[i] + t);
		if (i < min_len)
			c.v[i] -= b.v[i];

		if (c.v[i] < 0){
			t = -1;
			c.v[i] += M;
		}
		else t = 0;
	}

	int n = c.v.size();
	while(n--){
		if (c.v[c.v.size() - 1] == 0) c.v.pop_back();
		else break;
	}
	if (c.v.empty()) c.v.push_back(0);
}

BI BI::operator - (const BI& x) const {
	BI a(*this), b(x), c;
	int swap = 0;
	int t = 0;
	if (b.sign == sign) {
		if (!sign) { // pos - pos
			if (*this < b){
				swap = 1;
				t = 1;
			}
		}
		else {// neg - neg
			a.sign = !a.sign;
			b.sign = !b.sign;
			if (*this > x){
				swap = 1;
				t = 0;
			}	
			else t = 1;
		}
	}
	else if (a.sign) return -(-a + b);
	else if (b.sign) return a + (-b);

	if (swap) aux_minus(b, a, c); else aux_minus(a, b, c);
	if (t) c.sign = !c.sign;
	check_zero(c);
	return c;
}

BI BI::operator - ()const {
	BI c(*this);
	if (c != 0) c.sign = !c.sign;
	check_zero(c);
	return c;
}


BI BI::operator *(const BI& b) const{
	BI c;
	int na = v.size();
	int nb = b.v.size();
	c.v.resize(na + nb + 1);
	for (int i = 0; i < na; i++)
		for (int j = 0; j < nb; j++) {
			c.v[i+j] += v[i] * b.v[j];
			c.v[i+j+1] += c.v[i+j] / M;
			c.v[i+j] %= M;
		}

	while (c.v.size() > 1 and !c.v[c.v.size()-1]) c.v.pop_back();
	c.sign = sign ^ b.sign;
	check_zero(c);
	return c;
}

BI BI::operator += (const BI& b){
	*this = *this + b;
	check_zero(*this);
	return *this;
}

BI BI::operator -= (const BI& b){
	*this = *this - b;
	check_zero(*this);
	return *this;
}

BI BI::operator *= (const BI& b){
	*this = *this * b;
	check_zero(*this);
	return *this;
}

