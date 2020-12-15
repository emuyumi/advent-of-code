#include <bits/stdc++.h>

using namespace std;

map<int,int> seen;

int main(){
    int n, last=-1, curr; n=6;
    for (int i=1;i<=n;++i){
        cin >> curr;
        seen[last]=i-1;
        last=curr;
    }
    for (int i=n+1;i<=2020;++i){
        if (seen.count(last)) curr=i-seen[last]-1;
        else curr=0;
        seen[last]=i-1;
        last=curr;
    }
    cout << last << '\n';
}