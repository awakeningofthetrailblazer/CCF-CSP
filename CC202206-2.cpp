#include<bits/stdc++.h>//c++14包含

using namespace std;

//*change stream
#define cin fin
#define cout fout
ifstream fin("inputdata.txt");
ofstream fout("outputdata.txt");
//*/

//structure
struct node{
    int xx,yy;
};
//global variable
int n,L,S,cnt,spx,spy;
unordered_map<int,unordered_map<int,bool>> mp,sp;

vector<node> mpv;
node spnd;

//function announcement
void init();

bool mapfit(int xx,int yy);

bool cmp(node a,node b);

int main(){
    init();

    for(auto nd:mpv){
        if(mapfit(nd.xx,nd.yy)) cnt++;
    }

    cout<<cnt<<endl;
    
    return 0;
}

void init(){
    cin>>n>>L>>S;

    int xx,yy;

    for(int i=0;i<n;i++) {
        cin>>xx>>yy;
        mp[xx][yy]=true;
        mpv.push_back({xx,yy});
    }

    for(int i=S;i>=0;i--){
        for(int j=0;j<=S;j++){
            cin>>xx;
            sp[i][j]=bool(xx);
            if(sp[i][j]) {
                spnd={i,j};
            }
        }
    }

    cnt=0;
}

bool mapfit(int xx,int yy){
    int x0=xx-spnd.xx,y0=yy-spnd.yy;
    for(int i=0;i<=S;i++){
        if(x0+i>L) return false;
        for(int j=0;j<=S;j++){
            if(y0+j>L) return false;
            if(mp[x0+i][y0+j]!=sp[i][j]) return false;
        }
    }
    return true;
}

bool cmp(node a,node b){
    if(a.xx!=b.xx) return a.xx<b.xx;
    else return a.yy<b.yy; 
}
