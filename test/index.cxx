#include "../index.hxx"

#include <iostream>

#define ASSERT(message, ...) do { \
    if(!(__VA_ARGS__)) { \
          cerr << "FAIL: " << message << endl; \
          exit(1);\
        } \
    else { \
          cout << "OK: " << message << endl; \
          count++;\
        } \
} while(0);

int main () {
  using namespace std;

  int count = 0;
  int plan = 4;

  string f = "/test/parallel/test-path.js";
  
  {
    auto r = Util::String::search(f, "\\w+");
    ASSERT("search results == 5", r.size() == 5);
  }

  {
    auto r = Util::String::split(f, "/");
    ASSERT("parts after split == 4", r.size() == 4);
  }

  {
    auto r = Util::String::replace("Hello, World!", "o", "x");
    ASSERT("replaced letters in string", r == "Hellx, Wxrld!");
  }

  {
    const string s = "Hello, World!";

    auto r = Util::String::replace_token(s, "l", [&](string const& m, int index) {
      return string("L" + to_string(index));
    });

    ASSERT("replaced tokens in string", r == "HeL0L1o, WorL2d!");
  }

  ASSERT("count == plan", count == plan)
}
