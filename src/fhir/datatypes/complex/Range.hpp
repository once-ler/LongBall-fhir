#pragma once

#include <map>
#include "json.hpp"
#include "fhir/datatypes/complex/Quantity.hpp"

using namespace std;
using json = nlohmann::json;
namespace complex = LongBall::fhir::datatypes::complex;

namespace LongBall {
  namespace fhir {
    namespace datatypes {
      namespace complex {
        struct Range {
          complex::Quantity low;
          complex::Quantity high;
        };

        void to_json(json& j, const Range& p) {
          j = json{
            { "low", p.low },
            { "high", p.high }
          };
        }

        void from_json(const json& j, Range& p) {
          p.low = j.value("low", Quantity{});
          p.high = j.value("high", Quantity{});
        }
      }
    }
  }
}
