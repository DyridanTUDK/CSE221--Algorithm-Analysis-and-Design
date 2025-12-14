#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N; 

    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;

    vector<vector<int>> dist (N+1, vector<int>(N+1, -1));
    queue<pair<int,int>> q;

    int dx[8] = {2,2,-2,-2,1,1,-1,-1};
    int dy[8] = {1,-1,1,-1,2,-2,2,-2} ;

    q.push({x1,y1});
    dist[x1][y1] = 0;

    while (!q.empty())
    {
        auto [x,y] = q.front();
        q.pop();

        for(int i = 0; i<8 ;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx<1||ny<1||nx>N||ny>N) continue;
            if(dist[nx][ny]!= -1)continue;
            dist[nx][ny] = dist[x][y] + 1;
            if(nx==x2&&ny==y2){
                cout<< dist[nx][ny] << "\n";
                return 0;
            }
            q.push({nx,ny});
        }
    }

    // Not reachable
    cout<<-1<<"\n";
    return 0;
}