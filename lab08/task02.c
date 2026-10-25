#include<stdio.h>
void swapValues(int *A, int *B) {
	int temp = *A;
	*A = *B;
	*B = temp;
	return;
}
int main() {
	int A, B;
	printf("Enter price A: ");
    scanf("%d", &A);
    printf("\nEnter price B: ");
    scanf("%d", &B);
    printf("\nBefore swap: A = %d , B = %d", A, B);
    swapValues(&A, &B);
    printf("\nAfter swap: A = %d , B = %d", A, B);
    return 0;
}
