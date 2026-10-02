#include <stdio.h>                                          // Standard input output library

#define MAX 20                                              // Maximum accounts ki limit

struct Account {                                            // Bank account ka structure
    int accNo;                                              // Account number
    char name[50];                                          // Account holder ka naam
    double balance;                                         // Balance
};                                                          // Structure end

int findAccount(struct Account a[], int n, int accNo) {     // Account number se index dhundhne ka function
    for (int i = 0; i < n; i++) {                           // Har account check karo
        if (a[i].accNo == accNo) return i;                  // Mil gaya to uska index return karo
    }                                                       // for loop end
    return -1;                                              // Nahi mila to -1 return karo
}                                                           // findAccount function end

int main() {                                                // Program yahin se start hota hai (main function)
    struct Account acc[MAX];                                // Accounts ka array
    int count = 0, choice, accNo, idx;                      // Ginti, menu choice, account number, index
    double amount;                                          // Paise ki raashi

    do {                                                    // Menu baar baar dikhane ka loop
        printf("\n===== BANKING SYSTEM =====\n");           // Heading
        printf("1. Create Account\n2. Deposit\n3. Withdraw\n4. Check Balance\n5. Show All\n6. Exit\n");   // Menu
        printf("Enter choice: ");                           // Choice maango
        scanf("%d", &choice);                               // Choice input lo

        switch (choice) {                                   // Choice ke hisaab se kaam
            case 1:                                         // Naya account banana
                if (count >= MAX) {                         // Limit poori ho gayi
                    printf("Bank is full!\n");              // Message
                    break;                                  // switch se bahar
                }                                           // if block end
                printf("Enter account number: ");           // Account number maango
                scanf("%d", &accNo);                        // Input lo
                if (findAccount(acc, count, accNo) != -1) { // Agar yeh number pehle se hai
                    printf("Account already exists!\n");    // Duplicate nahi chalega
                    break;                                  // switch se bahar
                }                                           // if block end
                acc[count].accNo = accNo;                   // Account number save karo
                printf("Enter holder name: ");              // Naam maango
                scanf(" %49[^\n]", acc[count].name);        // Spaces ke saath naam input lo
                printf("Enter opening balance: ");          // Shuruaati balance maango
                scanf("%lf", &acc[count].balance);          // Balance input lo
                count++;                                    // Account ginti badhao
                printf("Account created successfully!\n");  // Confirmation
                break;                                      // switch se bahar
            case 2:                                         // Deposit
                printf("Enter account number: ");           // Account number maango
                scanf("%d", &accNo);                        // Input lo
                idx = findAccount(acc, count, accNo);       // Account dhundho
                if (idx == -1) {                            // Nahi mila
                    printf("Account not found!\n");         // Message
                    break;                                  // switch se bahar
                }                                           // if block end
                printf("Enter amount to deposit: ");        // Raashi maango
                scanf("%lf", &amount);                      // Raashi input lo
                if (amount <= 0) {                          // Galat raashi
                    printf("Invalid amount!\n");            // Message
                } else {                                    // Sahi raashi
                    acc[idx].balance += amount;             // Balance mein jodo
                    printf("Deposited. New balance: %.2lf\n", acc[idx].balance);   // Naya balance dikhao
                }                                           // if-else end
                break;                                      // switch se bahar
            case 3:                                         // Withdraw
                printf("Enter account number: ");           // Account number maango
                scanf("%d", &accNo);                        // Input lo
                idx = findAccount(acc, count, accNo);       // Account dhundho
                if (idx == -1) {                            // Nahi mila
                    printf("Account not found!\n");         // Message
                    break;                                  // switch se bahar
                }                                           // if block end
                printf("Enter amount to withdraw: ");       // Raashi maango
                scanf("%lf", &amount);                      // Raashi input lo
                if (amount <= 0) {                          // Galat raashi
                    printf("Invalid amount!\n");            // Message
                } else if (amount > acc[idx].balance) {     // Balance se zyada nikalna chahta hai
                    printf("Insufficient balance!\n");      // Paise kam hain
                } else {                                    // Sab theek hai
                    acc[idx].balance -= amount;             // Balance mein se ghatao
                    printf("Withdrawn. New balance: %.2lf\n", acc[idx].balance);   // Naya balance dikhao
                }                                           // if-else end
                break;                                      // switch se bahar
            case 4:                                         // Balance check
                printf("Enter account number: ");           // Account number maango
                scanf("%d", &accNo);                        // Input lo
                idx = findAccount(acc, count, accNo);       // Account dhundho
                if (idx == -1) printf("Account not found!\n");   // Nahi mila
                else printf("%s's balance: %.2lf\n", acc[idx].name, acc[idx].balance);   // Balance dikhao
                break;                                      // switch se bahar
            case 5:                                         // Saare accounts dikhana
                if (count == 0) printf("No accounts yet.\n");    // Koi account nahi
                for (int i = 0; i < count; i++) {           // Har account par loop
                    printf("AccNo: %d | Name: %s | Balance: %.2lf\n",
                           acc[i].accNo, acc[i].name, acc[i].balance);   // Details print karo
                }                                           // for loop end
                break;                                      // switch se bahar
            case 6:                                         // Exit
                printf("Thank you for banking with us!\n"); // Vida message
                break;                                      // switch se bahar
            default:                                        // Galat choice
                printf("Invalid choice!\n");                // Error message
        }                                                   // switch end
    } while (choice != 6);                                  // 6 dabane tak chalta rahega

    return 0;                                               // Program successfully khatam
}                                                           // main function end
