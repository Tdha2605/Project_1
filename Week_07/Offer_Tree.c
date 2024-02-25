// C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Order
{
    char customerID[11];
    char productID[11];
    int price;
    char shopID[11];
    char time_point[9];
};

struct Order orders[100000];
int num_orders = 0;

void processOrder(char *customerID, char *productID, int price, char *shopID, char *time_point)
{
    strcpy(orders[num_orders].customerID, customerID);
    strcpy(orders[num_orders].productID, productID);
    orders[num_orders].price = price;
    strcpy(orders[num_orders].shopID, shopID);
    strcpy(orders[num_orders].time_point, time_point);
    num_orders++;
}

int totalNumberOrders()
{
    return num_orders;
}

int totalRevenue()
{
    int total = 0;
    for (int i = 0; i < num_orders; i++)
    {
        total += orders[i].price;
    }
    return total;
}

int revenueOfShop(char *shopID)
{
    int total = 0;
    for (int i = 0; i < num_orders; i++)
    {
        if (strcmp(orders[i].shopID, shopID) == 0)
        {
            total += orders[i].price;
        }
    }
    return total;
}

int totalConsumeOfCustomerShop(char *customerID, char *shopID)
{
    int total = 0;
    for (int i = 0; i < num_orders; i++)
    {
        if (strcmp(orders[i].customerID, customerID) == 0 && strcmp(orders[i].shopID, shopID) == 0)
        {
            total += orders[i].price;
        }
    }
    return total;
}

int is_Period(char *time, char *from_time, char *to_time)
{
    return (strcmp(time, from_time) >= 0 && strcmp(time, to_time) <= 0);
}

int totalRevenueInPeriod(char *from_time, char *to_time)
{
    int total = 0;
    for (int i = 0; i < num_orders; i++)
    {
        if (is_Period(orders[i].time_point, from_time, to_time))
        {
            total += orders[i].price;
        }
    }
    return total;
}

int main()
{
    char input[100];
    char do_what[100];

    while (1)
    {
        fgets(input, sizeof(input), stdin);
        if (input[0] == '#')
        {
            break;
        }

        char *customerID = strtok(input, " ");
        char *productID = strtok(NULL, " ");
        int price = atoi(strtok(NULL, " "));
        char *shopID = strtok(NULL, " ");
        char *time_point = strtok(NULL, " \n");

        processOrder(customerID, productID, price, shopID, time_point);
    }

    while (1)
    {
        fgets(input, sizeof(input), stdin);
        if (input[0] == '#')
        {
            break;
        }

        char *query = strtok(input, " \n");

        if (strcmp(query, "?total_number_orders") == 0)
        {
            printf("%d\n", totalNumberOrders());
        }
        else if (strcmp(query, "?total_revenue") == 0)
        {
            printf("%d\n", totalRevenue());
        }
        else if (strcmp(query, "?revenue_of_shop") == 0)
        {
            char *shopID = strtok(NULL, " \n");
            printf("%d\n", revenueOfShop(shopID));
        }
        else if (strcmp(query, "?total_consume_of_customer_shop") == 0)
        {
            char *customerID = strtok(NULL, " ");
            char *shopID = strtok(NULL, " \n");
            printf("%d\n", totalConsumeOfCustomerShop(customerID, shopID));
        }
        else if (strcmp(query, "?total_revenue_in_period") == 0)
        {
            char *from_time = strtok(NULL, " ");
            char *to_time = strtok(NULL, " \n");
            printf("%d\n", totalRevenueInPeriod(from_time, to_time));
        }
    }

    return 0;
}
