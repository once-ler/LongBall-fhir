#pragma once

#include "fhir/datatypes/Element.hpp"
#include "fhir/datatypes/complex/Coding.hpp"
#include "json.hpp"
#include "common/util.hpp"

using namespace LongBall::fhir::datatypes;
using namespace LongBall::fhir::datatypes::complex;
using namespace LongBall::common::util;

using json = nlohmann::json;

namespace LongBall {
  namespace fhir {
    namespace element {

      template<>
      struct Element<Coding> {
        json operator()() const {
          return Coding{};
        }

        json operator()(const json& arr, const vector<json::json_pointer>& coll, const Coding& coding = {}) const {
          auto v = firstOrEmptyString(arr, coll, coding.code);

          return Coding{
            coding.system,
            coding.version,
            v,
            coding.url,
            v,
            false
          };
        }

        enum class Field {
          System, Version, Code, Url, Display, UserSelected
        };

        using FieldMap = const map<Field, const vector<json::json_pointer>>&;

        json operator()(const json& arr, FieldMap dict, const Coding& coding = {}) const {
          json j;

          for (const auto& e : dict) {
            switch (e.first) {
            case Field::System:
              j["system"] = firstOrEmptyString(arr, e.second, coding.system);
              break;
            case Field::Version:
              j["version"] = firstOrEmptyString(arr, e.second, coding.version);
              break;
            case Field::Code:
              j["code"] = firstOrEmptyString(arr, e.second, coding.code);
              break;
            case Field::Url:
              j["url"] = firstOrEmptyString(arr, e.second, coding.url);
              break;
            case Field::Display:
              j["display"] = firstOrEmptyString(arr, e.second, coding.display);
              break;
            case Field::UserSelected:
              j["userSelected"] = firstOrDefault(arr, e.second, coding.userSelected);
              break;
            default:
              break;
            }
          }

          return j;
        }

      };

    }
  }
}
