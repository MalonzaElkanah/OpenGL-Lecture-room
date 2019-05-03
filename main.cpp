#include <windows.h>
#include <GL/glut.h>



//Initializes 3D rendering
void initRendering() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);          //Enable lighting
    glEnable(GL_LIGHT0);            //Enable light #0
    glEnable(GL_LIGHT1);            //Enable light #1
    glEnable(GL_NORMALIZE);         //Automatically normalize normals
    glShadeModel(GL_SMOOTH);        //Enable smooth shading
}

//Called when the window is resized
void handleResize(int w, int h) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(120.0, (double)w / (double)h, 1.0, 200.0);
}

float _angle = 0.0f;


//Draws the 3D scene
///DRAW FLOUR walls
void drawClassroomWalls(){
    glBegin(GL_QUADS);

        //flour
        glColor3f(0.5f, 0.5f, 0.7f);

        glVertex3f(-30.0f, -3.0f, -60.0f);
        glVertex3f(30.0f, -3.0f, -60.0f);
        glVertex3f(30.0f, -3.0f, 20.0f);
        glVertex3f(-30.0f, -3.0f, 20.0f);

        //frontwall
        glColor3f(0.5f, 0.5f, 0.3f);

        glVertex3f(-30.0f, -3.0f, 20.0f);
        glVertex3f(30.0f, -3.0f, 20.0f);
        glVertex3f(30.0f, 20.0f, 20.0f);
        glVertex3f(-30.0f, 20.0f, 20.0f);

        //WhiteBoard
        glColor3f(01.0f, 01.0f, 01.0f);

        glVertex3f(-20.0f, 0.0f, 19.8f);
        glVertex3f(20.0f, 0.0f, 19.8f);
        glVertex3f(20.0f, 10.0f, 19.8f);
        glVertex3f(-20.0f, 10.0f, 19.8f);

        //left wall
        glColor3f(0.5f, 0.5f, 0.3f);

        glVertex3f(30.0f, -3.0f, 20.0f);
        glVertex3f(30.0f, -3.0f, -60.0f);
        glVertex3f(30.0f, 20.0f, -60.0f);
        glVertex3f(30.0f, 20.0f, 20.0f);

        //right wall
        glVertex3f(-30.0f, -3.0f, 20.0f);
        glVertex3f(-30.0f, -3.0f, -60.0f);
        glVertex3f(-30.0f, 20.0f, -60.0f);
        glVertex3f(-30.0f, 20.0f, 20.0f);

        //back wall
        glVertex3f(-30.0f, -3.0f, -60.0f);
        glVertex3f(30.0f, -3.0f, -60.0f);
        glVertex3f(30.0f, 20.0f, -60.0f);
        glVertex3f(-30.0f, 20.0f, -60.0f);

        //Ceiling Board
        glColor3f(0.3f, 0.3f, 0.3f);

        glVertex3f(-30.0f, 20.0f, -60.0f);
        glVertex3f(30.0f, 20.0f, -60.0f);
        glVertex3f(30.0f, 20.0f, 20.0f);
        glVertex3f(-30.0f, 20.0f, 20.0f);

    glEnd();
}


