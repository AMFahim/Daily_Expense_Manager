#include <stdio.h>

struct Income {
    float amount;
};

struct Expense {
    float amount;
};

void displayMenu() {
    printf("\n********** Daily Expense Manager **********\n");
    printf("1. Add Income\n");
    printf("2. Add Expense\n");
    printf("3. View Income Records\n");
    printf("4. View Expense Records\n");
    printf("5. Exit\n");
    printf("******************************************\n");
}

void addIncome(struct Income *income) {
    printf("\nEnter the income amount: ");
    scanf("%f", &(income->amount));

    // add income data
    FILE *file = fopen("income_records.txt", "a");
    if (file != NULL) {
        fprintf(file, "%.2f\n", income->amount);
        fclose(file);
        printf("Income added successfully!\n");
    } else {
        printf("Something Went Wrong!\n");
    }
}

void addExpense(struct Expense *expense) {
    printf("\nEnter the expense amount: ");
    scanf("%f", &(expense->amount));

    //add Expanse data
    FILE *file = fopen("expense_records.txt", "a");
    if (file != NULL) {
        fprintf(file, "%.2f\n", expense->amount);
        fclose(file);
        printf("Expense added successfully!\n");
    } else {
        printf("Something Went Wrong!\n");
    }
}

void viewIncomeRecords() {
    printf("\n********** Income Records **********\n");

    //view income data
    FILE *file = fopen("income_records.txt", "r");
    if (file != NULL) {
        float amount;
        while (fscanf(file, "%f", &amount) == 1) {
            printf("Income Amount: $%.2f\n", amount);
        }
        fclose(file);
    } else {
        printf(" No Income Amount found.\n");
    }

    printf("************************************\n");
}

void viewExpenseRecords() {
    printf("\n********** Expense Records **********\n");

    // view expense data
    FILE *file = fopen("expense_records.txt", "r");
    if (file != NULL) {
        float amount;
        while (fscanf(file, "%f", &amount) == 1) {
            printf("Expense Amount: $%.2f\n", amount);
        }
        fclose(file);
    } else {
        printf("No Expanse amount found.\n");
    }

    printf("*************************************\n");
}

int main() {
    FILE *incomeFile = fopen("income_records.txt", "a");
    fclose(incomeFile);

    FILE *expenseFile = fopen("expense_records.txt", "a");
    fclose(expenseFile);

    struct Income income = {0};
    struct Expense expense = {0};
    int choice;

    do {
        displayMenu();
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addIncome(&income);
                break;
            case 2:
                addExpense(&expense);
                break;
            case 3:
                viewIncomeRecords();
                break;
            case 4:
                viewExpenseRecords();
                break;
            case 5:
                printf("Thanks, Have a nice moment!\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 to 5.\n");
        }

    } while (choice != 5);

    return 0;
}
