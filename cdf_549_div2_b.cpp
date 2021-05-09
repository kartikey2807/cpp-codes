#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
using namespace std;
typedef double  dbl;
typedef long long int lld;
#define PI 3.14159265358979323
#define foi(i,n) for(i = 0; i < n; i+=1)
#define fod(i,n) for(i=n-1; i >=0; i-=1)
#define MAX std::numeric_limits<lld>::max()
#define MIN std::numeric_limits<lld>::min()
#define FastIO  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
lld pro_ (lld x)
{
	lld temp = x , prod = 1;
	while (temp){
		lld r = temp % 10;
		prod *= r;
		temp  = temp / 10;
	}
	return  prod;
}
lld max_ (lld n)
{
	vector<lld>v;
	lld temp = n;
	while (temp){
		lld r = temp%10;
		v.push_back(r);
		temp  = temp/10;
	}
	reverse(v.begin(), v.end());
	lld maxim = n;
	for(lld i = 0; i < v.size(); i+= 1){
		if (v[i] == 0)
			continue;
		vector<lld>temp;
		temp = v;
		temp[i]-= 1;
		for(lld j = i+1;j < temp.size();j+=1){
			temp[j] = 9;
		}
		lld x = 0;
		for(lld j = 0; j < temp.size(); j+=1){
			x = (x*10)+temp[j];
 		}
 		if (pro_(x) > pro_(maxim)){
 			maxim = x;
 		}
	}
	return maxim;
}
int main ()
{
	#ifndef ONLINE_JUDGE
	freopen("inputf.in",  "r",   stdin);
	freopen("outputf.in", "w",  stdout);
	#endif
	FastIO
	lld n, k;
	cin >> n;
	cout << pro_(max_(n));
	return 0;
}