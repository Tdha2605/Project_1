#include <stdio.h>

void input_array(int array[], int n)
{
    for(int i = 0; i < n; i++)
    {
        array[i] = i + 1;
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int next_permutation(int array[], int n)
{
    int i = n - 1;
    while (i > 0 && array[i - 1] >= array[i])
    {
        i--;
    }
    if (i <= 0)
    {
        return 0;
    }

    int j = n - 1;

    while (array[j] <= array[i - 1])
    {
        j--;
    }

    swap(&array[i - 1], &array[j]);

    j = n - 1;
    
    while (i < j)
    {
        swap(&array[i], &array[j]);
        i++;
        j--;
    }
    return 1;
}

int main()
{
    int n;
    scanf("%d", &n);

    int array[n];

    input_array(array, n);

    do
    {
        print_array(array, n);
    } while (next_permutation(array, n));

    return 0;
}
