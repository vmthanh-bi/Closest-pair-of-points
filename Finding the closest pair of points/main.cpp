#include <iostream>
#include <fstream>
#include <float.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
  
struct Point
{
    double x, y;
    Point() { x = 0; y = 0; }
    Point(double a,double b) { x = a; y = b; }
};
  
int sortX(const void* a, const void* b)
{
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    return (p1->x - p2->x);
}

int sortY(const void* a, const void* b)
{
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    return (p1->y - p2->y);
}
  
float dist(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) +(p1.y - p2.y)*(p1.y - p2.y));
}
  
float bruteForce(Point P[], int n)
{
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
    return min;
}
  
float findMin(float x, float y)
{
    return (x < y)? x : y;
}
  
float recursive(Point Px[], Point Py[], int n)
{
    // Check whether |P| <= 3, if so, use brute force method.
    if (n <= 3)
        return bruteForce(Px, n);

    // Find the middle point that bisects the point set P.
    int pL = n/2;
    int pR = n - pL;
    Point l = Px[pL]; //Vertical line l
    
    // Divide array X into arrays xL and xR.
    Point xL[pL];
    Point xR[n-pL];
    int xLi = 0, xRi = 0;
    for (int i = 0; i < n; i++)
    {
      if (Px[i].x <= l.x && xLi<pL)
          xL[xLi++] = Px[i];
      else
          xR[xRi++] = Px[i];
    }
    
    // Divide array Y into arrays yL and yR.
    Point yL[pL];
    Point yR[pR];
    int yLi = 0, yRi = 0;
    for (int i = 0; i < n; i++)
    {
      if (Py[i].x <= l.x && yLi<pL)
          yL[yLi++] = Py[i];
      else
          yR[yRi++] = Py[i];
    }
    
    // Make each side of the set P conquer itself and find the closest pair of points, respectively.
    float dl = recursive(xL, yL, pL);
    float dr = recursive(xR, yR, pR);
  
    // Determine the smaller distance.
    float d = findMin(dl, dr);
  
    // Check if there is a pair with one point on each side of the set with a distance less than d.
    Point yPrime[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(Py[i].x - l.x) < d)
            yPrime[j] = Py[i];
            j++;

    // Determine the closest pair.
    float min = d;
    for (int a = 0; a < j; ++a)
        for (int b = a+1; b < j && (yPrime[b].y - yPrime[a].y) < min; ++b)
            if (dist(yPrime[a],yPrime[b]) < min)
                min = dist(yPrime[a], yPrime[b]);
  
    return min; // return distance of the closest pair
}
  
// Sorting the points before the first recursive call
float presort(Point P[], int n)
{
    Point Px[n];
    Point Py[n];
    for (int i = 0; i < n; i++)
    {
        Px[i] = P[i];
        Py[i] = P[i];
    }
  
    qsort(Px, n, sizeof(Point), sortX);
    qsort(Py, n, sizeof(Point), sortY);
  
    return recursive(Px, Py, n);
}
  
// Driver program to test above functions
int main()
{
    int n = 10000;
    Point *P = new Point[n];
    std::ifstream in;
    in.open("points.txt");
    double x,y;
    int i;
    while(in >> x >> y) {
      P[i] = Point(x,y);
      i++;
    }
    cout << "The closest pair of points in the set is " << presort(P, n);
    return 0;
}
