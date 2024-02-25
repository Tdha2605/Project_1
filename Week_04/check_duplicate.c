#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    int key;
    bool exists;
} hash_Table;

void HashTable(hash_Table hashTable[], int size)
{
    for (int i = 0; i < size; i++)
    {
        hashTable[i].key = 0;
        hashTable[i].exists = false;
    }
}

bool insert(hash_Table hashTable[], int size, int key)
{
    int index = key % size; 

    while (hashTable[index].exists)
    {
        if (hashTable[index].key == key)
        {
            return true;
        }
        // khi đã tồn tại thì cộng tới lúc hashtable đang trống
        index = (index + 1) % size;
    }
    // nếu chưa tồn tại vị trí, thêm vào hashtable
    hashTable[index].key = key;
    hashTable[index].exists = true;
    return false;
}

void check_again(int arr[], int n)
{
    hash_Table hashTable[100001];
    HashTable(hashTable, 100001);

    for (int i = 0; i < n; i++)
    {
        if (insert(hashTable, 100001, arr[i]))
            printf("1\n");
        else
            printf("0\n");
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    check_again(arr, n);

    return 0;
}