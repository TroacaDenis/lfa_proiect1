#include <fstream>
#include <string>
#include <vector>
using namespace std;
ifstream fin("nfa.in");
ofstream fout("nfa.out");
int n,m,nf,ni,si,x,y,sf[1001],ok;
vector<int>r;
string cuv;
char a[1001][1001];
void nfa(string cuv, int l, int k){
    if(l>=cuv.size()){
        for(int j=0;j<nf;j++)
            if (sf[j]==k){
                ok=1;
                r.push_back(k);
                break;
            }
    }
    else{
        for(int i=0;i<n;i++){
            if(a[k][i]==cuv[l]){
                r.push_back(k);
                nfa(cuv,l+1,i);
                if(ok==1)
                    break;
                r.pop_back();

            }

        }
    }
}
int main(){
    fin>>n>>m;
    for(int i=1;i<=m;i++){
        fin>>x>>y;
        fin>>a[x][y];
    }
    fin>>si;
    fin>>nf;
    for(int i=0;i<nf;i++)
        fin>>sf[i];
    fin>>ni;
    for(int i=1;i<=ni;i++){
        fin>>cuv;
        ok=0;
        nfa(cuv,0,si);
        if(ok==1){
            fout<<"DA"<<'\n'<<"Traseu: ";
            for(int i=0;i<r.size();i++)
                fout<<r[i]<<" ";
            fout<<'\n';
        }
        else
            fout<<"NU"<<'\n';
        r.clear();
    }

}


