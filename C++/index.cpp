#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <chrono>

using namespace std;


void bubble(int *vetor,int tam)
{
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    int aux;
    for(int i=0; i<tam; i++)
        for(int j=0; j<tam-1-i; j++)
        {
            if(vetor[j+1]<vetor[j])
            {
                aux=vetor[j];
                vetor[j]=vetor[j+1];
                vetor[j+1]=aux;
            }
        }
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    cout << "Bubble Sort [ms]: " << (chrono::duration_cast<chrono::milliseconds>(end - begin).count()) << endl;
    if (tam == 100000) {
       cout << "--------------------" << endl;
    }
}

void selection(int *vetor,int tam)
{
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    int menor;
    int aux;

    for(int i=0; i<(tam-1); i++)
    {
        menor = i;
        for(int j=(i+1); j<tam; j++)
        {
            if(vetor[j]<vetor[menor])
                menor=j;
        }
        aux=vetor[i];
        vetor[i]=vetor[menor];
        vetor[menor]=aux;
    }
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    cout << "Selection Sort [ms]: " << (chrono::duration_cast<chrono::milliseconds>(end - begin).count()) << endl;
    if (tam == 100000) {
       cout << "--------------------" << endl;
    }
}

void insertion(int *vet,int n)
{
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    int aux;
    int i,j;


    for( i = 1 ; i < n; i++)
    {
       aux = vet[i];
       j = i-1;
        while (j >= 0 && vet[j]>aux)
          {
                vet[j+1]=vet[j];
                j--;
          }
        vet[j+1] = aux;
    }
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    cout << "Insertion Sort [ms]: " << (chrono::duration_cast<chrono::milliseconds>(end - begin).count()) << endl;
    if (n == 100000) {
       cout << "--------------------" << endl;
    }
}

void shell (int *vet,int n)
{
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    int j,h;
    int aux;

    for (h = n/2; h > 0; h /= 2)
    {
        for (int i = h; i < n; i++)
        {

            aux = vet[i];

            for (j = i; j >= h && vet[j - h] > aux; j -= h)
                vet[j] = vet[j - h];

            vet[j] = aux;
        }
    }
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    cout << "Shell Sort [ms]: " << (chrono::duration_cast<chrono::milliseconds>(end - begin).count()) << endl;
    if (n == 100000) {
       cout << "--------------------" << endl;
    }
}

void mergeIntercala(int *vet,int *aux,int ini, int meio, int fin)
{
    int atual,fimEsq, n;
    atual = ini;
    fimEsq = meio-1;
    n = fin - ini + 1;

    while((ini <= fimEsq) && (meio <= fin))
    {
        if(vet[ini] <= vet[meio])
            aux[atual++] = vet[ini++];
        else
            aux[atual++] = vet[meio++];
    }

    while(ini <= fimEsq)
        aux[atual++]=vet[ini++];

    while(meio <= fin)
        aux[atual++] = vet[meio++];

    for (int i = 0; i < n; i++)
    {
        vet[fin] = aux [fin];
        fin--;
    }
}

void mergeDivide(int *vet,int *aux, int ini, int fin)
{
    int meio;

    if(fin > ini)  //divide ate ter tamanho 1
    {
        meio = (fin+ini)/2;
        //divide problema em 2
        mergeDivide(vet,aux,ini,meio);
        mergeDivide(vet,aux,meio+1,fin);
        //intercala metades
        mergeIntercala(vet,aux,ini,meio+1,fin);
    }
}

void mergesort(int *vet,int n)
{
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    int *aux=new int[n];
    mergeDivide(vet,aux,0,n-1);
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    cout << "Merge Sort [ms]: " << (chrono::duration_cast<chrono::milliseconds>(end - begin).count()) << endl;
    if (n == 100000) {
       cout << "--------------------" << endl;
    }
}



int partition (int *vet, int esq, int dir)
{
    int x;
    int pivo = vet[dir]; // pivot
    int i = (esq - 1); // Index of smaller element


    for (int j = esq; j <= dir - 1; j++)
    {

        if (vet[j] < pivo)
        {
            i++;
            x=vet[i];
            vet[i]=vet[j];
            vet[j]=x;
        }
    }


    x=vet[i+1];
    vet[i+1]=vet[dir];
    vet[dir]=x;

    return (i + 1);
}

void quick(int *vet, int esq, int dir)
{

    if (esq < dir)
    {
        int aux = partition(vet, esq, dir);

        quick(vet, esq, aux - 1);
        quick(vet, aux + 1, dir);
    }
}

int main ()
{
    int n,tempo_ini,tempo_fim,tempo_ms;
    int *vet;
    int valores[5] = {1000, 5000, 10000, 50000, 100000};
    ifstream arq;

    n=100000;

    vet = new int[n];

    int i=0;
    arq.open("../assets/1000000numeros.txt"); // abre o arquivo para leitura
    if (arq.is_open()){

        //cout << "[";
        while((!arq.eof()) && (i<n)){
            int tmp;
            arq >> tmp;
            vet[i] = tmp;
            i++;
        }
        //cout << "]";


    }else{
        cout << "O arquivo nao pode ser aberto" << endl;
        abort();
    }

    for(int k=0;k<5;k++){
        bubble(vet,valores[k]);
    }


    for(int k=0;k<5;k++){
        selection(vet,valores[k]);
    }


    for(int k=0;k<5;k++){
        insertion(vet,valores[k]);
    }


    for(int k=0;k<5;k++){
        shell (vet,valores[k]);
    }


    for(int k=0;k<5;k++){
        mergesort(vet,valores[k]);
    }

    
    for(int k=0;k<5;k++){
        chrono::steady_clock::time_point begin = chrono::steady_clock::now();
        quick(vet,0,valores[k]-1);
        chrono::steady_clock::time_point end = chrono::steady_clock::now();
        cout << "Quick Sort [ms]: " << (chrono::duration_cast<chrono::milliseconds>(end - begin).count()) << endl;
    }
    


    delete[] vet;
    arq.close();
    return 0;
}
