#include <stdio.h>
int sumShelf(const int *shelf, int count) {
    int sum = 0;
    int j;
    for (j= 0; j < count; j++)
        sum += *(shelf + j);
    return sum;
}
int findLargestShelf(const int *counts, int shelves) {
    int best = 0;
    int i;
    for (i = 1; i < shelves; i++) {
        if (counts[i] > counts[best])
            best = i;
    }
    return best;
}
int main() {
    int shelfA[] = {101, 102, 103};
    int shelfB[] = {201, 202};
    int shelfC[] = {301, 302, 303, 304};
    int *shelves[] = {shelfA, shelfB, shelfC};
    int counts[] = {3, 2, 4};
    int n = 3;
    int i;
    for (i = 0; i < n; i++) {
        int total = sumShelf(shelves[i], counts[i]);
        printf("Shelf %d ID total: %d\n", i + 1, total);
    }
    int largest = findLargestShelf(counts, n);
    printf("Shelf with the most books: Shelf %d (%d books)\n",
           largest + 1, counts[largest]);
    return 0;
}
