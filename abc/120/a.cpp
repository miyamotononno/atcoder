#include <iostream>
using namespace std;

int main()
{
  int a, b, c;
  cin >> a >> b >> c;
  int d = b / a;
  if (d > c)
  {
    cout << c << endl;
  }
  else
  {
    cout << d << endl;
  }
}
