#include <GL/glut.h>
void DisplayTriangle(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            glViewport(j * glutGet(GLUT_WINDOW_WIDTH) / 5, i * glutGet(GLUT_WINDOW_HEIGHT) / 5,
            glutGet(GLUT_WINDOW_WIDTH) / 5, glutGet(GLUT_WINDOW_HEIGHT) / 5);
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            if(i%2==0 && j%2==0) gluOrtho2D(-1, 1, -1, 1); // Define a 2D orthographic projection
            if(i%2==0 && j%2==1) gluOrtho2D(1, -1, -1, 1);
            if(i%2==1 && j%2==0) gluOrtho2D(-1, 1, 1, -1);
            if(i%2==1 && j%2==1) gluOrtho2D(1, -1, 1, -1);

            glBegin(GL_TRIANGLES);
            glColor3f(0.0f, 0.0f, 1.0f);//b
            glVertex2f(-1.0f, 1.0f);//zuun deed
            glColor3f(1.0f, 0.0f, 0.0f);//r
            glVertex2f(-1.0f, -1.0f);//zuun dood
            glColor3f(0.0f, 0.0f, 1.0f);//b
            glVertex2f(1.0f, -1.0f);//baruun dood
            glEnd();
            glBegin(GL_TRIANGLES);
            glVertex2f(1.0f, -1.0f);//baruun dood
            glColor3f(0.0f, 1.0f, 0.0f);//g
            glVertex2f(1.0f, 1.0f);//baruun deed
            glColor3f(0.0f, 0.0f, 1.0f);//b
            glVertex2f(-1.0f, 1.0f);//zuun deed
            glEnd();
        }
    }

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(720, 720);
    glutCreateWindow("Triangle Pattern");
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glutDisplayFunc(DisplayTriangle);
    glutMainLoop();
    return 0;
}
