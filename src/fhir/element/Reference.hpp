#pragma once

#include "fhir/datatypes/Element.hpp"
#include "fhir/datatypes/complex/Reference.hpp"
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
      struct Element<Reference> {
        json operator()() const {
          return Reference{};
        }

        json operator()(const json& arr, const vector<json::json_pointer>& coll, const Reference& reference = {}) const {
          auto _ = firstOrEmptyString(arr, coll, reference.display);

          return Reference{ _, _ };
        }

        enum class Field {
          Display, Reference
        };

        using FieldMap = const map<Field, const vector<json::json_pointer>>&;

        json operator()(const json& arr, FieldMap dict, const Reference& reference = {}) const {
          json j;

          for (const auto& e : dict) {
            switch (e.first) {
            case Field::Display:
              j["display"] = firstOrEmptyString(arr, e.second, reference.display);
              break;
            case Field::Reference:
              j["reference"] = firstOrEmptyString(arr, e.second, reference.reference);
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
