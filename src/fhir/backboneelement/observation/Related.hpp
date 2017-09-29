#pragma once

#include <map>
#include "json.hpp"
#include "fhir/datatypes/complex/Reference.hpp"
#include "fhir/datatypes/primitive.hpp"

using namespace std;
using namespace LongBall::fhir::datatypes::complex;
namespace Primitive = LongBall::fhir::datatypes::primitive;
using json = nlohmann::json;

namespace LongBall {
  namespace fhir {
    namespace backboneelement {
      namespace observation {

        struct Related {
          Primitive::code type;  // has-member|derived-from|sequel-to|replaces|qualified-by|interfered-by
          Reference target; // <Observation|QuestionnaireResponse>
        };

        void to_json(json& j, const Related& p) {
          j = json{
            { "type", p.type },
            { "target", p.target }
          };
        }

        void from_json(const json& j, Related& p) {
          p.type = j.value("type", "");
          p.target = j.value("target", Reference{});
        }
      }
      
    }
  }
}
