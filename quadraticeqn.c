//program to find the roots of a quadratic equation
#include <stdio.h>
#include <math.h>
void main()
{
    float a,b,c,discriminant;
    double root1,root2;
    printf("Enter the value of the three coefficents of a quadratic equation a, b and c -\n ");
    scanf ("%f %f %f",&a,&b,&c);
    discriminant = b*b - 4*a*c;
    if(discriminant < 0)
    printf("\n\nROOTS ARE IMAGINARY\n");
    else 
    {
    root1 = (double)((-b + sqrt(discriminant))/(2.0*a));
    root2 = (double)((-b - sqrt(discriminant))/(2.0*a));
    printf("The first root: %f \n",root1);
    printf("The second root: %f ", root2);
   }
}