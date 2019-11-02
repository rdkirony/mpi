#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"
#include "dados.h"
#define MAX 1000


int main(int argc, char* argv[])
{   
    
    int size,i,teste;
    MPI_Init(NULL, NULL);

    MPI_Comm_size(MPI_COMM_WORLD, &size);
    int janela[size];
    for(int i=0;i<size;i++){
        janela[i] = i;
    }
    //MPI_Comm_rank(MPI_COMM_WORLD, &teste);
    MPI_Comm_rank(MPI_COMM_WORLD, & Aeroporto.codigo);
    Aeroporto.horarioPartida = 2;
    Aeroporto.tempoVoo = 3; 


    //Voos com origem do aeroporto 0
    Aeroporto.origemVoo = 0;
    novoVoo(Aeroporto.origemVoo,1,Aeroporto.horarioPartida,Aeroporto.tempoVoo);
    //Voos com origem do aeroporto 1
    Aeroporto.origemVoo = 1;
    novoVoo(Aeroporto.origemVoo,2,Aeroporto.horarioPartida,Aeroporto.tempoVoo);
    novoVoo(Aeroporto.origemVoo,2,Aeroporto.horarioPartida,Aeroporto.tempoVoo);
    novoVoo(Aeroporto.origemVoo,2,Aeroporto.horarioPartida,Aeroporto.tempoVoo);
    //Voos com origem do aeroporto 2
    Aeroporto.origemVoo = 2;
    novoVoo(Aeroporto.origemVoo,3,Aeroporto.horarioPartida,Aeroporto.tempoVoo);
    novoVoo(Aeroporto.origemVoo,3,Aeroporto.horarioPartida,Aeroporto.tempoVoo);
    novoVoo(Aeroporto.origemVoo,1,Aeroporto.horarioPartida,Aeroporto.tempoVoo);
    //Voos com origem do aeroporto 3
    Aeroporto.origemVoo = 3;
    novoVoo(Aeroporto.origemVoo,0,Aeroporto.horarioPartida,Aeroporto.tempoVoo);

    destino(Aeroporto.codigo);
   
    for(int i=0;i<size;i++){
        imprimir(janela[i]);
    }
     
    MPI_Finalize();
     
    return 0;
}
