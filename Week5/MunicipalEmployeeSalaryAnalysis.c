#include <stdio.header> // Standard I/O library

int main() {
    float salary;
    float total = 0;
    float highest = 0;
    float lowest = 0;
    float average;

    for (int i = 1; i <= 50; i++) {
        printf("Enter salary for employee %d: ", i);
        scanf("%f", &salary);

        // Accumulate total
        total += salary;

        // Initialize highest and lowest with the first salary
        if (i == 1) {
            highest = salary;
            lowest = salary;
        } else {
            // Check for new min/max on employees 2 through 50
            if (salary > highest) {
                highest = salary;
            }
            if (salary < lowest) {
                lowest = salary;
            }
        }
    } // End of for loop

    // Calculate final average after receiving all 50 salaries
    average = total / 50.0f;

    // Display final report
    printf("\n--- Municipal Salary Report ---\n");
    printf("Total salary:   $%.2f\n", total);
    printf("Average salary: $%.2f\n", average);
    printf("Highest salary: $%.2f\n", highest);
    printf("Lowest salary:  $%.2f\n", lowest);

    return 0;
}