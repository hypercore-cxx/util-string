#include "index.hxx"

#include <regex>
#include <string>
#include <vector>

namespace Util {
  namespace String {
    std::vector<std::string> split(const std::string &s, const std::string &res) {
      std::vector<std::string> elems;
      std::regex re(res);

      std::sregex_token_iterator
        iter(s.begin(), s.end(), re, -1),
        end;

      while (iter != end) {
        elems.push_back(*iter);
        ++iter;
      }

      return elems;
    }

    std::vector<std::string> search(const std::string &s, const std::string &res) {
      std::vector<std::string> elems;
      std::regex re(res);

      std::sregex_token_iterator
        iter(s.begin(), s.end(), re),
        end;

      while (iter != end) {
        elems.push_back(*iter);
        ++iter;
      }

      return elems;
    }

    std::string replace(const std::string &s, const std::string &res, const std::string &rep) {
      return std::regex_replace(s, std::regex(res), rep);
    }
  } // namespace String
} // namespace Util
