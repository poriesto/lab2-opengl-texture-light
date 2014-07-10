/*
	File: GLWindow.hpp
	Author: poriesto
	Description: parent class for window
*/
#include <GL/glut.h>
#include <string>

struct Rect {
    int w, h;
};

class GLWindow
{
protected:
    Rect rect;
    std::string name;
    int subwindows, initPosx, initPosy, main;
    unsigned int mode;
    void initMainwnd(int argc, std::string argv);
	void close(void);

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

    //dont touch this methods
private:
    static void Render(void);
    static void Mice(int button, int state, int x, int y);
    static void Idlefunc(void);
    static void Keyboard(unsigned char key, int x, int y);
    static void Motion(int x, int y);
    static void PassiveMotion(int x, int y);
    static void Resize(int w, int h);
    static void Visible(int vis);
public:
    GLWindow();
    virtual ~GLWindow();

    //seters
    void setname(std::string _name);
    void setinitPosition(int x, int y);
    void setwidthheight(int w, int h);
    void setwidthheight(Rect _rect);
    //geters
    std::string getName(void);
    Rect getRect(void);
    //show the window
    void show(int argc, std::string argv);
};
