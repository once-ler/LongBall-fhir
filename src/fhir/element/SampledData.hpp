#pragma once

#include "fhir/datatypes/Element.hpp"
#include "fhir/datatypes/complex/SampledData.hpp"
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
      struct Element<SampledData> {
        json operator()() const {
          return SampledData{};
        }

        json operator()(const json& arr, const vector<json::json_pointer>& coll = {}, const SampledData& sampledData = {}) {
          auto v = firstOrEmptyString(arr, coll, sampledData.data);
          auto copy = sampledData;
          copy.data = v.get<string>();
          return copy;
        }

        enum class Field {
          Origin, Period, Factor, LowerLimit, UpperLimit, Dimensions, Data
        };

        using FieldMap = const map<Field, const vector<json::json_pointer>>&;

        json operator()(const json& arr, FieldMap dict, const SampledData& sampledData = {}) const {
          json j;

          for (const auto& e : dict) {
            switch (e.first) {
            case Field::Origin:
              j["origin"] = firstOrDefault(arr, e.second, sampledData.origin);
              break;
            case Field::Period:
              j["period"] = firstOrDefault(arr, e.second, sampledData.period);
              break;
            case Field::Factor:
              j["period"] = firstOrDefault(arr, e.second, sampledData.factor);
              break;
            case Field::LowerLimit:
              j["period"] = firstOrDefault(arr, e.second, sampledData.lowerLimit);
              break;
            case Field::UpperLimit:
              j["period"] = firstOrDefault(arr, e.second, sampledData.upperLimit);
              break;
            case Field::Dimensions:
              j["period"] = firstOrDefault(arr, e.second, sampledData.dimensions);
              break;
            case Field::Data:
              j["period"] = firstOrDefault(arr, e.second, sampledData.data);
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
