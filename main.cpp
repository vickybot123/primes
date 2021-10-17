#include <iostream>
#include <cmath>

using namespace std;

const int maxValue = 1001;
int primes[maxValue];

bool isPrime(int x)
{
    if (x<2)
        return false;

    if(x%2==0)
        return false;

    int cached = primes[x];
    if (cached == 1)
        return true;

    if (cached == 2)
        return false;

    double xs = sqrt(x);
    for(int i=2; i<=xs; i++)
        if (x%i == 0)
        {
            primes[x] = 2;
            return false;
        }

    primes[x] = 1;
    return true;
}

void printPrimesLt(int m)
{
    for(int k=2; k<=m; k++)
        if(isPrime(k))
            cout <<k << ' ' ;
}

int main()
{
    int x;
    char answer;
    do
    {
        answer = 'n';
        cout << "input x: " ;
        cin >> x;
        if (x >= maxValue)
        {
            cout << x << " >= " << maxValue << ", plz input another!!" << endl;
            answer = 'y';
            continue;
        }

        printPrimesLt(x);
        cout << endl << "Do you want to continue? (y/N): ";
        cin >> answer;
        if (answer == 'd')
        {
            for (int i=0; i<maxValue; i++)
                cout << primes[i] << " " ;
            cout << endl;
        }
    }
    while (answer == 'y');
    return 0;
}
