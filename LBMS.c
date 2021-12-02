/*This code is written by Aryan Srivastava*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *file;
int current_size=0;
struct stats
{
    char book_name[256], name[256];

    struct issue
    {
        int date, month, year;
    } issue_date;

    struct due
    {
        int date, month, year;
    }due_date;

} *link;

void display(FILE *file, struct stats *link)
{
    file = fopen("library_data.txt", "r");
    if (file == NULL)
        printf("No file found\n");
    else
    {
        for (int i = 0; i < current_size; i++)
        {
            printf("Book Name : %s\n", (link+i)->book_name);
            printf("Issued on : %d/%d/%d\n", (link+i)->issue_date.date, (link+i)->issue_date.month, (link+i)->issue_date.year);
            printf("Issued to : %s\n", (link+i)->name);
            printf("Due Date : %d/%d/%d\n\n", (link+i)->due_date.date, (link+i)->due_date.month, (link+i)->due_date.year);
        }
    }
    fclose(file);
}

int tamper(FILE * file, struct stats *link)
{
    file = fopen("library_data.txt", "a+");    
    char choice;
choice:
    printf("Enter A to Add a Book\nEnter D to Delete a book\n->");
    scanf(" %c", &choice);

    if(choice == 'A' || choice == 'a')
    {
        realloc(link, current_size+1);
        printf("Enter Book's name : ");
        scanf(" %[^\n]", &(link+current_size)->book_name);
        fprintf(file, "Book Name : %s\n", (link+current_size)->book_name);
    date:
        printf("Enter Issue Date : ");
        scanf("%d/%d/%d", &(link+current_size)->issue_date.date, &(link+current_size)->issue_date.month, &(link+current_size)->issue_date.year);
        if((link+current_size)->issue_date.month == 1 || (link+current_size)->issue_date.month == 3 || (link+current_size)->issue_date.month == 5 || (link+current_size)->issue_date.month == 7 || (link+current_size)->issue_date.month == 8 || (link+current_size)->issue_date.month == 10 || (link+current_size)->issue_date.month == 12)
        {
            if((link+current_size)->issue_date.date>31)
            {
                printf("Invalid Date\n");
                goto date;
            }
        }
        else if((link+current_size)->issue_date.month == 4 || (link+current_size)->issue_date.month == 6 || (link+current_size)->issue_date.month == 9 || (link+current_size)->issue_date.month == 11)
        {
            if((link+current_size)->issue_date.date > 30)
            {
                printf("Invalid Date\n");
                goto date;
            }
        }
        else if((link+current_size)->issue_date.month == 2)
        {
            if ((((link+current_size)->issue_date.year % 4 == 0) && ((link+current_size)->issue_date.year % 100!= 0)) || ((link+current_size)->issue_date.year%400 == 0))
            {
                if((link+current_size)->issue_date.date > 29)
                {
                    printf("Invalid Date\n");
                    goto date;
                }
            }
            else
            {
                if((link+current_size)->issue_date.date > 28)
                {
                    printf("Invalid Date\n");
                    goto date;
                }
            }
        }
        else if((link+current_size)->issue_date.month >12){
            printf("Invalid Month\n");
            goto date;
        }
        printf("Book Issued to : ");
        scanf(" %[^\n]", &(link+current_size)->name);

        //due date
         if ((((link+current_size)->issue_date.year % 4 == 0) && ((link+current_size)->issue_date.year % 100!= 0)) || ((link+current_size)->issue_date.year%400 == 0))
        {
            if(((link+current_size)->issue_date.month==2) && ((link+current_size)->issue_date.date >15))    //feb
            {
                int z = 29-(link+current_size)->issue_date.date;
                (link+current_size)->due_date.date=14-z;
                (link+current_size)->due_date.month = (link+current_size)->issue_date.month+1;
                (link+current_size)->due_date.year = (link+current_size)->issue_date.year;
            }
            else if(((link+current_size)->issue_date.month==2) && ((link+current_size)->issue_date.date <=15))
            {
                (link+current_size)->due_date.date=14+(link+current_size)->issue_date.date;
                (link+current_size)->due_date.month = (link+current_size)->issue_date.month;
                (link+current_size)->due_date.year = (link+current_size)->issue_date.year;
            }
            else if((link+current_size)->issue_date.month == 1 || (link+current_size)->issue_date.month == 3 || (link+current_size)->issue_date.month == 5 || (link+current_size)->issue_date.month == 7 || (link+current_size)->issue_date.month == 8 || (link+current_size)->issue_date.month == 10)
            {
                if((link+current_size)->issue_date.date > 17)
                {
                    int z = 31-(link+current_size)->issue_date.date;
                    (link+current_size)->due_date.date=14-z;
                    (link+current_size)->due_date.month = (link+current_size)->issue_date.month+1;
                    (link+current_size)->due_date.year = (link+current_size)->issue_date.year;
                }
                else
                {
                    (link+current_size)->due_date.date=14+(link+current_size)->issue_date.date;
                    (link+current_size)->due_date.month = (link+current_size)->issue_date.month;
                    (link+current_size)->due_date.year = (link+current_size)->issue_date.year;   
                }
            } 
            else if((link+current_size)->issue_date.month == 4 || (link+current_size)->issue_date.month == 6 || (link+current_size)->issue_date.month == 9 || (link+current_size)->issue_date.month == 11)
            {
                if((link+current_size)->issue_date.date > 16)
                {
                    int z = 30-(link+current_size)->issue_date.date;
                    (link+current_size)->due_date.date=14-z;
                    (link+current_size)->due_date.month = (link+current_size)->issue_date.month+1;
                    (link+current_size)->due_date.year = (link+current_size)->issue_date.year;
                }
                else
                {
                    (link+current_size)->due_date.date=14+(link+current_size)->issue_date.date;
                    (link+current_size)->due_date.month = (link+current_size)->issue_date.month;
                    (link+current_size)->due_date.year = (link+current_size)->issue_date.year;   
                }
            } 
            else if((link+current_size)->issue_date.month == 12)
            {
                if((link+current_size)->issue_date.date > 17)
                {
                    int z = 31-(link+current_size)->issue_date.date;
                    (link+current_size)->due_date.date=14-z;
                    (link+current_size)->due_date.month = 1;
                    (link+current_size)->due_date.year = (link+current_size)->issue_date.year+1;
                }
                else
                {
                    (link+current_size)->due_date.date=14+(link+current_size)->issue_date.date;
                    (link+current_size)->due_date.month = (link+current_size)->issue_date.month;
                    (link+current_size)->due_date.year = (link+current_size)->issue_date.year;
                }
            }
        }


            else 
            {
                if((((link+current_size)->issue_date.month==2) && ((link+current_size)->issue_date.date >14)))
                {
                    int z = 28-(link+current_size)->issue_date.date;
                    (link+current_size)->due_date.date=14-z;
                    (link+current_size)->due_date.month = (link+current_size)->issue_date.month+1;
                    (link+current_size)->due_date.year = (link+current_size)->issue_date.year;
                }
                else if((((link+current_size)->issue_date.month==2) && ((link+current_size)->issue_date.date <=14)))
                {
                    (link+current_size)->due_date.date=14+(link+current_size)->issue_date.date;
                    (link+current_size)->due_date.month = (link+current_size)->issue_date.month;
                    (link+current_size)->due_date.year = (link+current_size)->issue_date.year;
                }
                else if((link+current_size)->issue_date.month == 1 || (link+current_size)->issue_date.month == 3 || (link+current_size)->issue_date.month == 5 || (link+current_size)->issue_date.month == 7 || (link+current_size)->issue_date.month == 8 || (link+current_size)->issue_date.month == 10)
                {
                    if((link+current_size)->issue_date.date > 17)
                    {
                        int z = 31-(link+current_size)->issue_date.date;
                        (link+current_size)->due_date.date=14-z;
                        (link+current_size)->due_date.month = (link+current_size)->issue_date.month+1;
                        (link+current_size)->due_date.year = (link+current_size)->issue_date.year;
                    }
                    else
                    {
                        (link+current_size)->due_date.date=14+(link+current_size)->issue_date.date;
                        (link+current_size)->due_date.month = (link+current_size)->issue_date.month;
                        (link+current_size)->due_date.year = (link+current_size)->issue_date.year;   
                    }
                } 
                else if((link+current_size)->issue_date.month == 4 || (link+current_size)->issue_date.month == 6 || (link+current_size)->issue_date.month == 9 || (link+current_size)->issue_date.month == 11)
                {
                    if((link+current_size)->issue_date.date > 16)
                    {
                        int z = 30-(link+current_size)->issue_date.date;
                        (link+current_size)->due_date.date=14-z;
                        (link+current_size)->due_date.month = (link+current_size)->issue_date.month+1;
                        (link+current_size)->due_date.year = (link+current_size)->issue_date.year;
                    }
                    else
                    {
                        (link+current_size)->due_date.date = 14 + (link+current_size)->issue_date.date;
                        (link+current_size)->due_date.month = (link+current_size)->issue_date.month;
                        (link+current_size)->due_date.year = (link+current_size)->issue_date.year;   
                    }
                }
            else if((link+current_size)->issue_date.month == 12)
            {
                if((link+current_size)->issue_date.date > 17)
                {
                    int z = 31-(link+current_size)->issue_date.date;
                    (link+current_size)->due_date.date=14-z;
                    (link+current_size)->due_date.month = 1;
                    (link+current_size)->due_date.year = (link+current_size)->issue_date.year+1;
                }
                else
                {
                    (link+current_size)->due_date.date=14+(link+current_size)->issue_date.date;
                    (link+current_size)->due_date.month = (link+current_size)->issue_date.month;
                    (link+current_size)->due_date.year = (link+current_size)->issue_date.year;
                }
            } 
            }
            fprintf(file, "Issued on : %d/%d/%d\n", (link+current_size)->issue_date.date, (link+current_size)->issue_date.month, (link+current_size)->issue_date.year);
            fprintf(file, "Issued to : %s\n", (link+current_size)->name);
            fprintf(file, "Due Date : %d/%d/%d\n", (link+current_size)->due_date.date, (link+current_size)->due_date.month, (link+current_size)->due_date.year);
        
    current_size++;
    fclose(file);
    }

    else if(choice == 'D' || choice =='d')
    {
        char input[256];
        printf("Enter the Name of the BOOK to Delete -> ");
        scanf(" %[^\n]", &input);
        int t=0, tpy=-1; //ticker
        int l2 = strlen(input);
        if(current_size==0) 
            printf("NO books found in Data Base");
        else
        {
            for(int i=0; i<current_size; i++)
            {
                int l1 = strlen((link+i)->book_name);
                int n=0, m=0; //tickers
                while((link+i)->book_name[n] != '\0')
                {
                    if((link+i)->book_name[n]  == input[m]) 
                    {    
                        while((link+i)->book_name[n] == input[m]  && (link+i)->book_name[n] !='\0')
                        {
                            n++;
                            m++;
                        }
                        if(m == l2 && ((link+i)->book_name[n] == ' ' || (link+i)->book_name[n]  == '\0')) 
                        {
                            printf("Book Name : %s has been deleted off the system\n\n", (link+i)->book_name);
                            t++;
                            tpy=i;
                            break;
                        }
                    } 
                    else
                    {         
                        while((link+i)->book_name[n] != ' ')
                        {   
                            n++;
                            if((link+i)->book_name[n]  == '\0')
                                break;
                        }
                    }
                    n++;
                    m=0; 
                }
            }
                if(t==0)
                    printf("'%s' No such Book exists.\n", input);
            for(int z=tpy; z<current_size -1; z++)
            {
                strcpy((link+z)->book_name, (link+z+1)->book_name);
                (link+z)->issue_date.date=(link+z+1)->issue_date.date;
                (link+z)->issue_date.month=(link+z+1)->issue_date.month;
                (link+z)->issue_date.year=(link+z+1)->issue_date.year;
                (link+z)->due_date.date=(link+z+1)->due_date.date;
                (link+z)->due_date.month=(link+z+1)->due_date.month;
                (link+z)->due_date.year=(link+z+1)->due_date.year;
                strcpy((link+z)->name, (link+z+1)->name);
            }
            current_size--;
            fclose(file);
            file =fopen("library_data.txt", "w");
            for(int z=0; z<current_size; z++)
            {
                fprintf(file, "Book Name : %s\n", (link+z)->book_name);
                fprintf(file, "Issued on : %d/%d/%d\n", (link+z)->issue_date.date, (link+z)->issue_date.month, (link+z)->issue_date.year);
                fprintf(file, "Issued to : %s\n", (link+z)->name);
                fprintf(file, "Due Date : %d/%d/%d\n", (link+z)->due_date.date, (link+z)->due_date.month, (link+z)->due_date.year);
            }
            fclose(file);
        } 
    }    
    else if(choice != 'a' || choice !='d' || choice != 'A' || choice !='D')
    {
        printf("Invalid Input! Please Try again\n");
        goto choice;
    }
}

void fine_calc()
{
    int choice, days;
    float discount, amount;
    char name[256], book_name[256];
    printf("Enter number of days the book is overdue by -> ");
    scanf("%d", &days);
    printf("Enter discount (in percentage) (if any)-> ");
    scanf("%f", &discount);
    printf("Enter name of the fine payer-> ");
    scanf(" %[^\n]", &name);
    printf("Enter name of the overdue book-> ");
    scanf(" %[^\n]s", &book_name);
    //reciept
    for(int i=0; i<56;i++)
        printf("*");
    printf("\n\tLibrary\n");
    printf("\tFine Reciept\n\n");
    printf("Name: %s\n", name);
    printf("Book Name: %s\n", book_name);
    printf("Fine per day: Rs 2.00\n");
    printf("Number of overdue days: %d\n", days);
    printf("Total: Rs. %d", 2*days);
    printf("\nDiscount(if any): %0.2f\n", discount);
    printf("Total Discount: Rs. %0.2f\n", (2*days*discount)/100);
    amount= ((2*days)*(100-discount))/100;
    printf("Grand Total:Rs. %0.2f\n", amount);
    for(int i=0; i<56;i++)
        printf("*");
    printf("\n");
}

void search (struct stats * link)
{
    char input[256];
    printf("Enter the Name of BOOK -> ");
    scanf(" %[^\n]", &input);
    int t=0; //ticker
    int l2 = strlen(input);
    if(current_size==0) 
        printf("NO books found in Data Base");
    else
    {
        for(int i=0; i<current_size; i++)
        {
            int l1 = strlen((link+i)->book_name);
            int n=0, m=0; //tickers
            while((link+i)->book_name[n] != '\0')
            {
                if((link+i)->book_name[n]  == input[m]) 
                {    
                    while((link+i)->book_name[n] == input[m]  && (link+i)->book_name[n] !='\0')
                    {
                        n++;
                        m++;
                    }
                    if(m == l2 && ((link+i)->book_name[n] == ' ' || (link+i)->book_name[n]  == '\0')) 
                    {
                        printf("Book Name : %s\n\n", (link+i)->book_name);
                        t++;
                    }
                } 
                else
                {         
                    while((link+i)->book_name[n] != ' ')
                    {   
                        n++;
                        if((link+i)->book_name[n]  == '\0')
                            break;
                    }
                }
                n++;
                m=0; 
            }
    
        }
        if(t==0)
                printf("'%s' No such Book exists.\n", input); 
    }
}

int main()
{
    link = (struct stats *)malloc(current_size * sizeof(struct stats));
    int m;
    file = fopen("library_data.txt", "r"); 
    while(getc(file) != EOF)
    {
        fscanf(file, "%*s%*s%*s%[^\n]", &(link+current_size)->book_name);
        fscanf(file, "%*s%*s%*s%d/%d/%d", &(link+current_size)->issue_date.date, &(link+current_size)->issue_date.month, &(link+current_size)->issue_date.year);
        fscanf(file, "%*s%*s%*s%[^\n]", &(link+current_size)->name);
        fscanf(file, "%*s%*s%*s%d/%d/%d", &(link+current_size)->due_date.date, &(link+current_size)->due_date.month, &(link+current_size)->due_date.year);
        current_size++;
    }
    if(current_size !=0)
        current_size--;
    fclose(file);
menu:
    for (int i = 0; i < 28; i++)
        printf("x-");
    printf("x\n\t\t\tMENU\n");
    printf("Enter 1 to Display All Records of Library\n");
    printf("Enter 2 to Add or Drop Records from the System\n");
    printf("Enter 3 to Search any book within the Library\n");
    printf("Enter 4 Fine calcualtion if book is deposited after due date\n->");
    scanf("%d", &m);
    switch (m)
    {
    case 1:
        display(file, link);
        goto menu;

    case 2:
        tamper(file, link);
        goto menu;

    case 3:
        search(link);
        goto menu;

    case 4:
        fine_calc();
        goto menu;

    Default:
        printf("Invalid Input\n");
        goto menu;
    }
    return 0;
}