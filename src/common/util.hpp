#pragma once

#include <ctime>
#include <iostream>
#include <locale>
#include "json.hpp"
#include "common/string_util.hpp"

using namespace std;

using json = nlohmann::json;

namespace LongBall {
  namespace common {
    namespace util {
      string getCurrentTime() {
        string c;
        std::time_t rawtime;
        std::tm* timeinfo;
        char buffer[80];

        std::time(&rawtime);
        timeinfo = std::localtime(&rawtime);

        std::strftime(buffer, 80, "%Y-%m-%dT%H:%M:%SZ", timeinfo);

        c.assign(buffer);

        return c;
      }

      uint64_t getCurrentTimeMilliseconds() {
        string c;
        std::time_t rawtime;
        std::tm* timeinfo;

        std::time(&rawtime);
        timeinfo = std::localtime(&rawtime);

        time_t timeSinceEpoch = mktime(timeinfo);

        return 1000 * timeSinceEpoch;
      }

      template<typename F>
      decltype(auto) filterJsonArray(const json& arr, const F& func) {
        return find_if(arr.begin(), arr.end(), func);
      }

      json findOne(const json& arr, const json::json_pointer& p) noexcept {
        json r_;

        for (const auto& o : arr) {          
          r_ = o.value(p, json(nullptr));
          if (!r_.is_null()) break;
        }

        return r_;
      };

      // Find first json path from a set that is not null.
      json firstOrDefault(const json& arr, const vector<json::json_pointer>& coll, const json& defaultValue = json(nullptr)) noexcept {
        auto r_ = defaultValue;
        
        if (!arr.is_array() || coll.size() == 0) return r_;

        for (const auto& p : coll) {
          r_ = findOne(arr, p);
          if (!r_.is_null()) break;
        }

        return r_.is_null() ? defaultValue : r_;
      }
      
      json emptyStringIfNull(const json& j, const string& defaultValue = "") {
        if (j.is_array()) {
          vector<string> vs;
          for (auto const& e : j) {
            if (e.is_string()) {
              vs.emplace_back(e.get<string>());
            }
          }

          std::string s = join(vs.begin(), vs.end(), std::string(","));
          return s;
        }
        return j.is_null() ? defaultValue : j.get<string>();        
      }

      json firstOrEmptyString(const json& arr, const vector<json::json_pointer>& coll, const string& defaultValue = "") {
        return emptyStringIfNull(firstOrDefault(arr, coll));
      }

    }
  }
}
