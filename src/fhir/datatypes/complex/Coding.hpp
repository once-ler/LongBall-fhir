#pragma once

#include <map>
#include "json.hpp"
#include "fhir/datatypes/primitive.hpp"

using namespace std;
using json = nlohmann::json;
namespace primitive = LongBall::fhir::datatypes::primitive;

namespace LongBall {
  namespace fhir {
    namespace datatypes {
      namespace complex {
        struct Coding {
          primitive::uri system;
          string version;
          primitive::code code;
          primitive::uri url;
          string display;
          primitive::boolean userSelected;
        };

        void to_json(json& j, const Coding& p) {
          j = json{
            { "system", p.system },
            { "version", p.version },
            { "code", p.code },
            { "url", p.url },
            { "display", p.display },
            { "userSelected", p.userSelected }
          };
        }

        void from_json(const json& j, Coding& p) {
          p.system = j.value("system", "");
          p.version = j.value("version", "");
          p.code = j.value("code", "");
          p.url = j.value("url", "");
          p.display = j.value("display", "");
          p.userSelected = j.value("userSelected", false);
        }
      }
    }
  }
}
