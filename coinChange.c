#include <stdio.h>

int main()
{
    int amount, n;

    printf("Enter amount: ");
    scanf("%d", &amount);

    printf("Enter number of denominations: ");
    scanf("%d", &n);

    int coins[n];

    printf("Enter denominations: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &coins[i]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (coins[i] < coins[j])
            {
                int temp = coins[i];
                coins[i] = coins[j];
                coins[j] = temp;
            }
        }
    }

    int count = 0;

    printf("Coins used: ");

    for (int i = 0; i < n; i++)
    {
        while (amount >= coins[i])
        {
            amount = amount - coins[i];
            count++;

            printf("%d ", coins[i]);
        }
    }

    if (amount == 0)
        printf("\nMinimum coins needed = %d\n", count);
    else
        printf("\nAmount cannot be formed\n");

    return 0;
}