#include <bits/stdc++.h>
using namespace std;
#include "./trigram.h"

void eq_test(double r, double e, string comment) {
  const double eps = 1e-6;
  if (abs(r - e) > eps) {
    cerr << "assert error: " << comment << endl;
    cerr << "( " << r << " , " << e << " )" << endl;
  }
}

int main() {

  vector< map<tuple<string, string, string>, double> > t(3);
  t[0] = as_trigram_map(
      string("I can continue viewing the video of Ema chan's angel taiso"));
  t[1] = as_trigram_map(
      string("I can continue viewing the video of Ema's angel taiso"));
  t[2] = as_trigram_map(
      string("I can continue viewing the video of the angel taiso"));

  for (int i = 0; i < 3; ++i) {
    eq_test(similarity(t[i], t[i]), 1.0, "reflexive");
  }

  for (int i = 0; i < 3; ++i) {
    for (int j = i + 1; j < 3; ++j) {
      eq_test(
          similarity(t[i], t[j]),
          similarity(t[j], t[i]), "symmetric");
    }
  }

  return 0;
}
