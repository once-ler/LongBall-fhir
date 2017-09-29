#pragma once

#include <map>
#include "json.hpp"
#include "fhir/datatypes/complex/Coding.hpp"
#include "fhir/datatypes/primitive.hpp"

using namespace std;
using json = nlohmann::json;
namespace primitive = LongBall::fhir::datatypes::primitive;
namespace complex = LongBall::fhir::datatypes::complex;

namespace LongBall {
  namespace fhir {
    namespace datatypes {
      namespace complex {
        struct CodeableConcept {
          complex::Coding coding;
          primitive::string text;
        };

        void to_json(json& j, const CodeableConcept& p) {
          j = json{
            { "coding", p.coding },
            { "text", p.text }
          };
        }

        void from_json(const json& j, CodeableConcept& p) {
          p.coding = j.value("coding", Coding{});
          p.text = j.value("text", "");
        }
      }
    }
  }
}

