#include <stdio.h>


struct stock
{
    char name[10];
    float price;
} store[6], read[6];
struct buy
{
    char item[100];
    int quantity;
    float price;
};
struct customer
{
    char name[100], servedby[100];
    int items;
    struct buy data[40];
} cust,other;

int main()
{
    FILE *fptr;
    int again = 1;
    float total;
    int quantity;
    char filename[100];
    char item[100];
    int opt;
    char product[100];
    int items;
    int i = 0;
    while (again =1)
    {
        system("clear");
        printf("\n\n  ====================WebOpt_Grocery=============");
        printf("\n\n1:view stock price");
        printf("\n2:purchase items");
        printf("\n3:view transactions");
        printf("\n\n your option ? ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            system("clear");
            fptr = fopen("store.dat", "r");
            fread(&read, sizeof(struct stock), 6, fptr);
            printf("\n ________________Webopt__grocery___________________");
            for (i = 0; i < 6; i++)
            {
                printf("\n\n***************************************************");
                printf("\n\nstock_name: %s", read[i].name);
                printf("\n\nstock price: %f ksh\n", read[i].price);
            };
              fclose(fptr);
               break;
               system("clear");
               case 2:
            system("clear");
            printf("\nEnter your customer name: ");
            scanf("%s", cust.name);
            printf("\nEnter number of items to buy: ");
            scanf("%d", &cust.items);
            system("clear");
            for (i = 0; i < cust.items; i++)
            {
                printf("\nEnter item %d name : ", i + 1);
                scanf("%s", cust.data[i].item);
                printf("\nEnter  quantity: ");
                scanf("%d", &cust.data[i].quantity);
                printf("\nEnter  price: ");
                scanf("%f", &cust.data[i].price);
            };

            printf("\n\t\tWebOpt_Grocery");
            printf("\nDate: 29/5/2023");
            printf("\nInvoice to %s:", cust.name);
            printf("\n\n===================================================");
            printf("\n Item\t\tquantity\t   unit price");
            printf("\n===================================================");
            for (i = 0; i < cust.items; i++)
            {
                printf("\n%s\t\t  %d\t\t   %f", cust.data[i].item, cust.data[i].quantity, cust.data[i].price);
                total += cust.data[i].quantity * cust.data[i].price;
            };
            printf("\n===================================================");
            printf("Total price:  %f", total);
            printf("\n===================================================");
            printf("Discount:  0.05%");
            printf("\n===================================================");
            printf("Tax-rate:  0.15%");
            printf("\n===================================================");
            printf("Total-net price:  %f", total - total * 0.05 + total * 0.15);
            printf("\n---------------------------------------------------");
            printf("\n\nEnter seller's name:  ");
            scanf("%s", cust.servedby);
            strcpy(filename,cust.name);
            fptr = fopen(strcat(filename,".dat"), "w");
            fwrite(&cust, sizeof(struct customer), 1, fptr);
            fclose(fptr);
            break;
     
            default:
            system("clear");
            printf("\n\n Enter customer name:  ");
            scanf("%s",product);
            
            fptr = fopen(strcat(product,".dat"), "r");
            fread(&other, sizeof(struct customer), 1, fptr);
            printf("\n\t\tWebOpt_Grocery");
            printf("\nDate: 29/5/2023");
            printf("\nInvoice to %s:", other.name);
            printf("\n\n===================================================");
            printf("\n Item\t\tquantity\t   unit price");
            printf("\n===================================================");
            for (i = 0; i < other.items; i++)
            {
                printf("\n%s\t\t  %d\t\t   %f", other.data[i].item, other.data[i].quantity, other.data[i].price);
                total += other.data[i].quantity * other.data[i].price;
            };
            printf("\n===================================================");
            printf("Total price:  %f", total);
            printf("\n===================================================");
            printf("Discount:  0.05%");
            printf("\n===================================================");
            printf("Tax-rate:  0.15%");
            printf("\n===================================================");
            printf("Total-net price:  %f", total - total * 0.05 + total * 0.15);
printf("\n===================================================");
            printf("\n Served by : %s",other.servedby);
            
            printf("\n---------------------------------------------------");
            
            fclose(fptr);
            break;
        };

        printf("\n\nDo you want to continue [y/n]:  ");
        scanf("%d", &again);
        system("clear");
    }
    return 0;
}