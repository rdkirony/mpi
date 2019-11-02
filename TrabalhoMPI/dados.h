#define MAX 1000
struct{
    int codigo;
    int numeroPousos = 0;
    int numeroDecolagens = 0;
    int codigoVoo;
    int origemVoo;
    int horarioChegada;
    float horarioPartida;
    float tempoVoo;
    int lc;
}Aeroporto;

int aux[MAX];
int aux2[MAX];

void novoVoo(int origem, int destino,  float horarioPartida, float tempoVoo){

    MPI_Bsend(&origem, 1, MPI_INT, destino, 0, MPI_COMM_WORLD);
    MPI_Bsend(&destino, 1, MPI_INT, destino, 0, MPI_COMM_WORLD);
    MPI_Bsend(&horarioPartida, 1, MPI_INT, destino, 0, MPI_COMM_WORLD);
    MPI_Bsend(&tempoVoo, 1, MPI_INT, destino, 0, MPI_COMM_WORLD);  
    
    if(origem == Aeroporto.codigo){
        int i=0;
        Aeroporto.numeroDecolagens++;
        aux[i++] = Aeroporto.numeroDecolagens;
        //printf("\nDecolagem %d do dia detectada destino aeroporto %d\n",Aeroporto.numeroDecolagens,destino); 
    }
    if(destino == Aeroporto.codigo){
        int i=0;
        Aeroporto.numeroPousos++;
        aux2[i++] = Aeroporto.numeroPousos;
    }
       
}
void destino(int origemVoo){

    
} 

void imprimir(int janela){
    float received;
    float received2;
    int codigoDestino;
    int codigoOrigem;
    MPI_Recv(&codigoOrigem, 1, MPI_INT, janela, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE); 
    MPI_Recv(&codigoDestino, 1, MPI_INT, janela, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE); 
    MPI_Recv(&received, 1, MPI_INT, janela, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    MPI_Recv(&received2, 1, MPI_INT, janela, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE); 
    if(janela == Aeroporto.codigo){
        printf("\nCódigo %d\n",janela);
        printf("\nPousos:    %d  Decolagens:   %d\n",Aeroporto.numeroPousos,Aeroporto.numeroDecolagens);
        printf("\nPousos   Origem   Horário de Chegada   Tempode voo\n");
        for(int i=0;i<Aeroporto.numeroPousos;i++){ 
            printf("\n%d%d         %d            %d                  %d\n",codigoOrigem,aux[i],codigoOrigem,received+received2,received2);
        }
        printf("\nDecolagens  Destino   Horário de Partida   Tempode voo\n");
        for(int i=0;i<Aeroporto.numeroDecolagens;i++){ 
            printf("\n%d%d              %d            %d                  %d\n",codigoOrigem,aux2[i],codigoDestino,received,received2);
        }        
    }
}
