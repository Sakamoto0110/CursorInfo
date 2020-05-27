#include <iostream>
#include <windows.h>
using namespace std;
void gotoxy(int x, int y) {
    COORD pos = {x, y};
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}
void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

void run(){

    Sleep(40);
    //system("cls");
    POINT p;
    int line = 0;
    if (GetCursorPos(&p)){
        gotoxy(0,line);
        cout << "                             ";
        gotoxy(0,line);
        cout << "Position.X: " << p.x << endl;
        line++;

        gotoxy(0,line);
        cout << "                             ";
        gotoxy(0,line);
        cout << "Position.Y: " << p.y << endl;
        line++;

    }
    line++;
    COLORREF pixel = GetPixel(GetDC(NULL),(int)p.x,(int)p.y);
    int r = GetRValue(pixel);
    int g = GetGValue(pixel);
    int b = GetBValue(pixel);

    gotoxy(0,line);
    cout << "                             ";
    gotoxy(0,line);
    cout << "Red value: " << r << endl;
    line++;

    gotoxy(0,line);
    cout << "                             ";
    gotoxy(0,line);
    cout << "green value: " << g << endl;
    line++;

    gotoxy(0,line);
    cout << "                             ";
    gotoxy(0,line);
    cout << "Blue value: " << b << endl;
    line++;

}

int main()
{
    bool paused = false;


    SetConsoleTitle("Coord Utilities! By Sakamoto.");
    SetWindowPos( GetConsoleWindow(),
                  HWND_TOP,
                  10,
                  10,
                  300,
                  170,
                  SWP_NOZORDER

                 );

    while(1){
        ShowConsoleCursor(false);
        if( !paused ){
            run();
        }
        if( GetAsyncKeyState(0x10) ){
            paused = false;
        }
        if( GetAsyncKeyState(0x11) ){
            paused = true;
        }


    }
    return 0;
}
