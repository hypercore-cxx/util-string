#ifndef HYPER_UTIL_STRING_H
#define HYPER_UTIL_STRING_H

#include <regex>
#include <string>
#include <vector>

namespace Hyper {
  namespace Util {
    namespace String {
      using String = std::string;
      using ReplaceCallback = std::function<std::string (const std::string&, int)>;

      inline std::vector<String> split(const String &s, const String &res) {
        std::vector<String> elems;
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

      inline std::vector<String> search(const String &s, const String &res) {
        std::vector<String> elems;
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

      inline std::smatch match (const String& s, const String& sre) {
        std::regex RE(sre);
        std::smatch result;
        std::regex_match(s, result, RE);
        return result;
      }

      inline bool test (const String& s, const String& sre) {
        std::regex RE(sre);
        std::smatch result;
        return std::regex_match(s, result, RE);
      }

      const char* ws = " \t\n\r\f\v";

      inline String rtrim(const String& s, const char* t = ws) {
        auto tmp = s;
        tmp.erase(tmp.find_last_not_of(t) + 1);
        return tmp;
      }

      inline String ltrim(const String& s, const char* t = ws) {
        auto tmp = s;
        tmp.erase(0, tmp.find_first_not_of(t));
        return tmp;
      }

      inline String trim(const String& s, const char* t = ws) {
        return ltrim(rtrim(s, t), t);
      }

      inline String replace(const String &s, const String &res, const String &rep) {
        return std::regex_replace(s, std::regex(res), rep);
      }

      inline String replace(const String s, const String res, ReplaceCallback&& cb) {
        std::regex re(res);

        String ret;
        int count = 0;

        std::sregex_token_iterator
          begin(s.begin(), s.end(), re, { -1, 0 }),
          end;

        std::for_each(begin, end, [&](String const& m) {
          if (m == res) {
            ret += cb(m, count++);
          } else {
            ret += m;
          }
        });

        return ret;
      }
    }
  } // namespace Util
} // namespace Hyper

#endif
