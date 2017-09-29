#pragma once

#include <map>
#include "json.hpp"
#include "fhir/datatypes/complex/Reference.hpp"
#include "fhir/datatypes/primitive.hpp"

using namespace std;
using json = nlohmann::json;
namespace primitive = LongBall::fhir::datatypes::primitive;
namespace complex = LongBall::fhir::datatypes::complex;

namespace LongBall {
  namespace fhir {
    namespace datatypes {
      namespace complex {
        struct Annotation {
          complex::Reference authorReference;
          primitive::string authorString;
          primitive::dateTime time;
          primitive::string text;
        };

        void to_json(json& j, const Annotation& p) {
          j = json{
            { "authorReference", p.authorReference },
            { "authorString", p.authorString },
            { "time", p.time },
            { "text", p.text }
          };
        }

        void from_json(const json& j, Annotation& p) {
          p.authorReference = j.value("authorReference", Reference{});
          p.authorString = j.value("authorString", "");
          p.time = j.value("time", nullptr);
          p.text = j.value("text", "");
        }
      }
    }
  }
}
