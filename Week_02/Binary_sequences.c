// Given an integer n,
// write a program that generates all binary sequences
// without consecutive 11 in a lexicographic order.
#include <stdio.h>
#include <string.h>


void generate_sequences(int n, char *sequence, int last_digit)
{
    if (n == 0)
    {
        printf("%s\n", sequence);
        return;
    }

    sequence[n - 1] = '0';
    generate_sequences(n - 1, sequence, 0);

    if (last_digit != 1)
    {
        sequence[n - 1] = '1';
        generate_sequences(n - 1, sequence, 1);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    char sequence[n + 1];
    memset(sequence, 0, sizeof(sequence));
    generate_sequences(n, sequence, 0);
    return 0;
}
