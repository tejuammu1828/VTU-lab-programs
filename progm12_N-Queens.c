/*
Program 12: N-Queens problem using Bactracking Technique.

Aim:
Design and implement a C program to solve the N-Queens problem using Backtracking Technique.
*/
#include<stdio.h>
#include<math.h> // for abs() function

int place(int x[], int k)
{
    for(int i = 1; i < k; i++)
    {
        if((x[i] == x[k]) || (abs(i-k) == abs(x[i]-x[k])))
            return 0;
    }
    return 1;
}

int nqueens(int n)
{
    int x[10], k, count = 0;

    k = 1;        // Select first queen
    x[k] = 0;

    while(k != 0)
    {
        x[k]++;   // Place kth queen in next column

        while((x[k] <= n) && (!place(x,k)))
            x[k]++;

        if(x[k] <= n)
        {
            if(k == n)
            {
                printf("\nSolution %d\n", ++count);

                for(int i = 1; i <= n; i++)
                {
                    for(int j = 1; j <= n; j++)
                    {
                        printf("%c ", j == x[i] ? 'Q' : 'X');
                    }
                    printf("\n");
                }
            }
            else
            {
                k++;      // Select next queen
                x[k] = 0;
            }
        }
        else
        {
            k--;         // Backtrack
        }
    }

    return count;
}

int main()
{
    int n;

    printf("Enter the size of chessboard: ");
    scanf("%d",&n);

    printf("\nThe number of possibilities are %d", nqueens(n));

    return 0;
}