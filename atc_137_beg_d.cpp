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
	cin >> s;
	map <lld, lld> points;
	lld curr = 0;
	for(lld i = 1; i < s.length() - 1; i++){
		if (s[i] == 'L' && s[i+1] == 'R'){
			points[curr] = i;
			curr= i+1;
		}
	}
	points[curr] = s.length()- 1;
	lld A[s.length()];
	for(lld i = 0; i < s.length(); i++){
		A[i]= 0;
	}
	for(map <lld, lld> :: iterator pos = points.begin(); pos != points.end(); pos++){
		if (((pos->second)-(pos->first)+1)%2 == 0){
			for(lld i = pos->first; i < pos->second; i++){
				if (s[i] == 'R' && s[i+1] == 'L'){
					A[i] = A[i+1] = ((pos->second)-(pos->first)+1) / 2;
					break;
				}
			}
		}
		else{
			lld count_r = 0;
			lld count_l = 0;
			for(lld i = pos->first; i <=pos->second; i++){
				if (s[i] == 'R'){
					count_r++;
				}
				if (s[i] == 'L'){
					count_l++;
				}
			}
			for(lld i = pos->first; i < pos->second; i++){
					if (s[i] == 'R' && s[i+1] == 'L'){
					if (min(count_l, count_r)%2 == 0){
						if (count_l < count_r){
							A[i] = (((pos->second)-(pos->first)+1)/2) + 1;
							A[i+1]=(((pos->second)-(pos->first)+1)/2) + 0;
						}
						else{
							A[i] = (((pos->second)-(pos->first)+1)/2) + 0;
							A[i+1]=(((pos->second)-(pos->first)+1)/2) + 1;
						}
						break;
					}
					else{
						if (count_l < count_r){
							A[i] = (((pos->second)-(pos->first)+1)/2) + 0;
							A[i+1]=(((pos->second)-(pos->first)+1)/2) + 1;
						}
						else{
							A[i] = (((pos->second)-(pos->first)+1)/2) + 1;
							A[i+1]=(((pos->second)-(pos->first)+1)/2) + 0;
						}
						break;
					}
				}
			}
		}
	}
	for(lld i = 0; i < s.length(); i++){
		cout << A[i] << " ";
	}
	return 0;
}