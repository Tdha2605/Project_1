#include <stdio.h>

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int min(int a, int b)
{
    return (a < b) ? a : b;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


/*
            6                  8                                       4
            from = 6           to = 0                                  ans = 1
            from = 6 != 4 => temp = min(6,8) = 6;                      ans = 2
                             to += 6 =6; 
                             from -= 6 = 0   
            from = 0 => from = 6                                       ans = 3
            to != b ---> Lặp với from = 6; to = 6
            temp = min(6,8-6) = 2 => to += 2 = 8; from -=2 = 4         ans = 4 -> break;
            
*/
int process(int a, int b, int c)
{
    int from = a;
    int to = 0;

    int ans = 1;

    while (from != c && to != c)
    {
        int temp = min(from, b - to);

        to += temp;
        from -= temp;

        ans++;

        if (from == c || to == c)
        {
            break;
        }

        if (from == 0)
        {
            from = a;
            ans++;
        }

        if (to == b)
        {
            to = 0;
            ans++;
        }
    }
    return ans;
}

int minAns(int a, int b, int c)
{
    // Chọn cách rót là từ bình a sang bình b nên phảo đảm bảo a <= b
    if (a > b)
    {
        swap(&a, &b);
    }

    if (c > b)
        return -1;
    
    // Chỉ giải được nếu ước chung lớn nhất của a và b chia hết cho c
    if ((c % gcd(b, a)) != 0)
    {
        return -1;
    }

    return min(process(b, a, c), process(a, b, c));
}

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    printf("%d", minAns(a, b, c));
    return 0;
}
