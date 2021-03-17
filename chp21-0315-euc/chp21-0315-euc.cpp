#include <iostream> 
#include <vector>  
using namespace std;

struct MDC
{
    const vector<int>& valor;
    int             mdc;
    int             Euclides(int, int);
    MDC(const vector<int>&);
    friend ostream& operator << (ostream& sai, const MDC& m);
};


int main(int argc, char** argv)
{
    vector<int> valor{}; // vazio
    if (argc < 3) return -1;
    for (int i = 1; i < argc; i += 1) valor.push_back(atoi(argv[i]));
    MDC teste(valor);
    cout << teste;
    return 0;
}

MDC::MDC(const vector<int>& valor) : valor(valor), mdc(valor[0])
{
    for (int i = 1; i < (int)valor.size(); i += 1) mdc = Euclides(mdc, valor[i]);
}

int MDC::Euclides(int a, int b)
{   // MDC pelo metodo de Euclides
    int resto;
    while (b != 0)
    {
        resto = a % b;
        a = b;
        b = resto;
    }
    return a;
}

ostream& operator << (ostream& sai, const MDC& m)
{
    sai << "MDC(";
    for (int i = 0; i < (int)m.valor.size() - 1; i += 1)
        sai << m.valor[i] << ",";
    sai << m.valor[m.valor.size() - 1] << ") = " << m.mdc << "\n";
    return sai;
};

// fim