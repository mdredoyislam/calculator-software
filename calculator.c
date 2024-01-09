#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int choice;
    displayMainMenu();
    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                calculateAge();
                break;
            case 2:
                calculateArea();
                break;
            case 3:
                solveEquation();
                break;
            case 4:
                printf("Thanks for using the calculator!\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a number between 1 and 7.\n");
        }
    } while (1);

    return 0;
}
// Function to display the main menu
void displayMainMenu() {
    printf("\nMain Menu\n\n");
    printf("Press 1 for calculate Age \n");
    printf("Press 2 for calculate Area \n");
    printf("Press 3 for Solve Equation \n");
    printf("Press 4 for Exit\n\n");
}
// Function to calculate age
void calculateAge(){

    int birthDay, birthMonth, birthYear;
    int presentDay, presentMonth, presentYear;

    // Ask the user for birth date
    printf("Enter your birth date in the form of DD/MM/YYYY: ");
    scanf("%d/%d/%d", &birthDay, &birthMonth, &birthYear);

    // Ask the user for present date
    printf("Enter the present date in the form of DD/MM/YYYY: ");
    scanf("%d/%d/%d", &presentDay, &presentMonth, &presentYear);

    // Calculate age
    int ageYears, ageMonths, ageDays;

    // Calculate years
    ageYears = presentYear - birthYear;

    // Adjust age if birthday hasn't occurred yet this year
    if (presentMonth < birthMonth || (presentMonth == birthMonth && presentDay < birthDay)) {
        ageYears--;
    }

    // Calculate months and days
    if (presentMonth < birthMonth) {
        ageMonths = 12 - birthMonth + presentMonth - 1;
    } else {
        ageMonths = presentMonth - birthMonth;
    }

    if (presentDay < birthDay) {
        int daysInPreviousMonth;
        if (presentMonth == 1) {
            daysInPreviousMonth = 31; // Assuming January always has 31 days
        } else {
            // You can add more accurate days in other months
            daysInPreviousMonth = 30; // Example value
        }
        ageDays = daysInPreviousMonth - birthDay + presentDay;
    } else {
        ageDays = presentDay - birthDay;
    }

    // Print the age
    printf("Your age is: %d years, %d months, and %d days\n", ageYears, ageMonths, ageDays);

}

// Function to calculate area for a triangle
float calculateTriangleArea(int a, int b, int c) {
    // Heron's formula to calculate area of a triangle
    float s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// Function to calculate area for a rectangle
float calculateRectangleArea(int a, int b) {
    return a * b;
}

// Function to calculate area for a trapezium
float calculateTrapeziumArea(int a, int b, int c, int d) {
    return 0.5 * (a + b) * sqrt(c * c - pow((pow((b - a), 2) + c * c - d * d) / (2 * (b - a)), 2));
}

// Function to calculate area for a circle
float calculateCircleArea(int r) {
    return M_PI * r * r;
}

// Function to handle Area Calculator Menu
void calculateArea() {
    int areaChoice;
    do {
        printf("\nArea Calculator Menu\n\n");
        printf("Press 1 for Triangle\n");
        printf("Press 2 for Rectangle\n");
        printf("Press 3 for Trapezium\n");
        printf("Press 4 for Circle\n");
        printf("Press 5 for Return Main Menu \n\n");
        printf("Enter your choice: ");
        scanf("%d", &areaChoice);

        switch (areaChoice) {
            case 1:
                // Triangle
                {
                    int side1, side2, side3;
                    printf("Enter the lengths of three sides of the triangle: ");
                    scanf("%d %d %d", &side1, &side2, &side3);

                    if (side1 + side2 > side3 && side2 + side3 > side1 && side3 + side1 > side2) {
                        float area = calculateTriangleArea(side1, side2, side3);
                        printf("Area of the triangle: %.2f\n", area);
                    } else {
                        printf("Invalid triangle. Please enter valid side lengths.\n");
                    }
                }
                break;

            case 2:
                // Rectangle
                {
                    int length, width;
                    printf("Enter the lengths of two sides of the rectangle: ");
                    scanf("%d %d", &length, &width);

                    if (length > 0 && width > 0) {
                        float area = calculateRectangleArea(length, width);
                        printf("Area of the rectangle: %.2f\n", area);
                    } else {
                        printf("Invalid rectangle. Please enter valid side lengths.\n");
                    }
                }
                break;

            case 3:
                // Trapezium
                {
                    int side1, side2, side3, side4;
                    printf("Enter the lengths of four sides of the trapezium: ");
                    scanf("%d %d %d %d", &side1, &side2, &side3, &side4);

                    if (side1 > 0 && side2 > 0 && side3 > 0 && side4 > 0) {
                        float area = calculateTrapeziumArea(side1, side2, side3, side4);
                        printf("Area of the trapezium: %.2f\n", area);
                    } else {
                        printf("Invalid trapezium. Please enter valid side lengths.\n");
                    }
                }
                break;

            case 4:
                // Circle
                {
                    int radius;
                    printf("Enter the radius of the circle: ");
                    scanf("%d", &radius);

                    if (radius > 0) {
                        float area = calculateCircleArea(radius);
                        printf("Area of the circle: %.2f\n", area);
                    } else {
                        printf("Invalid circle. Please enter a valid radius.\n");
                    }
                }
                break;

            case 5:
                displayMainMenu();
                break;

            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (1);
}

// Function to solve a system of linear equations (simple)
void solveLinearEquations() {
    int a, b, c, d, e, f;

    // Input coefficients
    printf("Enter the coefficients of the linear equations (ax + by = c, dx + ey = f):\n");
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

    // Check if there is a unique solution
    if ((a * e - b * d) == 0) {
        printf("The system of equations does not have a unique solution.\n");
    } else {
        // Calculate values of x and y
        double x = (c * e - b * f) / (a * e - b * d);
        double y = (a * f - c * d) / (a * e - b * d);

        // Print the solution
        printf("One valid solution is: x = %.2f, y = %.2f\n", x, y);
    }
}

// Function to solve a quadratic equation (complex)
void solveQuadraticEquation() {
    int a, b, c;

    // Input coefficients
    printf("Enter the coefficients of the quadratic equation (ax^2 + bx + c = 0):\n");
    scanf("%d %d %d", &a, &b, &c);

    // Calculate the discriminant
    double discriminant = b * b - 4 * a * c;

    // Check if the roots are real or complex
    if (discriminant >= 0) {
        // Real roots
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);

        // Print the roots
        printf("Real roots are: x1 = %.2f, x2 = %.2f\n", root1, root2);
    } else {
        // Complex roots
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-discriminant) / (2 * a);

        // Print the roots
        printf("Complex roots are: x1 = %.2f + %.2fi, x2 = %.2f - %.2fi\n", realPart, imaginaryPart, realPart, imaginaryPart);
    }
}

// Function to handle Equation Solving Menu
void solveEquation() {
    int equationChoice;

    do {
        printf("\nEquation Solving Menu\n\n");
        printf("Press 1 for Simple Equation\n");
        printf("Press 2 for Complex Equation\n");
        printf("Press 3 for Returning to the Main Menu\n\n");
        printf("Enter your choice: ");
        scanf("%d", &equationChoice);

        switch (equationChoice) {
            case 1:
                // Simple Equation
                solveLinearEquations();
                break;

            case 2:
                // Complex Equation
                solveQuadraticEquation();
                break;

            case 3:
                displayMainMenu();
                break;

            default:
                printf("Invalid choice. Please enter a number between 1 and 3.\n");
        }
    } while (1);
}
