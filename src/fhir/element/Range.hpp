#pragma once

#include "fhir/datatypes/Element.hpp"
#include "fhir/datatypes/complex/Range.hpp"
#include "fhir/datatypes/complex/Quantity.hpp"
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
      struct Element<Range> {
        json operator()() const {
          return Range{};
        }

        json operator()(const json& arr, const vector<json::json_pointer>& coll = {}, const Range& range = {}) {
          auto v = firstOrDefault(arr, coll, range.low);
          auto copy = range;
          Quantity q;
          q.value = v.get<double>();
          copy.low = q;
          copy.high = q;
          return copy;
        }

        enum class Field {
          Low, High
        };

        using FieldMap = const map<Field, const vector<json::json_pointer>>&;

        json operator()(const json& arr, FieldMap dict, const Range& range = {}) const {
          json j;

          for (const auto& e : dict) {
            switch (e.first) {
            case Field::Low:
              j["low"] = firstOrDefault(arr, e.second, range.low);
              break;
            case Field::High:
              j["high"] = firstOrDefault(arr, e.second, range.high);
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
