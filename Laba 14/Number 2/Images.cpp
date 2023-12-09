

#include "Images.h"

void Image0(HDC hdc, int cx, int cy, COLORREF color) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, color);
    SelectObject(hdc, hPen);

    POINT p[4] = {
        cx,        	cy + 20,
        cx + 20,	cy - 20,
        cx - 20,   	cy - 20,
        cx,        	cy + 20
    };
    Polyline(hdc, p, 4);

    DeleteObject(hPen);
}

void Image1(HDC hdc, int cx, int cy, COLORREF color) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, color);
    SelectObject(hdc, hPen);

    POINT p[4] = {
        cx,        	cy - 20,
        cx - 20,	cy + 20,
        cx + 20,   	cy + 20,
        cx,        	cy - 20
    };
    Polyline(hdc, p, 4);

    DeleteObject(hPen);
}

void PictureV(HDC hdc) {
    int x, y, i;

    x = 100;
    y = 50;
    i = 0;
    do {

        Image0(hdc, x, y, RGB(0, 255, 0));
        y += 70;

        i++;
    } while (i < 6);
}

void PictureH(HDC hdc) {
    int x, y, j;

    x = 100;
    y = 50;
    j = 0;
    do {

        Image0(hdc, x, y, RGB(255, 0, 0));
        x += 50;

        j++;
    } while (j < 8);
}

void PictureVH(HDC hdc) {
    int x, y, i, j;

    y = 50;
    i = 0;
    do {

        x = 100;
        j = 0;
        do {
            Image0(hdc, x, y, RGB(255, 255, 0));
            x += 50;

            j++;
        } while (j < 8);

        y += 70;

        i++;
    } while (i < 6);
}