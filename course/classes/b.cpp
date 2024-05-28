#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

struct Top {
    int x = 0, y = 0;
};

class Polygon {
   public:
    Top* tops;
    int n;

   public:
    virtual double getPerimeter() = 0;
    virtual void isPolygon() = 0;
    double distance(Top pt1, Top pt2) {
        return sqrt(pow(pt1.x - pt2.x, 2) + pow(pt1.y - pt2.y, 2));
    }
    Polygon() {}
};

class Triangle : public Polygon {
   public:
    double a = 0, b = 0, c = 0;
    Triangle() {
        n = 3;
        tops = new Top[n];
        for (int i = 0; i < n; i++) {
            cin >> tops[i].x >> tops[i].y;
        }

        a = distance(tops[1], tops[0]);
        b = distance(tops[2], tops[1]);
        c = distance(tops[0], tops[2]);
        isPolygon();
    }

    double getPerimeter() override {
        return a + b + c;
    }
    void isPolygon() override {
        if ((a == 0 || b == 0 || c == 0)) throw 1;
        if (a >= b + c || b >= a + c || c >= a + b) throw 1;
    }
    // Triangle() { delete tops; }
};

class Quadrangle : public Polygon {
   public:
    double a = 0, b = 0, c = 0, d = 0;
    Quadrangle() {
        n = 4;
        tops = new Top[n];
        for (int i = 0; i < n; i++) {
            cin >> tops[i].x >> tops[i].y;
        }

        a = distance(tops[1], tops[0]);
        b = distance(tops[2], tops[1]);
        c = distance(tops[3], tops[2]);
        d = distance(tops[0], tops[3]);
        isPolygon();
    }

    double getPerimeter() override {
        return a + b + c + d;
    }
    void isPolygon() override {
        if ((a == 0 || b == 0 || c == 0 || d == 0)) throw 1;
        // if (a >= b + c || b >= a + c || c >= a + b) throw 1;
    }
};

int main() {
    try {
        Polygon* pg = nullptr;
        pg = new Quadrangle;
        // cout << "Perimeter" << endl;
        cout << fixed << setprecision(4) << pg->getPerimeter() << endl;
    } catch (int) {
        cout << "No polygon" << endl;
        return 0;
    }

    return 0;
}
