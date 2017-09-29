#pragma once

#include "fhir/datatypes/Element.hpp"
#include "fhir/datatypes/complex/CodeableConcept.hpp"
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
      struct Element<CodeableConcept> {
        json operator()() const {
          return CodeableConcept{};
        }

        json operator()(const json& arr, const vector<json::json_pointer>& coll, const CodeableConcept& codeableConcept = {}) const {
          auto v = firstOrEmptyString(arr, coll, codeableConcept.coding.code);
          
          return CodeableConcept{
            Coding{
              codeableConcept.coding.system,
              codeableConcept.coding.version,
              v, 
              codeableConcept.coding.url,
              v, 
              false
            },
            v
          };
        }
      };

    }
  }
}
