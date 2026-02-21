#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int prefix = 0;
    int count = 0;

    // Frequency array (range assumed small)
    int freq[10001] = {0};   
    int offset = 5000;       // to handle negative prefix sums

    freq[offset] = 1;  // prefix sum = 0

    for(int i = 0; i < n; i++)
    {
        prefix += arr[i];

        if(freq[prefix + offset] > 0)
            count += freq[prefix + offset];

        freq[prefix + offset]++;
    }

    printf("%d", count);

    return 0;
}