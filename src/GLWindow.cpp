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

void GLWindow::close()
{
	glutDestroyWindow(main);
}

void GLWindow::Render()
{
	app->render();
}

void GLWindow::Mice(int button, int state, int x, int y)
{
	app->mouse(button, state, x, y);
	glutPostWindowRedisplay(app->main);
}

void GLWindow::Idlefunc()
{
	app->idlefunc();
}

void GLWindow::Keyboard(unsigned char key, int x, int y)
    {
        app->keyboard(key, x, y);
        glutPostWindowRedisplay(app->main);
    }

void GLWindow::Motion(int x, int y)
    {
        app->motion(x, y);
    }
void GLWindow::PassiveMotion(int x, int y)
    {
        app->passmotion(x, y);
    }
void GLWindow::Resize(int w, int h)
    {
        app->resize(w, h);
        glutPostWindowRedisplay(app->main);
    }
void GLWindow::Visible(int vis) 
{}
