#include<stdio.h>
int heap[1000];
int sz; // size of the heap
// idx -> index 

void Heap(){ sz = 0;}

void heapify(int idx, int sz){
    int largest = idx;
    int leftidx = 2 * idx + 1;
    int rightidx = 2 * idx + 2;
    if (leftidx < sz && heap[leftidx] > heap[largest]){
        largest = leftidx;
    }
    if (rightidx < sz && heap[rightidx] > heap[largest]){
        largest = rightidx;
    }
    if (largest != idx){
        int temp = heap[largest];
        heap[largest] = heap[idx];
        heap[idx] = temp;
        heapify(largest, sz);
    }
}

void heapsort(){
    int sz = sz;
    while(sz > 0){
        int k = heap[0];
        heap[0] = heap[sz - 1];
        heap[sz - 1] = k;
        sz--;
        heapify(0, sz);
    }
}

void maxheapinsert(int data){
    int index = sz;
    sz++;
    heap[index] = data;
    while(index >= 0){
        int p_idx = index/2;
        if(heap[p_idx] < heap[index]){
            int temp = heap[p_idx];
            heap[p_idx] = heap[index];
            heap[index] = temp;
            index = p_idx;
        }
        else return;
    }
}

void deleteFromMaxHeap(){
    if (sz == 0) return;
    heap[0] = heap[sz - 1];
    sz--;
    int i = 0;
    while (i < sz){
        int left_idx = 2 * i + 1;
        int right_idx = 2 * i + 2;
        if (left_idx < sz && heap[left_idx] > heap[i]){
            int temp = heap[left_idx];
            heap[left_idx] = heap[i];
            heap[i] = temp;
            i = left_idx;
        }
        else if (right_idx < sz && heap[right_idx] > heap[i]){
            int temp = heap[right_idx];
            heap[right_idx] = heap[i];
            heap[i] = temp;
            i = right_idx;
        }
        else return;
    }
}

void display(){
    for(int i = 0; i < sz; i++) printf("%d ", heap[i]);
    printf("\n");
}

int main(){
    Heap();
    int element;
    printf("Press -1 for stop the insertion\n");
    printf("Enter the element\n");
    while (1){
        scanf("%d", &element);
        if (element == -1) break;
        maxheapinsert(element);
    }
    printf("Before Sorting : ");
    display();
    heapsort();
    printf("After Sorting : ");
    display();
    return 0;
}

// 0 
// 14
// 15
// 5
// 20
// 30
// 8
// 40