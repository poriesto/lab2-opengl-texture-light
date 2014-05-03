/*
Задание 25.
1. Предметы: цилиндр(прозрачность 0,7), сфера, конус(с зеркальностью).
2. Источники: 3, 2 точечные белые, 1 направленный цветной (угол 30)
3. Наложить текстуры.
*/
#include <iostream>
#include "../include/lab2.h"
using namespace std;

int main()
{
    string name = "lab2", argv = "-w GLUT_RGB GLUT_DEPTH";
    int argc = 3;
    unsigned int mode = GLUT_DOUBLE|GLUT_RGBA;
    Rect rct;
    rct.w = 640; rct.h = 480;
    lab2* lab = new lab2(0, mode);
	cout << "Program launched" << endl;

    lab->setname(name);
    lab->setinitPosition(10, 10);
    lab->setwidthheight(rct);
    lab->show(argc, argv);

    return 0;
}
