#pragma once

#include <map>
#include "json.hpp"
#include "fhir/datatypes/complex/Period.hpp"
#include "fhir/datatypes/primitive.hpp"

using namespace std;
using json = nlohmann::json;
namespace primitive = LongBall::fhir::datatypes::primitive;
namespace complex = LongBall::fhir::datatypes::complex;

namespace LongBall {
  namespace fhir {
    namespace datatypes {
      namespace complex {
        struct ClassHistory {
          primitive::code Class;
          complex::Period period;
        };

        void to_json(json& j, const ClassHistory& p) {
          j = json{
            { "class", p.Class },
            { "period", p.period }
          };
        }

        void from_json(const json& j, ClassHistory& p) {
          p.Class = j.value("class", "");
          p.period = j.value("period", Period{});
        }
      }
    }
  }
}

