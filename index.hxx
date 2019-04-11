#ifndef UTIL_H
#define UTIL_H

#include <regex>
#include <string>
#include <vector>
#include <sstream>

namespace Util {
  namespace String {
    std::vector<std::string> split(const std::string&, const std::string&);
    std::vector<std::string> search(const std::string&, const std::string&);
    std::string replace(const std::string&, const std::string&, const std::string&);

    //
    // It is not possible to explicitly instantiate a function template that
    // accepts a lambda since lambda types are generated for each compilation
    // unit. Hence, this type of implementation must live in the header file.
    //
    template<class F>
    inline std::string replace_token(const std::string s, const std::string res, F&& cb) {
      std::regex re(res);

      std::string ret;
      int count = 0;

      std::sregex_token_iterator
        begin(s.begin(), s.end(), re, { -1, 0 }),
        end;

      std::for_each(begin, end, [&](std::string const& m) {
        if (m == res) {
          ret += cb(m, count++);
        } else {
          ret += m;
        }
      });

      return ret;
    }
  }
}

#endif
