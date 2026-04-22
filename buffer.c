//in this we are just making the function not applying the locks (mutex & sema ) we can directly apply locks here by initializing the mutex and sema 
//at first place but to make code look cleaner locks are initialized in other file and then locks applied in third file
#include <stdio.h>
#define SIZE 5 //subject to change 

int buffer[SIZE];// shared buffer memory
int in = 0; //insert index
int out = 0; // remove index
int count = 0;// to keep check for buffer overflow

void insert(int item){ //placing order
    if (count == SIZE) {
        printf("buffer full\n");
        return;
    }
    buffer[in] = item;
    in = (in + 1) % SIZE;
    count++;
    printf("inserted: %d | count: %d/%d\n", item, count, SIZE);
}
int removeItem(){ //picking order from table
    if (count == 0) {
        printf("buffer empty\n");
        return -1;
    }
    int item = buffer[out];
    out = (out + 1) % SIZE;
    count--;
    printf("removed: %d | count: %d/%d\n", item, count, SIZE);
    return item;
}
int main(){
    insert(1);
    insert(2);
    insert(3);
    removeItem();
    insert(4);
    insert(5);
    insert(6);
    insert(7);  //buffer full
    removeItem();
    removeItem();
    removeItem();
    removeItem();
    removeItem();
    removeItem(); //buffer empty
    return 0;
}