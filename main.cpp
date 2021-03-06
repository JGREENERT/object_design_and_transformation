#include <iostream>
#include <cmath>
#include <algorithm>

#define GLEW_STATIC
#include <GL/glew.h>
#ifdef __APPLE__
#include <OpenGL/glu.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#endif

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <glm/gtx/io.hpp>
#include "My_Objects/Table.h"
#include "My_Objects/Window.h"
#include "My_Objects/AllComputer.h"
#include "My_Objects/AllKeyboard.h"

#undef GLFW_DLL
#include <GLFW/glfw3.h>

using namespace std;

Table table1;
Table table2;
Window window1;
AllComputer cp1;
AllComputer cp2;
AllComputer cp3;
AllComputer cp4;
AllComputer cp5;
AllComputer cp6;
AllComputer cp7;
AllComputer cp8;
AllKeyboard keyboard1;
AllKeyboard keyboard2;
AllKeyboard keyboard3;
AllKeyboard keyboard4;
AllKeyboard keyboard5;
AllKeyboard keyboard6;
AllKeyboard keyboard7;
AllKeyboard keyboard8;

void init_model();
void win_refresh(GLFWwindow*);
float arc_ball_rad_square;
int screen_ctr_x, screen_ctr_y;

glm::mat4 camera_cf; // {glm::translate(glm::mat4(1.0f), glm::vec3{0,0,-5})};
glm::mat4 table1_cf;
glm::mat4 table2_cf;
glm::mat4 window1_cf;
glm::mat4 computer_cf;

void err_function (int what, const char *msg) {
    cerr << what << " " << msg << endl;
}


void win_resize (GLFWwindow * win, int width, int height)
{
#ifdef DEBUG
    cout << __FUNCTION__ << " " << width << "x" << height << endl;
#endif
    int w, h;
    glfwGetWindowSize(win, &w, &h);
    screen_ctr_x = w / 2.0;
    screen_ctr_y = h / 2.0;
    float rad = min(h,w)/2;
    arc_ball_rad_square = rad * rad;
    /* Use the entire window for our view port */
    glViewport(0, 0, width, height);
    /* Use GL_PROJECTION to select the type of synthetic camera */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    /* near-plane(1) & far-plane(10) are always POSITIVE and they measure
     * the distances along the Z-axis in front of the camera */
    gluPerspective(60.0, static_cast<float> (width)/ static_cast<float> (height), 1, 10);
}

