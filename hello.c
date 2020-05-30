#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
void *thread_fun(void *vargp) 
{ 
    printf("Hello World\n"); 
    return 0; 
}  
int main() 
{ 
    pthread_t thread_id; 
    printf("Before Thread Creation\n"); 
    pthread_create(&thread_id, NULL, thread_fun, NULL); 
    pthread_join(thread_id, NULL); 
    printf("After Thread Creation\n"); 
    exit(0); 
}