#include <iostream>
#include <chrono>
using namespace std;
using namespace std ::chrono;

void a(int n);
void b(int n);
void f(int n); // void c(int n);
void d(int n);

//  g++ -o Program7 Program7.cpp&Program7.exe

int main()
{
   
    int N, M;
    cout << "Enter the smaller number: ";
    cin >> N;
    cout << "Enter the larger number: ";
    cin >> M;

    
    auto start = high_resolution_clock::now();
    a(N);
    auto end = high_resolution_clock::now();
    cout << "Time taken for code 1 : " << duration_cast<microseconds>(end - start).count() << " microsecond" << endl;

    // start = high_resolution_clock::now();
    // b(N);
    // end = high_resolution_clock::now();
    // cout << "Time taken for code 2 : " << duration_cast<microseconds>(end - start).count() << " microsecond" << endl;

    start = high_resolution_clock::now();
    f(N);
    end = high_resolution_clock::now();
    cout << "Time taken for code 3 : " << duration_cast<microseconds>(end - start).count() << " microsecond" << endl;

    start = high_resolution_clock::now();
    d(N);
    end = high_resolution_clock::now();
    cout << "Time taken for code 4 : " << duration_cast<microseconds>(end - start).count() << " microsecond" << endl;

    cout << endl
         << "For Input Size : " << M << endl;

    start = high_resolution_clock::now();
    a(M);
    end = high_resolution_clock::now();
    cout << "Time taken for code 1 : " << duration_cast<microseconds>(end - start).count() << " microsecond" << endl;

    //start = high_resolution_clock::now();
    //b(M);
    //end = high_resolution_clock::now();
    //cout << "Time taken for code 2 : " << duration_cast<microseconds>(end - start).count() << " microsecond" << endl;

    start = high_resolution_clock::now();
    f(M);
    end = high_resolution_clock::now();
    cout << "Time taken for code 3 : " << duration_cast<microseconds>(end - start).count() << " microsecond" << endl;

    start = high_resolution_clock::now();
    d(M);
    end = high_resolution_clock::now();
    cout << "Time taken for code 4 : " << duration_cast<microseconds>(end - start).count() << " microsecond" << endl;

    return 0;
}

void a(int n)
{
    int x = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            x = x + 1;
        }
    }
    // cout << "A.x : " << x << endl;
}

void b(int n)
{
    int x = 0;
    int j = n;
    while (j >= 1)
    {
        for (int i = 1; i <= j; i++)
        {
            x = x + 1;
        }
        j = n / 2;
    }
    // cout << "B.x : " << x;
}

void f(int n)
{
    int x = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            for (int k = 1; k <= i; k++)
            {
                x = x + 1;
            }
        }
    }
    // cout << "C.x : " << x;
}

void d(int n)
{
    int x = 0;
    int i = n;
    while (i >= 1)
    {
        for (int j = 1; j <= n; j++)
        {
            x = x + 1;
            i = i / 2;
        }
    }
    // cout << "D.x : " << x;
}