void win_refresh (GLFWwindow *win) {
//    cout << __PRETTY_FUNCTION__ << endl;
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);

    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity();
    /* place the camera using the camera coordinate frame */
    glMultMatrixf (glm::value_ptr(camera_cf));

    //Tables
    glPushMatrix();
    glTranslatef(3, 0, -1);
    glMultMatrixf(glm::value_ptr(table1_cf));
    glRotated(90, 0, 1, 0);
    table1.render();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3, 0, -1);
    glMultMatrixf(glm::value_ptr(table2_cf));
    glRotated(90, 0, 1, 0);
    table2.render();
    glPopMatrix();

    //Window
    glPushMatrix();
    glTranslatef(0, 1.75, -3.5);
    glMultMatrixf(glm::value_ptr(window1_cf));
    window1.render();
    glPopMatrix();

    //Computers
    glPushMatrix();
    glTranslatef(4, 0, -2.25);
    glScaled(.9, .9, .9);
    glRotatef(90, 0, -1, 0);
    glMultMatrixf(glm::value_ptr(computer_cf));
    cp1.render();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4, 0, .25);
    glScaled(.9, .9, .9);
    glRotatef(90, 0, -1, 0);
    glMultMatrixf(glm::value_ptr(computer_cf));
    cp2.render();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2, 0, .25);
    glScaled(.9, .9, .9);
    glRotatef(90, 0, 1, 0);
    glMultMatrixf(glm::value_ptr(computer_cf));
    cp3.render();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2, 0, -2.25);
    glScaled(.9, .9, .9);
    glRotatef(90, 0, 1, 0);
    glMultMatrixf(glm::value_ptr(computer_cf));
    cp4.render();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2, 0, -2.25);
    glScaled(.9, .9, .9);
    glRotatef(90, 0, -1, 0);
    glMultMatrixf(glm::value_ptr(computer_cf));
    cp5.render();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2, 0, .25);
    glScaled(.9, .9, .9);
    glRotatef(90, 0, -1, 0);
    glMultMatrixf(glm::value_ptr(computer_cf));
    cp6.render();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4, 0, .25);
    glScaled(.9, .9, .9);
    glRotatef(90, 0, 1, 0);
    glMultMatrixf(glm::value_ptr(computer_cf));
    cp7.render();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4, 0, -2.25);
    glScaled(.9, .9, .9);
    glRotatef(90, 0, 1, 0);
    glMultMatrixf(glm::value_ptr(computer_cf));
    cp8.render();
    glPopMatrix();

    //Keyboards
    glPushMatrix();
    glTranslatef(-2, .1, -2.65);
    glScaled(.9, .9, .9);
    glMultMatrixf(glm::value_ptr(computer_cf));
    keyboard5.render();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2, .1, -.25);
    glScaled(.9, .9, .9);
    glMultMatrixf(glm::value_ptr(computer_cf));
    keyboard6.render();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.35, .1, -.25);
    glScaled(.9, .9, .9);
    glMultMatrixf(glm::value_ptr(computer_cf));
    keyboard7.render();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.35, .1, -2.65);
    glScaled(.9, .9, .9);
    glMultMatrixf(glm::value_ptr(computer_cf));
    keyboard8.render();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.65, .1, -2.65);
    glScaled(.9, .9, .9);
    glMultMatrixf(glm::value_ptr(computer_cf));
    keyboard5.render();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.65, .1, -.25);
    glScaled(.9, .9, .9);
    glMultMatrixf(glm::value_ptr(computer_cf));
    keyboard6.render();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4, .1, -.25);
    glScaled(.9, .9, .9);
    glMultMatrixf(glm::value_ptr(computer_cf));
    keyboard7.render();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4, .1, -2.65);
    glScaled(.9, .9, .9);
    glMultMatrixf(glm::value_ptr(computer_cf));
    keyboard8.render();
    glPopMatrix();

    //Lines
    glBegin(GL_LINE_STRIP);
    float x = 4;
    float y = 0.15f;
    float z = .5f;
    glVertex3f(x, y, z);
    glVertex3f(3.3f, y, z);
    glVertex3f(3.3f, y, z-.3);
    glEnd();

    glBegin(GL_LINE_STRIP);
    x = 2;
    glRotatef(-45, 0, 0, 1);
    glVertex3f(x, y, z);
    glVertex3f(2.6f, y, z);
    glVertex3f(2.6f, y, z-.3);
    glEnd();

    glBegin(GL_LINE_STRIP);
    x = 4;
    z -= 2.5;
    glRotatef(-45, 0, 0, 1);
    glVertex3f(x, y, z);
    glVertex3f(3.3f, y, z);
    glVertex3f(3.3f, y, z-.3);
    glEnd();

    glBegin(GL_LINE_STRIP);
    x = 2;
    glRotatef(-45, 0, 0, 1);
    glVertex3f(x, y, z);
    glVertex3f(2.6f, y, z);
    glVertex3f(2.6f, y, z-.3);
    glEnd();

    glBegin(GL_LINE_STRIP);
    x = -4;
    y = 0.15f;
    z = .5f;
    glVertex3f(x, y, z);
    glVertex3f(-3.3f, y, z);
    glVertex3f(-3.3f, y, z-.3);
    glEnd();

    glBegin(GL_LINE_STRIP);
    x = -2;
    glRotatef(-45, 0, 0, 1);
    glVertex3f(x, y, z);
    glVertex3f(-2.6f, y, z);
    glVertex3f(-2.6f, y, z-.3);
    glEnd();

    glBegin(GL_LINE_STRIP);
    x = -4;
    z -= 2.5;
    glRotatef(-45, 0, 0, 1);
    glVertex3f(x-.23, y, z);
    glVertex3f(-3.3f, y, z);
    glVertex3f(-3.3f, y, z-.3);
    glEnd();

    glBegin(GL_LINE_STRIP);
    x = -2;
    glRotatef(-45, 0, 0, 1);
    glVertex3f(x, y, z);
    glVertex3f(-2.6f, y, z);
    glVertex3f(-2.6f, y, z-.3);
    glEnd();

    /* must swap buffer at the end of render function */
    glfwSwapBuffers(win);
}

