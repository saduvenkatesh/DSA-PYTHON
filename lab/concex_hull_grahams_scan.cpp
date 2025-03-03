#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;
};

// A global reference point used for sorting
Point p0;

// Function to find the orientation of ordered triplet (p, q, r)
// Returns:
//  0 -> Collinear
//  1 -> Counterclockwise (left turn)
//  2 -> Clockwise (right turn)
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;  // Collinear
    return (val > 0) ? 2 : 1; // Clockwise or Counterclockwise
}

// A comparator function to sort points based on polar angle with p0
bool compare(Point p1, Point p2) {
    int orient = orientation(p0, p1, p2);
    if (orient == 0)
        return (p1.x < p2.x); // If collinear, pick closer point
    return (orient == 2);
}

// Function to find convex hull using Graham's Scan Algorithm
vector<Point> convexHull(vector<Point> &points) {
    int n = points.size();
    if (n < 3) {
        cout << "Convex hull is not possible\n";
        return {};
    }

    // Step 1: Find the point with the lowest y-coordinate (or leftmost if tie)
    int minY = 0;
    for (int i = 1; i < n; i++)
        if (points[i].y < points[minY].y || (points[i].y == points[minY].y && points[i].x < points[minY].x))
            minY = i;

    // Place the lowest point at the beginning
    swap(points[0], points[minY]);
    p0 = points[0];

    // Step 2: Sort the remaining points by polar angle with p0
    sort(points.begin() + 1, points.end(), compare);

    // Step 3: Build the convex hull using a stack
    stack<Point> hull;
    hull.push(points[0]);
    hull.push(points[1]);
    hull.push(points[2]);

    for (int i = 3; i < n; i++) {
        while (hull.size() > 1) {
            Point second = hull.top();
            hull.pop();
            Point first = hull.top();
            if (orientation(first, second, points[i]) != 2) continue; // Remove right turns
            hull.push(second);
            break;
        }
        hull.push(points[i]);
    }

    // Collect results into a vector
    vector<Point> result;
    while (!hull.empty()) {
        result.push_back(hull.top());
        hull.pop();
    }
    return result;
}

// Function to display points
void printHull(vector<Point> &hull) {
    cout << "Convex Hull Points:\n";
    for (auto &p : hull)
        cout << "(" << p.x << ", " << p.y << ")\n";
}

int main() {
    int n;
    cout << "Enter number of points: ";
    cin >> n;

    vector<Point> points(n);
    cout << "Enter points (x y):\n";
    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;

    vector<Point> hull = convexHull(points);

    if (!hull.empty())
        printHull(hull);

    return 0;
}


/*
       Find the lowest point (or leftmost if there's a tie). This will be the starting point of the convex hull.

       Sort all other points based on their polar angle with respect to the starting point. If two points have the same angle, keep the closer one first.
       
       Initialize the convex hull with the first three sorted points.
       
       Iterate through the remaining points and check the orientation (left turn or right turn):
       
       If a right turn (or collinear in some cases) is found, remove the last added point from the hull.
       Otherwise, add the current point to the hull.
       After processing all points, the remaining points in the stack form the convex hull.
*/