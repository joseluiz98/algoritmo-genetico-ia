#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int main()
{
    int n=30; ///limite m�ximo de valores para a,b,c,d
    int m=4; ///quantidade de genes (a,b,c,d)
    int npop=6; ///numero de individuos da populacao
    int f[4] = {1,2,3,4}; ///coeficientes da funcao objetivo
    float pc=0.25; ///probabilidade de cruzamento
    float pm=0.1; ///probabilidade de mutacao
    int Chromossome[npop][m], NewChromossome[npop][m];

    srand(time(NULL));
    for(int i = 0; i<npop; i++)
    {
        for(int j = 0; j<m; j++)
        {
            Chromossome[i][j] = rand() % 30 + 1;
        }
    }

    float F_obj[npop];
    int contador=0;

    while(contador<50)
    {
        for(int i=0; i<npop; i++)
        {
            for(int j=0; j<m; j++)
            {
                F_obj[i] += abs(f[j]*Chromossome[i][j]-30);
            }
        }


        float Fitness[npop],Total=0;
        for(int i=0; i<npop; i++)
        {
            Fitness[i]=1/(1+F_obj[i]);
            Total += Fitness[i];
        }

        float P[npop];
        for(int i=0; i<npop; i++)
        {
            P[i] = Fitness[i]/Total;
        }

        float C[npop],soma=0;
        for(int i=0; i<npop; i++)
        {
            soma += P[i];
            C[i] = soma;
        }

        double R[npop];
        for(int i=0; i<npop; i++)
        {
            R[i] = (rand()%101);
            R[i] /= 100;
        }

        int aux = 0;
        for(int i=0; i<npop; i++)
        {
            /// Descobre quantos elementos de R são maiores que C
          for(int k=0; k<npop; k++)
          {
              if(R[k] > C[k])
              {
                  aux++;
              }
          }

          for(int j = 0; j<m; j++)
          {
              if (aux != 0) NewChromossome[i][j] = Chromossome[aux+1][j];
              else
                NewChromossome[i][j] = Chromossome[1][j];
          }
        }


        contador++;
        }

        for(int i=0; i<npop; i++)
        {
            for(int j=0; j<m; j++)
            {
                Chromossome[i][j]=NewChromossome[i][j];
            }
        }

        int tam_pai=0;
        double R[npop];
        while(tam_pai<1)
        {
            for(int i=0; i<npop; i++)
            {
                R[i] = (rand()%101);
                R[i] /= 100;
            }

            int v=0;
            for(int i=0; i<npop; i++)
            {
                if(R[i] < pc)
                {
                    v = i;
                    break;
                }
            }
            pai = v;
            /// PARAMOS NA LINHA 70

        }
    return 0;
}
