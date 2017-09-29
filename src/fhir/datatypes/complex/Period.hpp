#pragma once

#include <map>
#include "json.hpp"
#include "fhir/datatypes/complex/Coding.hpp"
#include "fhir/datatypes/primitive.hpp"

using namespace std;
using json = nlohmann::json;
// namespace primitive = LongBall::fhir::datatypes::primitive;
// namespace complex = LongBall::fhir::datatypes::complex;

namespace LongBall {
  namespace fhir {
    namespace datatypes {
      namespace complex {
        struct Period {
          primitive::dateTime start;
          primitive::dateTime end;
        };

        void to_json(json& j, const Period& p) {
          j = json{
            { "start", p.start },
            { "end", p.end }
          };
        }

        void from_json(const json& j, Period& p) {
          p.start = j.value("start", "");
          p.end = j.value("end", "");
        }
      }
    }
  }
}

