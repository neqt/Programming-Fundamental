//check if it's a magic square
#include <stdio.h>
#include <stdbool.h>

int main()
{
    int size, x, y, i, j, sqr[10][10], hor = 0, ver = 0, dia1 = 0, dia2 = 0, cnt = 0;
    bool is_equal = true;
    scanf("%d", &size);
    for (y = 0; y < size; y++)
    {
        for (x = 0; x < size; x++)
        {
            scanf("%d", &sqr[x][y]);
        }
    }

    //check diagonal (\)
    x = 0, y = 0;
    do
    {
        dia1 += sqr[x++][y++];
    } while (x < size && y < size);

    //check diagonal (/)
    i = size - 1, j = 0;
    do
    {
        dia2 += sqr[i--][j++];
    } while (i >= 0 && j < size);

    if (dia1 != dia2)
    {
        is_equal = false;
    }
    else
    {
        //check horizontal (-)
        for (y = 0; y < size; y++)
        {
            hor = 0;
            for (x = 0; x < size; x++)
            {
                hor += sqr[x][y];
            }
            if (hor != dia1)
            {
                is_equal = false;
                break;
            }
            else
            {
                //check vertical (|)
                for (x = 0; x < size; x++)
                {
                    ver = 0;
                    for (y = 0; y < size; y++)
                    {
                        ver += sqr[x][y];
                    }
                    if (ver != dia1)
                    {
                        is_equal = false;
                        break;
                    }
                }
            }
        }
    }

    if (is_equal)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }

    return 0;
}