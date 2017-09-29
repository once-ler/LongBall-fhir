#pragma once

#include <map>
#include "json.hpp"
#include "fhir/datatypes/complex/CodeableConcept.hpp"
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

        struct Participant {
          CodeableConcept type;
          Period period;
          Reference individual;
        };

        void to_json(json& j, const Participant& p) {
          j = json{
            { "type", p.type },
            { "period", p.period },
            { "individual", p.individual }
          };
        }

        void from_json(const json& j, Participant& p) {
          p.type = j.value("type", CodeableConcept{});
          p.period = j.value("period", Period{});
          p.individual = j.value("individual", Reference{});
        }
      }
      
    }
  }
}

