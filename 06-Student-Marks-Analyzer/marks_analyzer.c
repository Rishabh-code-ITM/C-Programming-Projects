#include <stdio.h>                                          // Standard input output library

#define SUBJECTS 5                                          // Har student ke 5 subjects

int main() {                                                // Program yahin se start hota hai (main function)
    int n;                                                  // Students ki ginti
    printf("Enter number of students: ");                   // Students ki sankhya maango
    scanf("%d", &n);                                        // Input lo
    if (n <= 0 || n > 50) {                                 // 1 se 50 ke bahar ki value
        printf("Please enter between 1 and 50.\n");         // Message
        return 1;                                           // Error code ke saath band
    }                                                       // if block end

    float marks[50][SUBJECTS];                              // 2D array: har row ek student, har column ek subject
    float total[50];                                        // Har student ka total
    float classTotal = 0;                                   // Poori class ke totals ka sum
    int passCount = 0, topper = 0, lowest = 0;              // Pass hone wale, topper ka index, sabse kam wale ka index

    for (int i = 0; i < n; i++) {                           // Har student ke liye
        total[i] = 0;                                       // Total 0 se start
        printf("\nStudent %d - enter %d marks: ", i + 1, SUBJECTS);   // Marks maango
        int failed = 0;                                     // Kisi subject mein fail hua ya nahi
        for (int j = 0; j < SUBJECTS; j++) {                // Har subject ke liye
            scanf("%f", &marks[i][j]);                      // Marks input lo
            total[i] += marks[i][j];                        // Total mein jodo
            if (marks[i][j] < 33) failed = 1;               // 33 se kam hai to fail flag on
        }                                                   // inner for loop end
        if (!failed) passCount++;                           // Kisi mein fail nahi hua to pass count badhao
        classTotal += total[i];                             // Class total mein jodo
        if (total[i] > total[topper]) topper = i;           // Zyada total mila to topper update
        if (total[i] < total[lowest]) lowest = i;           // Kam total mila to lowest update
    }                                                       // outer for loop end

    printf("\n===== RESULT ANALYSIS =====\n");               // Heading
    for (int i = 0; i < n; i++) {                           // Har student ka summary
        float percent = total[i] / SUBJECTS;                // Percentage (har subject 100 mein se)
        printf("Student %d: Total = %.1f, Percentage = %.2f%%\n", i + 1, total[i], percent);   // Print karo
    }                                                       // for loop end

    printf("\nClass average (total): %.2f\n", classTotal / n);          // Class ka average total
    printf("Topper: Student %d with %.1f marks\n", topper + 1, total[topper]);   // Topper ki details
    printf("Lowest: Student %d with %.1f marks\n", lowest + 1, total[lowest]);   // Sabse kam wale ki details
    printf("Passed: %d | Failed: %d\n", passCount, n - passCount);     // Pass aur fail ki ginti
    printf("Pass percentage: %.2f%%\n", (float)passCount / n * 100);   // Pass percentage

    return 0;                                               // Program successfully khatam
}                                                           // main function end
