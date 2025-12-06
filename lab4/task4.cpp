#include <iostream>
#include <vector>
using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    vector<int> eq(a,0);
    for(int i =0; i<b*2;i++){
        int t;
        cin >> t; 
        eq[t-1]++;
    }
    int ct = 0;
    for(int i=0;i<eq.size(); i++){
        if(eq[i]%2!=0) ct++;
    }
    if(ct>2||ct==1){
        cout<<"NO";
    }
    else{
    cout<<"YES";
    }
    return 0;
}