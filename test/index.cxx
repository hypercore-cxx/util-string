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
  int plan = 14;

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

  {
    auto r = Util::String::trim("!Hello, World!!", "!");
    ASSERT("trim", r == "Hello, World");
  }

  {
    auto r = Util::String::rtrim("!Hello, World!!", "!");
    ASSERT("rtrim", r == "!Hello, World");
  }

  {
    auto r = Util::String::ltrim("!Hello, World!!", "!");
    ASSERT("ltrim", r == "Hello, World!!");
  }

  {
    auto r = Util::String::match(f, "/(\\w+)/(.*)");
    ASSERT("parts after match == 2", r.size() == 3);
  }

  {
    auto r = Util::String::match("/foo/bar/", "/(\\w+)/(\\w+)/");
    ASSERT("match (passing)", r[1] == "foo" && r[2] == "bar");
  }

  {
    auto r = Util::String::match("crap", "/(\\w+)/(\\w+)/");
    ASSERT("match (failing)", r.empty());
  }

  {
    auto r = Util::String::test("f", "[a-zA-Z]");
    ASSERT("test (passing)", r == true);
  }

  {
    auto r = Util::String::test("1", "[a-zA-Z]");
    ASSERT("test (failing)", r == false);
  }

  {
    auto r = Util::String::test(f, "^/(\\w+)/(\\w+)/(\\w+)-path.js$");
    ASSERT("test exact", r == true);
  }

  {
    auto r = Util::String::test(f, "^(\\w+)/(\\w+)/(\\w+)-path.js$");
    ASSERT("test exact", r == false);
  }

  ASSERT("count == plan", count == plan)
}
