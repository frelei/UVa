//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=652&page=show_problem&problem=1071

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <sstream>

using namespace std;
 

void floyd(int matrix[][100])
{
    for (int k = 0; k < 100; k++) 
     for (int i = 0; i < 100; i++)
       for (int j = 0; j < 100; j++)
         matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
}


int main ()
{
    int T = 1;
    while(true)
    {
        // READ VALUES
        int a,b;
        vector<int> input;
        while(cin >> a >> b)
        {
            if(!a && !b) break;
            input.push_back(a-1);
            input.push_back(b-1);
        }
        if (input.size() == 0) break;

        // Initialize Matrix
        int max = *max_element(begin(input), end(input));
        int matrix[100][100] = {0};

        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++)
                matrix[i][j] = 999;
            matrix[i][i] = 0;
        }


        for (int i = 0; i < input.size(); i += 2)
        {
            int row = input[i];
            int column = input[i + 1];
            matrix[row][column] = 1;
        }

        floyd(matrix);

        int ans = 0;
        int total = 0;
        for (int i = 0; i < max + 1; i++)
        {
            for (int j = 0; j < max + 1; j++)
            {
                if (matrix[i][j] != 0 && matrix[i][j] != 999)
                {
                    ans += matrix[i][j];
                    total += 1;
                }
            }
        }
        printf("Case %d: average length between pages = %0.3f clicks\n",T, (float)ans / total);
        T++;
    }

    return 0;
}