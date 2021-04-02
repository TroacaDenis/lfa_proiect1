#include <fstream>
#include <string>
#include <vector>
using namespace std;
ifstream fin("nfa.in");
ofstream fout("nfa.out");
int n, m, nr_finale, nr_cuv, s_initiala, x, y, s_finale[1001], ok;
vector<int> traseu;
string cuv;
char a[1001][1001];
void nfa(string cuv, int indice_litera, int s_curenta)
{
    if (indice_litera >= cuv.size())
    {
        for (int j = 0; j < nr_finale; j++)
            if (s_finale[j] == s_curenta)
            {
                ok = 1;
                traseu.push_back(s_curenta);
                break;
            }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (a[s_curenta][i] == cuv[indice_litera])
            {
                traseu.push_back(s_curenta);
                nfa(cuv, indice_litera + 1, i);
                if (ok == 1)
                    break;
                traseu.pop_back();
            }
        }
    }
}
int main()
{
    fin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        fin >> x >> y;
        fin >> a[x][y];
    }
    fin >> s_initiala;
    fin >> nr_finale;
    for (int i = 0; i < nr_finale; i++)
        fin >> s_finale[i];
    fin >> nr_cuv;
    for (int i = 1; i <= nr_cuv; i++)
    {
        fin >> cuv;
        ok = 0;
        nfa(cuv, 0, s_initiala);
        if (ok == 1)
        {
            fout << "DA" << '\n'
                 << "Traseu: ";
            for (int i = 0; i < traseu.size(); i++)
                fout << traseu[i] << " ";
            fout << '\n';
        }
        else
            fout << "NU" << '\n';
        traseu.clear();
    }
}
