# 부동소수점 출력 방법

## C

    #include <iostream>
    using namespace std;

    int main()
    {
        double pi = 3.141592653589793;
        cout << fixed;
        cout.precision(2);
        cout << pi << "\n";
        cout.precision(9);
        cout << pi << "\n";
        cout.precision(15);
        cout << pi << "\n";
    }

## C++

    #include <stdio.h>

    int main()
    {
        double pi = 3.141592653589793;
        printf("%.2lf\n",pi);
        printf("%.9lf\n",pi);
        printf("%.15lf\n",pi);
    }

## Java

    import java.io.*;
    import java.util.*;

    public class 부동소수점출력 {
        public static void main(String[] args) {
            double pi = 3.141592653589793;
            System.out.println(String.format("%.2f",pi));
            System.out.println(String.format("%.9f",pi));
            System.out.println(String.format("%.15f",pi));
        }
    }