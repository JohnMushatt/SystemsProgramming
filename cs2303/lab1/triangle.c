/*triangl.c -- John Mushatt */
#include <stdio.h>
#include <math.h>

int main() {
  float xA, yA, xB, yB, xC, yC;
  float lengthAB, lengthBC, lengthCA;
  float circumference, area, perimeter;

  printf("Enter the x- and y-coordinates of point A: ");
  scanf("%f %f",&xA,&yA );
  printf("Enter the x- and y-coordinates of point B: ");
  scanf("%f %f",&xB,&yB );
  printf("Enter the x- and y-coordinates of point C: ");
  scanf("%f %f",&xC,&yC );

  lengthAB = sqrt(pow((xA-xB),2) + pow((yA-yB),2));
  lengthBC = sqrt(pow((xB-xC),2) + pow((yB-yC),2));
  lengthCA = sqrt(pow((xC-xA),2) + pow((yC-yA),2));

  circumference = (lengthAB + lengthBC + lengthCA);
  perimeter = .5 * (lengthAB + lengthBC + lengthCA);
  area = sqrt(perimeter * (perimeter-lengthAB) * (perimeter-lengthBC) *
  (perimeter-lengthCA));
  printf("Length of AB is %.3f\nLength of BC is %.3f\nLength of CA is %.3f"
  "\nCircumference is %.3f\nArea is %.3f",lengthAB,lengthBC,lengthCA,circumference,area);
  return 0;
}
