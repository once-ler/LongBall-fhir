#pragma once

#include <map>
#include "json.hpp"
#include "fhir/datatypes/complex/CodeableConcept.hpp"
#include "fhir/datatypes/complex/Quantity.hpp"
#include "fhir/datatypes/complex/Range.hpp"
#include "fhir/datatypes/complex/Ratio.hpp"
#include "fhir/datatypes/complex/SampledData.hpp"
#include "fhir/datatypes/complex/Attachment.hpp"
#include "fhir/datatypes/complex/Period.hpp"
#include "fhir/backboneelement/observation/ReferenceRange.hpp"
#include "fhir/datatypes/primitive.hpp"

using namespace std;
using namespace LongBall::fhir::datatypes::complex;
namespace Primitive = LongBall::fhir::datatypes::primitive;
using json = nlohmann::json;

namespace LongBall {
  namespace fhir {
    namespace backboneelement {
      namespace observation {

        struct Component {
          CodeableConcept code;
          Quantity valueQuantity;
          CodeableConcept valueCodeableConcept;
          Primitive::string valueString;
          Range valueRange;
          SampledData valueSampledData;
          Attachment valueAttachment;
          Primitive::time valueTime;
          Primitive::dateTime valueDateTime;
          Period valuePeriod;
          CodeableConcept dataAbsentReason;
          ReferenceRange referenceRange;
        };

        void to_json(json& j, const Component& p) {
          j = json{
            { "code", p.code },
            { "valueQuantity", p.valueQuantity },
            { "valueCodeableConcept", p.valueCodeableConcept },
            { "valueString", p.valueString },
            { "valueRange", p.valueRange },
            { "valueSampledData", p.valueSampledData },
            { "valueAttachment", p.valueAttachment },
            { "valueTime", p.valueTime },
            { "valueDateTime", p.valueDateTime },
            { "valuePeriod", p.valuePeriod },
            { "dataAbsentReason", p.dataAbsentReason },
            { "referenceRange", p.referenceRange }
          };
        }

        void from_json(const json& j, Component& p) {
          p.code = j.value("code", CodeableConcept{});
          p.valueQuantity = j.value("valueQuantity", Quantity{});
          p.valueCodeableConcept = j.value("valueCodeableConcept", CodeableConcept{});
          p.valueString = j.value("valueString", "");
          p.valueRange = j.value("valueRange", Range{});
          p.valueSampledData = j.value("valueSampledData", SampledData{});
          p.valueAttachment = j.value("valueAttachment", Attachment{});
          p.valueTime = j.value("valueTime", "");
          p.valueDateTime = j.value("valueDateTime", "");
          p.valuePeriod = j.value("valuePeriod", Period{});
          p.dataAbsentReason = j.value("dataAbsentReason", CodeableConcept{});
          p.referenceRange = j.value("referenceRange", ReferenceRange{});
        }
      }
      
    }
  }
}
