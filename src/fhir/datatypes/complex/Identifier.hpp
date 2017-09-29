#pragma once

#include <map>
#include <vector>
#include "json.hpp"
#include "fhir/datatypes/complex/CodeableConcept.hpp"
#include "fhir/datatypes/complex/Period.hpp"
#include "fhir/datatypes/complex/Reference.hpp"
#include "fhir/datatypes/primitive.hpp"

using namespace std;
using json = nlohmann::json;
namespace primitive = LongBall::fhir::datatypes::primitive;
namespace complex = LongBall::fhir::datatypes::complex;

namespace LongBall {
  namespace fhir {
    namespace datatypes {
      
      enum class IdentifierUse {
        Usual, Official, Temp, Secondary
      };

      map<IdentifierUse, primitive::string> identifierUse {
        {IdentifierUse::Usual, "usual"},
        {IdentifierUse::Official, "official"},
        {IdentifierUse::Temp, "temp"},
        {IdentifierUse::Secondary, "secondary"}
      };

      /* Reference https://www.hl7.org/fhir/DSTU2/datatypes.html#Identifier */
      namespace complex {
        struct Identifier {
          primitive::string code; // usual | official | temp | secondary (If known)
          complex::CodeableConcept type;
          primitive::string system;
          primitive::string value;
          complex::Period period;
          complex::Reference assigner;
        };

        void to_json(json& j, const Identifier& p) {
          j = json{
            {"code", p.code},
            {"type", p.type},
            {"system", p.system},
            {"value", p.value},
            {"period", p.period},
            {"assigner", p.assigner}
          };
        }

        void from_json(const json& j, Identifier& p) {
          p.code = j.value("code", "");
          p.type = j.value("type", CodeableConcept{});
          p.system = j.value("system", "");
          p.value = j.value("value", "");
          p.period = j.value("period", Period{});
          p.assigner = j.value("assigner", Reference{});
        }

      }
    }
  }

}
