#include <bits\stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, x ,y;
    cin >> N >> x >> y;

    vector<pair<long long, long long>> moves;

    int dx[8] = {1,-1,0,0,1,1,-1,-1};
    int dy[8] = {0,0,1,-1,1,-1,1,-1};

    for( int i = 0; i<8; i++){
        long long nx = x + dx[i];
        long long ny = y + dy[i];
        if(nx>=1 && nx<=N && ny>=1 && ny <= N){
            moves.push_back({nx,ny});
        }
    }

    int K  = moves.size();
    for(int i = 0 ; i < K ; i++){
        for(int j = i+1; j<K; j++){
            if(moves[j].first<moves[i].first || (moves[j].first == moves[i].first && moves[j].second < moves[i].second) ){
                swap(moves[i], moves[j]);
            }
        }
    }



    cout<<moves.size()<<"\n";
    for(auto &p: moves){
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}