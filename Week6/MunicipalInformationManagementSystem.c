#include <stdio.h>
#include <string.h>

#define NUM_SALARIES 50
#define NUM_BUDGETS 10
#define NUM_REGISTRATIONS 20
#define REG_STR_LEN 20

// Function prototypes
void processSalaries(void);
void processBudgets(void);
void processRegistrations(void);

int main(void) {
    int choice;

    do {
        printf("\n==================================================\n");
        printf(" MUNICIPAL INFORMATION MANAGEMENT SYSTEM\n");
        printf("==================================================\n");
        printf("1. Employee Salaries Module\n");
        printf("2. Department Budgets Module\n");
        printf("3. Vehicle Registrations Module\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                processSalaries();
                break;
            case 2:
                processBudgets();
                break;
            case 3:
                processRegistrations();
                break;
            case 4:
                printf("\nExiting system. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}

// Module A: Employee Salaries
void processSalaries(void) {
    float salaries[NUM_SALARIES];
    float sum = 0.0f;
    float highest, lowest, searchTarget;
    int i, foundCount = 0;

    printf("\n--- Employee Salaries Module ---\n");
    for (i = 0; i < NUM_SALARIES; i++) {
        printf("Enter salary for employee %d: ", i + 1);
        scanf("%f", &salaries[i]);
    }

    // Display all salaries
    printf("\n--- Captured Salaries ---\n");
    for (i = 0; i < NUM_SALARIES; i++) {
        printf("Employee %d: $%.2f\n", i + 1, salaries[i]);
    }

    // Initialize statistics with the first value
    highest = salaries[0];
    lowest = salaries[0];

    // Calculate sum, highest, and lowest
    for (i = 0; i < NUM_SALARIES; i++) {
        sum += salaries[i];
        if (salaries[i] > highest) {
            highest = salaries[i];
        }
        if (salaries[i] < lowest) {
            lowest = salaries[i];
        }
    }

    float average = sum / NUM_SALARIES;

    printf("\n--- Salary Statistics ---\n");
    printf("Average Salary: $%.2f\n", average);
    printf("Highest Salary: $%.2f\n", highest);
    printf("Lowest Salary : $%.2f\n", lowest);

    // Search for a salary
    printf("\nEnter a salary to search for: ");
    scanf("%f", &searchTarget);

    printf("\nSearch Results:\n");
    for (i = 0; i < NUM_SALARIES; i++) {
        // Compare using a small tolerance for floating-point comparison
        if (salaries[i] >= searchTarget - 0.01f && salaries[i] <= searchTarget + 0.01f) {
            printf("- Salary $%.2f found at Employee %d\n", searchTarget, i + 1);
            foundCount++;
        }
    }

    if (foundCount == 0) {
        printf("Salary $%.2f was not found in the records.\n", searchTarget);
    }
}

// Module B: Department Budgets
void processBudgets(void) {
    float budgets[NUM_BUDGETS];
    float totalBudget = 0.0f;
    int i, j;

    printf("\n--- Department Budgets Module ---\n");
    for (i = 0; i < NUM_BUDGETS; i++) {
        printf("Enter budget for Department %d: ", i + 1);
        scanf("%f", &budgets[i]);
    }

    // Display raw budgets
    printf("\n--- Captured Budgets ---\n");
    for (i = 0; i < NUM_BUDGETS; i++) {
        printf("Department %d: $%.2f\n", i + 1, budgets[i]);
    }

    // Calculate Total and Average
    for (i = 0; i < NUM_BUDGETS; i++) {
        totalBudget += budgets[i];
    }
    float averageBudget = totalBudget / NUM_BUDGETS;

    printf("\n--- Budget Statistics ---\n");
    printf("Total Budget  : $%.2f\n", totalBudget);
    printf("Average Budget: $%.2f\n", averageBudget);

    // Sort budgets from lowest to highest using Bubble Sort
    for (i = 0; i < NUM_BUDGETS - 1; i++) {
        for (j = 0; j < NUM_BUDGETS - 1 - i; j++) {
            if (budgets[j] > budgets[j + 1]) {
                float temp = budgets[j];
                budgets[j] = budgets[j + 1];
                budgets[j + 1] = temp;
            }
        }
    }

    // Display sorted budgets
    printf("\n--- Budgets Sorted (Lowest to Highest) ---\n");
    for (i = 0; i < NUM_BUDGETS; i++) {
        printf("[%d] $%.2f\n", i + 1, budgets[i]);
    }
}

// Module C: Vehicle Registration Numbers
void processRegistrations(void) {
    char registrations[NUM_REGISTRATIONS][REG_STR_LEN];
    char searchTarget[REG_STR_LEN];
    int i, foundIndex = -1;

    printf("\n--- Vehicle Registration Numbers Module ---\n");
    for (i = 0; i < NUM_REGISTRATIONS; i++) {
        printf("Enter registration number %d: ", i + 1);
        scanf("%19s", registrations[i]);
    }

    // Display all registration numbers
    printf("\n--- Captured Registration Numbers ---\n");
    for (i = 0; i < NUM_REGISTRATIONS; i++) {
        printf("Vehicle %d: %s\n", i + 1, registrations[i]);
    }

    // Search for a registration number
    printf("\nEnter a registration number to search for: ");
    scanf("%19s", searchTarget);

    for (i = 0; i < NUM_REGISTRATIONS; i++) {
        if (strcmp(registrations[i], searchTarget) == 0) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        printf("\nResult: Registration number '%s' was found at record index %d (Vehicle %d).\n", 
               searchTarget, foundIndex, foundIndex + 1);
    } else {
        printf("\nResult: Registration number '%s' was not found.\n", searchTarget);
    }
}