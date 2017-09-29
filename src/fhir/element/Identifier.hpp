#pragma once

#include "fhir/datatypes/Element.hpp"
#include "fhir/datatypes/complex/Identifier.hpp"
#include "fhir/datatypes/complex/Period.hpp"
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
      struct Element<Identifier> {
        json operator()() const {
          return Identifier{};
        }

        json operator()(const json& arr, const vector<json::json_pointer>& coll, Identifier identifier = {}) {
          auto v = firstOrEmptyString(arr, coll, identifier.value);
          
          return Identifier{
            identifier.code.empty() ? identifierUse[IdentifierUse::Usual] : identifier.code,
            identifier.type,
            identifier.system,
            v,
            identifier.period,
            identifier.assigner
          };
        }
        
        enum class Field {
          Code, Type, System, Value, Period, Assigner
        };

        using FieldMap = const map<Field, const vector<json::json_pointer>>&;

        json operator()(const json& arr, FieldMap dict, const Identifier& identifier = {}) const {
          json j;

          for (const auto& e : dict) {
            switch (e.first) {
              case Field::Code:
                j["code"] = identifier.code.empty() ? identifierUse[IdentifierUse::Usual] : identifier.code;
                break;
              case Field::Type:
                j["type"] = Element<CodeableConcept>()(arr, e.second, identifier.type);
                break;
              case Field::System:
                j["system"] = firstOrEmptyString(arr, e.second, identifier.system);
                break;
              case Field::Value:
                j["value"] = firstOrEmptyString(arr, e.second, identifier.value);
                break;
              case Field::Period:
                j["period"] = Element<Period>()(arr, e.second, identifier.period);
                break;
              case Field::Assigner:
                j["assigner"] = Element<Reference>()(arr, e.second);
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
