#include <bits/stdc++.h>
#include <set>
#include <vector>
#include <string>
#include <limits>
using namespace std;
typedef long long int lld;
#define MAXN 1000001
#define FastIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
lld spf[MAXN];
void sieve (){
    spf[1]= 1;
    for(lld i=2; i<MAXN; i+=1)
        spf[i] = i;
    for(lld i=4; i<MAXN; i+=2)
        spf[i] = 2;
    for(lld i=3; i*i<MAXN;i++)
    {
        if (spf[i] == i)
        {
            for(lld j=i*i;j<MAXN;j+=i){
                if (spf[j]==j)
                    spf[j]= i;
            }
        }
    }
}
vector <lld>  getFactorization (lld x){
    vector<lld>ret; 
    while (x != 1){
        ret.push_back(spf[x]);
        x/= spf[x];
    }
    return ret;
}
double getComb (double n  ,  double x){
    if (x > n){
        return 0;
    }
    else{
        double r = 1.0;
        for(double i = 1.0;i<=x; i+=1){
            double a = n-i+1;
            double b = a / i;
            r*=b;
        }
        return r;
    }
}
void merge(lld crr[], lld brr[], lld arr[], lld l, lld m, lld r){
    lld i , j ,  k;
    lld n1 = m-l+1; 
    lld n2 = r - m;
    lld L1[n1],L2[n1],L3[n1];
    lld R1[n2],R2[n2],R3[n2];
    for (i = 0; i < n1; i++){
        L1[i] = arr[l + i];
        L2[i] = brr[l + i];
        L3[i] = crr[l + i];
    }
    for (j = 0; j < n2; j++){
        R1[j] = arr[m+1+j];
        R2[j] = brr[m+1+j];
        R3[j] = crr[m+1+j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L1[i] <= R1[j]){
            arr[k] = L1[i];
            brr[k] = L2[i];
            crr[k] = L3[i];
            i++;
        }
        else{
            arr[k] = R1[j];
            brr[k] = R2[j];
            crr[k] = R3[j];
            j++;
        }
        k++;
    }
        while (i   <   n1){
            arr[k] = L1[i];
            brr[k] = L2[i];
            crr[k] = L3[i];
            i++;
            k++;
        }
        while (j   <   n2){
            arr[k] = R1[j];
            brr[k] = R2[j];
            crr[k] = R3[j];
            j++;
            k++;
        }
}
void mergeSort(lld crr[], lld brr[], lld arr[], lld l, lld r){
    if (l < r)
    {
        lld m = l+(r-l)/2;
        mergeSort(crr, brr, arr,l, m);
        mergeSort(crr, brr,arr,m+1,r);
        merge(crr, brr, arr, l, m, r);
    } 
} 
int main () {
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("inputf.in",  "r",  stdin);
    // for writing output to output.txt
    freopen("outputf.in", "w", stdout);
    #endif
    FastIO
    double a;
    double x;
    double y;
    cin >> a;
    cin >> x;
    cin >> y;
    lld o, f;
    f = 0;
    if (y>0.0 && y < a){
        if (x  > (-a/2) && x  < (a/2)){
            f = 1;
            o = 1;
        }
    }
    else{
        lld j = 2;
        lld i = 1;
        lld n = 2;
        lld p = 3;
        lld q = 4;
        while(y>=(i*a)){
            if (i%2 != 0  && j%2 == 0){
                if (y>(i*a)&& y<(j*a)){
                if (x>(-a/2)&&x<(a/2)){
                    f = 1;
                    o = n;
                    break;
                }
                }
                n += 3;
            }
            if (i%2 == 0  && j%2 != 0){
                if (y>(i*a)&& y<(j*a)){
                if (x > (-a) && x < 0){
                    f = 1;
                    o = p;
                    break;
                }
                if (x > 0 &&  x < (a)){
                    f = 1;
                    o = q;
                    break;
                }
                }
                p += 3;
                q += 3;
            }
                i += 1;
                j += 1;
        }
    }
    if (f == 0){
        cout << "-1\n";
    }
    else{
        cout <<o<<"\n";
    }
    return 0;
}