/* action: GLFW_PRESS, GLFW_RELEASE, or GLFW_REPEAT */
void key_handler (GLFWwindow *win, int key, int scan_code, int action, int mods)
{
    cout << __FUNCTION__ << endl;
    if (action != GLFW_PRESS) return;
    if (mods == GLFW_MOD_SHIFT) {
        switch (key) {
            case GLFW_KEY_D: /* Uppercase 'D' */
                /* pre mult: trans  Z-ax of the world */
                table1_cf = glm::translate(glm::vec3{0, +0.5f, 0}) * table1_cf;
                break;
        }
    }
    else {
        switch (key) {
            case GLFW_KEY_D: /* lowercase 'd' */
                /* pre mult: trans  Z-ax of the world */
                table1_cf = glm::translate(glm::vec3{0, -0.5f, 0}) * table1_cf;
                break;
            case GLFW_KEY_MINUS:
                /* post mult: rotate around Z-ax of the hex nut */
                table1_cf = table1_cf * glm::rotate(1.0f, glm::vec3{0, 0, 1});
                table2_cf = table2_cf * glm::rotate(180.0f, glm::vec3{0, 0, 1});
                break;
            case GLFW_KEY_ESCAPE:
                glfwSetWindowShouldClose(win, true);
                break;
            case GLFW_KEY_0:
                glPolygonMode(GL_FRONT, GL_LINE);
                break;
            case GLFW_KEY_1:
                glPolygonMode(GL_FRONT, GL_FILL);
                break;
            case GLFW_KEY_2:
                table1_cf = table1_cf * glm::scale(glm::vec3(0.5, 0.5, 0.5));
                break;
            case GLFW_KEY_3:
                table1_cf = table1_cf * glm::scale(glm::vec3(2, 2, 2));
                break;
            case GLFW_KEY_4:
                camera_cf *= glm::translate(glm::vec3(0, 1, -2));
                camera_cf *= glm::rotate(4.5f, glm::vec3(0, 1, 0));
                break;
            case GLFW_KEY_5:
                camera_cf *= glm::translate(glm::vec3(0, 0, -4));
                camera_cf *= glm::rotate(180.0f, glm::vec3(1, 0, 0));
                break;
            case GLFW_KEY_6:
                camera_cf *= glm::translate(glm::vec3(0, -1, -3));
                camera_cf *= glm::rotate(170.0f * 9, glm::vec3(0, 1, 0));
                break;
            case GLFW_KEY_7:
                camera_cf *= glm::translate(glm::vec3(0, 0, -3));
                camera_cf *= glm::rotate(-180.0f * 9, glm::vec3(1, 0, 0));
                break;
            case GLFW_KEY_8:
                window1_cf = window1_cf * glm::translate(glm::vec3(0, -0.25, 0.5));
                break;
            case GLFW_KEY_9:
                window1_cf = window1_cf * glm::translate(glm::vec3(0, 0.25, -0.5));
                break;
        }
    }
    win_refresh(win);
}

