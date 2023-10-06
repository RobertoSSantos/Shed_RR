#include <stdio.h>
#include <pthread.h>
#include <math.h>
#include <unistd.h>
#include <time.h>

//Para Compilar executar em terminal -> gcc -o alias shed_rr.c -lm
//Para executar em terminal -> ./alias

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
    param.sched_priority = 25;

    start_t = clock();

    //Configurar o schedule
    pthread_setschedparam(thread_4, SCHED_RR, &param);

    // Inicio do processo 

    end_t = clock();
    double total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Tempo de execucao thread 4: %f\n", total_t  );

    //Finalizando a thread
    pthread_exit(NULL);
}