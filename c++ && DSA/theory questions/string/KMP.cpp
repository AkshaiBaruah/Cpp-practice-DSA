#include<bits/stdc++.h>
using namespace std;

void fillLPS(int LPS[] , string p){
    int m = p.length();
    LPS[0] = 0;
    int len = 0;
    int i = 1;
    while(i<m){
        if(p[i] == p[len]){
            LPS[i] = len + 1;
            len++;
            i++;
        }
        else{
            if(len == 0){
                LPS[i] = 0;
                i++;
            }
            else{
                len = LPS[len -1];
            }
        }
    }
}
void KMP(string &t , string &p){
    int n = t.length() , m = p.length();
    if(m > n)
        return;
    int LPS[m];
    fillLPS(LPS , p);

    int i = 0 , j =0;
    while(i<n){
        
        while(j<m){
            if(p[j] != t[i])
                break;
            j++; i++;
        }
        if(j == m){
            cout<<i-m<<" ";
            j = LPS[j-1];
            
        }
        else if(j == 0){
            i++;
        }
        else{
            j = LPS[j-1];
        }

    }
}
int main(){
    string text = "aabaaabaaac";
    string pat = "aabaaac";
    KMP(text , pat);
    return 0;
}