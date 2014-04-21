#include "../include/GLWindow.hpp"
void GLWindow::initMainwnd(int argc, std::string argv)
{
    char *ar[argv.size()];
    app = this;
    for(unsigned int i = 0; i < argv.size(); i++)
    {
        ar[i] = &argv[i];
    }

    glutInit(&argc,  ar);
    glutInitDisplayMode(mode);
    glutInitWindowSize(rect.w, rect.h);
    glutInitWindowPosition(initPosx, initPosy);
    main = glutCreateWindow(name.c_str());
    glutDisplayFunc(Render);
    glutKeyboardFunc(Keyboard);
    glutVisibilityFunc(Visible);
    glutMouseFunc(Mice);
    glutMotionFunc(Motion);
    glutPassiveMotionFunc(PassiveMotion);
}
