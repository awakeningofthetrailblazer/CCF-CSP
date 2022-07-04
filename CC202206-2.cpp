#include<bits/stdc++.h>//c++14包含

using namespace std;

//*change stream
#define cin fin
#define cout fout
ifstream fin("inputdata.txt");
ofstream fout("outputdata.txt");
//*/



vector<double> num;

int main(){

    int N;
    double x,avg=0,var=0,res;
    cin>>N;
    while(N--){
        cin>>x;
        avg+=x;
        num.push_back(x);
    }

    avg/=num.size();

    for(int i=0;i<num.size();i++){
        var+=(num[i]-avg)*(num[i]-avg);
    }

    var/=num.size();

    for(int i=0;i<num.size();i++){
        res=(num[i]-avg)/sqrt(var);
        cout<<i<<' '<<res<<endl;
    }
    
    return 0;
}
