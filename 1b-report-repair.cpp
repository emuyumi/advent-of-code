#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ifstream file("test.txt");
    string str; vector<int> a;
    int ans=0;
    while (getline(file,str)){
        a.push_back(stoi(str));
    }
    for (int i=0;i<a.size();++i){
        for (int j=i+1;j<a.size();++j){
            for (int k=j+1;k<a.size();++k){
                if (a[i]+a[j]+a[k]==2020) ans=a[i]*a[j]*a[k];
            }
        }
    }
    cout << ans << '\n';
}