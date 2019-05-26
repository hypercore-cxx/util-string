# SYNOPSIS
Functional string helpers.


# USAGE
This module is designed to work with the [`datcxx`][0] build tool. To add this
module to your project us the following command...

```bash
build add datcxx/util-string
```


# TEST

```bash
build test
```


# STRING

### SEARCH
Search a string for regular expression matches, returns a `vector<string>`.

```c++
std::string f = "/test/parallel/test-path.js";
std::vector<string> r = search(f, "\\w+");
// r.size() == 5
```

### MATCH
Same as search but return a [cmatch][1] starting with the complete input at
index `0`. This will potentially be depricated.

```c++
std::string f = "/test/parallel/test-path.js";
cmatch r = match(f, "/(\\w+)/(.*)");
// r.size() == 3
```

### SPLIT
Split on a regular expression.

```c++
std::string f = "/test/parallel/test-path.js";
vector<string> r = split(f, "/");
//  r.size() == 4
```

### TEST
Test if a string is an exact match.

```c++
std::string f = "/test/parallel/test-path.js";
bool r = test(f, "^/(\\w+)/(\\w+)/(\\w+)-path.js$");
// r == true
```

### TRIM, RTRIM, LTRIM

```c++
string r = trim("/foobar//", "/");
// r.trim() == "foobar"

string r = rtrim("!Hello, World!!", "!");
// r == "!Hello, World"

string r = ltrim("!Hello, World!!", "!");
// r == "Hello, World!!"
```

### REPLACE

```c++
string r = replace("Hello, World!", "o", "x");
// r == "Hellx, Wxrld!"
``` 

```c++
const string s = "Hello, World!";

string r = replace(s, "l", [&](string const& m, int index) {
  return string("L" + to_string(index));
});

// r == "HeL0L1o, WorL2d!"
```

[0]:https://github.com/datcxx/build
[1]:https://en.cppreference.com/w/cpp/regex/match_results
