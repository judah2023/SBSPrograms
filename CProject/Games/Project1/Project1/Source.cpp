#include "graphics.h"
#pragma comment(lib,"graphics.lib")
int main()
{
    int gb = DETECT, gm;
    char string[3] = "";
    initgraph(&gb, &gm, string);

    line(0, 0, 200, 400);

    getch();

    closegraph();
    return 0;
}