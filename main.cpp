#include <stdlib.h>
#include <math.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

/* GLUT callback Handlers */
void resize(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Set color to white for the background
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2f(-1.0, 1.0);
    glVertex2f(1.0, 1.0);
    glVertex2f(1.0, -1.0);
    glVertex2f(-1.0, -1.0);
    glEnd();

    // Set color to red for the circle
    glColor3f(1.f, 0.f, 0.f); // Red circle color code for Bangladesh flag

    // Center of the circle
    float centerX = 0.0;
    float centerY = 0.0;

    // Radius of the circle
    float radius = 0.4; // Adjust the radius to fit nicely within the green background

    // Number of vertices to approximate the circle
    int numVertices = 100;

    glBegin(GL_POLYGON);
    for (int i = 0; i < numVertices; ++i) {
        float theta = 2.0 * 3.1415926 * i / numVertices; // Angle for each vertex
        float x = centerX + radius * cos(theta); // Calculate x coordinate
        float y = centerY + radius * sin(theta); // Calculate y coordinate
        glVertex2f(x, y); // Set vertex
    }
    glEnd();

    glFlush();
}

/* Program entry point */
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(1080,1080);
    glutCreateWindow("Bangladesh Flag");
    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    glClearColor(1, 1, 1, 1);
    glutMainLoop();
    return EXIT_SUCCESS;
}
