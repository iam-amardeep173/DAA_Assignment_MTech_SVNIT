#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

long long generate_power(int bits)
{
    long long n = 0;
    int msb = bits - 1;
    for(long long i = 0; i < bits; ++i)
    {
        if(i == msb)
          n |= 1 << i;
        else
          n |= (rand() % 2)<< i;
       // cout<< n << endl;
    }
    return n;
}

// Binary Exponentiation
long long binaryExponentiation(long long a, long long n) {
    long long result = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            result *= a;
        }
        a *= a;
        n /= 2;
    }
    return result;
}

// Square-and-Multiply Exponentiation
long long squareAndMultiply(long long a, long long n) {
    long long result = 1;
    long long base = a;
    while (n > 0) {
        if (n % 2 == 1) {
            result *= base;
        }
        base *= base;
        n /= 2;
    }
    return result;
}

// Conventional Exponentiation
long long conventionalExponentiation(long long a, long long n) {
    long long result = 1;
    for (long long i = 0; i < n; i++) {
        result *= a;
    }
    return result;
}



int main() {
   
   /* long long a, n;
    cout << "Enter the smaller number: ";  //a=2
    cin >>a;
    cout << "Enter the larger number: ";   //n =5
    cin >> n; */
    long long a,bits;
    cout<<"Enter the a(base) value and bits length of power value : "<<endl;
    cin>>a>>bits;
    
    if (bits<1 || bits>31)
    {
        cout<<"Bits length should be between 1-31 : "<<endl;
    }

    srand((time(nullptr)));
    long long n = generate_power(bits); 
    cout<<"The random value generate is : ";
    cout<< n << endl;
    
    high_resolution_clock::time_point start_time, end_time;
    
    // Binary Exponentiation
    start_time = high_resolution_clock::now();
    long long result1 = binaryExponentiation(a, n);
    end_time = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(end_time - start_time);
    
    cout << "Binary_Exponentiation Result: " << result1 << endl;
    cout << "Binary_Exponentiation Time: " << duration1.count() << " microseconds" << endl;
    
    // Conventional Exponentiation
    start_time = high_resolution_clock::now();
    long long result2 = conventionalExponentiation(a, n);
    end_time = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(end_time - start_time);
    
    cout << "Conventional Exponentiation Result: " << result2 << endl;
    cout << "Conventional Exponentiation Time: " << duration2.count() << " microseconds" << endl;
    
    // Square-and-Multiply Exponentiation
    start_time = high_resolution_clock::now();
    long long result3 = squareAndMultiply(a, n);
    end_time = high_resolution_clock::now();
    auto duration3 = duration_cast<microseconds>(end_time - start_time);
    
    cout << "Square-and-Multiply Result: " << result3 << endl;
    cout << "Square-and-Multiply Time: " << duration3.count() << " microseconds" << endl;

    return 0;
}
