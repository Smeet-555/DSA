#include <stdio.h>

int main() {
    int index = -1,n;
    printf("Enter the array Size : ");
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i]=i+1;
    }
    int k;
    printf("Enter k : ");
    scanf("%d",&k);

    for (int a = 1; a < k; a++)
    {
                for (int i = n - 2; i >= 0; i--) {
                if (arr[i] < arr[i + 1]) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            for (int i = 0; i < n / 2; i++) {
                int temp = arr[i];
                arr[i] = arr[n - 1 - i];
                arr[n - 1 - i] = temp;
            }
        } else {

            for (int i = n - 1; i > index; i--) {
                if (arr[i] > arr[index]) {
                    int temp = arr[i];
                    arr[i] = arr[index];
                    arr[index] = temp;
                    break;
                }
            }

            int start = index + 1, end = n - 1;
            while (start < end) {
                int temp = arr[start];
                arr[start] = arr[end];
                arr[end] = temp;
                start++;
                end--;
            }
        }
    }
    

    printf("Next permutation: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
