#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "buffer.h"

#define num_prod 3
#define items_limit 5

void* producer(void* arg){
    int id = *(int*)arg;
    for (int i = 0; i < items_limit; i++) {
        int item = (id * 10) + i;
        insert(item);
        sleep(1);
    }
    printf("producer %d done\n", id);
    return NULL;
    
}

