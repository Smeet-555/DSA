#include <stdio.h>
#include <string.h>

int main()
{
    char s1[100], s2[100];
    int freq1[26] = {0};
    int freq2[26] = {0};
    int same = 1;

    printf("Enter first string: ");
    scanf("%s", s1);

    printf("Enter second string: ");
    scanf("%s", s2);

    // Check length
    if (strlen(s1) != strlen(s2))
    {
        printf("Strings are Not Simqual\n");
        return 0;
    }

    // Count characters
    for (int i = 0; i < strlen(s1); i++)
    {
        freq1[s1[i] - 'a']++;
        freq2[s2[i] - 'a']++;
    }

    // Compare frequencies
    for (int i = 0; i < 26; i++)
    {
        if (freq1[i] != freq2[i])
        {
            same = 0;
            break;
        }
    }

    if (same)
        printf("Strings are Simqual\n");
    else
        printf("Strings are Not Simqual\n");

    return 0;
}