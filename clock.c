#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//Function prototypes
int seconds_x(int s);
int seconds_y(int s);
int minutes_x(int m, int s);
int minutes_y(int m, int s);
int hours_x(int h, int m);
int hours_y(int h, int m);

//Radius of the clock
int r = 90;

//Value of pi
const double PI = 3.14;

int main(void) {
    //Get time from user
    int hour, min, sec;
    printf("Enter time (HH MM SS): ");
    scanf("%i %i %i", &hour, &min, &sec);

    //Create a clock SVG file
    FILE *clock = fopen("clock.svg", "w");

    //Write SVG to file and use calculated coordinates for hands"
    fprintf(clock, "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"200\" height=\"200\" viewBox=\"-100 -100 200 200\"> <circle cx=\"0\" cy=\"0\" r=\"94\" fill=\"maroon\"/> <circle cx=\"0\" cy=\"0\" r=\"90\" fill=\"transparent\" stroke=\"black\" stroke-width=\"7\" stroke-dasharray=\"0.2 0.8\" stroke-dashoffset=\"0.1\" pathLength=\"60\"/> <circle cx=\"0\" cy=\"0\" r=\"50 \" fill=\"transparent\" stroke=\"orange\" stroke-width=\"4\" stroke-dasharray=\"0.2 0.8\" stroke-dashoffset=\"0.1\" pathLength=\"60\"/> //dial <circle cx=\"0\" cy=\"0\" r=\"90\" fill=\"transparent\" stroke=\"orange\" stroke-width=\"7\" stroke-dasharray=\"0.2 4.8\" stroke-dashoffset=\"0.1\" pathLength=\"60\"/> //hour hand <line x1=\"0\" y1=\"0\" x2=\"%i\" y2=\"%i\" stroke=\"black \" stroke-width=\"5\" stroke-linecap=\"round\"/> //minute hand <line x1=\"0\" y1=\"0\" x2=\"%i\" y2=\"%i\" stroke=\"black\" stroke-width=\"5\" stroke-linecap=\"round\"/> //seconds hand <line x1=\"0\" y1=\"0\" x2=\"%i\" y2=\"%i\" stroke=\"orange\" stroke-width=\"2\" stroke-linecap=\"round\"/> </svg>",  hours_x(hour, min), hours_y(hour, min), minutes_x(min, sec), minutes_y(min, sec), seconds_x(sec), seconds_y(sec));
    fclose(clock);

}

//Calculate x coordinates for seconds hand
int seconds_x(int s) {
    double deg = (s * 6);
    double rad = deg * (PI/180);
    double x = sin(rad) * r;
    return x;
}

//Calculate y coordinates for seconds hand
int seconds_y(int s) {
    double deg = (s * 6);
    double rad = deg * (PI/180);
    double y = cos(rad) * r;
    return -y;
}

//Calculate x coordinates for minutes hand
int minutes_x(int m, int s) {
    double deg;
    if (s >= 30)
        deg = (m * 6) + 3;
    else
        deg = (m * 6);
    double rad = deg * (PI/180);
    double x = sin(rad) * r;
    return x;
}

//Calculate y coordinates for minutes hand
int minutes_y(int m, int s) {
    double deg;
    if (s >= 30)
        deg = (m * 6) + 3;
    else
        deg = (m * 6);
    double rad = deg * (PI/180);
    double y = cos(rad) * r;
    return -y;
}

//Calculate x coordinates for hours hand
int hours_x(int h, int m) {
    double deg;
    if (m >= 30)
        deg = (h * 30) + 15;
    else
        deg = (h * 30);
    double rad = deg * (PI/180);
    double x = sin(rad) * r/2;
    return x;
}

//Calculate y coordinates for hours hand
int hours_y(int h, int m) {
    double deg;
    if (m >= 30)
        deg = (h * 30) + 15;
    else
        deg = (h * 30);
    double rad = deg * (PI/180);
    double y = cos(rad) * r/2;
    return -y;
}
