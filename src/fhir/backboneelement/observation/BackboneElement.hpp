#pragma once

#include "fhir/element/Identifier.hpp"
#include "fhir/element/CodeableConcept.hpp"
#include "fhir/element/Reference.hpp"
#include "fhir/element/Period.hpp"
#include "fhir/element/Quantity.hpp"
#include "fhir/element/Range.hpp"
#include "fhir/element/SampledData.hpp"
#include "fhir/element/Attachment.hpp"

#include "fhir/datatypes/BackboneElement.hpp"
#include "fhir/backboneelement/observation/ReferenceRange.hpp"
#include "fhir/backboneelement/observation/Related.hpp"
#include "fhir/backboneelement/observation/Component.hpp"
#include "json.hpp"
#include "common/util.hpp"

using namespace LongBall::fhir::datatypes;
using namespace LongBall::fhir::datatypes::complex;
using namespace LongBall::fhir::element;
using namespace LongBall::fhir::backboneelement;
using namespace LongBall::fhir::backboneelement::observation;
using json = nlohmann::json;

namespace Util = LongBall::common::util;

namespace LongBall {
  namespace fhir {
    namespace backboneelement {

      template<>
      struct BackboneElement<ReferenceRange> {
        enum class Field {
          Low, High, Meaning, Age, Text
        };

        using FieldMap = const map<Field, const vector<json::json_pointer>>&;

        json operator()(const json& arr, FieldMap dict) const {
          json j;

          for (const auto& e : dict) {
            switch (e.first) {
            case Field::Low:
              j["low"] = Element<Quantity>()(arr, e.second);
              break;
            case Field::High:
              j["high"] = Element<Quantity>()(arr, e.second);
              break;
            case Field::Meaning:
              j["meaning"] = Element<CodeableConcept>()(arr, e.second);
              break;
            case Field::Age:
              j["age"] = Element<Range>()(arr, e.second);
              break;
            case Field::Text:
              j["text"] = firstOrEmptyString(arr, e.second);
              break;
            default:
              break;
            }
          }

          return j;
        }
      };

      template<>
      struct BackboneElement<Related> {
        enum class Field {
          Type, Target
        };

        using FieldMap = const map<Field, const vector<json::json_pointer>>&;

        json operator()(const json& arr, FieldMap dict) const {
          json j;

          for (const auto& e : dict) {
            switch (e.first) {
            case Field::Type:
              j["type"] = Element<Quantity>()(arr, e.second);
              break;
            case Field::Target:
              j["target"] = Element<Quantity>()(arr, e.second);
              break;            
            default:
              break;
            }
          }

          return j;
        }
      };

      template<>
      struct BackboneElement<Component> {
        enum class Field {
          Code, ValueQuantity, ValueCodeableConcept, ValueString, ValueRange, ValueSampledData, ValueAttachment, ValueTime, ValueDateTime, ValuePeriod, DataAbsentReason, ReferenceRange
        };

        using FieldMap = const map<Field, const vector<json::json_pointer>>&;
        
        json operator()(const json& arr, FieldMap dict) const {
          json j;

          for (const auto& e : dict) {
            switch (e.first) {
            case Field::Code:
              j["code"] = firstOrEmptyString(arr, e.second);
              break;
            case Field::ValueQuantity:
              j["valueQuantity"] = Element<Quantity>()(arr, e.second);
              break;
            case Field::ValueCodeableConcept:
              j["valueCodeableConcept"] = Element<CodeableConcept>()(arr, e.second);
              break;
            case Field::ValueString:
              j["valueString"] = firstOrEmptyString(arr, e.second);
              break;
            case Field::ValueRange:
              j["valueRange"] = Element<Range>()(arr, e.second);
              break;
            case Field::ValueSampledData:
              j["valueSampledData"] = Element<SampledData>()(arr, e.second);
              break;
            case Field::ValueAttachment:
              j["valueAttachment"] = Element<Attachment>()(arr, e.second);
              break;
            case Field::ValueTime:
              j["valueTime"] = firstOrDefault(arr, e.second);
              break;
            case Field::ValueDateTime:
              j["valueDateTime"] = firstOrDefault(arr, e.second);
              break;
            case Field::ValuePeriod:
              j["valuePeriod"] = Element<Period>()(arr, e.second);
              break;
            case Field::DataAbsentReason:
              j["dataAbsentReason"] = Element<CodeableConcept>()(arr, e.second);
              break;
            case Field::ReferenceRange:
              // User will have to populate this like: Observation.component.referenceRange = BackboneElement<ReferenceRange>(...) afterwards?
              j["referenceRange"] = ReferenceRange{}; 
              break;
            default:
              break;
            }
          }

          return j;
        }
      };

    }
  }
}
