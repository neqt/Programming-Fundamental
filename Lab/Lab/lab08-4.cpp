#include <stdio.h>
#include <windows.h>
#include <time.h>
#define scount 80
#define screen_x 1200
#define screen_y 675
HANDLE rHnd;
HANDLE wHnd;
DWORD fdwMode;
CHAR_INFO consoleBuffer[screen_x * screen_y];
COORD bufferSize = { screen_x,screen_y };
COORD characterPos = { 0,0 };
COORD shipPos;
SMALL_RECT windowSize = { 0,0,screen_x - 1,screen_y - 1 };
COORD star[scount];
int color = 7;
int cnt = 0;

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

int randrange(int start, int stop) {
	return rand() % (stop - start + 1) + start;
}

void init_star() {
	for (int i = 0; i < 80; i++) {
		star[i].X = randrange(0, screen_x);
		star[i].Y = randrange(0, screen_y);
	}
}

void star_fall() {
	for (int i = 0; i < scount; i++) {
		if (star[i].Y >= screen_y - 1) {
			star[i] = { (rand() % screen_x),1 };
		}
		else {
			star[i] = { star[i].X, star[i].Y + 1 };
		}
	}
}

void fill_star_to_buffer() {
	for (int i = 0; i < scount; i++) {
		consoleBuffer[star[i].X + screen_x * star[i].Y].Char.AsciiChar = '*';
		consoleBuffer[star[i].X + screen_x * star[i].Y].Attributes = 7;
	}
}

void fill_ship_to_buffer() {
	char ship[] = "<-O->";
	for (int i = 0; i < 5; i++) {
		int index = shipPos.X + i + screen_x * shipPos.Y;
		if (0 <= index && index < screen_x * screen_y) {
			consoleBuffer[index].Char.AsciiChar = ship[i];
			consoleBuffer[index].Attributes = color;
		}
	}
}

bool hit_star() {
	for (int i = 0; i < 80; i++) {
		if (star[i].X >= shipPos.X - 2 && star[i].X <= shipPos.X + 2 && shipPos.Y == star[i].Y) {
			cnt++;
			star[i].X = randrange(0, screen_x);
			star[i].Y = 1;
			if (cnt == 10) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	bool play = true;
	DWORD numEvents = 0;
	DWORD numEventsRead = 0;
	setConsole(screen_x, screen_y);
	setMode();
	srand(time(NULL));
	init_star();
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
						color = randrange(1, 15);
					}
				}
				else if (eventBuffer[i].EventType == MOUSE_EVENT) {
					short posx = eventBuffer[i].Event.MouseEvent.dwMousePosition.X;
					short posy = eventBuffer[i].Event.MouseEvent.dwMousePosition.Y;
					if (eventBuffer[i].Event.MouseEvent.dwButtonState &
						FROM_LEFT_1ST_BUTTON_PRESSED) {
						color = randrange(1, 15);
					}
					else if (eventBuffer[i].Event.MouseEvent.dwEventFlags & MOUSE_MOVED) {
						shipPos = { short(posx - 2),posy };
					}
				}
			}
			delete[] eventBuffer;
		}
		star_fall();
		clear_buffer();
		fill_star_to_buffer();
		fill_ship_to_buffer();
		if (hit_star()) {
			play = false;
		}
		fill_buffer_to_console();
		Sleep(100);
	}
	return 0;
}