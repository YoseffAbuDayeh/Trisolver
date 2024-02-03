/*
* Name:			trisolver
* Description:	Solve all angles and lengths of a triangle.
* Author:		Yoseff Salim Abu Dayeh Portillo
* Date:			2023-01-13
*/
#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

char format[10];
char Type1[16];
char Type2[16];
float SA1, SA2, SA3;

void finalPrint(double side1, double side2, double side3, double angle1, double angle2, double angle3) {
    /*
    * Name:        Final Print
    * Objective:   Gets the perimeter, and area. Also outputs the data obtained
    * Parameters:  All the sides and angles of a triangle
    * Returns:     Nothing
    */
    if ((side1 < (side2 + side3) && side2 < (side1 + side3) && side3 < (side1 + side2)))
    {
        double Perimeter = side1 + side2 + side3; // Formula of the perimeter
        double semiPerimeter = Perimeter / 2;
        double Area = sqrt(semiPerimeter * (semiPerimeter - side1) * (semiPerimeter - side2) * (semiPerimeter - side3));
        // Calculates the area using heron's formula; to get the area one needs the semiperimeter.

        if (side1 == side2 && side2 == side3)
        {
            strcpy(Type1, "Equilateral");
        }
        else if (side1 == side2 || side1 == side3 || side2 == side3)
        {
            strcpy(Type1, "Isosceles");
        }
        else
        {
            strcpy(Type1, "Scalene");
        }

        if (angle1 == 90 || angle2 == 90 || angle3 == 90)
        {
            strcpy(Type2, "Right");
        }
        else if (angle1 > 90 || angle2 > 90 || angle3 > 90)
        {
            strcpy(Type2, "Obstuse");
        }
        else
        {
            strcpy(Type2, "Acute");
        } // Determines the Type of the triangle.
        printf("Format: %s\n", format);
        printf("a = %6.3lf\talpha = %8.3lf\n", side1, angle1);
        printf("b = %6.3lf\tbeta  = %8.3lf\n", side2, angle2);
        printf("c = %6.3lf\tgamma = %8.3lf\n", side3, angle3);
        printf("Perimeter = %7.3lf\n", Perimeter);
        printf("Area      = %7.3lf\n", Area);
        printf("Type      = %s, %s\n\n", Type1, Type2);
    } // Outputs all the information we now have
    else
        printf("ERROR: Impossible triangle\n\n");
}

void SSS(double Side1, double Side2, double Side3) {
    /*
    * Name:        SSS
    * Objective:   Calculate the triangles measures when given 3 sides
    * Parameters:  All three side lenghts of a triangle
    * Returns:     Nothing
    */

    double Side1Pow = pow(Side1, 2);
    double Side2Pow = pow(Side2, 2);
    double Side3Pow = pow(Side3, 2); 
    //Getting the powers in a different line so that the math is cleaner
    double Angle1 = acos((Side2Pow + Side3Pow - Side1Pow) / (2 * Side2 * Side3)) * 180 / M_PI;
    double Angle2 = acos((Side1Pow + Side3Pow - Side2Pow) / (2 * Side1 * Side3))*180/M_PI;
    double Angle3 = -1 * (Angle1 + Angle2 - 180);
    //Getting angles and then outputting the formula to a method that will do all the outputs.
    finalPrint(Side1, Side2, Side3, Angle1, Angle2, Angle3);
}

void SSA(double Side2, double Side3, double Angle1)
{
    /*
    * Name:             SSA
    * Purpose:          Get the missing side and two angles
    * Parameters:       Two sides and an angle of a triangle
    * Returns:          Nothing
    */
    double Angle1Rad = Angle1 * M_PI / 180.0;

    double ratio = Side2 / sin(Angle1Rad);
    double sin_b = Side3 / ratio;
    double Angle2 = asin(sin_b);
    Angle2 = Angle2 * 180 / M_PI;
    // Formula for getting the second angle having 2 sides and an angle. Had to put it in multiple lines since I got errors when putting it in the same line.
    double Angle3 = 180 - (Angle1 + Angle2);
    double Angle3Rad = Angle3 * M_PI / 180.0;
    double Side1 = sqrt(pow(Side3, 2) + pow(Side2, 2) - 2 * Side2 * Side3 * cos(Angle3 * M_PI / 180));
    //Using formulas to get the remaining information
    finalPrint(Side1, Side2, Side3, Angle3, Angle1, Angle2);
}

