#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

double pi = 2 * asin(1.0);

class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
protected:
    double radius;
    static int idCounter;
    int id;

public:
    Circle(double radius) {
        this->radius = radius;
        id = ++idCounter;
    }

    double area() const override {
        return pi * radius * radius;
    }

    void conclusion()
    {
        cout << "Круг ID: " << id << ", Радиус: " << radius << ", Площадь: " << area() << endl;
    }

    ~Circle() {}
};

int Circle::idCounter = 0;


class Sphere : public Circle {
public:
    Sphere(double radius) : Circle(radius) {}

    double volume()
    {
        return (4.0 / 3.0) * pi * pow(radius, 3);
    }

    void conclusion()
    {
        Circle::conclusion();
        cout << "Объем сферы: " << volume() << endl;
    }
};


class Rectangle : public Shape {
protected:
    double width, height;
    static int idCounter;
    int id;

public:
    Rectangle(double width, double height) {
        this->width = width;
        this->height = height;
        id = ++idCounter;
    }

    double area() const override {
        return width * height;
    }

    void conclusion()
    {
        cout << "Прямоугольник ID: " << id << ", Ширина: " << width << ", Высота: " << height << ", Площадь: " << area() << endl;
    }

    ~Rectangle() {}
};

int Rectangle::idCounter = 0;


class Box : public Rectangle {
public:
    Box(double width, double height) : Rectangle(width, height) {}

    double volume()
    {
        return width * height * 5;
    }

    void conclusion()
    {
        Rectangle::conclusion();
        cout << "Объем коробки: " << volume() << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    const int size = 52;
    Shape* shapes[size];
    int shapeCount = 0;
    int choice;

    do {
        cout << "Меню:\n "
            << "1.Добавить круг\n"
            << "2.Добавить сферу\n"
            << "3.Добавить прямоугольник\n"
            << "4.Добавить коробку\n"
            << "5.Показать фигуры\n"
            << "0.Выход\n";
        cin >> choice;

        if (choice == 1) {
            double radius;
            cout << "Введите радиус круга: ";
            cin >> radius;
            shapes[shapeCount++] = new Circle(radius);
        }
        else if (choice == 2) {
            double radius;
            cout << "Введите радиус сферы: ";
            cin >> radius;
            shapes[shapeCount++] = new Sphere(radius);
        }
        else if (choice == 3) {
            double width, height;
            cout << "Введите ширину и высоту прямоугольника: ";
            cin >> width >> height;
            shapes[shapeCount++] = new Rectangle(width, height);
        }
        else if (choice == 4) {
            double width, height;
            cout << "Введите ширину и высоту коробки: ";
            cin >> width >> height;
            shapes[shapeCount++] = new Box(width,
                height);
        }
        else if (choice == 5) {
            for (int i = 0; i < shapeCount; ++i) {
                if (dynamic_cast<Circle*>(shapes[i])) {
                    dynamic_cast<Circle*>(shapes[i])->conclusion();
                }
                else if (dynamic_cast<Rectangle*>(shapes[i])) {
                    dynamic_cast<Rectangle*>(shapes[i])->conclusion();
                }
            }
        }

    } while (choice != 0);


    for (int i = 0; i < shapeCount; ++i) {
        delete shapes[i];
    }

}