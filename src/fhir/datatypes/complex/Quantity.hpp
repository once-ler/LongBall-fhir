#pragma once

#include <map>
#include "json.hpp"
#include "fhir/datatypes/primitive.hpp"

using namespace std;
using json = nlohmann::json;
namespace primitive = LongBall::fhir::datatypes::primitive;

namespace LongBall {
  namespace fhir {
    namespace datatypes {
      namespace complex {
        struct Quantity {
          primitive::decimal value;
          primitive::code comparator;
          string unit;
          primitive::uri system;
          primitive::code code;
        };

        void to_json(json& j, const Quantity& p) {
          j = json{
            { "value", p.value },
            { "comparator", p.comparator },
            { "unit", p.unit },
            { "system", p.system },
            { "code", p.code }
          };
        }

        void from_json(const json& j, Quantity& p) {
          p.value = j.value("value", 0);
          p.comparator = j.value("comparator", "");
          p.unit = j.value("unit", "");
          p.system = j.value("system", "");
          p.code = j.value("code", "");
        }
      }
    }
  }
}
