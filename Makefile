大体ただしそうな、tri-gram とそれ同士の cosine 類似度

```cpp
map<tuple<string, string, string>, double>
as_trigram_map(string);

double
similarity(
  map<tuple<string, string, string>, double>&,
  map<tuple<string, string, string>, double>&);
```

