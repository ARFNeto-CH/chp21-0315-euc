#include <execution> 
#include <iostream> 
#include <vector>  
using namespace std;

struct MDC
{
    const vector<int>& valor;
    int             mdc;
    MDC(const vector<int>&);
    friend ostream& operator<< (ostream& sai, const MDC& m);
};

auto Euclides = [](int a, int b)
{   // MDC pelo metodo de Euclides
    int resto;
    while (b != 0)
    {   resto = a % b;
        a = b;
        b = resto;
    };
    return a;
};

int main(int argc, char** argv)
{
    vector<int>valor{}; // vazio
    if (argc < 3) return -1; // precisa de 2 ao menos
    for (int i = 1; i < argc; i += 1) valor.push_back(atoi(argv[i]));
    MDC teste(valor); // os valores estao todos no vetor 'valor'
    cout << teste;

    return 0;
};

MDC::MDC(const vector<int>& valor) : valor(valor), mdc(0)
{
    mdc = std::reduce(std::execution::par, valor.begin(), valor.end(), mdc, Euclides);
};

ostream& operator << (ostream& sai, const MDC& m)
{
    sai << "MDC(";
    for (int i = 0; i < (int)m.valor.size() - 1; i += 1)
        sai << m.valor[i] << ",";
    sai << m.valor[m.valor.size() - 1] << ") = " << m.mdc << "\n";
    return sai;
};
