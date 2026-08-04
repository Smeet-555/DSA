#include <stdio.h>

int hour, min, sec;

void addSeconds(int add)
{
    sec = sec + add;

    min = min + sec / 60;
    sec = sec % 60;

    hour = hour + min / 60;
    min = min % 60;

    printf("Time after adding seconds = %02d:%02d:%02d\n",
           hour, min, sec);
}

void subtractSeconds(int sub)
{
    sec = sec - sub;

    while (sec < 0)
    {
        sec += 60;
        min--;
    }

    while (min < 0)
    {
        min += 60;
        hour--;
    }

    printf("Time after subtracting seconds = %02d:%02d:%02d\n",
           hour, min, sec);
}

int main()
{
    int add, sub;

    printf("Enter initial time (HH MM SS): ");
    scanf("%d %d %d", &hour, &min, &sec);

    printf("Enter seconds to add: ");
    scanf("%d", &add);

    addSeconds(add);

    printf("Enter seconds to subtract: ");
    scanf("%d", &sub);

    subtractSeconds(sub);

    return 0;
}