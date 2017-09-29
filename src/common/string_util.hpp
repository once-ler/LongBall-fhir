#pragma once

#ifdef _WIN32
#pragma warning(disable : 4996)
#endif

#include <memory>
#include <iostream>
#include <string>
#include <cstdio>

namespace LongBall {
  namespace common {
    namespace util {

      template<typename ... Args>
      std::string string_format(const std::string& format, Args ... args) {
        size_t size = snprintf(nullptr, 0, format.c_str(), args ...) + 1; // Extra space for '\0'
        std::unique_ptr<char[]> buf(new char[size]);
        snprintf(buf.get(), size, format.c_str(), args ...);
        return std::string(buf.get(), buf.get() + size - 1); // We don't want the '\0' inside
      }

      struct string_concat {
        template <typename LHS, typename RHS>
        std::string operator()(LHS const& lhs, RHS const& rhs) const {
          std::stringstream ss;
          ss << lhs << rhs;
          return ss.str();
        }
      };

      // std::string s=join(array.begin(), array.end(), std::string(","));
      template <class T, class A>
      T join(const A &begin, const A &end, const T &t) {
        T result;
        for (A it = begin;
          it != end;
          it++) {
          if (!result.empty())
            result.append(t);
          result.append(*it);
        }
        return result;
      }

      // source: https://github.com/zeux/pugixml
      void xml_encode(std::string& data) {
        std::string buffer;
        buffer.reserve(data.size());
        for (size_t pos = 0; pos != data.size(); ++pos) {
          switch (data[pos]) {
          case '&':  buffer.append("&amp;");       break;
          case '\"': buffer.append("&quot;");      break;
          case '\'': buffer.append("&apos;");      break;
          case '<':  buffer.append("&lt;");        break;
          case '>':  buffer.append("&gt;");        break;
          default:   buffer.append(&data[pos], 1); break;
          }
        }
        data.swap(buffer);
      }

    }
  }
}
