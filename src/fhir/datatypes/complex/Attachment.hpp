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
        struct Attachment {
          primitive::code contentType;
          primitive::code language;
          primitive::base64Binary data;
          primitive::uri url;
          primitive::unsignedInt size;
          primitive::base64Binary hash;
          primitive::string title;
          primitive::dateTime creation;
        };

        void to_json(json& j, const Attachment& p) {
          j = json{
            { "contentType", p.contentType },
            { "language", p.language },
            { "data", p.data },
            { "url", p.url },
            { "size", p.size },
            { "hash", p.hash },
            { "title", p.title },
            { "creation", p.creation }
          };
        }

        void from_json(const json& j, Attachment& p) {
          p.contentType = j.value("contentType", "");
          p.language = j.value("language", "");
          p.data = j.value("data", "");
          p.url = j.value("url", "");
          p.size = j.value("size", 0);
          p.hash = j.value("hash", "");
          p.title = j.value("title", "");
          p.creation = j.value("creation", "");
        }
      }
    }
  }
}
