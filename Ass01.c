#include <stdio.h>

struct Date
{
    int day;
    int month;
    int year;
};

void initDate(struct Date *ptrDate)
{
    printf("\nTodays Date = 09/09/2024");
}

void printDateOnConsole(struct Date *ptrDate)
{
    printf("\nDate - %d/%d/%d", ptrDate->day, ptrDate->month, ptrDate->year);
}

void acceptDateOnConsole(struct Date *ptrDate)
{
    printf("\n\nEnter Day - ");
    scanf("%d", &ptrDate->day);
    printf("Enter Month - ");
    scanf("%d", &ptrDate->month);
    printf("Enter Year - ");
    scanf("%d", &ptrDate->year);
}

int main()
{
    int choice;
    struct Date D1;

    do
    {
        printf("\n\n0.EXIT \n 1.InitDate \n 2.AcceptDate \n 3.DisplayDate");
        printf("\n\nEnter Your Choice - ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            initDate(&D1);
        }
        break;

        case 2:
        {
            acceptDateOnConsole(&D1);
        }
        break;

        case 3:
        {
            printDateOnConsole(&D1);
        }
        break;

        default:
        {
            printf("Invalid Input!");
        }
        break;
        }
    } while (choice!=0);
    
    return 0;
}