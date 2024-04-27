#include <bits/stdc++.h>

using namespace std;
int a,b,c;
int main()
{
    cin >> a >> b >> c;
    int max1 = max(a,b);
    int max2 = max(max1,c);
    cout << max2;
}