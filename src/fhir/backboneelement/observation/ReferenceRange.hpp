#pragma once

#include <map>
#include "json.hpp"
#include "fhir/datatypes/complex/CodeableConcept.hpp"
#include "fhir/datatypes/complex/Quantity.hpp"
#include "fhir/datatypes/complex/Range.hpp"
#include "fhir/datatypes/primitive.hpp"

using namespace std;
using namespace LongBall::fhir::datatypes::complex;
namespace Primitive = LongBall::fhir::datatypes::primitive;
using json = nlohmann::json;

namespace LongBall {
  namespace fhir {
    namespace backboneelement {
      namespace observation {

        struct ReferenceRange {
          Quantity low;
          Quantity high;
          CodeableConcept meaning;
          Range age;
          Primitive::string text;
        };

        void to_json(json& j, const ReferenceRange& p) {
          j = json{
            { "low", p.low },
            { "high", p.high },
            { "meaning", p.meaning },
            { "age", p.age },
            { "text", p.text }
          };
        }

        void from_json(const json& j, ReferenceRange& p) {
          p.low = j.value("low", Quantity{});
          p.high = j.value("high", Quantity{});
          p.meaning = j.value("meaning", CodeableConcept{});
          p.age = j.value("age", Range{});
          p.text = j.value("text", "");
        }
      }
      
    }
  }
}
