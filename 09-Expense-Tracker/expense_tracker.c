#include <stdio.h>                                          // Standard input output library

#define FILENAME "expenses.txt"                             // Expenses save karne wali file

int main() {                                                // Program yahin se start hota hai (main function)
    int choice;                                             // Menu choice

    do {                                                    // Menu baar baar dikhane ka loop
        printf("\n===== EXPENSE TRACKER =====\n");          // Heading
        printf("1. Add Expense\n2. View All Expenses\n3. Total Spending\n4. Exit\n");   // Menu
        printf("Enter choice: ");                           // Choice maango
        scanf("%d", &choice);                               // Choice input lo

        if (choice == 1) {                                  // Expense add karna
            char category[30];                              // Category (Food, Travel, etc.)
            float amount;                                   // Kharcha
            printf("Enter category (one word): ");          // Category maango
            scanf(" %29s", category);                       // Category input lo
            printf("Enter amount: ");                       // Raashi maango
            scanf("%f", &amount);                           // Raashi input lo
            if (amount <= 0) {                              // Galat raashi
                printf("Invalid amount!\n");                // Message
                continue;                                   // Loop ke agle iteration par jao
            }                                               // if block end
            FILE *fp = fopen(FILENAME, "a");                // Append mode: purana data rakhkar end mein jodta hai
            if (fp == NULL) {                               // File nahi khuli
                printf("Cannot open file!\n");              // Error message
                continue;                                   // Agle iteration par
            }                                               // if block end
            fprintf(fp, "%s %.2f\n", category, amount);     // File mein ek line likhi: category amount
            fclose(fp);                                     // File band karo
            printf("Expense added!\n");                     // Confirmation
        } else if (choice == 2 || choice == 3) {            // View ya total, dono ke liye file padhni padegi
            FILE *fp = fopen(FILENAME, "r");                // Read mode mein file kholi
            if (fp == NULL) {                               // File hai hi nahi
                printf("No expenses recorded yet.\n");      // Message
                continue;                                   // Agle iteration par
            }                                               // if block end
            char category[30];                              // File se padhi hui category
            float amount, total = 0;                        // Padhi hui raashi aur total
            int n = 0;                                      // Entries ki ginti
            if (choice == 2) printf("\n%-4s %-15s %s\n", "No.", "Category", "Amount");   // Table ka heading
            while (fscanf(fp, "%29s %f", category, &amount) == 2) {   // Jab tak ek poori entry padh paaye
                n++;                                        // Ginti badhao
                total += amount;                            // Total mein jodo
                if (choice == 2) printf("%-4d %-15s %.2f\n", n, category, amount);   // View mode mein entry dikhao
            }                                               // while loop end
            fclose(fp);                                     // File band karo
            if (choice == 3) printf("Total spending: %.2f (%d entries)\n", total, n);   // Total mode mein sum dikhao
        } else if (choice != 4) {                           // 1,2,3,4 ke alawa kuch bhi
            printf("Invalid choice!\n");                    // Error message
        }                                                   // if-else chain end
    } while (choice != 4);                                  // 4 dabane tak chalta rahega

    printf("Goodbye!\n");                                   // Vida message
    return 0;                                               // Program successfully khatam
}                                                           // main function end
