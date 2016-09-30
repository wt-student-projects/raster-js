
#include "OpenGL.h"
#include "gl/GLU.h"
#include "gl/gl.h"

void glClearColor(v8::FunctionArgs args)
{
    if (args.Length() == 4)
    {
        auto r = args[0].As<v8::Number>()->Value();
        auto g = args[1].As<v8::Number>()->Value();
        auto b = args[2].As<v8::Number>()->Value();
        auto a = args[3].As<v8::Number>()->Value();

        glClearColor(r, g, b, a);
    }
}

void glClear(v8::FunctionArgs args)
{
    if (args.Length() == 1)
    {
        glClear(args[0]->NumberValue());
    }
}

void glBegin(v8::FunctionArgs args)
{
    if (args.Length() == 1)
    {
        glBegin(static_cast<GLenum>(args[0]->NumberValue()));
    }
}

void glColor3(v8::FunctionArgs args)
{
    if (args.Length() == 3)
    {
        auto r = args[0].As<v8::Number>()->Value();
        auto g = args[1].As<v8::Number>()->Value();
        auto b = args[2].As<v8::Number>()->Value();

        glColor3f(r, g, b);
    }
}

void glVertex2(v8::FunctionArgs args)
{
    if (args.Length() == 2)
    {
        auto x = args[0].As<v8::Number>()->Value();
        auto y = args[1].As<v8::Number>()->Value();

        glVertex2f(x, y);
    }
}

void glVertex3(v8::FunctionArgs args)
{
    if (args.Length() == 3)
    {
        auto x = args[0].As<v8::Number>()->Value();
        auto y = args[1].As<v8::Number>()->Value();
        auto z = args[2].As<v8::Number>()->Value();

        glVertex3f(x, y, z);
    }
}

void glLoadIdentity(v8::FunctionArgs args)
{
    ::glLoadIdentity();
}

void glMatrixMode(v8::FunctionArgs args)
{
    if (args.Length() == 1)
    {
        ::glMatrixMode(args[0].As<v8::Number>()->Value());
    }
}

void glTranslate(v8::FunctionArgs args)
{
    if (args.Length() == 3)
    {
        auto x = args[0].As<v8::Number>()->Value();
        auto y = args[1].As<v8::Number>()->Value();
        auto z = args[2].As<v8::Number>()->Value();

        glTranslatef(x, y, z);
    }
}

void glRotate(v8::FunctionArgs args)
{
    if (args.Length() == 4)
    {
        auto r = args[0].As<v8::Number>()->Value();
        auto x = args[1].As<v8::Number>()->Value();
        auto y = args[2].As<v8::Number>()->Value();
        auto z = args[3].As<v8::Number>()->Value();

        glRotatef(r, x, y, z);
    }
}

void glPerspective(v8::FunctionArgs args)
{
    if (args.Length() == 4)
    {
        auto fov = args[0].As<v8::Number>()->Value();
        auto aspect = args[1].As<v8::Number>()->Value();
        auto min = args[2].As<v8::Number>()->Value();
        auto max = args[3].As<v8::Number>()->Value();

        gluPerspective(fov, aspect, min, max);
    }
}

void glEnd(v8::FunctionArgs args)
{
    glEnd();
}

void glEnable(v8::FunctionArgs args)
{
    if (args.Length() == 1)
    {
        glEnable(args[0].As<v8::Integer>()->Value());
    }
}

void compute::registerOpenGL(v8::Exports exports)
{
    AttachFunction(exports, "gluPerspective", glPerspective);
    AttachFunction(exports, "glEnable", glEnable);
    AttachFunction(exports, "glMatrixMode", glMatrixMode);
    AttachFunction(exports, "glLoadIdentity", glLoadIdentity);
    AttachFunction(exports, "glTranslatef", glTranslate);
    AttachFunction(exports, "glRotatef", glRotate);
    AttachFunction(exports, "glClearColor", glClearColor);
    AttachFunction(exports, "glVertex3f", glVertex3);
    AttachFunction(exports, "glVertex2f", glVertex2);
    AttachFunction(exports, "glColor3f", glColor3);
    AttachFunction(exports, "glClear", glClear);
    AttachFunction(exports, "glBegin", glBegin);
    AttachFunction(exports, "glEnd", glEnd);
}