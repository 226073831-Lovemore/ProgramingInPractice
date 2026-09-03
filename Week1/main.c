#include <stdio.h>
#include <string.h>

int main(void) {
    char municipality_name[100];
    char mayor_name[100];
    unsigned long population;

    // 1. Display System Title
    printf("-----\n");
    printf("        MUNICIPAL FINANCIAL MANAGEMENT SYSTEM        \n");
    printf("---------\n\n");

    // 2. Display Welcome Message
    printf("Welcome to Windhoek Municipality!\n");
    printf("-----\n\n");

    // 3. Prompt User for Inputs
    printf("Enter Municipality Name: ");
    if (fgets(municipality_name, sizeof(municipality_name), stdin) != NULL) {
        municipality_name[strcspn(municipality_name, "\n")] = '\0';
    }

    printf("Enter Mayor's Name:      ");
    if (fgets(mayor_name, sizeof(mayor_name), stdin) != NULL) {
        mayor_name[strcspn(mayor_name, "\n")] = '\0';
    }

    printf("Enter Population:        ");
    scanf("%lu", &population);

    // 4. Display Formatted Output Report
    printf("\n   \n");
    printf("                 MUNICIPAL REPORT                   \n");
    printf("    \n");
    printf(" Municipality Name : %s\n", municipality_name);
    printf(" Mayor's Name      : %s\n", mayor_name);
    printf(" Population        : %lu\n", population);
    printf("  \n");

    return 0;
}