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
int main ()
{
	#ifndef ONLINE_JUDGE
	freopen("inputf.in",  "r",   stdin);
	freopen("outputf.in", "w",  stdout);
	#endif
	FastIO
	string s;
	string t;
	cin >> s;
	cin >> t;
	if (s.length() != t.length()){
		cout <<  "NO";
	}
	else{
		lld f =1;
		lld i, j;
		j =  s.length()-1;
		for(i = 0; i < t.length(); i++){
			if (t[i] != s[j]){
				f = 0;
				break;
			}
			j--;
		}
		if (f == 0)
			cout <<  "NO";
		else
			cout << "YES";
	}
	return 0;
}