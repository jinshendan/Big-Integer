#include <bits/stdc++.h>
using namespace std;
class BI {
private:	
	void init();
	BI add(const BI& a, const BI& b);
public:
	vector<int> v;
	bool sign;

	/* List of possible constructors */

	// Initialized by an (int)
	BI(){
		v.resize(0);
		sign = 0;
	}
	BI(int n){ 
		(*this) = n; 
	}

	// Initialized by C-style string
	BI(const char* str) {
		(*this) = str;
	}

	// Initialized by String
	BI(string str) {
		(*this) = str;
	}

	/* Operator overloading  */

	
	friend istream& operator>> (istream& in, BI& x);
	friend ostream& operator<< (ostream& os, const BI& x);

	// Assign
	BI operator = (int n);
	BI operator = (const char* str);
	BI operator = (string str);
	BI operator = (const BI& x);


	// Comparaison with absolute value
	bool operator < (const BI& b) const;
	bool operator > (const BI& b) const;
	bool operator <= (const BI& b) const;
	bool operator >= (const BI& b) const;
	bool operator != (const BI& b) const;
	bool operator == (const BI& b) const;

	// +, +=, -(b), - , -=, *, *=
	BI operator + (const BI& b) const;
	BI operator += (const BI& b);
	BI operator - (const BI& b) const;
	BI operator - () const;
	BI operator -=(const BI& b);
	BI operator * (const BI& b) const;
	BI operator *= (const BI& b);
};
