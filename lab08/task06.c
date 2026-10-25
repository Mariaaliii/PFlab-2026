#include <stdio.h>
int deposit(float *balance, float amount) {
    if (amount <= 0) {
        return 0;
    }
    *balance = *balance + amount;
    return 1;
}
int withdraw(float *balance, float amount) {
    if (amount <= 0 || amount > *balance) {
        return 0;
    }
    *balance = *balance - amount;
    return 1;
}
int main() {
    float balance = 1000.0, amount;
    int choice, result;
    do {
        printf("Choose option (1-4): ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter amount: ");
            scanf("%f", &amount);
            result = deposit(&balance, amount);

            if (result)
                printf("Amount deposited successfully.\n");
            else
                printf("Invalid amount.\n");
        }
        else if (choice == 2) {
            printf("Enter amount: ");
            scanf("%f", &amount);
            result = withdraw(&balance, amount);
            if (result)
                printf("Amount withdrawn successfully.\n");
            else
                printf("Insufficient funds or invalid amount.\n");
        }
        else if (choice == 3)
        {
            printf("Current balance: %.2f\n", balance);
        }
        else if (choice == 4)
        {
            printf("Goodbye.\n");
        }
        else
        {
            printf("Invalid option.\n");
        }
    } while (choice != 4);
    return 0;
}
