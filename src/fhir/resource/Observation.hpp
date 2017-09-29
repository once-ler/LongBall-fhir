#pragma once

// https://www.hl7.org/fhir/observation.html

#include "json.hpp"
#include "common/util.hpp"
#include "fhir/datatypes/primitive.hpp"
#include "fhir/datatypes/complex/Identifier.hpp"
#include "fhir/datatypes/complex/Reference.hpp"
#include "fhir/datatypes/complex/Quantity.hpp"
#include "fhir/datatypes/complex/Range.hpp"
#include "fhir/datatypes/complex/Ratio.hpp"
#include "fhir/datatypes/complex/SampledData.hpp"
#include "fhir/datatypes/complex/Attachment.hpp"
#include "fhir/backboneelement/observation/ReferenceRange.hpp"
#include "fhir/backboneelement/observation/Related.hpp"
#include "fhir/backboneelement/observation/Component.hpp"

using namespace std;
using namespace LongBall::fhir::datatypes::complex;
using namespace LongBall::fhir::backboneelement::observation;

using json = nlohmann::json;
namespace Primitive = LongBall::fhir::datatypes::primitive;

namespace LongBall {
  namespace fhir {
    namespace resource {

      struct Observation {
        Primitive::string resourceType = "Observation";
        vector<Identifier> identifier;
        vector<Reference> basedOn;
        Primitive::code status;
        vector<CodeableConcept> category;
        CodeableConcept code;
        Reference subject;
        Reference context;
        Primitive::dateTime effectiveDate;
        Period effectivePeriod;
        Primitive::instant issued;
        Reference performer;
        Quantity valueQuantity;
        CodeableConcept valueCodeableConcept;
        Primitive::string valueString;
        Primitive::boolean valueBoolean;
        Range valueRange;
        Ratio valueRatio;
        SampledData valueSampledData;
        Attachment valueAttachment;
        Primitive::time valueTime;
        Primitive::dateTime valueDateTime;
        Period valuePeriod;
        CodeableConcept dataAbsentReason;
        CodeableConcept interpretation;
        Primitive::string comment;
        CodeableConcept bodySite;
        CodeableConcept method;
        Reference specimen;
        Reference device;
        vector<ReferenceRange> referenceRange;
        vector<Related> related;
        vector<Component> component;
      };

      void to_json(json& j, const Observation& p) {
        j = json{
          { "resourceType", p.resourceType },
          { "identifier", p.identifier },
          { "basedOn", p.basedOn },
          { "status", p.status },
          { "category", p.category },
          { "code", p.code },
          { "subject", p.subject },
          { "context", p.context },
          { "effectiveDate", p.effectiveDate },
          { "effectivePeriod", p.effectivePeriod },
          { "issued", p.issued },
          { "performer", p.performer },
          { "valueQuantity", p.valueQuantity },
          { "valueCodeableConcept", p.valueCodeableConcept },
          { "valueString", p.valueString },
          { "valueBoolean", p.valueBoolean },
          { "valueRange", p.valueRange },
          { "valueRatio", p.valueRatio },
          { "valueSampledData", p.valueSampledData },
          { "valueAttachment", p.valueAttachment },
          { "valueTime", p.valueTime },
          { "valueDateTime", p.valueDateTime },
          { "valuePeriod", p.valuePeriod },
          { "dataAbsentReason", p.dataAbsentReason },
          { "interpretation", p.interpretation },
          { "comment", p.comment },
          { "bodySite", p.bodySite },
          { "method", p.method },
          { "specimen", p.specimen },
          { "device", p.device },
          { "referenceRange", p.referenceRange },
          { "related", p.related },
          { "component", p.component }
        };
      }

      void from_json(const json& j, Observation& p) {
        // p.resourceType = j.value("resourceType", "Observation");
        for (const auto& e : j.value("identifier", json::array({}))) {
          p.identifier.emplace_back(e.get<Identifier>());
        }
        for (const auto& e : j.value("basedOn", json::array({}))) {
          p.basedOn.emplace_back(e.get<Reference>());
        }
        p.status = j.value("status", "");
        for (const auto& e : j.value("category", json::array({}))) {
          p.category.emplace_back(e.get<CodeableConcept>());
        }
        p.code = j.value("code", CodeableConcept{});
        p.subject = j.value("subject", Reference{});
        p.context = j.value("context", Reference{});
        p.effectiveDate = j.value("context", "");
        p.effectivePeriod = j.value("context", Period{});
        p.issued = j.value("issued", "");
        p.performer = j.value("performer", Reference{});
        p.valueQuantity = j.value("valueQuantity", Quantity{});
        p.valueCodeableConcept = j.value("valueCodeableConcept", CodeableConcept{});
        p.valueString = j.value("valueString", "");
        p.valueBoolean = j.value("valueBoolean", false);
        p.valueRange = j.value("valueRange", Range{});
        p.valueRatio = j.value("valueRatio", Ratio{});
        p.valueSampledData = j.value("valueSampledData", SampledData{});
        p.valueAttachment = j.value("valueAttachment", Attachment{});
        p.valueTime = j.value("valueTime", "");
        p.valueDateTime = j.value("valueDateTime", "");
        p.valuePeriod = j.value("valuePeriod", Period{});
        p.dataAbsentReason = j.value("dataAbsentReason", CodeableConcept{});
        p.interpretation = j.value("interpretation", CodeableConcept{});
        p.comment = j.value("comment", "");
        p.bodySite = j.value("bodySite", CodeableConcept{});
        p.method = j.value("method", CodeableConcept{});
        p.specimen = j.value("specimen", Reference{});
        p.device = j.value("device", Reference{});
        for (const auto& e : j.value("referenceRange", json::array({}))) {
          p.referenceRange.emplace_back(e.get<ReferenceRange>());
        }
        for (const auto& e : j.value("related", json::array({}))) {
          p.related.emplace_back(e.get<Related>());
        }
        for (const auto& e : j.value("component", json::array({}))) {
          p.component.emplace_back(e.get<Component>());
        }        
      }

    }
  }
}
