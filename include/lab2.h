/*
	File: lab2.h
	Author: poriesto
	Description: class implement window with gl object
*/
#ifndef LAB2_H
#define LAB2_H

#include "GLWindow.h"
#include "imageloader.h"

GLuint loadTexture(Image* image);

class lab2 : public GLWindow
{
public:
    lab2(int _subwindows = 0, unsigned int _mode = GLUT_DOUBLE|GLUT_RGBA);
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
	GLUquadric* cylinder;
	GLUquadric* sphere;
   	GLUquadric* conus;
    //light
	GLfloat yVal, yVal1, yVal2;
    //for scene objects
    GLint stacks, slices;
	//cylinder
    GLfloat xCenterCylinder, yCenterCylinder, zCenterCylinder;
   	GLfloat baseRad, topRad, cyheight;
    //conus
	GLfloat xCenterConus, yCenterConus, zCenterConus, conusRad, coheight;
	//sphere
	GLfloat xCenterSphere, yCenterSphere, zCenterSphere, spRad;
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
    void spot(double a, double b, double c, double d, double e, double f);
	void spot2(double a, double b, double c, double d, double e, double f);
	void spot3(double a, double b, double c, double d, double e, double f);
};

#endif // LAB2_H
