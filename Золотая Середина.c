#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

#define MAXHEAPSIZE 1000000
#define MAXHEAP 1
#define MINHEAP 0

#define SWAP(a, b) do { typeof(a) tmp = a; a = b; b = tmp; } while (0)

typedef struct heap{
    int HeapSize;
    int* h;
    bool mode;
} heap;

void initializeHeap(heap* aheap, bool amode){
    aheap->h = malloc(MAXHEAPSIZE*sizeof(int));
    aheap->HeapSize = 0;
    aheap->mode = amode;
}

void siftUp(heap* aheap, int i){
    while(aheap->mode ? (aheap->h[i] > aheap->h[(i-1)/2]) : (aheap->h[i] < aheap->h[(i-1)/2])){
        SWAP(aheap->h[i], aheap->h[(i-1)/2]);
        i = (i-1)/2;
    }
}

void siftDown(heap* aheap, int i){
    int l,r,j;
    while (2*i + 1 < aheap->HeapSize){
        l = 2*i + 1;
        r = 2*i + 2;
        j = l;
        if ((r < aheap->HeapSize) && (aheap->mode ? (aheap->h[r] > aheap->h[l]) : (aheap->h[r] < aheap->h[l]))){
            j = r;
        }
        if (aheap-> mode ? aheap->h[i] >= aheap->h[j] : aheap->h[i] <= aheap->h[j]){
            break;
        }
        SWAP(aheap->h[i], aheap->h[j]);
        i = j;
    }
}

void add(int n, heap* aheap){
    aheap->HeapSize++;
    aheap->h[aheap->HeapSize-1] = n;
    siftUp(aheap,aheap->HeapSize-1);
}

int deleteRoot(heap* aheap){
    int root = aheap->h[0];
    aheap->h[0] = aheap->h[aheap->HeapSize - 1];
    aheap->HeapSize--;
    siftDown(aheap,0);
    return (root);
}

int main() {
    heap minh, maxh;
    initializeHeap(&minh,MINHEAP);
    initializeHeap(&maxh,MAXHEAP);

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        int t; scanf("%d",&t);
        if (maxh.HeapSize == 0){
            add(t,&maxh);
        } else if (t < maxh.h[0]){
            add(t,&maxh);
            if (minh.HeapSize + 1 < maxh.HeapSize){
                add(deleteRoot(&maxh),&minh);
            }
        } else if (minh.HeapSize == 0){
            add(t,&minh);
        } else {
            add(t,&minh);
            if (minh.HeapSize > maxh.HeapSize){
                add(deleteRoot(&minh),&maxh);
            }
        }
        printf("%d ", maxh.h[0]);
    }
    return 0;
}
