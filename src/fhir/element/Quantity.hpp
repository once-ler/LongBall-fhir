#pragma once

#include "fhir/datatypes/Element.hpp"
#include "fhir/datatypes/complex/Quantity.hpp"
#include "json.hpp"
#include "common/util.hpp"

using namespace LongBall::fhir::datatypes;
using namespace LongBall::fhir::datatypes::complex;
using json = nlohmann::json;

namespace Util = LongBall::common::util;

namespace LongBall {
  namespace fhir {
    namespace element {

      template<>
      struct Element<Quantity> {
        json operator()() const {
          return Quantity{};
        }

        json operator()(const json& arr, const vector<json::json_pointer>& coll, const Quantity& quantity = {}) const {
          auto v = firstOrDefault(arr, coll);
          auto q = v.is_number() ? v.get<double>() : 0;

          return Quantity{ q, "", "", "", "" };
        }
      };

    }
  }
}
