#pragma once

#include <map>
#include "json.hpp"
#include "fhir/datatypes/complex/Quantity.hpp"
#include "fhir/datatypes/primitive.hpp"

using namespace std;
using json = nlohmann::json;
namespace primitive = LongBall::fhir::datatypes::primitive;
namespace complex = LongBall::fhir::datatypes::complex;

namespace LongBall {
  namespace fhir {
    namespace datatypes {
      namespace complex {
        struct SampledData {
          complex::Quantity origin;
          primitive::decimal period;
          primitive::decimal factor;
          primitive::decimal lowerLimit;
          primitive::decimal upperLimit;
          primitive::positiveInt dimensions;
          primitive::string data;
        };

        void to_json(json& j, const SampledData& p) {
          j = json{
            { "origin", p.origin },
            { "period", p.period },
            { "factor", p.factor },
            { "lowerLimit", p.lowerLimit },
            { "upperLimit", p.upperLimit },
            { "dimensions", p.dimensions },
            { "data", p.data }
          };
        }

        void from_json(const json& j, SampledData& p) {
          p.origin = j.value("origin", Quantity{});
          p.period = j.value("period", 0);
          p.factor = j.value("factor", 0);
          p.lowerLimit = j.value("lowerLimit", 0);
          p.upperLimit = j.value("upperLimit", 0);
          p.dimensions = j.value("dimensions", 0);
          p.data = j.value("data", "");
        }
      }
    }
  }
}

