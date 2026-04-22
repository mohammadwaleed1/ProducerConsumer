//as defined in buffer file that we didnt included locks there,locks are defined here and applied to func in thirs file
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
pthread_mutex_t lock;
sem_t full; //sema lock for waiter to see if there are any orders to pick (value > 0) and to indicate no order (value =0)
sem_t empty;//sema lock to for chef to see if the table is empty to place the dish (value > 0) and to indicate table is full(value =0)

void init_sync(){
    pthread_mutex_init(&lock, NULL);
    sem_init(&full, 0, 0);// starts at 0, nothing for waiter to pick
    sem_init(&empty, 0, 5);// starts at 5, table in empty chef will fill the table
    printf("mutex and semaphores ready\n");
}
void destroy_sync(){
    pthread_mutex_destroy(&lock);
    sem_destroy(&full);
    sem_destroy(&empty);
    printf("cleanup done\n");
}
int main(){
    init_sync();
    destroy_sync();
    return 0;
}