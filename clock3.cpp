#include <graphics.h>
#include <time.h>
#include <stdio.h>

void drawDigit(int x, int y, int num) {
    char str[2];
    sprintf(str, "%d", num);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 4);
    outtextxy(x, y, str);
}

void drawClock(int hour, int min, int sec) {
    cleardevice();
    drawDigit(100, 100, hour / 10);
    drawDigit(150, 100, hour % 10);
    outtextxy(200, 100, (char*)":");
    drawDigit(250, 100, min / 10);
    drawDigit(300, 100, min % 10);
    outtextxy(350, 100, (char*)":");
    drawDigit(400, 100, sec / 10);
    drawDigit(450, 100, sec % 10);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm,(char*) "");

    int colors[] = {RED, GREEN, BLUE, YELLOW, CYAN, MAGENTA, WHITE};
    int colorIndex = 0;
    int numColors = sizeof(colors) / sizeof(colors[0]);

    while (!kbhit()) {
        time_t now = time(NULL);
        struct tm *t = localtime(&now);

        int hour = t->tm_hour;
        int min = t->tm_min;
        int sec = t->tm_sec;

        setbkcolor(colors[colorIndex]);
        colorIndex = (colorIndex + 1) % numColors;

        drawClock(hour, min, sec);

        delay(1000);
    }

    closegraph();
    return 0;
}

