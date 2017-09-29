#pragma once

#include <vector>
#include <map>
#include "json.hpp"
#include "fhir/datatypes/complex/Coding.hpp"
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
        struct Signature {
          vector<complex::Coding> type;
          primitive::instant when;
          primitive::uri whoUri;
          complex::Reference whoReference;
          primitive::code contentType;
          primitive::base64Binary blob;
        };

        void to_json(json& j, const Signature& p) {
          j = json{
            { "type", p.type },
            { "when", p.when },
            { "whoUri", p.whoUri },
            { "whoReference", p.whoReference },
            { "contentType", p.contentType },
            { "blob", p.blob }
          };
        }

        void from_json(const json& j, Signature& p) {
          p.when = j.value("when", nullptr);
          p.whoUri = j.value("whoUri", "");
          p.whoReference = j.value("whoReference", Reference{});
          p.contentType = j.value("contentType", "");
          p.blob = j.value("blob", nullptr);

          for (const auto& e : j.value("type", json::array({}))) {
            p.type.emplace_back(e.get<std::string>());
          }
        }
      }
    }
  }
}
