#ifndef _POINT2F_H_
#define _POINT2F_H_
#include <GL/gl.h>

struct Point2f
{
    public:
        Point2f(){};
        Point2f(const Point2f& other);
        Point2f(GLfloat _x, GLfloat _y):
        x(_x), y(_y){}
        Point2f& operator=(const Point2f& other);

        GLfloat x = 0.0f;
        GLfloat y = 0.0f;
};

#endif // _POINT2F_H_