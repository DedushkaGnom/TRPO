#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>
#include <math.h>
#include <time.h>

using namespace std;
//*
// 1, 15	Создать класс-интерфейс пространственной фигуры, который содержит три элемента с модификатором доступа
// protected. Создать производные классы: прямоугольный параллелепипед, правильная пирамида с треугольным основанием,
// полый цилиндр. Для каждой из фигур предусмотреть вывод ее названия и вычисление объема. Случайным образом выбрать
// фигуру и с помощью оператора dynamic_cast произвести конвертацию типа из класса-интерфейса в производный.*//

class figureSize {
protected:
    double dim1, dim2, dim3;        // размеры фигуры
public:
    void setdim(double d1, double d2) {
        dim1 = d1;
        dim2 = d2;
    }

    void setdim(double d1, double d2, double d3) {
        dim1 = d1;
        dim2 = d2;
        dim3 = d3;
    }

    void getdim(double &d1, double &d2) {
        d1 = dim1;
        d2 = dim2;
    }

    void getdim(double &d1, double &d2, double &d3) {
        d1 = dim1;
        d2 = dim2;
        d3 = dim3;
    }

    virtual void my_name() { cout << "I am an figureSize" << endl; }

    virtual double getsize() { return 1; }
};

class rectangular_parallelepiped : public figureSize { //a , b , c
public:
    double getsize() {
        double d1, d2, d3;
        getdim(d1, d2, d3);
        return d1 * d2 * d3;
    }

    void my_name() { cout << "I am a rectangular parallelepiped" << endl; }
};

class regular_triangular_pyramid : public figureSize {
public:
    double getsize() {
        double d1, d2;
        getdim(d1, d2);
        return d1 * d2 * d2 * sqrt(3);
    }

    void my_name() { cout << "I am a regular triangular pyramid" << endl; }
};

class hollow_cylinder : public figureSize {
public:
    double getsize() {
        const double Pi = 3.14159;
        double d1, d2, d3;
        getdim(d1, d2, d3);
        return Pi * fabs(d1 * d1 - d2 * d2) * d3;
    }

    void my_name() { cout << "I am a hollow cylinder" << endl; }
};

figureSize *GetObj();

int main() {
    figureSize *Ptr;
    figureSize *cPtr;
    double d1, d2, h;
    Ptr = GetObj();
    Ptr->my_name();
    string str = typeid(*Ptr).name();
    size_t found;
    if (found = str.find("figureSize") != string::npos) {
        cPtr = dynamic_cast<figureSize *>(Ptr);
        if (cPtr != nullptr) {
            cout << "dynamic cast is successful" << endl;
        }
        cout << "Input d1 and d2" << endl;
        cin >> d1 >> d2;
        Ptr->setdim(d1, d2);
        cout << "Square of figure = " << Ptr->getsize() << endl;
    } else if (found = str.find("rectangular_parallelepiped") != string::npos) {
        cPtr = dynamic_cast<rectangular_parallelepiped *>(Ptr);
        if (cPtr != nullptr) {
            cout << "dynamic cast is successful" << endl;
        }
        cout << "Input d1 and d2" << endl;
        cin >> d1 >> d2;
        cout << "Input h" << endl;
        cin >> h;
        Ptr->setdim(d1, d2, h);
        cout << "Square of figure = " << Ptr->getsize() << endl;

    } else if (found = str.find("regular_triangular_pyramid") != string::npos) {
        cPtr = dynamic_cast<regular_triangular_pyramid *>(Ptr);
        if (cPtr != nullptr) {
            cout << "dynamic cast is successful" << endl;
        }
        cout << "Input d1 and d2" << endl;
        cin >> d1 >> d2;
        Ptr->setdim(d1, d2);
        cout << "Square of figure = " << Ptr->getsize() << endl;
    } else if (found = str.find("hollow_cylinder") != string::npos) {
        cout << "Input d1 and d2" << endl;
        cin >> d1 >> d2;
        cout << "Input h" << endl;
        cin >> h;
        Ptr->setdim(d1, d2, h);
        cout << "Square of figure = " << Ptr->getsize() << endl;
        cPtr = dynamic_cast<hollow_cylinder *>(Ptr);
        if (cPtr != nullptr) {
            cout << "dynamic cast is successful" << endl;
        }
    }
    return 0;
}

figureSize *GetObj() {
    figureSize *p;
    time_t t;
    srand((int) time(&t));
    switch (rand() % 4) {
        case 0:
            p = new figureSize;
            break;
        case 1:
            p = new rectangular_parallelepiped;
            break;
        case 2:
            p = new regular_triangular_pyramid;
            break;
        case 3:
            p = new hollow_cylinder;
            break;
    }
    return p;
}
