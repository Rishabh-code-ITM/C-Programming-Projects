#include <stdio.h>                                          // Standard input output library
#include <string.h>                                         // String functions ke liye

#define MAX 100                                             // Maximum students ki limit

struct Student {                                            // Student ka structure
    int roll;                                               // Roll number
    char name[50];                                          // Naam
    char course[30];                                        // Course
    float marks;                                            // Marks
};                                                          // Structure end

int findStudent(struct Student s[], int n, int roll) {      // Roll se student ka index dhundhne ka function
    for (int i = 0; i < n; i++) {                           // Har student check karo
        if (s[i].roll == roll) return i;                    // Mil gaya to index return
    }                                                       // for loop end
    return -1;                                              // Nahi mila to -1
}                                                           // findStudent function end

int main() {                                                // Program yahin se start hota hai (main function)
    struct Student st[MAX];                                 // Students ka array
    int count = 0, choice, roll, idx;                       // Ginti, choice, roll, index

    do {                                                    // Menu baar baar dikhane ka loop
        printf("\n===== STUDENT MANAGEMENT =====\n");       // Heading
        printf("1. Add\n2. Display All\n3. Search\n4. Update\n5. Delete\n6. Exit\n");   // Menu
        printf("Enter choice: ");                           // Choice maango
        scanf("%d", &choice);                               // Choice input lo

        switch (choice) {                                   // Choice ke hisaab se kaam
            case 1:                                         // Student add karna
                if (count >= MAX) {                         // Limit poori
                    printf("Database full!\n");             // Message
                    break;                                  // switch se bahar
                }                                           // if block end
                printf("Enter roll number: ");              // Roll maango
                scanf("%d", &roll);                         // Input lo
                if (findStudent(st, count, roll) != -1) {   // Duplicate roll
                    printf("Roll number already exists!\n");    // Message
                    break;                                  // switch se bahar
                }                                           // if block end
                st[count].roll = roll;                      // Roll save karo
                printf("Enter name: ");                     // Naam maango
                scanf(" %49[^\n]", st[count].name);         // Spaces ke saath naam input lo
                printf("Enter course: ");                   // Course maango
                scanf(" %29[^\n]", st[count].course);       // Course input lo
                printf("Enter marks: ");                    // Marks maango
                scanf("%f", &st[count].marks);              // Marks input lo
                count++;                                    // Ginti badhao
                printf("Student added!\n");                 // Confirmation
                break;                                      // switch se bahar
            case 2:                                         // Saare students dikhana
                if (count == 0) printf("No records.\n");    // Khali list
                for (int i = 0; i < count; i++) {           // Har student par loop
                    printf("Roll: %d | %s | %s | Marks: %.1f\n",
                           st[i].roll, st[i].name, st[i].course, st[i].marks);   // Details print karo
                }                                           // for loop end
                break;                                      // switch se bahar
            case 3:                                         // Student search karna
                printf("Enter roll number: ");              // Roll maango
                scanf("%d", &roll);                         // Input lo
                idx = findStudent(st, count, roll);         // Student dhundho
                if (idx == -1) printf("Student not found!\n");   // Nahi mila
                else printf("Roll: %d | %s | %s | Marks: %.1f\n",
                            st[idx].roll, st[idx].name, st[idx].course, st[idx].marks);   // Details dikhao
                break;                                      // switch se bahar
            case 4:                                         // Student update karna
                printf("Enter roll number to update: ");    // Roll maango
                scanf("%d", &roll);                         // Input lo
                idx = findStudent(st, count, roll);         // Student dhundho
                if (idx == -1) {                            // Nahi mila
                    printf("Student not found!\n");         // Message
                    break;                                  // switch se bahar
                }                                           // if block end
                printf("Enter new name: ");                 // Naya naam maango
                scanf(" %49[^\n]", st[idx].name);           // Input lo
                printf("Enter new course: ");               // Naya course maango
                scanf(" %29[^\n]", st[idx].course);         // Input lo
                printf("Enter new marks: ");                // Naye marks maango
                scanf("%f", &st[idx].marks);                // Input lo
                printf("Record updated!\n");                // Confirmation
                break;                                      // switch se bahar
            case 5:                                         // Student delete karna
                printf("Enter roll number to delete: ");    // Roll maango
                scanf("%d", &roll);                         // Input lo
                idx = findStudent(st, count, roll);         // Student dhundho
                if (idx == -1) {                            // Nahi mila
                    printf("Student not found!\n");         // Message
                    break;                                  // switch se bahar
                }                                           // if block end
                for (int i = idx; i < count - 1; i++) {     // Baaki students ko ek step aage khiskao
                    st[i] = st[i + 1];                      // Agla student current ki jagah copy
                }                                           // for loop end
                count--;                                    // Ginti ghatao
                printf("Record deleted!\n");                // Confirmation
                break;                                      // switch se bahar
            case 6:                                         // Exit
                printf("Goodbye!\n");                       // Vida message
                break;                                      // switch se bahar
            default:                                        // Galat choice
                printf("Invalid choice!\n");                // Error message
        }                                                   // switch end
    } while (choice != 6);                                  // 6 dabane tak chalta rahega

    return 0;                                               // Program successfully khatam
}                                                           // main function end
