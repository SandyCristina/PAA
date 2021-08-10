//Tarefa de Programação - PAA
//Algoritmo de Ordenção - Quicksort
//Aluna: Sandy Cristina Barros

#include <iostream>
#include <locale.h>
using namespace std;

//FUNÇÃO PARTIÇÃO RESPONSAVEL POR FAZER AS ORDENAÇÕES POR MEIO DO PIVO
int particao(int vetor[], int posiInicial, int posiFinal)
{
    int pivo = vetor[posiFinal];
    int i = (posiInicial -1);
    for(int j = posiInicial; j <= posiFinal - 1; j++)
    {
        if(vetor[j] <= pivo)
        {
            i = i + 1;
            swap(vetor[i], vetor[j]);
        }
    }
    swap(vetor[i+1], vetor[posiFinal]);
    return i+1;
}

//PROCEDIMENTO QUICKSORT
void quicksort(int vetor[], int posiInicial, int posiFinal)
{
    int p = 0;
    if(posiInicial < posiFinal)
    {
        p = particao(vetor, posiInicial, posiFinal);
        quicksort(vetor, posiInicial, p-1);//esquerda do pivo
        quicksort(vetor, p+1, posiFinal);//direita do pivo
    }
}
int main()
{
    setlocale(LC_ALL, "Portuguese");
    int posiInicial = 0;
    int posiFinal = 14;
    int vetor[15]= {9,10,-1,3,6,2,1,-3,1,0,-2,15,8,-7,0};

    //MOSTRANDO O VETOR DESORDENADO
    cout << "--------------- VETOR DESORDENADO ---------------" << endl;
    for(int i = 0; i < 15; i ++)
    {
        cout <<" " <<vetor[i]<< " ";
    }
    cout<<" "<<endl;

    //CHAMANDO O PROCEDIMENTO
    quicksort(vetor, posiInicial, posiFinal);
    cout << endl;

    //MOSTRANDO O VETOR ORDENADO
    cout << "--------------- VETOR ORDENADO ---------------" << endl;
    for(int i = 0; i < 15; i ++)
    {
        cout <<" " <<vetor[i]<<" ";
    }
    cout<<" "<<endl;

    return 0;
}
