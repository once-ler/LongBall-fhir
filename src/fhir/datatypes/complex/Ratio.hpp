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
        struct Ratio {
          complex::Quantity numerator;
          complex::Quantity denominator;
        };

        void to_json(json& j, const Ratio& p) {
          j = json{
            { "numerator", p.numerator },
            { "denominator", p.denominator }
          };
        }

        void from_json(const json& j, Ratio& p) {
          p.numerator = j.value("numerator", Quantity{});
          p.denominator = j.value("denominator", Quantity{});
        }
      }
    }
  }
}
