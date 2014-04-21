#include <GL/glut.h>
#include <string>

struct Rect {
    int w, h;
};
class GLWindow;
static GLWindow *app;

class GLWindow
{
protected:
    Rect rect;
    int subwindows, initPosx, initPosy, main;
    unsigned int mode;
    std::string name;
    void initMainwnd(int argc, std::string argv);

    //this methods must be implimented
    virtual void resize(int w, int h) = 0;
    virtual void initGL(void) = 0;
    virtual void createsubwindows(void) = 0;
    virtual void render(void) = 0;
    virtual void keyboard(unsigned char key, int x, int y) = 0;
    virtual void mouse(int button, int state, int x, int y) = 0;
    virtual void motion(int x, int y) = 0;
    virtual void passmotion(int x, int y) = 0;
    virtual void idlefunc(void) = 0;

	void close(void)
	{
		glutDestroyWindow(main);
	}

    //dont touch this methods
private:
    static void Render(void)
    {
        app->render();
    }
    static void Mice(int button, int state, int x, int y)
    {
        app->mouse(button, state, x, y);
        glutPostWindowRedisplay(app->main);
    }
    static void Idlefunc(void)
    {
        app->idlefunc();
    }
    static void Keyboard(unsigned char key, int x, int y)
    {
        app->keyboard(key, x, y);
        glutPostWindowRedisplay(app->main);
    }
    static void Motion(int x, int y)
    {
        app->motion(x, y);
    }
    static void PassiveMotion(int x, int y)
    {
        app->passmotion(x, y);
    }
    static void Resize(int w, int h)
    {
        app->resize(w, h);
        glutPostWindowRedisplay(app->main);
    }
    static void Visible(int vis) {}
public:
    GLWindow() {}
    virtual ~GLWindow() {}

    //seters
    void setname(std::string _name)
    {
        name = _name;
    }
    void setinitPosition(int x, int y)
    {
        initPosx = x;
        initPosy = y;
    }
    void setwidthheight(int w, int h)
    {
        rect.w = w;
        rect.h = h;
    }
    void setwidthheight(Rect _rect)
    {
        rect = _rect;
    }

    //geters
    std::string getName(void)
    {
        return name;
    }
    Rect getRect(void)
    {
        return rect;
    }

    //show the window
    void show(int argc, std::string argv)
    {
        initMainwnd(argc , argv);
        initGL();
        glutMainLoop();
    }
};
