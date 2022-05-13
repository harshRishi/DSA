#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

double geometricSum(int k) {
    if(k == 0) {
        return 1;
    } else {
        double smallk = 1 / (pow(2, k)); // calculating last digit
        return geometricSum(k -1) + smallk; // calling recursion again with k-1 and so on while adding small k.
    }
    // Write your code here

}

int main()
{
  int k;
  cin >> k;
  cout << fixed << setprecision(5);
  cout << geometricSum(k) << endl;
}
