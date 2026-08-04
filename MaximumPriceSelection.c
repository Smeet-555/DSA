#include<stdio.h>
#include<string.h>

struct Item {
    int price;
    char category[20];
};

int main(){
    int N, K, M;

    printf("Enter the number of items: ");
    scanf("%d", &N);

    printf("Enter the maximum number of same categories that can be selected repeatedly: ");
    scanf("%d", &K);

    printf("Enter the number of items");
    scanf("%d", &M);

    struct Item items[M];

    for(int i = 0; i < M; i++){
        printf("Enter price and category of item %d: ", i + 1);
        scanf("%d %s", &items[i].price, items[i].category);
    }

    // sort items in descending order of price
    for(int i = 0; i < M - 1; i++){
        for(int j = i+1; j < M; j++){
            if(items[i].price < items[j].price){
                struct Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

  // Stores unique category names
    char selectedCategories[100][20];

    // Stores how many items have been selected from each category
    int count[100] = {0};

    // Number of unique categories stored
    int categoryCount = 0;

    // Tracks total price and number of selected items
    int totalPrice = 0;
    int selectedCount = 0;

    for (int i = 0; i < M && selectedCount < N; i++)
    {
        int found = -1;

        // Search whether this category already exists
        for (int j = 0; j < categoryCount; j++)
        {
            if (strcmp(items[i].category, selectedCategories[j]) == 0)
            {
                found = j;
                break;
            }
        }

        if (found == -1)
        {
            // New category
            strcpy(selectedCategories[categoryCount], items[i].category);
            count[categoryCount] = 1;

            totalPrice += items[i].price;
            selectedCount++;
            categoryCount++;
        }
        else if (count[found] < K)
        {
            // Existing category but still under limit
            count[found]++;

            totalPrice += items[i].price;
            selectedCount++;
        }
    }

    printf("\nTotal Price = %d\n", totalPrice);

    printf("\nCategory-wise Selection:\n");

    for (int i = 0; i < categoryCount; i++)
    {
        printf("%s -> %d item(s)\n", selectedCategories[i], count[i]);
    }

    return 0;
}