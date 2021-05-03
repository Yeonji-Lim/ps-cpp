/* 2021.5.3 Solved - 1240KB 0ms */
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<double, double>> d;
pair<double, double> min_v, kang_v, del, delt;

double f(double t) {
    return sqrt( pow(del.first+delt.first*t,2) + pow(del.second+delt.second*t, 2) );
}

pair<double, double> diff (pair<double, double> a, pair<double, double> b) {
    pair<double, double> ret;
    ret.first = b.first - a.first;
    ret.second = b.second - a.second;
    return ret;
}

pair<double, double> add (pair<double, double> a, pair<double, double> b) {
    pair<double, double> ret;
    ret.first = a.first + b.first;
    ret.second = a.second + b.second;
    return ret;
}

int main() {
    double t, s;
    for(int i = 0; i < 4; i++) {
        scanf("%lf %lf", &t, &s);
        d.emplace_back(t, s);
    }
    min_v = diff(d[0],d[1]);
    kang_v = diff(d[2], d[3]);
    del = diff(d[0], d[2]);
    delt = diff(min_v, kang_v);
    if(delt.first == 0 && delt.second == 0) {
        printf("%.10lf", f(0));
        return 0;
    }
    t = -1 * (del.first * delt.first + del.second * delt.second) / (pow(delt.first, 2) + pow(delt.second, 2));
    if(0.0 <= t && t <= 1.0)
        printf("%.10lf", f(t));
    else if(t < 0.0)
        printf("%.10lf", f(0));
    else
        printf("%.10lf", f(1));
    return 0;
}