void ASA(double Angle1, double Side3, double Angle2)
{
     /*
    * Name:             ASA
    * Purpose:          Get the missing angle and two sides
    * Parameters:       Two angles and an a side of a triangle
    * Returns:          Nothing
    */
    double Angle1Rad = Angle1 * M_PI / 180.0;
    double Angle2Rad = Angle2 * M_PI / 180.0;
    double Angle3 = -1 * (Angle1 + Angle2 - 180);
    double Angle3Rad = Angle3 * M_PI / 180.0;
    double Side1, Side2;
    Side1 = (Side3 * sin(Angle1Rad))/ sin(Angle3Rad);
    Side2 = (Side3 * sin(Angle2Rad))/ sin(Angle3Rad);
    finalPrint(Side1, Side2, Side3, Angle1, Angle2, Angle3);
}

void SAS(double Side1, double Angle3, double Side2) {
    /*
    * Name:             SSA
    * Purpose:          Get the missing side and two angles
    * Parameters:       Two sides and an angle of a triangle
    * Returns:          Nothing
    */
    double Side3 = sqrt(pow(Side1, 2) + pow(Side2, 2) - 2 * Side1 * Side2 * cos(Angle3 * M_PI / 180));
    double Angle2Rad = acos((Side1 * Side1 + Side3 * Side3 - Side2 * Side2) / (2 * Side1 * Side3));
    double Angle2 = Angle2Rad * 180 / M_PI;
    double Angle1 = 180 - (Angle3 + Angle2);
    // Obtains the angles using the formulas then gives it to the method to get the last two things needed and produce an output
    finalPrint(Side1, Side2, Side3, Angle1, Angle2, Angle3);
}



int main() {
    printf("TriSolver 1.0.1 by: Yoseff Abu Dayeh\n");
    while (1) {
        while (1)
        {
            printf("\n-> ");
            rewind(stdin); // Buffer flush, we buffer after we get the inputs but just to make sure the buffer is empty.
            int validate = scanf("%s %f %f %f", format, &SA1, &SA2, &SA3); // Grabbing the inputs from the user
            
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
            {
                validate++;
            }
            for (int i = 0; i < 10; i++)
            {
                format[i] = toupper(format[i]);
            } // Makes whatever the user inputted an upper case letter
            if (strcmp(format, "QUIT") == 0 || strcmp(format, "END") == 0 || strcmp(format, "BYE") == 0 || strcmp(format, "EXIT") == 0)
            {
                return 1;
            } // If the user inputs quit, end, bye, or exit then the program will close.
            if (validate != 4)
            {
                printf("Bad command: Format # # #\nwhere Format = SSS|SAS|ASA|SSA\n\t# = a real number\n");
                continue;
            } // If the program gets more than 4 inputs (which it shouldn't get because of how I did it) then it'd throw out the error.

            if ((strcmp(format, "ASA") == 0 || strcmp(format, "SSS") == 0 || strcmp(format, "SAS") == 0 || strcmp(format, "SSA") == 0) == 0)
            {
                printf("Unknown command triangle format '%s'\n", format);
                continue;
            } // If the user picks a word that's not from the list it will tell the user that it is an unknown command.
            break;
        }
        if (SA1 < 0)
            SA1 *= -1;
        if (SA2 < 0)
            SA2 *= -1;
        if (SA3 < 0)
            SA3 *= -1;
        //Makes the number positives
        if (strcmp(format, "SSS") == 0)
        {
            SSS(SA1, SA2, SA3);
        }
        else if (strcmp(format, "SSA") == 0)
        {
            SSA(SA1, SA2, SA3);
        }
        else if (strcmp(format, "ASA") == 0)
        {
            ASA(SA1, SA2, SA3);
        }
        else if (strcmp(format, "SAS") == 0)
        {
            SAS(SA1, SA2, SA3);
        }
        //Call the method according to what the user asked.
    }
    return 1;
}