///DRAW CHAIR
void drawScene(float x, float z) {

    glBegin(GL_QUADS);

        //Front
        glVertex3f(-2.0f+x, -0.2f, 2.0f+z);
        glVertex3f(2.0f+x, -0.2f, 2.0f+z);
        glVertex3f(2.0f+x, 0.2f, 2.0f+z);
        glVertex3f(-2.0f+x, 0.2f, 2.0f+z);
        //Right
        glVertex3f(2.0f+x, -0.2f, -2.0f+z);
        glVertex3f(2.0f+x, 0.2f, -2.0f+z);
        glVertex3f(2.0f+x, 0.2f, 2.0f+z);
        glVertex3f(2.0f+x, -0.2f, 2.0f+z);
        //Back
        glVertex3f(-2.0f+x, -0.2f, -2.0f+z);
        glVertex3f(-2.0f+x, 0.2f, -2.0f+z);
        glVertex3f(2.0f+x, 0.2f, -2.0f+z);
        glVertex3f(2.0f+x, -0.2f, -2.0f+z);
        //Left
        glVertex3f(-2.0f+x, -0.2f, -2.0f+z);
        glVertex3f(-2.0f+x, -0.2f, 2.0f+z);
        glVertex3f(-2.0f+x, 0.2f, 2.0f+z);
        glVertex3f(-2.0f+x, 0.2f, -2.0f+z);
        //top
        glVertex3f(2.0f+x, 0.2f, 2.0f+z);
        glVertex3f(-2.0f+x, 0.2f, 2.0f+z);
        glVertex3f(-2.0f+x, 0.2f, -2.0f+z);
        glVertex3f(2.0f+x, 0.2f, -2.0f+z);

        //bottom
        glVertex3f(2.0f+x, -0.2f, 2.0f+z);
        glVertex3f(-2.0f+x, -0.2f, 2.0f+z);
        glVertex3f(-2.0f+x, -0.2f, -2.0f+z);
        glVertex3f(2.0f+x, -0.2f, -2.0f+z);

       //table front leg
        //front
        glVertex3f(1.8f+x,-0.2f,1.6f+z);
        glVertex3f(1.4f+x, -0.2f, 1.6f+z);
        glVertex3f(1.4f+x, -3.0f, 1.6f+z);
        glVertex3f(1.8f+x, -3.0f, 1.6f+z);

        //back
        glVertex3f(1.8f+x,-0.2f,1.2f+z);
        glVertex3f(1.4f+x, -0.2f, 1.2f+z);
        glVertex3f(1.4f+x, -3.0f, 1.2f+z);
        glVertex3f(1.8f+x, -3.0f, 1.2f+z);

        //right
        glVertex3f(1.8f+x,-0.2f,1.6f+z);
        glVertex3f(1.8f+x, -0.2f, 1.2f+z);
        glVertex3f(1.8f+x, -3.0f, 1.2f+z);
        glVertex3f(1.8f+x, -3.0f, 1.6f+z);

        //left
        glVertex3f(1.4f+x,-0.2f,1.6f+z);
        glVertex3f(1.4f+x, -0.2f, 1.2f+z);
        glVertex3f(1.4f+x, -3.0f, 1.2f+z);
        glVertex3f(1.4f+x, -3.0f, 1.6f+z);

        //back leg back
        //front
        glVertex3f(1.8f+x,-0.2f,-1.2f+z);
        glVertex3f(1.4f+x, -0.2f, -1.2f+z);
        glVertex3f(1.4f+x, -3.0f, -1.2f+z);
        glVertex3f(1.8f+x, -3.0f, -1.2f+z);

        //back
        glVertex3f(1.8f+x,-0.2f,-1.6f+z);
        glVertex3f(1.4f+x, -0.2f, -1.6f+z);
        glVertex3f(1.4f+x, -3.0f, -1.6f+z);
        glVertex3f(1.8f+x, -3.0f, -1.6f+z);

        //right
        glVertex3f(1.8f+x,-0.2f,-1.6f+z);
        glVertex3f(1.8f+x, -0.2f, -1.2f+z);
        glVertex3f(1.8f+x, -3.0f, -1.2f+z);
        glVertex3f(1.8f+x, -3.0f, -1.6f+z);

        //left
        glVertex3f(1.4f+x,-0.2f,-1.6f+z);
        glVertex3f(1.4f+x, -0.2f, -1.2f+z);
        glVertex3f(1.4f+x, -3.0f, -1.2f+z);
        glVertex3f(1.4f+x, -3.0f, -1.6f+z);

        //leg left front
        glVertex3f(-1.8f+x,-0.2f,1.6f+z);
        glVertex3f(-1.4f+x, -0.2f, 1.6f+z);
        glVertex3f(-1.4f+x, -3.0f, 1.6f+z);
        glVertex3f(-1.8f+x, -3.0f, 1.6f+z);

        //back
        glVertex3f(-1.8f+x,-0.2f,1.2f+z);
        glVertex3f(-1.4f+x, -0.2f, 1.2f+z);
        glVertex3f(-1.4f+x, -3.0f, 1.2f+z);
        glVertex3f(-1.8f+x, -3.0f, 1.2f+z);

        //right
        glVertex3f(-1.8f+x,-0.2f,1.6f+z);
        glVertex3f(-1.8f+x, -0.2f, 1.2f+z);
        glVertex3f(-1.8f+x, -3.0f, 1.2f+z);
        glVertex3f(-1.8f+x, -3.0f, 1.6f+z);

        //left
        glVertex3f(-1.4f+x,-0.2f,1.6f+z);
        glVertex3f(-1.4f+x, -0.2f, 1.2f+z);
        glVertex3f(-1.4f+x, -3.0f, 1.2f+z);
        glVertex3f(-1.4f+x, -3.0f, 1.6f+z);

        //left leg back front

        //front
        glVertex3f(-1.8f+x,-0.2f,-1.2f+z);
        glVertex3f(-1.4f+x, -0.2f, -1.2f+z);
        glVertex3f(-1.4f+x, -3.0f, -1.2f+z);
        glVertex3f(-1.8f+x, -3.0f, -1.2f+z);

        //back
        glVertex3f(-1.8f+x,-0.2f,-1.6f+z);
        glVertex3f(-1.4f+x, -0.2f, -1.6f+z);
        glVertex3f(-1.4f+x, -3.0f, -1.6f+z);
        glVertex3f(-1.8f+x, -3.0f, -1.6f+z);

        //right
        glVertex3f(-1.8f+x,-0.2f,-1.6f+z);
        glVertex3f(-1.8f+x, -0.2f, -1.2f+z);
        glVertex3f(-1.8f+x, -3.0f, -1.2f+z);
        glVertex3f(-1.8f+x, -3.0f, -1.6f+z);

        //left
        glVertex3f(-1.4f+x,-0.2f,-1.6f+z);
        glVertex3f(-1.4f+x, -0.2f, -1.2f+z);
        glVertex3f(-1.4f+x, -3.0f, -1.2f+z);
        glVertex3f(-1.4f+x, -3.0f, -1.6f+z);


        ///chair back-arms

    ///left arm
        //front
        glVertex3f(-1.6f+x, 0.2f, -1.6f+z);
        glVertex3f(-2.0f+x, 0.2f, -1.6f+z);
        glVertex3f(-2.0f+x, 3.6f, -1.6f+z);
        glVertex3f(-1.6f+x, 3.6f, -1.6f+z);
        //back
        glVertex3f(-1.6f+x, 0.2f, -2.0f+z);
        glVertex3f(-2.0f+x, 0.2f, -2.0f+z);
        glVertex3f(-2.0f+x, 3.6f, -2.0f+z);
        glVertex3f(-1.6f+x, 3.6f, -2.0f+z);
        //right
        glVertex3f(-1.6f+x, 0.2f, -1.6f+z);
        glVertex3f(-1.6f+x, 0.2f, -2.0f+z);
        glVertex3f(-1.6f+x, 3.6f, -2.0f+z);
        glVertex3f(-1.6f+x, 3.6f, -1.6f+z);
        //left
        glVertex3f(-2.0f+x, 0.2f, -1.6f+z);
        glVertex3f(-2.0f+x, 0.2f, -2.0f+z);
        glVertex3f(-2.0f+x, 3.6f, -2.0f+z);
        glVertex3f(-2.0f+x, 3.6f, -1.6f+z);
        //top+x
        glVertex3f(-1.6f+x, 3.6f, -1.6f+z);
        glVertex3f(-2.0f+x, 3.6f, -1.6f+z);
        glVertex3f(-1.6f+x, 3.6f, -2.0f+z);
        glVertex3f(-2.0f+x, 3.6f, -2.0f+z);

        //right arm
         //front
        glVertex3f(1.6f+x, 0.2f, -1.6f+z);
        glVertex3f(2.0f+x, 0.2f, -1.6f+z);
        glVertex3f(2.0f+x, 3.6f, -1.6f+z);
        glVertex3f(1.6f+x, 3.6f, -1.6f+z);
        //back
        glVertex3f(1.6f+x, 0.2f, -2.0f+z);
        glVertex3f(2.0f+x, 0.2f, -2.0f+z);
        glVertex3f(2.0f+x, 3.6f, -2.0f+z);
        glVertex3f(1.6f+x, 3.6f, -2.0f+z);
        //right
        glVertex3f(1.6f+x, 0.2f, -1.6f+z);
        glVertex3f(1.6f+x, 0.2f, -2.0f+z);
        glVertex3f(1.6f+x, 3.6f, -2.0f+z);
        glVertex3f(1.6f+x, 3.6f, -1.6f+z);
        //left
        glVertex3f(2.0f+x, 0.2f, -1.6f+z);
        glVertex3f(2.0f+x, 0.2f, -2.0f+z);
        glVertex3f(2.0f+x, 3.6f, -2.0f+z);
        glVertex3f(2.0f+x, 3.6f, -1.6f+z);
        //top
        glVertex3f(1.6f+x, 3.6f, -1.6f+z);
        glVertex3f(2.0f+x, 3.6f, -1.6f+z);
        glVertex3f(1.6f+x, 3.6f, -2.0f+z);
        glVertex3f(2.0f+x, 3.6f, -2.0f+z);


        ///chair back

        //front
        glColor3f(1,0,0);

        glVertex3f(-2.1f+x, 2.0f, -1.7f+z);
        glVertex3f(2.1f+x, 2.0f, -1.7f+z);
        glVertex3f(2.1f+x, 3.5f, -1.7f+z);
        glVertex3f(-2.1f+x, 3.5f, -1.7f+z);
        //back
        glVertex3f(-2.1f+x, 2.0f, -1.8f+z);
        glVertex3f(2.1f+x, 2.0f, -1.8f+z);
        glVertex3f(2.1f+x, 3.5f, -1.8f+z);
        glVertex3f(-2.1f+x, 3.5f, -1.8f+z);
        //left
        glVertex3f(-2.1f+x, 2.0f, -1.7f+z);
        glVertex3f(-2.1f+x, 2.0f, -1.8f+z);
        glVertex3f(-2.1f+x, 3.5f, -1.8f+z);
        glVertex3f(-2.1f+x, 3.5f, -1.7f+z);
        //right
        glVertex3f(2.1f+x, 2.0f, -1.7f+z);
        glVertex3f(2.1f+x, 2.0f, -1.8f+z);
        glVertex3f(2.1f+x, 3.5f, -1.8f+z);
        glVertex3f(2.1f+x, 3.5f, -1.7f+z);

    glEnd();

    ///CHAIR TABLE
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);

        //Front
        glVertex3f(-2.0f+x, 1.6f, 3.0f+z);
        glVertex3f(2.0f+x, 1.6f, 3.0f+z);
        glVertex3f(2.0f+x, 2.0f, 3.0f+z);
        glVertex3f(-2.0f+x, 2.0f, 3.0f+z);

        //Right
        glVertex3f(2.0f+x, 1.6f, 1.0f+z);
        glVertex3f(2.0f+x, 2.0f, 1.0f+z);
        glVertex3f(2.0f+x, 2.0f, 3.0f+z);
        glVertex3f(2.0f+x, 1.6f, 3.0f+z);

        //Back
        glVertex3f(-2.0f+x, 1.6f, 1.0f+z);
        glVertex3f(-2.0f+x, 2.0f, 1.0f+z);
        glVertex3f(2.0f+x, 2.0f, 1.0f+z);
        glVertex3f(2.0f+x, 1.6f, 1.0f+z);

        //Left
        glVertex3f(-2.0f+x, 1.6f, 1.0f+z);
        glVertex3f(-2.0f+x, 1.6f, 3.0f+z);
        glVertex3f(-2.0f+x, 2.0f, 3.0f+z);
        glVertex3f(-2.0f+x, 2.0f, 1.0f+z);

        //top
        glVertex3f(2.0f+x, 2.0f, 3.0f+z);
        glVertex3f(-2.0f+x, 2.0f, 3.0f+z);
        glVertex3f(-2.0f+x, 2.0f, 1.0f+z);
        glVertex3f(2.0f+x, 2.0f, 1.0f+z);

        //bottom
        glVertex3f(2.0f+x, 1.6f, 3.0f+z);
        glVertex3f(-2.0f+x, 1.6f, 3.0f+z);
        glVertex3f(-2.0f+x, 1.6f, 1.0f+z);
        glVertex3f(2.0f+x, 1.6f, 1.0f+z);

        ///Connect Chair with the table

        //Right
        glVertex3f(-1.5f+x, 1.6f, -2.0f+z);
        glVertex3f(-1.5f+x, 2.0f, -2.0f+z);
        glVertex3f(-1.5f+x, 2.0f, 3.0f+z);
        glVertex3f(-1.5f+x, 1.6f, 3.0f+z);

        //Back
        glVertex3f(-2.0f+x, 1.6f, -2.0f+z);
        glVertex3f(-2.0f+x, 2.0f, -2.0f+z);
        glVertex3f(-1.5f+x, 2.0f, -2.0f+z);
        glVertex3f(-1.5f+x, 1.6f, -2.0f+z);

        //Left
        glVertex3f(-2.0f+x, 1.6f, -2.0f+z);
        glVertex3f(-2.0f+x, 2.0f, -2.0f+z);
        glVertex3f(-2.0f+x, 2.0f, 3.0f+z);
        glVertex3f(-2.0f+x, 1.6f, 3.0f+z);

        //top
        glVertex3f(-1.5f+x, 2.0f, 3.0f+z);
        glVertex3f(-2.0f+x, 2.0f, 3.0f+z);
        glVertex3f(-2.0f+x, 2.0f, -2.0f+z);
        glVertex3f(-1.5f+x, 2.0f, -2.0f+z);

        //bottom
        glVertex3f(-1.5f+x, 1.6f, 3.0f+z);
        glVertex3f(-2.0f+x, 1.6f, 3.0f+z);
        glVertex3f(-2.0f+x, 1.6f, -2.0f+z);
        glVertex3f(-1.5f+x, 1.6f, -2.0f+z);

    glEnd();
    glFlush();

}

