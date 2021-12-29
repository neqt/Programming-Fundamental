#include <stdio.h>
#include <windows.h>
#include <time.h>
#define screen_x 80
#define screen_y 25
HANDLE rHnd;
HANDLE wHnd;
DWORD fdwMode;
CHAR_INFO consoleBuffer[screen_x * screen_y];
COORD bufferSize = { screen_x,screen_y };
COORD characterPos = { 0,0 };
COORD playerPos;
SMALL_RECT windowSize = { 0,0,screen_x - 1,screen_y - 1 };
int color = 7;

int setConsole(int x, int y) {
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
	SetConsoleScreenBufferSize(wHnd, bufferSize);
	return 0;
}

void clear_buffer() {
	for (int y = 0; y < screen_y; ++y) {
		for (int x = 0; x < screen_x; ++x) {
			consoleBuffer[x + screen_x * y].Char.AsciiChar = ' ';
			consoleBuffer[x + screen_x * y].Attributes = 7;
		}
	}
}

void fill_buffer_to_console() {
	WriteConsoleOutputA(wHnd, consoleBuffer, bufferSize, characterPos,
		&windowSize);
}

int setMode() {
	rHnd = GetStdHandle(STD_INPUT_HANDLE);
	fdwMode = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT |
		ENABLE_MOUSE_INPUT;
	SetConsoleMode(rHnd, fdwMode);
	return 0;
}

void setcolor(int fg, int bg) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}

int rand(int start, int stop) {
	return rand() % (stop - start + 1) + start;
}

void fill_player_to_buffer() {
	consoleBuffer[playerPos.X + screen_x * playerPos.Y].Char.AsciiChar = '<';
	consoleBuffer[playerPos.X + screen_x * playerPos.Y].Attributes = color;
	consoleBuffer[playerPos.X+1 + screen_x * playerPos.Y].Char.AsciiChar = '-';
	consoleBuffer[playerPos.X+1 + screen_x * playerPos.Y].Attributes = color;
	consoleBuffer[playerPos.X+2 + screen_x * playerPos.Y].Char.AsciiChar = 'O';
	consoleBuffer[playerPos.X+2 + screen_x * playerPos.Y].Attributes = color;
	consoleBuffer[playerPos.X+3 + screen_x * playerPos.Y].Char.AsciiChar = '-';
	consoleBuffer[playerPos.X+3 + screen_x * playerPos.Y].Attributes = color;
	consoleBuffer[playerPos.X+4 + screen_x * playerPos.Y].Char.AsciiChar = '>';
	consoleBuffer[playerPos.X+4 + screen_x * playerPos.Y].Attributes = color;
}

int main() {
	bool play = true;
	DWORD numEvents = 0;
	DWORD numEventsRead = 0;
	setConsole(screen_x, screen_y);
	setMode();
	while (play) {
		GetNumberOfConsoleInputEvents(rHnd, &numEvents);
		if (numEvents != 0) {
			INPUT_RECORD* eventBuffer = new INPUT_RECORD[numEvents];
			ReadConsoleInput(rHnd, eventBuffer, numEvents, &numEventsRead);
			for (DWORD i = 0; i < numEventsRead; ++i) {
				if (eventBuffer[i].EventType == KEY_EVENT &&
					eventBuffer[i].Event.KeyEvent.bKeyDown == true) {
					if (eventBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE) {
						play = false;
					}
					if (eventBuffer[i].Event.KeyEvent.uChar.AsciiChar == 'c') {
						color = rand(1, 15);
					}
				}
				else if (eventBuffer[i].EventType == MOUSE_EVENT) {
					short posx = eventBuffer[i].Event.MouseEvent.dwMousePosition.X;
					short posy = eventBuffer[i].Event.MouseEvent.dwMousePosition.Y;
					if (eventBuffer[i].Event.MouseEvent.dwButtonState &
						FROM_LEFT_1ST_BUTTON_PRESSED) {
						color = rand(1, 15);
					}
					else if (eventBuffer[i].Event.MouseEvent.dwButtonState &
						RIGHTMOST_BUTTON_PRESSED) {
						color = rand(1, 15);
					}
					else if (eventBuffer[i].Event.MouseEvent.dwEventFlags & MOUSE_MOVED) {
						fill_player_to_buffer();
						playerPos = { short(posx-2), posy };
					}
				}
			}
			delete[] eventBuffer;
		}
		clear_buffer();
		fill_player_to_buffer();
		fill_buffer_to_console();
		Sleep(100);
	}
	return 0;
}