# SYNOPSIS
Functions that make dealing with typical string operations easier.


# USAGE
This module is designed to work with the [`datcxx`][0] build tool. To add this
module to your project us the following command...

```bash
build add heapwolf/cxx-tap
```


# TEST

```bash
build test
```


# FUNCTIONS

```c++
string f = "/test/parallel/test-path.js";
```

### SEARCH
Search a string for regular expression matches, returns a `vector<string>`.

```c++
vector<string> r = Util::String::search(f, "\\w+");
// r.size() == 5
```

### SPLIT
Split on a regular expression.

```c++
vector<string> r = Util::String::split(f, "/");
//  r.size() == 4
```

### MATCH
If not empty, returns an array of matches starting with the complete input
at index `0`.

```c++
cmatch r = Util::String::match(f, "/(\\w+)/(.*)");
// r.size() == 3
```

### TEST
Test if a string is an exact match.

```c++
bool r = Util::String::test(f, "^/(\\w+)/(\\w+)/(\\w+)-path.js$");
// r == true
```

### TRIM, RTRIM, LTRIM

```c++
string r = Util::String::trim("/foobar//", "/");
// r.trim() == "foobar"

string r = Util::String::rtrim("!Hello, World!!", "!");
// r == "!Hello, World"

string r = Util::String::ltrim("!Hello, World!!", "!");
// r == "Hello, World!!"
```

### REPLACE

```c++
string r = Util::String::replace("Hello, World!", "o", "x");
// r == "Hellx, Wxrld!"
```

### REPLACE BY TOKEN

```c++
const string s = "Hello, World!";

string r = Util::String::replace_token(s, "l", [&](string const& m, int index) {
  return string("L" + to_string(index));
});

// r == "HeL0L1o, WorL2d!"
```

[0]:https://github.com/datcxx/build
