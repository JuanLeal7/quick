#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

bool repe(int n, int num[])
{
    for(int i=0; i<20; i++)
        if(n == num[i])
            return true;
    return false;
}
void quick(int numeros[],int inicio, int fin){
	int izq, der, piv,aux;
	izq=inicio;
	der=fin;
	piv= numeros[(izq + der)/2];
	
	do{
		while(numeros[izq]<piv && izq<fin){
			izq++;
		}
		while(numeros[der]>piv && der>inicio){
			der--;
		}
		if(izq<=der){
			aux= numeros[izq];
			numeros[izq] =numeros[der];
			numeros[der]=aux;
			izq++;
			der--;
		}
	}while(izq<=der);
	if(inicio<= der){
		quick(numeros,inicio,der);
	}
	if(fin>izq){
		quick(numeros,izq,fin);
	}
}
int main()
{
	
    srand(time(NULL));
    int n, numeros[20];
      cout << "Numeros en desorden:" << endl;
    for(int i=0; i<20; i++)
    {
        do
            n = 1 + rand() % 100;
          
        while(repe(n, numeros));
        numeros[i] = n;
        
        cout << numeros[i] << "  ";
     
    }
    cout << "" << endl;
cout << "Numeros en orden:" << endl;
        for (int i = 1; i < 21; ++i) {
      quick(numeros,0,20);
	  cout << numeros[i] << "  ";  
	}
}
