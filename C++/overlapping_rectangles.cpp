/*
 * Copyright 2016 - Elton Viana
 *
 * This algorithm verifies if exists a overlapped rectangle between
 * two defined rectangles and get the overlapped rectangle data too.
 * The rectangles are defined by:
 *   - A initial dot (x, y)
 *   - A Width
 *   - A Height
 */

#include <iostream>   // cin(), cout(), endl()
#include <algorithm>  // swap(), max(), min()

using std::cin;
using std::cout;
using std::endl;
using std::swap;
using std::max;
using std::min;

typedef struct _Dot {
    double x, y;
} Dot;

typedef struct _Rectangle {
    Dot p;
    double w, h;
} Rectangle;

// Function prototype
bool overlapped_rectangle(Rectangle r1, Rectangle r2, Rectangle *i);

int main(int argc, char const *argv[]) {
    Rectangle r1 = {}, r2 = {}, i = {};

    // Get Rectangle 1 data
    cout << "Insert Rectangle 1 data:" << endl;
    cout << "Initial Dot:" << endl;
    cout << "  X = ";
    cin >> r1.p.x;
    cout << "  Y = ";
    cin >> r1.p.y;
    cout << "Width: ";
    cin >> r1.w;
    cout << "Height: ";
    cin >> r1.h;

    cout << endl;

    // Get Rectangle 2 data
    cout << "Insert Rectangle 2 data:" << endl;
    cout << "Initial Dot:" << endl;
    cout << "  X = ";
    cin >> r2.p.x;
    cout << "  Y = ";
    cin >> r2.p.y;
    cout << "Width: ";
    cin >> r2.w;
    cout << "Height: ";
    cin >> r2.h;

    // Calls Function
    if (overlapped_rectangle(r1, r2, &i)) {
        cout << "There's a overlapped rectangle" << endl << endl;
        cout << "Overlapped rectangle data:" << endl;
        cout << "  Initial Dot: (" << i.p.x << ", " << i.p.y << ")" << endl;
        cout << "  Width: " << i.w << endl;
        cout << "  Height: " << i.h << endl;
    } else {
        cout << "There's no overlapped rectangle" << endl;
    }

    return EXIT_SUCCESS;
}

bool overlapped_rectangle(Rectangle r1, Rectangle r2, Rectangle *i) {
    // Define r1/r2
    if (r1.p.x > r2.p.x)
        swap(r1, r2);

    if (r2.p.x <= r1.p.x + r1.w) {
        if (r1.p.y > r2.p.y)
            swap(r1, r2);
        if (r2.p.y <= r1.p.y + r1.h) {
            // Define overlapped rectangle initial dot
            i->p = {max(r1.p.x, r2.p.x), max(r1.p.y, r2.p.y)};
            // Define width
            i->w = min(abs(r1.p.x) + r1.w, abs(r2.p.x) + r2.w) - i->p.x;
            // Define height
            i->h = min(abs(r1.p.y) + r1.h, abs(r2.p.y) + r2.h) - i->p.y;

            return true;
        }
    }

    // Set all i fields to 0
    *i = {{0, 0}, 0, 0};

    return false;
}
