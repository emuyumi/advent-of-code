#include <bits/stdc++.h>

using namespace std;

char grid[101][101], nxt[101][101];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int rows=94, cols=92;
    freopen ("test.txt", "r", stdin);
    for (int i=1;i<=rows;++i){
        for (int j=1;j<=cols;++j){
            cin >> nxt[i][j];
        }
    }
    bool a=1;
    while (a){
        swap(nxt,grid);
        a=0;
        for (int i=1;i<=rows;++i){
            for (int j=1;j<=cols;++j){
                nxt[i][j]=grid[i][j];
                int cnt=0;
                for (int x=-1;x<=1;++x) for (int y=-1;y<=1;++y){
                    if (x==0&&y==0) continue;
                    for (int r=i+x,c=j+y;;r+=x,c+=y){
                        if (grid[r][c]=='#') cnt++;
                        if (grid[r][c]!='.') break;
                    }
                }
                if (grid[i][j]=='L'&&cnt==0) a=1, nxt[i][j]='#';
                if (grid[i][j]=='#'&&cnt>=5) a=1, nxt[i][j]='L';
            }
        }
    }
    int ans=0;
    for (int i=1;i<=rows;++i) for (int j=1;j<=cols;++j) ans+=nxt[i][j]=='#';
    cout << ans << '\n';
}