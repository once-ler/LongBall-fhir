#pragma once

#include "fhir/datatypes/Element.hpp"
#include "fhir/datatypes/complex/Attachment.hpp"
#include "json.hpp"
#include "common/util.hpp"

using namespace LongBall::fhir::datatypes;
using namespace LongBall::fhir::datatypes::complex;
using namespace LongBall::common::util;

using json = nlohmann::json;

namespace LongBall {
  namespace fhir {
    namespace element {

      template<>
      struct Element<Attachment> {
        json operator()() const {
          return Attachment{};
        }

        json operator()(const json& arr, const vector<json::json_pointer>& coll, const Attachment& attachment = {}) {
          auto v = firstOrEmptyString(arr, coll, attachment.data);
          auto copy = attachment;
          copy.data = v.get<string>();
          return copy;
        }
      };

    }
  }
}