void drawMultipleChair(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW); // keep it like this
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -14.0f);

    //Add ambient light
    GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f}; //Color (0.2, 0.2, 0.2)
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

    //Add positioned light
    GLfloat lightColor0[] = {0.5f, 0.5f, 0.5f, 1.0f}; //Color (0.5, 0.5, 0.5)
    GLfloat lightPos0[] = {0.0f, -8.0f, 8.0f, 1.0f}; //Positioned at (4, 0, 8)
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

    //Add directed light
    GLfloat lightColor1[] = {0.5f, 0.2f, 0.2f, 1.0f}; //Color (0.5, 0.2, 0.2)
    //Coming from the direction (-1, 0.5, 0.5)
    GLfloat lightPos1[] = {-1.0f, 0.5f, 0.5f, 0.0f};
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
    glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);

    glRotatef(10, 1.0f, 0.0f, 0.0f);
    glRotatef(-10, 0.0f, 0.0f, 1.0f);
    glRotatef(_angle,0.0f, 1.0f, 0.0f);


    drawClassroomWalls();

    glColor3f(1.0f, 1.0f, 0.0f);
    ///left column
        //1st row
    drawScene(14.0f, 0.0);
    drawScene(19.0, 0.0);
    drawScene(24.0f,0.0);
        //2nd row
    drawScene(14.0f, -7.0);
    drawScene(19.0, -7.0);
    drawScene(24.0f,-7.0);
        //3rd row
    drawScene(14.0f, -14.0);
    drawScene(19.0, -14.0);
    drawScene(24.0f,-14.0);
        //4th row
    drawScene(14.0f, -21.0);
    drawScene(19.0, -21.0);
    drawScene(24.0f,-21.0);
        //5th row
    drawScene(14.0f, -35.0);
    drawScene(19.0, -35.0);
    drawScene(24.0f,-35.0);
        //6th row
    drawScene(14.0f, -42.0);
    drawScene(19.0, -42.0);
    drawScene(24.0f,-42.0);
        //7th row
    drawScene(14.0f, -49.0);
    drawScene(19.0, -49.0);
    drawScene(24.0f,-49.0);
        //8th row
    drawScene(14.0f, -56.0);
    drawScene(19.0, -56.0);
    drawScene(24.0f,-56.0);


    ///center column
        //1st row
    drawScene(5.0f, 0.0);
    drawScene(0.0, 0.0);
    drawScene(-5.0f,0.0);
        //2nd row
    drawScene(5.0f, -07.0);
    drawScene(0.0, -07.0);
    drawScene(-5.0f,-07.0);
        //3rd row
    drawScene(5.0f, -14.0);
    drawScene(0.0, -14.0);
    drawScene(-5.0f,-14.0);
        //4th row
    drawScene(5.0f, -21.0);
    drawScene(0.0, -21.0);
    drawScene(-5.0f,-21.0);
        //5th row
    drawScene(5.0f, -35.0);
    drawScene(0.0, -35.0);
    drawScene(-5.0f,-35.0);
        //6th row
    drawScene(5.0f, -42.0);
    drawScene(0.0, -42.0);
    drawScene(-5.0f,-42.0);
        //7th row
    drawScene(5.0f, -49.0);
    drawScene(0.0, -49.0);
    drawScene(-5.0f,-49.0);
        //8th row
    drawScene(5.0f, -56.0);
    drawScene(0.0, -56.0);
    drawScene(-5.0f,-56.0);

    ///right column
        //1st row
    drawScene(-14.0f, 0.0);
    drawScene(-19.0, 0.0);
    drawScene(-24.0f,0.0);
        //2nd row
    drawScene(-14.0f, -07.0);
    drawScene(-19.0, -07.0);
    drawScene(-24.0f,-07.0);
        //3rd row
    drawScene(-14.0f, -14.0);
    drawScene(-19.0, -14.0);
    drawScene(-24.0f, -14.0);
        //4th row
    drawScene(-14.0f, -21.0);
    drawScene(-19.0, -21.0);
    drawScene(-24.0f,-21.0);
        //5th row
    drawScene(-14.0f, -35.0);
    drawScene(-19.0, -35.0);
    drawScene(-24.0f, -35.0);
        //6th row
    drawScene(-14.0f, -42.0);
    drawScene(-19.0, -42.0);
    drawScene(-24.0f,-42.0);
        //7th row
    drawScene(-14.0f, -49.0);
    drawScene(-19.0, -49.0);
    drawScene(-24.0f, -49.0);
        //8th row
    drawScene(-14.0f, -56.0);
    drawScene(-19.0, -56.0);
    drawScene(-24.0f,-56.0);

     glutSwapBuffers();
}

void update(int value) {
    _angle += 1.5f;
    if (_angle > 360) {
        _angle -= 360;
    }

    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}

int main(int argc, char** argv) {
    //Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1200, 700);

    //Create the window
    glutCreateWindow("CLASSROOM CHAIR");
    initRendering();

    //Set handler functions
    glutDisplayFunc(drawMultipleChair);

    glutReshapeFunc(handleResize);

    update(0);
    glutMainLoop();
    return 0;
}

