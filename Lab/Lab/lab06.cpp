#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdbool.h>

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
    printf("   |   ");
}

void erase_bullet(int x, int y) {
    gotoxy(x, y);
    setcolor(0, 0);
    printf("       ");
}

int main() {
    char ch = '.';
    int x = 38, y = 20;
    int direction=0;
    int i = 0;
    int bx[5], by[5];
    bool bulletStatus[5] = { false,false,false,false,false };
    setcursor(0);
    draw_ship(x, y);
    do {
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
                        bx[i] = x;
                        by[i] = y-1;
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
        for (int i = 0; i < 5; i++) {
            if (bulletStatus[i]) {
                erase_bullet(bx[i], by[i]);
                if (by[i] > 0) {
                    draw_bullet(bx[i], --by[i]);
                }
                else {
                    bulletStatus[i] = false;
                }
            }
        }
        Sleep(50);
    } while (ch != 'x');
    return 0;
}

/*
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdbool.h>
void gotoxy(int x, int y)
{
    COORD c = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void draw_ship(int x, int y)
{
    gotoxy(x, y);
    printf(" <-0-> ");
}
void setcolor(int fg, int bg)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}
void erase_ship(int x, int y)
{
    gotoxy(x, y);
    setcolor(0, 0);
    printf("       ");
}
void setcursor(bool visible)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = 20;
    SetConsoleCursorInfo(console, &lpCursor);
}
void  draw_bullet(int x, int y) {
    setcolor(15, 0);
    gotoxy(x, y);
    printf("  O   ");

}
void  erase_bullet(int x, int y) {
    gotoxy(x, y);
    setcolor(0, 0);
    printf("      ");
}
struct Bullet
{
    bool status = false;
    int x = 0, y = 0;
};

int main()
{
    char ch = '.';
    int x = 38, y = 20;
    setcursor(0);
    setcolor(2, 4);
    draw_ship(x, y);
    int dir = 0;
    const unsigned int bc = 5;
    Bullet bs[bc];
    do {
        if (_kbhit())
        {
            ch = _getch();
            if (ch == 'a')
            {
                dir = -1;
            }
            if (ch == 'd')
            {
                dir = 1;
            }
            if (ch == 's')
            {
                dir = 0;
            }
            if (ch == ' ') {
                for (size_t i = 0; i < bc; i++) {
                    if (!bs[i].status) {
                        bs[i].status = true;
                        bs[i].x = x;
                        bs[i].y = y;
                        break;
                    }
                }
            }
            fflush(stdin);
        }
        for (size_t i = 0; i < bc; i++) {
            erase_bullet(bs[i].x, bs[i].y);
            if (bs[i].status && bs[i].y > 0) {
                draw_bullet(bs[i].x, --bs[i].y);
            }
            else {
                bs[i].status = false;
            }
        }
        if (dir != 0)
        {
            if (dir == -1 && x > 0)
            {
                erase_ship(x, y);
                setcolor(2, 4);
                draw_ship(--x, y);
            }
            if (dir == 1 && x < 73)
            {
                erase_ship(x, y);
                setcolor(2, 4);
                draw_ship(++x, y);
            }
        }
        else {
            setcolor(2, 4);
            draw_ship(x, y);
        }
        dir == 0;
        Sleep(100);
    } while (ch != 'x');
    return 0;
}
*/