#pragma once

#include <map>
#include "json.hpp"
#include "fhir/datatypes/complex/Period.hpp"
#include "fhir/datatypes/complex/Reference.hpp"
#include "fhir/datatypes/primitive.hpp"

using namespace std;
using namespace LongBall::fhir::datatypes::complex;
namespace Primitive = LongBall::fhir::datatypes::primitive;
using json = nlohmann::json;

namespace LongBall {
  namespace fhir {
    namespace backboneelement {
      namespace encounter {

        struct Location {
          Reference location;
          Primitive::code status;
          Period period;
        };

        void to_json(json& j, const Location& p) {
          j = json{
            { "location", p.location },
            { "status", p.status },
            { "period", p.period }
          };
        }

        void from_json(const json& j, Location& p) {
          p.location = j.value("location", Reference{});
          p.status = j.value("status", "");
          p.period = j.value("period", Period{});
        }
      }

    }
  }
}

