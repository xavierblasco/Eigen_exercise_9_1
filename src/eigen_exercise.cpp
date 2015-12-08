//Std
#include <iostream> //Allows show messages
#include <math.h> //


//eigen
#include <eigen3/Eigen/Dense> //Main Eigen Library


using namespace std;
using namespace Eigen;

float pi = 3.14159265359;

int main()
{
    //Given
    Vector2d p0(10.8, -2.7);
    Vector2d mb(3.1, 1.2);
    Vector2d qs(12, 3);
    float Theta = 28 * (pi/180);
    float Beta = 41 * (pi/180);


    //Rotation Matrix
    Matrix2d R0B;
    Matrix2d RBS;
    Matrix3d T0B;
    Matrix3d TBS;

    Vector3d qs_aux;
    Vector3d qb_aux;
    Vector3d q0_aux;

    R0B << cos(Theta), -sin(Theta), sin(Theta), cos(Theta);
    RBS << cos(Beta), -sin(Beta), sin(Beta), cos(Beta);

    T0B << cos(Theta), -sin(Theta), p0[0], sin(Theta), cos(Theta), p0[1], 0 , 0 , 1;
    TBS << cos(Beta), -sin(Beta), mb[0], sin(Beta), cos(Beta), mb[1], 0 , 0 , 1;


    //Define Vector whit 3 values
    //qb
    qs_aux << qs[0], qs[1], 1;

    qb_aux = TBS * qs_aux;

    cout << " " << endl ;
    cout << " " << endl ;
    cout << "qb ******************************************* " << endl ;
    cout << "qb vector " << endl ;
    cout << qb_aux << endl ;
    cout << " " << endl ;
    cout << "qb(x,y) = (" << qb_aux[0] << " , " << qb_aux[1] << " )" << endl;


    //q0
    q0_aux = T0B * TBS * qs_aux;

    cout << " " << endl ;
    cout << " " << endl ;
    cout << "q0 ******************************************* " << endl ;
    cout << "q0 vector " << endl ;
    cout << q0_aux << endl ;
    cout << " " << endl ;
    cout << "q0(x,y) = (" << q0_aux[0] << " , " << q0_aux[1] << " )" << endl;
    cout << " " << endl ;
    cout << " " << endl ;

}
