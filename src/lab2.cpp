#include "../include/lab2.h"
#include <GL/glu.h>
#include <GL/gl.h>
#include <iostream>

lab2::lab2(int _subwindows, unsigned int _mode)
{
    //ctor
    subwindows = _subwindows;
    mode = _mode;
    yVal = 1.0;
}

lab2::~lab2()
{
    //dtor
}

void lab2::render(void)
{
    std::cout << "Render" << std::endl;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    GLfloat material_diffuse[] = {1.0, 1.0, 1.0, 1.0};
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_diffuse);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    glRotatef(yRot, 0.0f, 1.0f, 0.0f);
    glRotatef(zRot, 0.0f, 0.0f, 1.0f);
    glTranslatef(xTra, yTra, zTra);
    glScalef(nSca, nSca, nSca);

    glPushMatrix();
    spot(yVal,5.0,1.5,1.0,1.0,1.0);
    draw();

    glPopMatrix();
    disableLight();
}

void lab2::initGL(void)
{
	std::cout << "Initializete GL" << std::endl;
    xRot = -30;
    yRot = 0;
    zRot = 0;
    xTra = 0;
    yTra = 0;
    zTra = 0;
    nSca = 0.2;

    stacks = 25;
    slices = 25;
    xCenterCylinder = 0;
    yCenterSphere = 0;
    zCenterCylinder = 0;
    baseRad = 1.0;
    topRad = 1.0;
    cyheight = 3;
    cylinder = gluNewQuadric();

    xCenterConus = 0;
    yCenterConus = 0;
    zCenterConus = 0;
    conusRad = 1.0;
    coheight = 3;
    conus = gluNewQuadric();

    xCenterSphere = 0;
    yCenterSphere = 0;
    zCenterSphere = 3;
    spRad = 1.0;
    sphere = gluNewQuadric();

    image = loadBMP("earth.bmp");
    _textureId = loadTexture(image);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    glViewport(0,0, rect.w, rect.h);
    glEnable(GL_NORMALIZE);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_CULL_FACE);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_MULTISAMPLE);

    delete image;
}

void lab2::disableLight(void)
{
    glDisable(GL_LIGHT0);
    // элемент двойной буферизации
    glutSwapBuffers();
}

void lab2::moveCamera(int dir)
{
    switch(dir) {
    case 1:
        yTra += 0.05;
        break;
    case 2:
        yTra -= 0.05;
        break;
    case 3:
        xTra -= 0.05;
        break;
    case 4:
        xTra += 0.05;
        break;
    }
}

void lab2::rotate(int dir)
{
    switch(dir) {
    case 1:
        //up rotate
        std::cout << "Camera rotated up" << std::endl;
        xRot += 1.0;
        break;
    case 2:
        //down rotate;
        std::cout << "Camera rotated down" << std::endl;
        xRot -= 1.0f;
        break;
    case 3:
        //left
        std::cout << "Camera rotated left" << std::endl;
        zRot += 1.0;
        break;
    case 4:
        //right
        std::cout << "Camera rotated right" << std::endl;
        zRot -= 1.0;
        break;
    }
}

void lab2::keyboard(unsigned char key, int x, int y)
{
    std::cout << "Keyboard" << std::endl;
    switch(key) {
    case 'q':
        //exit(0);
		close();
    case 's':
        moveCamera(2);
        break;
    case 'a':
        moveCamera(3);
        break;
    case 'd':
        moveCamera(4);
        break;
    case 'w':
        moveCamera(1);
        break;
    case 'i':
        rotate(1);
        break;
    case 'k':
        rotate(2);
        break;
    case 'j':
        rotate(3);
        break;
    case 'l':
        rotate(4);
        break;
    case 'o':
        yVal++;
        break;
    case 't':
        scale(1);
        break;
    case 'y':
        scale(2);
        break;
    }
}

void lab2::scale(int scale)
{
    switch(scale) {
    case 1:
        nSca = static_cast<GLfloat>(nSca*1.1);
        break;
    case 2:
        nSca = static_cast<GLfloat>(nSca/1.1);
        break;
    }
}

void lab2::draw(void)
{


    gluQuadricDrawStyle (cylinder, GL_POLYGON);
    gluQuadricDrawStyle (sphere, GL_POLYGON);
    gluQuadricDrawStyle (conus, GL_POLYGON);
    gluQuadricTexture(cylinder, GL_TRUE);
    gluQuadricTexture(sphere, GL_TRUE);
    gluQuadricTexture(conus, GL_TRUE);

    glTranslatef(xCenterCylinder, yCenterCylinder, zCenterCylinder);
    glBindTexture(GL_TEXTURE_2D, _textureId);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    gluCylinder(cylinder, baseRad, topRad, cyheight, slices, stacks);

    glTranslatef(xCenterSphere, yCenterSphere, zCenterSphere);
    gluSphere(sphere, spRad, slices, stacks);

    glTranslatef(xCenterConus, yCenterConus, zCenterConus);
    gluCylinder(conus, conusRad, 0, coheight, slices, stacks);
}

int lab2::spot(double a, double b, double c, double d, double e, double f)
{
    /*
    a, b and c -- x, y and z co-ordinates for light position
    d, e and f -- x, y and z co-ordinates for spot light position
    */
    std::cout << "Spot light" << std::endl;
    glEnable(GL_LIGHT0);
    GLfloat mat_specular[] = { static_cast<GLfloat>(0.3), static_cast<GLfloat>(1.0), static_cast<GLfloat>(0.3), static_cast<GLfloat>(1.0) };
    GLfloat mat_shininess[] = { 50.0 };
    GLfloat light_position[] = { static_cast<GLfloat>(a),static_cast<GLfloat>(b),static_cast<GLfloat>(c), static_cast<GLfloat>(1.0) };
    GLfloat spotDir[] = { static_cast<GLfloat>(d),static_cast<GLfloat>(e),static_cast<GLfloat>(f) };
    glClearColor (0.5, 0.5, 0.5, 0.0);
    glShadeModel (GL_SMOOTH);
    glLightfv(GL_LIGHT0,GL_SPECULAR,mat_specular);
    glLightfv(GL_LIGHT0,GL_POSITION,light_position);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    // Definig spotlight attributes
    glLightf(GL_LIGHT0,GL_SPOT_CUTOFF,95.0);
    glLightf(GL_LIGHT0,GL_SPOT_EXPONENT,2.0);
    glLightfv(GL_LIGHT0,GL_SPOT_DIRECTION,spotDir);
    glEnable(GL_COLOR_MATERIAL);
    //glEnable(GL_DEPTH_TEST);

    return 0;
}

GLuint loadTexture(Image* image)
{
	std::cout << "Texture from image loading" << std::endl;
    GLuint textureId;

    glGenTextures(1, &textureId); //Make room for our texture

    glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit

    //Map the image to the texture

    glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D

                 0,                            //0 for now

                 GL_RGB,                       //Format OpenGL uses for image

                 image->width, image->height,  //Width and height

                 0,                            //The border of the image

                 GL_RGB, //GL_RGB, because pixels are stored in RGB format

                 GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored

                 //as unsigned numbers

                 image->pixels);               //The actual pixel data

    return textureId; //Returns the id of the texture

}
