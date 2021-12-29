#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdbool.h>
#include<time.h>

char cursor(int x, int y) {
    HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
    char buf[2]; COORD c = { x,y }; DWORD num_read;
    if (!ReadConsoleOutputCharacter(hStd, (LPTSTR)buf, 1, c, (LPDWORD)&num_read)) {
        return '\0';
    }
    else {
        return buf[0];
    }
}

void gotoxy(int x, int y) {
    COORD c = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void setcursor(bool visible) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = 20;
    SetConsoleCursorInfo(console, &lpCursor);
}

void setcolor(int fg, int bg) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}

void draw_ship(int x, int y) {
    gotoxy(x, y);
    setcolor(2, 4);
    printf(" <-0-> ");
}

void erase_ship(int x, int y) {
    gotoxy(x, y);
    setcolor(0, 0);
    printf("       ");
}

void draw_bullet(int x, int y) {
    gotoxy(x, y);
    setcolor(7, 0);
    printf("|");
}

void erase_bullet(int x, int y) {
    gotoxy(x, y);
    setcolor(0, 0);
    printf(" ");
}

int randrange(int start, int stop) {
    return rand() % (stop - start + 1) + start;
}

int main() {
    char ch = '.';
    int x = 38, y = 20;
    int direction = 0;
    //int i = 0;
    int score = 0;
    int bx[5], by[5];
    bool bulletStatus[5] = { false,false,false,false,false };
    setcursor(0);
    draw_ship(x, y);

    //random star
    srand(time(NULL));
    for (int i = 0; i < 20; i++) {
        gotoxy(randrange(10, 70), randrange(2, 5));
        setcolor(6, 0);
        printf("*");
    }

    do {
        //move ship
        if (_kbhit()) {
            ch = _getch();
            if (ch == 'a') {
                direction = -1;
            }
            else if (ch == 'd') {
                direction = 1;
            }
            else if (ch == 's') {
                direction = 0;
            }
            else if (ch == ' ') {
                for (int i = 0; i < 5; i++) {
                    if (!bulletStatus[i]) {
                        bulletStatus[i] = true;
                        bx[i] = x + 3;
                        by[i] = y - 1;
                        break;
                    }
                }
            }
            fflush(stdin);
        }
        if (direction != 0) {
            if (direction == -1 && x > 0) {
                erase_ship(x, y);
                draw_ship(--x, y);
            }
            else if (direction == 1 && x < 113) {
                erase_ship(x, y);
                draw_ship(++x, y);
            }
        }
        else {
            draw_ship(x, y);
        }

        //bullet
        for (int i = 0; i < 5; i++) {
            if (bulletStatus[i]) {
                Beep(1000, 50);
                erase_bullet(bx[i], by[i]);
                if (cursor(bx[i], by[i]-1) == '*') {
                    Beep(500, 50);
                    gotoxy(bx[i], by[i]-1);
                    setcolor(0, 0);
                    printf(" ");
                    gotoxy(randrange(10, 70), randrange(2, 5));
                    setcolor(6, 0);
                    printf("*");
                    bulletStatus[i] = false;
                    score++;
                }
                else if (by[i] >= 2) {
                    draw_bullet(bx[i], --by[i]);
                }
                else {
                    bulletStatus[i] = false;
                }
            }
        }

        //score
        gotoxy(110, 0);
        setcolor(7, 0);
        printf("Score : %d", score);

        Sleep(50);
    } while (ch != 'x');
    return 0;
}