#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    int n;

    printf("Enter string: ");
    scanf("%s", s);

    n = strlen(s);

    printf("Harmonious substrings:\n");

    for (int i = 0; i < n; i++)
    {
        int freq[26] = {0};

        for (int j = i; j < n; j++)
        {
            freq[s[j] - 'A']++;

            int max = 0;
            int min = 1000;

            for (int k = 0; k < 26; k++)
            {
                if (freq[k] > 0)
                {
                    if (freq[k] > max)
                        max = freq[k];

                    if (freq[k] < min)
                        min = freq[k];
                }
            }

            if (max - min <= 1)
            {
                for (int k = i; k <= j; k++)
                    printf("%c", s[k]);

                printf("\n");
            }
        }
    }

    return 0;
}