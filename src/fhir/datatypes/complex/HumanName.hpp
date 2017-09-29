#pragma once

#include <vector>
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

      enum class HumanNameUse {
        Usual, Official, Temp, Nickname, Anonymous, Old, Maiden
      };

      map<HumanNameUse, string> humanNameUse{
        { HumanNameUse::Usual, "usual" },
        { HumanNameUse::Official, "official" },
        { HumanNameUse::Temp, "temp" },
        { HumanNameUse::Nickname, "nickname" },
        { HumanNameUse::Anonymous, "anonymous" },
        { HumanNameUse::Old, "old" },
        { HumanNameUse::Maiden, "maiden" }
      };

      namespace complex {
        struct HumanName {
          primitive::code use;
          primitive::string text;
          vector<primitive::string> family;
          vector<primitive::string> given;
          vector<primitive::string> prefix;
          vector<primitive::string> suffix;
          complex::Period period;
        };

        void to_json(json& j, const HumanName& p) {
          j = json{
            { "use", p.use }, // usual | official | temp | nickname | anonymous | old | maiden
            { "text", p.text },
            { "family", p.family },
            { "given", p.given },
            { "prefix", p.prefix },
            { "suffix", p.suffix },
            { "period", p.period }
          };
        }

        void from_json(const json& j, HumanName& p) {
          p.use = j.value("use", "");
          p.text = j.value("text", "");
          p.period = j.value("period", Period{});
          
          for (const auto& e : j.value("family", json::array({}))) {
            p.family.emplace_back(e.get<std::string>());
          }
          for (const auto& e : j.value("given", json::array({}))) {
            p.given.emplace_back(e.get<std::string>());
          }
          for (const auto& e : j.value("prefix", json::array({}))) {
            p.prefix.emplace_back(e.get<std::string>());
          }
          for (const auto& e : j.value("suffix", json::array({}))) {
            p.suffix.emplace_back(e.get<std::string>());
          }          
        }
      }
    }
  }
}

