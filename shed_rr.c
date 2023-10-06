#include <stdio.h>
#include<stdlib.h>
#include <pthread.h>
#include <math.h>
#include <unistd.h>
#include <time.h>

//Para Compilar executar em terminal -> gcc -o shed shed_rr.c -lm
//Para executar em terminal -> ./shed

pthread_t thread_0, thread_1, thread_2, thread_3, thread_4;

void* task_0();
void* task_1();
void* task_2();
void* task_3();
void* task_4();

int main(){
    //Criacao das threads
    pthread_create(&thread_0, NULL, (void *) task_0, NULL);
    pthread_create(&thread_1, NULL, (void *) task_1, NULL);
    pthread_create(&thread_2, NULL, (void *) task_2, NULL);
    pthread_create(&thread_3, NULL, (void *) task_3, NULL);
    pthread_create(&thread_4, NULL, (void *) task_4, NULL);

    //Finaliza todas as threads quando a thread especificada termina e tem um retorno especificado
    pthread_join(thread_0, NULL);
    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);
    pthread_join(thread_3, NULL);
    pthread_join(thread_4, NULL);

    return 0;
}

void* task_0(){
    clock_t start_t, end_t;
    struct sched_param param;

    // Definicao da prioridade
    param.sched_priority = 10;

    start_t = clock();

    //Configurar o schedule
    pthread_setschedparam(thread_0, SCHED_RR, &param);

    // Inicio do processo
    int i,j = 0;
    while(j <= 1000000){
        for(i = 0; i > 1000000; i++){

        }
        j++;
    } 
    
    end_t = clock();
    double total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Tempo de execucao thread 0: %f\n ", total_t  );

    //Finalizando a thread
    pthread_exit(NULL);
}

void* task_1(){
    clock_t start_t, end_t;
    struct sched_param param;

    // Definicao da prioridade
    param.sched_priority = 70;

    start_t = clock();

    //Configurar o schedule
    pthread_setschedparam(thread_1, SCHED_RR, &param);

    // Inicio do processo
    int i, j, k;

    for(i=0; i <= 3000; i++){
        for(j = 300; j >= 0; j--){
            for(k=0; k <= 30;k++){

            }
        }
    } 


    end_t = clock();
    double total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Tempo de execucao thread 1: %f\n ", total_t  );

    //Finalizando a thread
    pthread_exit(NULL);
}

void* task_2(){
    clock_t start_t, end_t;
    struct sched_param param;

    // Definicao da prioridade
    param.sched_priority = 30;

    start_t = clock();

    //Configurar o schedule
    pthread_setschedparam(thread_2, SCHED_RR, &param);

    // Inicio do processo
    int i;
    int vet[100000];
    int n = 100000;

    for(i=0; i < n-1; i++){
        vet[i] = rand()%100;
    }

    for(i=0; i < n-1; i++){
        vet[i] *= 1;
    }

    end_t = clock();
    double total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Tempo de execucao thread 2: %f\n", total_t  );

    //Finalizando a thread
    pthread_exit(NULL);
}

void* task_3(){
    clock_t start_t, end_t;
    struct sched_param param;

    // Definicao da prioridade
    param.sched_priority = 80;

    start_t = clock();

    //Configurar o schedule
    pthread_setschedparam(thread_3, SCHED_RR, &param);

    // Inicio do processo 
    int i=0;
    int vet[100000];
    int n = sizeof(vet) / sizeof(vet[0]);
    int x = rand()%100;

    for(i=0; i < n-1; i++){
        vet[i] = rand()%100;
    }

    while(i <= n){
        int m = i + (n - i) / 2;
 
        // Check if x is present at mid
        if (vet[m] == x)
            m = m;
 
        // If x greater, ignore left half
        if (vet[m] < x)
            i = m + 1;
 
        // If x is smaller, ignore right half
        else
            n = m - 1;
    }

    end_t = clock();
    double total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Tempo de execucao thread 3: %f\n", total_t  );

    //Finalizando a thread
    pthread_exit(NULL);
}

void* task_4(){
    clock_t start_t, end_t;
    struct sched_param param;

    // Definicao da prioridade
    param.sched_priority = 99;

    start_t = clock();

    //Configurar o schedule
    pthread_setschedparam(thread_4, SCHED_RR, &param);

    // Inicio do processo 
    int size = 1000;  
    int i, j, k;

    int  *A = (int *) malloc (sizeof(int)*size*size);
    int  *B = (int *) malloc (sizeof(int)*size*size);
    int  *C = (int *) malloc (sizeof(int)*size*size);

    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            A[i * size + j] = rand() % (10 - 1) * 1;

    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            B[i * size + j] = rand() % (10 - 1) * 1;

    for(i = 0; i < size; i++)
        for(j = 0; j < size; j++)
            for(k = 0; k < size; k++)
                C[i * size + j] += A[i * size + k] * B[k * size + j];

    end_t = clock();
    double total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Tempo de execucao thread 4: %f\n", total_t  );

    //Finalizando a thread
    pthread_exit(NULL);
}