#include <iostream>
#include <string>
#include <map>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <cassert>

using namespace std;

map<tuple<string, string, string>, double>
as_trigram_map(string s)
{
  // get words
  vector<string> words;
  stringstream sin(s);
  while (sin) {
    string w; sin >> w;
    words.push_back(w);
  }
  const int n = words.size();

  map<tuple<string, string, string>, double> dict;

  // cout-up
  for (int i = 0; i < n - 2; ++i) {
    auto tri = make_tuple(words[i], words[i+1], words[i+2]);
    if (dict[tri] > 0.0) {
      dict[tri] += 1.0;
    } else {
      dict[tri] = 1.0;
    }
  }

  // normalize
  {
    double Z = 0.0;
    for (auto&pr : dict) { Z += pr.second * pr.second; }
    Z = 1 / sqrt(Z);
    for (auto&pr : dict) { pr.second *= Z; }
  }

  return dict;
}

double
similarity(
  map<tuple<string, string, string>, double> &d,
  map<tuple<string, string, string>, double> &e) {
  double r = 0;
  for (auto&pr : d) { r += pr.second * e[pr.first]; }
  r = min(1.0, max(0.0, r));
  return r;
}
