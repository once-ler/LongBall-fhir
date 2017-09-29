#pragma once

#include "fhir/datatypes/Element.hpp"
#include "fhir/datatypes/complex/Period.hpp"
#include "json.hpp"
#include "common/util.hpp"

using namespace LongBall::fhir::datatypes;
using namespace LongBall::fhir::datatypes::complex;
using json = nlohmann::json;

namespace Util = LongBall::common::util;

namespace LongBall {
  namespace fhir {
    namespace element {

      template<>
      struct Element<Period> {
        json operator()() const {
          return Period{};
        }

        json operator()(const json& arr, const vector<json::json_pointer>& coll, const Period& period = {}) const {
          auto _ = firstOrEmptyString(arr, coll, period.start);

          return Period{ _, _ };
        }

        enum class Field {
          Start, End
        };

        using FieldMap = const map<Field, const vector<json::json_pointer>>&;

        json operator()(const json& arr, FieldMap dict, const Period& period = {}) const {
          json j;

          for (const auto& e : dict) {
            switch (e.first) {
            case Field::Start:
              j["start"] = firstOrEmptyString(arr, e.second, period.start);
              break;
            case Field::End:
              j["end"] = firstOrEmptyString(arr, e.second, period.end);
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
