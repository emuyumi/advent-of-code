#include <bits/stdc++.h>

using namespace std;

bool last[105][105][105], arr[105][105][105];

void go(){
    swap(last,arr); memset(arr,0,sizeof arr);
    for (int x=1;x<=100;++x){
        for (int y=1;y<=100;++y){
            for (int z=1;z<=100;++z){
                int cnt=0;
                for (int dx=-1;dx<=1;++dx){
                    for (int dy=-1;dy<=1;++dy){
                        for (int dz=-1;dz<=1;++dz){
                            if (dx==0&&dy==0&&dz==0) continue;
                            cnt+=last[x+dx][y+dy][z+dz];
                        }
                    }
                }
                if (last[x][y][z]){
                    if (cnt==2||cnt==3) arr[x][y][z]=1;
                }
                else{
                    if (cnt==3) arr[x][y][z]=1;
                }
            }
        }
    }
}

int main(){
    int n; n=8;
    for (int i=41;i<=40+n;++i){
        for (int j=41;j<=40+n;++j){
            char a; cin >> a;
            arr[41][i][j]=a=='#';
        }
    }
    for (int i=1;i<=6;++i) go();
    int tot=0;
    for (int i=1;i<=100;++i){
        for (int j=1;j<=100;++j){
            for (int k=1;k<=100;++k){
                tot+=arr[i][j][k];
            }
        }
    }
    cout << tot << '\n';
}