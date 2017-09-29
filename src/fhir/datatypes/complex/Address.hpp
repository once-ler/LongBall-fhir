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

      enum class AddressUse {
        Home, Work, Temp, Old
      };

      map<AddressUse, string> addressUse{
        { AddressUse::Home, "home" },
        { AddressUse::Work, "work" },
        { AddressUse::Temp, "temp" },
        { AddressUse::Old, "old" }
      };

      enum class AddressType {
        Postal, Physical, Both
      };

      map<AddressType, string> addressType{
        { AddressType::Postal, "postal" },
        { AddressType::Physical, "physical" },
        { AddressType::Both, "both" }
      };

      namespace complex {
        struct Address {
          primitive::code use;
          primitive::code type;
          primitive::string text;
          vector<primitive::string> line;
          primitive::string city;
          primitive::string district;
          primitive::string state;
          primitive::string postalCode;
          primitive::string country;
          complex::Period period;
        };

        void to_json(json& j, const Address& p) {
          j = json{
            { "use", p.use }, // home | work | temp | old - purpose of this addres
            { "type", p.type }, // postal | physical | both
            { "text", p.text },
            { "line", p.line },
            { "city", p.city },
            { "district", p.district },
            { "state", p.state },
            { "postalCode", p.postalCode },
            { "country", p.country },
            { "period", p.period }
          };
        }

        void from_json(const json& j, Address& p) {
          p.use = j.value("use", "");
          p.type = j.value("type", "");
          p.text = j.value("text", "");
                    
          for (const auto& e : j.value("line", json::array({}))) {
            p.line .emplace_back(e.get<std::string>());
          }
          
          p.city = j.value("city", "");
          p.district = j.value("district", "");
          p.state = j.value("state", "");
          p.country = j.value("country", "");
          p.text = j.value("text", "");
          p.period = j.value("period", Period{});
        }
      }
    }
  }
}

