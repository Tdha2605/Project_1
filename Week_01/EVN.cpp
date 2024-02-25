#include <bits/stdc++.h>

double evalution(int kwh)
{
    double before_price = 0.0, after_price = 0.0, vat = 0.1;
    if (kwh <= 50)
    {
        before_price = kwh * 1728;
        after_price = kwh * 1728;
    }
    else if (kwh <= 100)
    {
        before_price = 50 * 1728 + (kwh - 50) * 1786;
        after_price = kwh * 1728;
    }
    else if (kwh <= 200)
    {
        before_price = 50 * 1728 + 50 * 1786 + (kwh - 100) * 2074;
        after_price = 100 * 1728 + (kwh - 100) * 2074;
    }
    else if (kwh <= 300)
    {
        before_price = 50 * 1728 + 50 * 1786 + 100 * 2074 + (kwh - 200) * 2612;
        after_price = 100 * 1728 + 100 * 2074 + (kwh - 200) * 2612;
    }
    else if (kwh <= 400)
    {
        before_price = 50 * 1728 + 50 * 1786 + 100 * 2074 + 100 * 2612 + (kwh - 300) * 2919;
        after_price = 100 * 1728 + 100 * 2074 + 200 * 2612 + (kwh - 400) * 3111;
    }
    else if (kwh <= 700)
    {
        before_price = 50 * 1728 + 50 * 1786 + 100 * 2074 + 100 * 2612 + 100 * 2919 + (kwh - 400) * 3015;
        after_price = 100 * 1728 + 100 * 2074 + 200 * 2612 + (kwh-400) * 3111;
    }
    else
    {
        before_price = 50 * 1728 + 50 * 1786 + 100 * 2074 + 100 * 2612 + 100 * 2919 + (kwh - 400) * 3015;
        after_price = 100 * 1728 + 100 * 2074 + 200 * 2612 + 300 * 3111 + (kwh - 700) * 3457;
    }
    return ((after_price * (1 + vat)) - (before_price * (1 + vat)));
}

int main()
{
    int kwh;
    scanf("%d", &kwh);

    double ans = evalution(kwh);

    printf("%.2f\n", ans);
    return 0;
}
