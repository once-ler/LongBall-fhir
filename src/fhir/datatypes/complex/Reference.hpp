#pragma once

#include <map>
#include "json.hpp"
#include "fhir/datatypes/primitive.hpp"

using namespace std;
using json = nlohmann::json;
namespace primitive = LongBall::fhir::datatypes::primitive;
namespace complex = LongBall::fhir::datatypes::complex;

namespace LongBall {
  namespace fhir {
    namespace datatypes {
      namespace complex {

        // TODO: need template
        // Reference<Location|Condition|Organization|EpisodeOfCare|ReferralRequest...>
        struct Reference {
          primitive::string reference;
          primitive::string display;
        };

        void to_json(json& j, const Reference& p) {
          j = json{
            { "reference", p.reference },
            { "display", p.display }
          };
        }

        void from_json(const json& j, Reference& p) {
          p.reference = j.value("reference", "");
          p.display = j.value("display", "");
        }
      }
    }
  }
}

