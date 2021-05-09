#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <complex>
#include <cstdio>
#include <vector>
#include <cctype>
#include <string>
#include <ctime>
#include <cmath>
#include <set>
#include <map>

typedef long double LD;
typedef long long LL;

using namespace std;

#define sz(A) (int)(A).size()
#define mp make_pair
#define pb push_back

struct vect {
	int x, y;

	vect() {}

	vect(int a, int b) {
		x = a, y = b;
	}

	void read() {
		cin >> x >> y;
	}
};

vect operator - (vect a, vect b) {
	return vect(a.x - b.x, a.y - b.y);
}

LL operator % (vect a, vect b) {
	return LL(a.x) * b.y - LL(a.y) * b.x;
}

int main() {
	vect a, b, c;
	a.read();
	b.read();
	c.read();

	vect ab = b - a, bc = c - b;

	if (ab % bc == 0) {
		puts("TOWARDS");
	}	
	else {
		if (ab % bc > 0) {
			puts("LEFT");
		}
		else {
			puts("RIGHT");
		}
	}
		
	return 0;
}