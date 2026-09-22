#include <stdio.h>

int main() {
    double revenue, expenses, balance;
    
    // Extension variables
    int departments;
    double payroll, procurement, assets;

    printf("====\n"); 
    printf("   MUNICIPAL BUDGET CALCULATOR   \n");
    printf("====\n\n");

    // Core financial inputs
    printf("Enter Total Revenue: ");
    scanf("%lf", &revenue);

    printf("Enter Total Expenses: ");
    scanf("%lf", &expenses);

    // Extension inputs
    printf("\nEnter Number of Departments: ");
    scanf("%d", &departments);

    printf("Enter Payroll Expenses: ");
    scanf("%lf", &payroll);

    printf("Enter Procurement Expenses: ");
    scanf("%lf", &procurement);

    printf("Enter Total Asset Value: ");
    scanf("%lf", &assets);

    // Calculation
    balance = revenue - expenses;

    // Output Summary
    printf("\n====\n");
    printf("   MUNICIPAL FINANCIAL SUMMARY   \n");
    printf("====\n");
    printf("Number of Departments : %d\n", departments);
    printf("Total Revenue         : $%.2f\n", revenue);
    printf("Total Expenses        : $%.2f\n", expenses);
    printf("  - Payroll           : $%.2f\n", payroll);
    printf("  - Procurement       : $%.2f\n", procurement);
    printf("Net Balance           : $%.2f\n", balance);
    printf("Total Asset Value     : $%.2f\n", assets);
    printf("====\n");

    return 0;
}