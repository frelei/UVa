/// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=12&problem=944&mosmsg=Submission+received+with+ID+17646824

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int values[55][55];
int val[55];

int cutting(int left, int right)
{
    if (left + 1 == right)
        return 0;

    int cut = values[left][right];

    if (cut != -1)
        return cut;

     int cost = 100000;
    for(int i = left + 1; i < right; i++)
    {
        cost= min(cost, cutting(left, i) + cutting(i, right) + val[right] - val[left]);
    }
    values[left][right] = cost;
    return cost;
}


int main ()
{
    while(true)
    {
        int cuts, lenght;
        cin  >> lenght;

        if (lenght == 0) break;

        cin >> cuts;
        memset(values, -1, sizeof(values));
        val[0] = 0;
        val[cuts + 1] = lenght;

        for(int i = 1; i <= cuts; i++)
            cin >> val[i];

        cout << "The minimum cutting is " << cutting(0, cuts + 1) << "." <<  endl;
    }
    return 0;
}
