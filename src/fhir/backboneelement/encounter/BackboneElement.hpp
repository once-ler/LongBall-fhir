#pragma once

// #include "fhir/element/Element.hpp"
#include "fhir/element/Identifier.hpp"
#include "fhir/element/CodeableConcept.hpp"
#include "fhir/element/Reference.hpp"
#include "fhir/element/Period.hpp"
#include "fhir/element/Quantity.hpp"

#include "fhir/datatypes/BackboneElement.hpp"
#include "fhir/backboneelement/encounter/Hospitalization.hpp"
#include "fhir/backboneelement/encounter/StatusHistory.hpp"
#include "fhir/backboneelement/encounter/Location.hpp"
#include "fhir/backboneelement/encounter/Participant.hpp"
#include "json.hpp"
#include "common/util.hpp"

using namespace LongBall::fhir::datatypes;
using namespace LongBall::fhir::datatypes::complex;
using namespace LongBall::fhir::element;
using namespace LongBall::fhir::backboneelement;
using json = nlohmann::json;

namespace Util = LongBall::common::util;

namespace LongBall {
  namespace fhir {
    namespace backboneelement {

      template<>
      struct BackboneElement<encounter::Hospitalization> {
        enum class Field{
          PreAdmissionIdentifier, Origin, AdmitSource, AdmittingDiagnosis, ReAdmission, DietPreference, SpecialCourtesy, SpecialArrangement, Destination, DischargeDisposition, DischargeDiagnosis
        };
        
        using FieldMap = const map<Field, const vector<json::json_pointer>>&;

        json operator()(const json& arr, FieldMap dict) const {

          json j;
          
          for (const auto& e : dict) {
            switch (e.first) {
              case Field::PreAdmissionIdentifier:
                j["preAdmissionIdentifier"] = Element<Identifier>()(arr, e.second);
                break;
              case Field::Origin:
                j["origin"] = Element<Reference>()(arr, e.second);
                break;
              case Field::AdmitSource:
                j["admitSource"] = Element<CodeableConcept>()(arr, e.second);
                break;
              case Field::AdmittingDiagnosis:
                j["admittingDiagnosis"] = Element<Reference>()(arr, e.second);
                break;
              case Field::ReAdmission:
                j["reAdmission"] = Element<CodeableConcept>()(arr, e.second);
                break;
              case Field::DietPreference:
                j["dietPreference"] = Element<CodeableConcept>()(arr, e.second);
                break;
              case Field::SpecialCourtesy:
                j["specialCourtesy"] = Element<CodeableConcept>()(arr, e.second);
                break;
              case Field::SpecialArrangement:
                j["specialArrangement"] = Element<CodeableConcept>()(arr, e.second);
                break;
              case Field::Destination:
                j["destination"] = Element<Reference>()(arr, e.second);
                break;
              case Field::DischargeDisposition:
                j["dischargeDisposition"] = Element<CodeableConcept>()(arr, e.second);
                break;
              case Field::DischargeDiagnosis:
                j["dischargeDiagnosis"] = Element<Reference>()(arr, e.second);
                break;
              default:
                break;
            }
          }

          return j;
        }
      };

      template<>
      struct BackboneElement<encounter::StatusHistory> {
        enum class Field{
          Status, History
        };
        
        using FieldMap = const map<Field, const vector<json::json_pointer>>&;

        json operator()(const json& arr, FieldMap dict) const {          
          json j;

          for (const auto& e : dict) {
            switch (static_cast<Field>(e.first)) {
              case Field::Status:
                j["status"] = firstOrEmptyString(arr, e.second);
                break;
              case Field::History:
                j["history"] = Element<Period>()(arr, e.second);
                break;
                default:
                break;
            }
          }
          return j;
        }
      };

      template<>
      struct BackboneElement<encounter::Location> {
        enum class Field {
          Location, Status, Period
        };

        using FieldMap = const map<Field, const vector<json::json_pointer>>&;

        json operator()(const json& arr, FieldMap dict) const {
          json j;

          for (const auto& e : dict) {
            switch (static_cast<Field>(e.first)) {
            case Field::Location:
              j["location"] = Element<Reference>()(arr, e.second);
              break;
            case Field::Status:
              j["status"] = firstOrEmptyString(arr, e.second);
              break;
            case Field::Period:
              j["period"] = Element<Period>()(arr, e.second);
              break;
            default:
              break;
            }
          }
          return j;
        }
      };

      template<>
      struct BackboneElement<encounter::Participant> {
        enum class Field {
          Type, Period, Individual
        };

        using FieldMap = const map<Field, const vector<json::json_pointer>>&;

        json operator()(const json& arr, FieldMap dict) const {
          json j;

          for (const auto& e : dict) {
            switch (static_cast<Field>(e.first)) {
            case Field::Type:
              j["type"] = Element<CodeableConcept>()(arr, e.second);
              break;
            case Field::Period:
              j["period"] = Element<Period>()(arr, e.second);
              break;
            case Field::Individual:
              j["individual"] = Element<Reference>()(arr, e.second);
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
