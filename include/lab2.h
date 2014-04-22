#ifndef LAB2_H
#define LAB2_H

#include "GLWindow.hpp"
#include "imageloader.h"

GLuint loadTexture(Image* image);

class lab2:public GLWindow
{
public:
    lab2(int _subwindows, unsigned int _mode);
    virtual ~lab2();
protected:
    inline void resize(int w, int h);
    inline void initGL(void);
    inline void createsubwindows(void);
    inline void render(void);
    inline void keyboard(unsigned char key, int x, int y);
    inline void mouse(int button, int state, int x, int y);
    inline void motion(int x, int y);
    inline void passmotion(int x, int y);
    inline void idlefunc(void);
private:
    //camera
    GLfloat xRot, yRot, zRot;
    GLfloat xTra, yTra, zTra, nSca;
    GLint yVal;
    //for scene objects
    GLint stacks, slices;
    GLfloat xCenterCylinder, yCenterCylinder, zCenterCylinder, baseRad, topRad, cyheight;
    GLfloat xCenterConus, yCenterConus, zCenterConus, conusRad, coheight;
    GLfloat xCenterSphere, yCenterSphere, zCenterSphere, spRad;
    GLUquadric* cylinder;
    GLUquadric* sphere;
    GLUquadric* conus;
	//texture
    Image* image;
	Image* img;
	Image* img1;
    GLuint _textureId[3];
private:
    //additional methods
    void draw(void);
    void setinitrotate(void);
    void moveCamera(int dir);
    void rotate(int dir);
    void scale(int scale);
    void disableLight(void);
    int spot(double a, double b, double c, double d, double e, double f);
};

#endif // LAB2_H
