#include <stdio.h>

int main() {
    double basic_salary, housing, transport, tax;
    double gross_salary, net_salary;

    printf("==\n");
    printf("   EMPLOYEE SALARY CALCULATOR   \n");
    printf("==\n\n");

 
    printf("Enter Basic Salary: ");
    scanf("%lf", &basic_salary);

    printf("Enter Housing Allowance: ");
    scanf("%lf", &housing);

    printf("Enter Transport Allowance: ");
    scanf("%lf", &transport);

    printf("Enter Tax Amount: ");
    scanf("%lf", &tax);

    
    gross_salary = basic_salary + housing + transport;
    net_salary = gross_salary - tax;

  
    printf("\n====\n");
    printf("   EMPLOYEE SALARY SUMMARY   \n");
    printf("====\n");
    printf("Basic Salary        : $%.2f\n", basic_salary);
    printf("Housing Allowance   : $%.2f\n", housing);
    printf("Transport Allowance : $%.2f\n", transport);
    printf("Gross Salary        : $%.2f\n", gross_salary);
    printf("Tax Deduction       : $%.2f\n", tax);
    printf("Net Salary          : $%.2f\n", net_salary);
    printf("==\n");

    return 0;
}