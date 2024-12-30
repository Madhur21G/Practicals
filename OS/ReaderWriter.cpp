#include "bits/stdc++.h"
using namespace std;
#define int long long
typedef int semaphore;

void signal (semaphore *s){
    (*s)++;
}

int wait(semaphore *s){
    if (*s <= 0){
        cout << "Semaphore waiting in spin lock" << '\n';
        return 0;
    }
    (*s)--;
    return 1;
}

// Mutx which avoids race condition in reading and writing
semaphore rw_mutex = 1;
// Mutex which avoids race condition in changing read_cnt
semaphore mutex = 1;
int read_cnt = 0;

void show_menu();

void writer() {
    if(!wait(&rw_mutex)) return;
    cout << "Writer has ebntered its critical section" << '\n';
    cout << "Enter operation to be performed during its operation" << '\n';
    show_menu();
    signal(&rw_mutex);
}

void reader() {
    if(!wait(%mutex)) return;
    read_cnt += 1;
    if(read_cnt == 1){
        if(!wait(&rw_mutex)) return;
    }
    signal(&mutex);
    cout << "Reader has enterd its critical section" << '\n';
    cout << "Enter operation to be performed during its operation" << '\n';
}

signed main(){
    show_menu();
    return 0;
}

void reader() {
    if (!wait(&mutex)) return;
    read_count++;
    if (read_count == 1)
        if (!wait(&rw_mutex)) return;
    signal(&mutex);
    printf("Reader has entered its critical section\n");
    printf("Enter operation to be performed during its operation\n");
    show_menu();
    if (!wait(&mutex)) return;
    read_count--;
    if (read_count == 0) signal(&rw_mutex);
    signal(&mutex);
}

void show_menu() {
    int option;
    do {
        printf("0. Exit\n");
        printf("1. Write\n");
        printf("2. Read\n");
        scanf("%d", &option);
        switch(option) {
            case 0: break;
            case 1: writer(); break;
            case 2: reader(); break;
            default: printf("Invalid option\n");
        }
    } while (option != 0);
}