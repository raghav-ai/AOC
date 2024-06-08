#include <iostream>
#include <istream>
#include <string>

using namespace std;

int main() {
  istream &in = cin;
  string s = "";
  long sum = 0;
  while (getline(in, s)) {
    int left = 0;
    int right = s.length() - 1;
    int val = -1;
    bool f1 = false;
    bool f2 = false;
    while (left <= right) {
      if (!f1 && s[left] >= 48 && s[left] <= 57) {
        if (val == -1) {
          val = 10 * ((int)(s[left]) - 48);
        } else {
          val += 10 * ((int)(s[left]) - 48);
        }
        f1 = true;
      }
      if (!f2 && s[right] >= 48 && s[right] <= 57) {
        if (val == -1) {
          val = ((int)(s[right]) - 48);
        } else {
          val += ((int)(s[right]) - 48);
        }
        f2 = true;
      }
      if (f1 && f2) {
        sum += val;
        break;
      } else if (f1) {
        right--;
      } else if (f2) {
        left++;
      } else {
        left++;
        right--;
      }
    }
  }

  cout << sum << endl;
  return 0;
}
