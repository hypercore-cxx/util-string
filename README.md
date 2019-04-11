# SYNOPSIS
Functions that make dealing with typical string operations easier.

# FUNCTIONS

```c++
string f = "/test/parallel/test-path.js";
```

### SEARCH

```c++
auto r = Util::String::search(f, "\\w+");
ASSERT("search results == 5", r.size() == 5);
```

### SPLIT

```c++
auto r = Util::String::split(f, "/");
ASSERT("parts after split == 4", r.size() == 4);
```

### REPLACE

```c++
auto r = Util::String::replace("Hello, World!", "o", "x");
ASSERT("replaced letters in string", r == "Hellx, Wxrld!");
```

### REPLACE BY TOKEN

```c++
const string s = "Hello, World!";

auto r = Util::String::replace_token(s, "l", [&](string const& m, int index) {
  return string("L" + to_string(index));
});

ASSERT("replaced tokens in string", r == "HeL0L1o, WorL2d!");
```

# TESTING
Using the [`dat-cxx`][0] build tool, run the following command.

```bash
build run test
```

[0]:https://github.com/datcxx/build
