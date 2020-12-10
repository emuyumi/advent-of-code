#include <bits/stdc++.h>

using namespace std;

set<int> s;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ifstream file("test.txt");
    string str;
    int ans=0;
    while (getline(file,str)){
        int n=stoi(str);
        if (s.count(2020-n)) ans=n*(2020-n);
        s.insert(n);
    }
    cout << ans << '\n';
}