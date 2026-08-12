#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char secret[20];
    char sentence[20][100];
    int score[20];
    int n;

    printf("Enter the secret word: ");
    scanf("%s", secret);

    printf("Enter the number of sentences: ");
    scanf("%d", &n);
    getchar(); // Consume newline

    printf("Enter the sentences:\n");
    for (int i = 0; i < n; i++)
    {
        fgets(sentence[i], sizeof(sentence[i]), stdin);
    }

    int len = strlen(secret);

    // Calculate similarity score for each sentence
    for (int i = 0; i < n; i++)
    {
        score[i] = 0;
        int j = 0;

        while (sentence[i][j] != '\0')
        {
            char word[20];
            int k = 0;

            // Skip spaces
            while (sentence[i][j] == ' ')
                j++;

            // If end of sentence is reached
            if (sentence[i][j] == '\0' || sentence[i][j] == '\n')
                break;

            // Copy one word
            while (sentence[i][j] != ' ' &&
                   sentence[i][j] != '\0' &&
                   sentence[i][j] != '\n')
            {
                word[k++] = sentence[i][j++];
            }

            word[k] = '\0';

            // Compare with secret word
            if (k == len)
            {
                for (int x = 0; x < len; x++)
                {
                    if (tolower(word[x]) == tolower(secret[x]))
                    {
                        score[i]++;
                    }
                }
            }
        }
    }

    // Sort sentences according to score (Descending)
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (score[i] < score[j])
            {
                int tempScore = score[i];
                score[i] = score[j];
                score[j] = tempScore;

                char tempSentence[100];
                strcpy(tempSentence, sentence[i]);
                strcpy(sentence[i], sentence[j]);
                strcpy(sentence[j], tempSentence);
            }
        }
    }

    printf("\nSimilarity Scores:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", score[i]);
    }


    printf("\nFinal Decoded String:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s", sentence[i]);
    }

    return 0;
}