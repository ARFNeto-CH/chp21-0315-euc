#include <iostream> 
#include <numeric> 
#include <vector>  
using namespace std;

int main(int argc, char** argv)
{
    vector<int> valor{}; // vazio
    int mdc = 0;
    if (argc < 3) return -1; // precisa de 2 ao menos
    for (int i = 1; i < argc; i += 1) valor.push_back(atoi(argv[i]));
    mdc = std::reduce(valor.begin(), valor.end(), mdc,
        [](int a, int b)
        {   // MDC pelo metodo de Euclides
            int resto;
            while (b != 0)
            {   resto = a % b;
                a = b;
                b = resto;
            };
            return a;
        });
    cout << "MDC = " << mdc << endl;
    return 0;
};