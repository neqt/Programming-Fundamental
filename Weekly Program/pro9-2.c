//check if it's a magic square
#include <stdio.h>
#include <stdbool.h>

bool is_magic_square(int size, int sqr[10][10])
{
    bool is_equal = false;
    bool is_horEqual = true, is_verEqual = true, is_diaEqual = true;
    int total_hor = 0, total_ver = 0, total_dia = 0;
    int sum_hor, sum_ver, sum_dia1 = 0, sum_dia2 = 0;
    int x, y, i = size - 1, j = 0;
    for (x = 0; x < size; x++)
    {
        sum_hor = 0, sum_ver = 0;
        for (y = 0; y < size; y++)
        {
            sum_hor += sqr[x][y];
            sum_ver += sqr[y][x];
            if (y == x)
            {
                sum_dia1 += sqr[x][y];
            }
        }

        do
        {
            sum_dia2 += sqr[i--][j++];
        } while (i >= 0 && j < size);

        if (x == 0)
        {
            total_hor = sum_hor;
            total_ver = sum_ver;
            total_dia = sum_dia2;
        }
        else
        {
            if (sum_hor != total_hor)
            {
                is_horEqual = false;
            }
            if (sum_ver != total_ver)
            {
                is_verEqual = false;
            }
        }
    }

    if (sum_dia1 != total_dia)
    {
        is_diaEqual = false;
    }

    if (is_diaEqual && is_horEqual && is_verEqual)
    {
        is_equal = true;
    }

    return is_equal;
}

int main()
{
    int size, x, y, sqr[10][10], row = 0, col = 0, dia = 0;
    scanf("%d", &size);
    for (y = 0; y < size; y++)
    {
        for (x = 0; x < size; x++)
        {
            scanf("%d", &sqr[x][y]);
        }
    }

    if (is_magic_square(size, sqr))
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }

    return 0;
}