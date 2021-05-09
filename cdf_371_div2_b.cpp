#include <bits/stdc++.h>
#include <set>
#include <map>
#include <string>
using namespace std;
typedef long long int lld;
#define FastIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
double getComb (double n, double x){
    if (x > n){
        return 0;
    }
    else{
        double r = 1.0;
        for(double i = 1.0; i<=x; i += 1){
            double a = n-i+1;
            double b = a / i;
            r*=b;
        }
        return r;
    }
}
void merge(lld brr[], lld arr[], lld l, lld m, lld r){
    lld i , j ,  k;
    lld n1 = m-l+1; 
    lld n2 = r - m;
    lld L1[n1],L2[n1];
    lld R1[n2],R2[n2];
    for (i = 0; i < n1; i++){
        L1[i] = arr[l + i];
        L2[i] = brr[l + i];
    }
    for (j = 0; j < n2; j++){
        R1[j] = arr[m+1+j];
        R2[j] = brr[m+1+j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L1[i] <= R1[j]){
            arr[k] = L1[i];
            brr[k] = L2[i];
            i++;
        }
        else{
            arr[k] = R1[j];
            brr[k] = R2[j];
            j++;
        }
        k++;
    }
        while (i   <   n1){
            arr[k] = L1[i];
            brr[k] = L2[i];
            i++;
            k++;
        }
        while (j   <   n2){
            arr[k] = R1[j];
            brr[k] = R2[j];
            j++;
            k++;
        }
}
void mergeSort(lld brr[], lld arr[], lld l, lld r){
    if (l < r)
    {
        lld m = l+(r-l)/2;
        mergeSort(brr, arr,l, m);
        mergeSort(brr,arr,m+1,r);
        merge(brr, arr, l, m, r);
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
    lld n, i;
    cin >> n;
    lld A[n];
    lld B[n];
    lld j;
    set <lld> Dset;
    for(i = 0; i<n; i+=1){
        cin >>A[i];
        Dset.insert(A[i]);
    }
    j = 0;
    set<lld>::iterator ps;
    for(ps = Dset.begin(); ps!=Dset.end(); ps++){
        B[j] = *ps;
        j++;
    }
    if (Dset.size() <= 3){
        if (Dset.size() == 1){
                cout << "YES" << "\n";
        }
        if (Dset.size() == 2){
                cout << "YES" << "\n";
        }
        if (Dset.size() == 3){
            if ((B[2] - B[1])  == (B[1] - B[0])){
                cout << "YES" << "\n";
            }
            else{
                cout <<  "NO" << "\n";
            }
        }
    }
    else{
                cout <<  "NO" << "\n";
    }
    return 0;
}