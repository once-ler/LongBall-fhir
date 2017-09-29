#pragma once

#include "fhir/datatypes/Element.hpp"
#include "fhir/datatypes/complex/Ratio.hpp"
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
      struct Element<Ratio> {
        json operator()() const {
          return Ratio{};
        }

        json operator()(const json& arr, const vector<json::json_pointer>& coll = {}, const Ratio& ratio = {}) {
          auto v = firstOrDefault(arr, coll, ratio.numerator);
          auto copy = ratio;
          Quantity q;
          q.value = v.get<double>();          
          copy.numerator = q;
          copy.denominator = q;
          return copy;
        }

        enum class Field {
          Numerator, Denominator
        };

        using FieldMap = const map<Field, const vector<json::json_pointer>>&;

        json operator()(const json& arr, FieldMap dict, const Ratio& ratio = {}) const {
          json j;

          for (const auto& e : dict) {
            switch (e.first) {
            case Field::Numerator:
              j["low"] = firstOrDefault(arr, e.second, ratio.numerator);
              break;
            case Field::Denominator:
              j["high"] = firstOrDefault(arr, e.second, ratio.denominator);
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
