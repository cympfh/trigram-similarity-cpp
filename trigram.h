map<tuple<string, string, string>, double>
as_trigram_map(string);

double
similarity(
  map<tuple<string, string, string>, double>&,
  map<tuple<string, string, string>, double>&);
