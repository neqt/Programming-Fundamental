#include <windows.h>
#include <time.h>

#define screen_x 80
#define screen_y 25

HANDLE wHnd;
CHAR_INFO consoleBuffer[screen_x * screen_y];
COORD bufferSize = { screen_x,screen_y };
COORD characterPos = { 0,0 };
SMALL_RECT windowSize = { 0,0,screen_x - 1,screen_y - 1 };

int setConsole(int x, int y)
{
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
	SetConsoleScreenBufferSize(wHnd, bufferSize);
	return 0;
}

int rand(int start, int stop) {
	return rand() % (stop - start + 1) + start;
}

void fill_data_to_buffer()
{
	for (int y = 0; y < screen_y; ++y) {
		for (int x = 0; x < screen_x; ++x) {
			consoleBuffer[x + screen_x * y].Char.AsciiChar = rand('A','Z');
			consoleBuffer[x + screen_x * y].Attributes = rand(0,255);
		}
	}
}

void fill_buffer_to_console()
{
	WriteConsoleOutputA(wHnd, consoleBuffer, bufferSize, characterPos,
		&windowSize);
}

int main()
{
	setConsole(screen_x, screen_y);
	for (int i = 0; i <= 10000; i++) {
		fill_data_to_buffer();
		fill_buffer_to_console();
	}
	Sleep(5000);
	return 0;
}