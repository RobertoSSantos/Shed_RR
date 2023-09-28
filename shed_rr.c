#include <stdio.h>
#include <pthread.h>
#include <math.h>
#include <unistd.h>

//Compilar - gcc -o alias shed_rr.c -lm
//Run - ./alias

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
    pthread_join(thread_4, NULL);

    return 0;
}

void* task_0(void *param){
    // set 
    pthread_exit(NULL);
}

void* task_1(void *param){
    pthread_exit(NULL);
}

void* task_2(void *param){
    pthread_exit(NULL);
}

void* task_3(void *param){
    pthread_exit(NULL);
}

void* task_4(void *param){
    pthread_exit(NULL);
}