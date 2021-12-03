/*Dato un vettore di 10 elementi predefiniti, il main crea un thread che si occupa di fare la somma del vettore.
Quando finisce, il main stampa il risultato*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pthread.h>

#define N 10

int v[N] = {10,11,12,13,14,15,16,17,18,19};
int somma=0;

void *thread_f(void *arg){
    
    printf("\nThread here, working");
    for(int i=0;i<N;i++){
        somma=somma+v[i];
    }
    
    printf("\nThread done. Exiting");
    pthread_exit(NULL);  //********* IMPORTANTE: NON DEVO METTERE EXIT MA PTHREAD_EXIT!!!
}

int main(){
    pthread_t thread;//tid
    void *retval;
    int res;
    printf("\nv : ");
    for(int i=0;i<N;i++){
        printf(" %d ",v[i]);
    }
    printf("\nCreo thread per la somma");
    res=pthread_create(&thread,NULL,thread_f,NULL); //se dovessi passare il vettore il 4° parametro sarebbe (void *)v
    if(res!=0){
        perror("\nCreate failed");
        exit(EXIT_FAILURE);
    }
    printf("\nThread sta eseguendo..");
    sleep(2);
    res=pthread_join(thread,NULL);
    if(res!=0){
        perror("\nJoin failed");
        exit(EXIT_FAILURE);
    }
    printf("\nThread done, result : %d",somma);
    exit(EXIT_SUCCESS);


}
