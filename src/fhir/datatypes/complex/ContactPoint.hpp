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

      enum class ContactPointUse {
        Home, Work, Temp, Old, Mobile
      };

      map<ContactPointUse, string> addressType{
        { ContactPointUse::Home, "home" },
        { ContactPointUse::Work, "work" },
        { ContactPointUse::Temp, "temp" },
        { ContactPointUse::Old, "old" },
        { ContactPointUse::Mobile, "mobile" }
      };

      namespace complex {
        struct ContactPoint {
          primitive::code system;
          primitive::string value;
          primitive::string text;
          primitive::string use; // home | work | temp | old | mobile - purpose of this contact point
          primitive::positiveInt rank;
          complex::Period period;
        };

        void to_json(json& j, const ContactPoint& p) {
          j = json{
            { "system", p.system },
            { "value", p.value }, 
            { "text", p.text },
            { "use", p.use },
            { "rank", p.rank },
            { "period", p.period }
          };
        }

        void from_json(const json& j, ContactPoint& p) {
          p.system = j.value("system", "");
          p.value = j.value("value", "");
          p.text = j.value("text", "");
          p.use = j.value("use", "");
          p.rank = j.value("rank", 0);
          p.period = j.value("period", Period{});
        }
      }
    }
  }
}

