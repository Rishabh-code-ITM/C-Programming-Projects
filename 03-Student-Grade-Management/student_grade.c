#include <stdio.h>                                          // Standard input output library

#define MAX 50                                              // Maximum students ki limit (macro constant)

struct Student {                                            // Student ka structure
    int roll;                                               // Roll number
    char name[50];                                          // Naam
    float marks[3];                                         // Teen subjects ke marks
    float percentage;                                       // Percentage
    char grade;                                             // Grade (A, B, C, D, F)
};                                                          // Structure end

char getGrade(float p) {                                    // Percentage se grade nikalne wala function
    if (p >= 90) return 'A';                                // 90 ya zyada: A
    if (p >= 75) return 'B';                                // 75 se 89: B
    if (p >= 60) return 'C';                                // 60 se 74: C
    if (p >= 40) return 'D';                                // 40 se 59: D
    return 'F';                                             // 40 se kam: Fail
}                                                           // getGrade function end

int main() {                                                // Program yahin se start hota hai (main function)
    struct Student s[MAX];                                  // Students ka array
    int count = 0, choice;                                  // Abhi tak kitne students hain, aur menu choice

    do {                                                    // Menu baar baar dikhane ka loop
        printf("\n--- Student Grade Management ---\n");     // Heading
        printf("1. Add Student\n2. Show All\n3. Search by Roll\n4. Exit\n");   // Menu options
        printf("Enter choice: ");                           // Choice maango
        scanf("%d", &choice);                               // Choice input lo

        switch (choice) {                                   // Choice ke hisaab se kaam
            case 1:                                         // Student add karna
                if (count >= MAX) {                         // Agar limit poori ho gayi
                    printf("Student list is full!\n");      // Message
                    break;                                  // switch se bahar
                }                                           // if block end
                printf("Enter roll number: ");              // Roll maango
                scanf("%d", &s[count].roll);                // Roll input lo
                printf("Enter name: ");                     // Naam maango
                scanf(" %49[^\n]", s[count].name);          // Spaces ke saath naam input lo
                float total = 0;                            // Total marks ka variable
                for (int i = 0; i < 3; i++) {               // Teen subjects ke liye loop
                    printf("Enter marks of subject %d: ", i + 1);   // Marks maango
                    scanf("%f", &s[count].marks[i]);        // Marks input lo
                    total += s[count].marks[i];             // Total mein jodo
                }                                           // for loop end
                s[count].percentage = total / 3;            // Percentage = total / subjects (har subject 100 mein se)
                s[count].grade = getGrade(s[count].percentage);   // Function se grade nikalo
                count++;                                    // Student ginti badhao
                printf("Student added!\n");                 // Confirmation
                break;                                      // switch se bahar
            case 2:                                         // Saare students dikhana
                if (count == 0) {                           // Agar koi student nahi hai
                    printf("No records found.\n");          // Message
                }                                           // if block end
                for (int i = 0; i < count; i++) {           // Har student par loop
                    printf("Roll: %d | Name: %s | %.2f%% | Grade: %c\n",
                           s[i].roll, s[i].name, s[i].percentage, s[i].grade);   // Student ki details print karo
                }                                           // for loop end
                break;                                      // switch se bahar
            case 3: {                                       // Roll number se search karna
                int r, found = 0;                           // Dhundhne wala roll aur found flag
                printf("Enter roll number to search: ");    // Roll maango
                scanf("%d", &r);                            // Roll input lo
                for (int i = 0; i < count; i++) {           // Har student check karo
                    if (s[i].roll == r) {                   // Agar roll match hua
                        printf("Name: %s | %.2f%% | Grade: %c\n",
                               s[i].name, s[i].percentage, s[i].grade);   // Details dikhao
                        found = 1;                          // Flag 1 kar do
                        break;                              // Aage dhundhne ki zaroorat nahi
                    }                                       // if block end
                }                                           // for loop end
                if (!found) printf("Student not found.\n"); // Nahi mila to message
                break;                                      // switch se bahar
            }                                               // case 3 block end
            case 4:                                         // Exit
                printf("Goodbye!\n");                       // Vida message
                break;                                      // switch se bahar
            default:                                        // Galat choice
                printf("Invalid choice!\n");                // Error message
        }                                                   // switch end
    } while (choice != 4);                                  // 4 dabane tak menu chalta rahega

    return 0;                                               // Program successfully khatam
}                                                           // main function end
