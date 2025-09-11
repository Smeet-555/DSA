#include <stdio.h>
#include <stdlib.h>

int hashset[0];

void init(int size)
{
    hashset[size];

    for (int i = 0; i < size; i++)
    {
        hashset[i] = -1;
    }
}

int hashfunc(int key, int size)
{
    return (abs(key) % size);
}

int contains(int size, int key)
{
    int index = hashfunc(key, size);
    for (int i = 0; i < size; i++)
    {
        if (i == index)
        {
            if (hashset[i] == -1)
            {
                hashset[i] = key;
                return 0;
            }
            else
            {
                return i+1;
            }
        }
    }
}

void hashInsert(int size, int key)
{
    int i = contains(size, key);
    if (!i)
        return;
    for (i; i < size; i++)
    {
        if (hashset[i] == -1)
        {
            hashset[i] = (key);
            return;
        }
    }
    printf("Hashset is not empty");
    return;
}

int removeElement(int size, int key)
{
    int index = hashfunc(key, size);
    for (int i = index; i < size; i++)
    {
        if (hashset[i] == key)
        {
            hashset[i] = -1;
            return i;
        }
    }
    return -1;
}

void dispaly(int size)
{

    for (int i = 0; i < size; i++)
    {
        printf("%d ", hashset[i]);
    }
}

int main()
{
    int size;
    printf("Enter the size of hashset: ");
    scanf("%d", &size);
    init(size);
    hashInsert(size, 5);
    hashInsert(size, 15);
    dispaly(size);

    return 0;
}
