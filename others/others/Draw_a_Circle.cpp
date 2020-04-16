/*
Problem Description
There are N points in a plane, each with a two-dimensional coordinate.We want to draw a circle which has at least two points within or on its border.You are asked to calculate the minimum radius of this circle.

Attention
This problem will not be countted into the total score of this course.

Input
The first line is an integer N, denoting the number of points. Following are N lines. Each contains a pair of real number (x, y), denoting the coordinate of a point.|x|<=10^9,|y|<=10^9.
30% of the test cases guarantee that N <= 1000.
All test cases guarantee that N <= 200000.

Output
Output only a real number rounding to 3 decimals after decimal point, denoting the minimum radius.

Sample Input
5
0.0 0.0
0.5 0.5
1.0 1.0
0.0 1.0
1.0 0.0
Sample Output
0.354
*/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

struct Point{
    double x;
    double y;
    Point(double tx, double ty):x(tx),y(ty){};
    bool operator <(const Point& p) const
    {
        return x < p.x;
    }
    bool operator >(const Point& p) const
    {
        return y < p.y;
    }
};

double get_distance(Point a, Point b) {
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

void print_vector(std::vector<Point> points) {
    for (std::vector<Point>::iterator iter = points.begin(); iter != points.end(); iter++) {
        printf("%f %f\n", iter->x, iter->y);
    }
}

double min_distance(std::vector<Point> points){
    int len = points.size();
    if (len == 2)
        return get_distance(points.at(0), points.at(1));
    else if (len == 3)
        return std::min(std::min(get_distance(points.at(0), points.at(1)),
                                 get_distance(points.at(0), points.at(2))),
                        get_distance(points.at(1), points.at(2)));
    else {
        int mid = len/2;
        // initialize the vector, containing only the first element without the last element
        std::vector<Point> left(points.begin(), points.begin() + mid);
        std::vector<Point> right(points.begin() + mid, points.end());
        double d = std::min(min_distance(left), min_distance(right));
        std::vector<Point> center;
        for (std::vector<Point>::iterator iter = points.begin(); iter != points.end(); iter++) {
            if (fabs(points.at(mid).x - iter->x) < d) {
                center.push_back(*iter);
            }
        }
        // sort by y value
        std::sort(center.begin(), center.end(), std::greater<Point>());
        int i=0, j=0, temp=0;
        for (;i < center.size(); i++) {
            temp = i + 12 > center.size()?center.size():i+12;
            for (j = i + 1;j < temp; j++) {
                d = std::min(d, get_distance(center.at(i), center.at(j)));
            }
        }
        return d;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    std::vector<Point> points;
    double x=0.0, y=0.0;
    int i = 0;
    for (; i < n; i++){
        scanf("%lf %lf", &x, &y);
        points.push_back(Point(x,y));
    }
    // sort by x value
    std::sort(points.begin(), points.end(), std::less<Point>());

    printf("%.3f\n", min_distance(points)/2.0);
    return 0;
}