/*
    The virtual trackeyboardall technique implemented here is based on:
    https://www.opengl.org/wiki/Object_Mouse_Trackeyboardall
*/
void cursor_handler (GLFWwindow *win, double xpos, double ypos) {
    int state = glfwGetMouseButton(win, GLFW_MOUSE_BUTTON_LEFT);
    static glm::vec3 first_click;
    static glm::mat4 current_cam;
    static bool is_tracking = false;

    glm::vec3 this_vec;
    if (state == GLFW_PRESS) {
        /* TODO: use glUnproject? */
        float x = (xpos - screen_ctr_x);
        float y = -(ypos - screen_ctr_y);
        float hypot_square = x * x + y * y;
        float z;

        /* determine whether the mouse is on the sphere or on the hyperbolic sheet */
        if (2 * hypot_square < arc_ball_rad_square)
            z = sqrt(arc_ball_rad_square - hypot_square);
        else
            z = arc_ball_rad_square / 2.0 / sqrt(hypot_square);
        if (!is_tracking) {
            /* store the mouse position when the button was pressed for the first time */
            first_click = glm::normalize(glm::vec3{x, y, z});
            current_cam = camera_cf;
            is_tracking = true;
        }
        else {
            /* compute the rotation w.r.t the initial click */
            this_vec = glm::normalize(glm::vec3{x, y, z});
            /* determine axis of rotation */
            glm::vec3 N = glm::cross(first_click, this_vec);

            /* determine the angle of rotation */
            float theta = glm::angle(first_click, this_vec);

            /* create a quaternion of the rotation */
            glm::quat q{cos(theta / 2), sin(theta / 2) * N};
            /* apply the rotation w.r.t to the current camera CF */
            camera_cf = current_cam * glm::toMat4(glm::normalize(q));
        }
        win_refresh(win);
    }
    else {
        is_tracking = false;
    }
}

void scroll_handler (GLFWwindow *win, double xscroll, double yscroll) {
    /* translate along the camera Z-axis */
    glm::mat4 z_translate = glm::translate((float)yscroll * glm::vec3{0, 0, 1});
    camera_cf =  z_translate * camera_cf;
    win_refresh(win);

}

void init_gl() {
    glEnable (GL_DEPTH_TEST);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glEnable(GL_CULL_FACE);
    glLineWidth(3.0);

    /* place the camera at Z=+5 (notice that the sign is OPPOSITE!) */
    camera_cf *= glm::translate(glm::vec3{0, 0, -5});
}

void make_model() {
    //Table
    table1.build();
    table2.build();
    table1_cf = glm::translate(glm::vec3(0, 0, 0));
    table2_cf = glm::translate(glm::vec3(0, 0, 0));
    //Window
    window1.build();
    window1_cf = glm::translate(glm::vec3(0, 0, 0));
    //Computers
    cp1.build();
    cp2.build();
    cp3.build();
    cp4.build();
    cp5.build();
    cp6.build();
    cp7.build();
    cp8.build();
    //Keyboards
    keyboard1.build();
    keyboard2.build();
    keyboard3.build();
    keyboard4.build();
    keyboard5.build();
    keyboard6.build();
    keyboard7.build();
    keyboard8.build();
    computer_cf = glm::translate(glm::vec3(0, 0, 0));
}

int main() {
    if(!glfwInit()) {
        cerr << "Can't initialize GLFW" << endl;
        glfwTerminate();
        exit (EXIT_FAILURE);
    }

    glfwSetErrorCallback(err_function);
    GLFWwindow * win;
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
    win = glfwCreateWindow(100, 50, "Test", NULL, NULL);
    if (!win) {
        cerr << "Can't create window" << endl;
        exit (EXIT_FAILURE);
    }

    glfwSetWindowRefreshCallback(win, win_refresh);
    /* On Mac with Retina display there is a discrepancy between units measured in
     * "screen coordinates" and "pixels" */
    // glfwSetWindowSizeCallback(win, win_resize);  /* use this for non-retina displays */
    glfwSetFramebufferSizeCallback(win, win_resize); /* use this for retina displays */
    glfwSetKeyCallback(win, key_handler);
    glfwSetCursorPosCallback(win, cursor_handler);
    glfwSetScrollCallback(win, scroll_handler);
    glfwMakeContextCurrent(win);

    /* glewInit must be invoked AFTER glfwMakeContextCurrent() */
    GLenum err = glewInit();
    if (err != GLEW_OK) {
        fprintf (stderr, "GLEW init error %s\n", glewGetErrorString(err));
        exit (EXIT_FAILURE);
    }

    /* GL functions can be called, only AFTER the window is created */
    const GLubyte *version = glGetString (GL_VERSION);
    printf ("GL Version is %s\n", version);


    glfwSetWindowSize(win, 450, 300);
    glfwSwapInterval(1);
    init_gl();
    make_model();

    int ev_num = 0;
    win_refresh(win);
    while (!glfwWindowShouldClose(win)) {
        glfwWaitEvents();
    }
    glfwDestroyWindow(win);
    glfwTerminate();
    return 0;
}
