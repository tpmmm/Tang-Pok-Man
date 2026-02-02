#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;

    bool operator<(const Point& p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
};

long long cross_product(Point O, Point A, Point B) {
    return (A.x - O.x) * 1LL * (B.y - O.y) - (A.y - O.y) * 1LL * (B.x - O.x);
}

vector<Point> convex_hull(vector<Point> A) {
    int n = A.size();
    if (n <= 1) return A;

    sort(A.begin(), A.end());
    vector<Point> hull;

    for (int i = 0; i < n; ++i) {
        while (hull.size() >= 2 &&
               cross_product(hull[hull.size()-2], hull.back(), A[i]) <= 0)
            hull.pop_back();
        hull.push_back(A[i]);
    }

    int lower_size = hull.size();
    for (int i = n-2; i >= 0; --i) {
        while (hull.size() > lower_size &&
               cross_product(hull[hull.size()-2], hull.back(), A[i]) <= 0)
            hull.pop_back();
        hull.push_back(A[i]);
    }

    hull.pop_back();      
    return hull;
}

int main() {
    int testCases;
    cin >> testCases;
    for (int test = 0; test < testCases; ++test) {
        int n;
        cin >> n;
        vector<Point> points(n);
        for (int i = 0; i < n; ++i)
            cin >> points[i].x >> points[i].y;

        vector<Point> hull = convex_hull(points);

        int start = 0;
        for (int i = 1; i < hull.size(); ++i) {
            if (hull[i].x < hull[start].x ||
               (hull[i].x == hull[start].x && hull[i].y < hull[start].y))
                start = i;
        }

        cout << hull.size() << '\n';
        for (int i = 0; i < hull.size(); ++i) {
            int idx = (start + i) % hull.size();
            cout << hull[idx].x << " " << hull[idx].y << '\n';
        }
    }
    return 0;
}