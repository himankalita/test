#include<GL/glut.h>
#include<GL/gl.h>
#include<math.h>
#include<unistd.h>
#include<stdio.h>
#define pi 3.14159
#define g 10

float x_0=0,y_0=0,x=0,y=0;
float theta=(pi)/7;
float v_0=40;
float tof;
int draw_endpoint=0;
int n_points=100;float X[100],Y[100];

float a_0=0,b_0=0,a=0,b=0;
float theta_1=(pi)/3;
float v_1=70;
float tof_1;

float A[100],B[100];
void timer();

void calc()
{
    int i;
    tof=2*v_0*sin(theta)/g;
    float del_t=tof/100;
    float temp=0;
    for(i=0;i<100;i++)
    {
        x=v_0*cos(theta)*temp;
        y=v_0*sin(theta)*temp - ((g*temp*temp)/2);
        X[i]=x;
        Y[i]=y;
        temp+=del_t;
    }
    for(i=0;i<10;i++){
        printf("%f %f \n",X[i],Y[i]);
    }
}

void calc_1()
{
    int j;
    tof_1=2*v_1*sin(theta_1)/g;
    float del_t=tof_1/100;
    float temp=0;
    for(j=0;j<100;j++)
    {
        a=v_1*cos(theta_1)*temp;
        b=v_1*sin(theta_1)*temp - ((g*temp*temp)/2);
        A[j]=a;
        B[j]=b;
        temp+=del_t;
    }
    //for(j=0;i<10;i++){
      //  printf("%f %f \n",X[i],Y[i]);

}

//void idle(){
//    draw_endpoint=(draw_endpoint +1)%n_points;
//    glutPostRedisplay();
//}

void display(){

    glClear( GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
     //glBegin(GL_TRIANGLES);
      glColor3f(0.0,1.0,0.0);
      glPointSize(1.0);
     glBegin(GL_POINTS);
     calc();
     calc_1();
     for(int i=0;i<draw_endpoint;i++)
        {glVertex2f(X[i],Y[i]);

//
//
//          glVertex2f(2+X[i],2+Y[i]);
//      glVertex2f(X[i]-0.5,Y[i]+0.5);
//      glVertex2f(X[i]+0.5,Y[i]+0.5);
//      glVertex2f(X[i]+1.0,Y[i]);
//      glVertex2f(X[i]+0.5,Y[i]-0.5);
//      glVertex2f(X[i]-0.5,Y[i]-0.5);
//      glVertex2f(X[i]-0.75,Y[i]-0.75);
//      glVertex2f(X[i]-0.5,Y[i]+0.5);
//        glEnd();
        }


//
//     for(int j=0;j<draw_endpoint;j++){glVertex2f(A[j],B[j]);}



//    glEnd();



     glEnd();
//     glPointSize(3.0);
//    glBegin(GL_LINE_LOOP);
//    for(int j=0;j<draw_endpoint;j++)
//        {glVertex2f(A[j],B[j]);
//     glVertex2f(A[j]-5,B[j]+5);
//      glVertex2f(A[j]+5,B[j]+5);
//      glVertex2f(A[j]+10,B[j]);
//      glVertex2f(A[j]+5,B[j]-5);
//      glVertex2f(A[j]-5,B[j]-5);
//      glVertex2f(A[j]-7.5,B[j]-7.5);
//      glVertex2f(A[j]-5,B[j]+5);
//        }
//     glEnd();
//     glBegin(GL_LINE);
//
//       glVertex2f(10,10);
//       glVertex2f(500,500);
//      glEnd();
    glutSwapBuffers();
}
void reshape(int w,int h)
{
    glViewport(0,0,w,h);
}

void initOpenGL()
{
    glClearColor(0.0,0.0,0.0,0.0); //set color

}
//b2Vec2 getTrajectoryPoint

int main(int argc,char **argv){

    //start freeglut
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(500 , 500);
    glutInitWindowPosition(100 , 100);
    glutCreateWindow("projectile");

    initOpenGL();

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,500.0,0.0,500.0);

    glutDisplayFunc(display);
//    glutIdleFunc(idle);
    glutReshapeFunc(reshape);
    glutTimerFunc(0,timer,0);

    glutMainLoop();


    return 0;

}

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0);
    if(x_positon<8)
        x_positon+=0.15;


}


