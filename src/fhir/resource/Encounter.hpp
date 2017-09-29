#pragma once

#include "json.hpp"
#include "fhir/datatypes/primitive.hpp"
#include "fhir/datatypes/complex/Identifier.hpp"
#include "fhir/datatypes/complex/Reference.hpp"
#include "fhir/datatypes/complex/Period.hpp"
#include "fhir/datatypes/complex/Quantity.hpp"
#include "fhir/backboneelement/encounter/StatusHistory.hpp"
#include "fhir/backboneelement/encounter/Participant.hpp"
#include "fhir/backboneelement/encounter/Hospitalization.hpp"
#include "fhir/backboneelement/encounter/Location.hpp"

using namespace std;
using namespace LongBall::fhir::datatypes::complex;
using namespace LongBall::fhir::backboneelement::encounter;

using json = nlohmann::json;
namespace Primitive = LongBall::fhir::datatypes::primitive;

namespace LongBall {
  namespace fhir {
    namespace resource {

      struct Encounter {
        Primitive::string resourceType = "Encounter";
        vector<Identifier> identifier;
        Primitive::code status;
        vector<StatusHistory> statusHistory;
        Primitive::code Class;
        vector<CodeableConcept> type;
        CodeableConcept priority;
        Reference patient;
        vector<Reference> episodeOfCare;
        vector<Reference> incomingReferral;
        vector<Participant> participant;
        Reference appointment;
        Period period;
        Quantity length;
        vector<CodeableConcept> reason;
        vector<Reference> indication;
        Hospitalization hospitalization;
        vector<Location> location;
        Reference serviceProvider;
        Reference partOf;
      };

      void to_json(json& j, const Encounter& p) {
        j = json{
          { "resourceType", p.resourceType },
          { "identifier", p.identifier },
          { "status", p.status },
          { "statusHistory", p.statusHistory },
          { "class", p.Class },
          { "type", p.type },
          { "priority", p.priority },
          { "patient", p.patient },
          { "episodeOfCare", p.episodeOfCare },
          { "incomingReferral", p.incomingReferral },
          { "participant", p.participant },
          { "appointment", p.appointment },
          { "period", p.period },
          { "length", p.length },
          { "reason", p.reason },
          { "indication", p.indication },
          { "hospitalization", p.hospitalization },
          { "location", p.location },
          { "serviceProvider", p.serviceProvider },
          { "partOf", p.partOf }
        };
      }

      void from_json(const json& j, Encounter& p) {
        p.resourceType = j.value("resourceType", "Encounter");
        for (const auto& e : j.value("identifier", json::array({}))) {
          p.identifier.emplace_back(e.get<Identifier>());
        }
        p.status = j.value("status", "");
        for (const auto& e : j.value("statusHistory", json::array({}))) {
          p.statusHistory.emplace_back(e.get<StatusHistory>());
        }
        p.Class = j.value("class", "");
        for (const auto& e : j.value("type", json::array({}))) {
          p.type.emplace_back(e.get<CodeableConcept>());
        }
        p.priority = j.value("priority", CodeableConcept{});
        p.patient = j.value("patient", Reference{});
        for (const auto& e : j.value("episodeOfCare", json::array({}))) {
          p.episodeOfCare.emplace_back(e.get<Reference>());
        }
        for (const auto& e : j.value("incomingReferral", json::array({}))) {
          p.incomingReferral.emplace_back(e.get<Reference>());
        }
        for (const auto& e : j.value("participant", json::array({}))) {
          p.participant.emplace_back(e.get<Participant>());
        }
        p.appointment = j.value("appointment", Reference{});
        p.period = j.value("period", Period{});
        p.length = j.value("length", Quantity{});
        for (const auto& e : j.value("reason", json::array({}))) {
          p.reason.emplace_back(e.get<CodeableConcept>());
        }
        for (const auto& e : j.value("indication", json::array({}))) {
          p.indication.emplace_back(e.get<Reference>());
        }
        p.hospitalization = j.value("hospitalization", Hospitalization{});
        for (const auto& e : j.value("location", json::array({}))) {
          p.location.emplace_back(e.get<Location>());
        }
        p.serviceProvider = j.value("serviceProvider", Reference{});
        p.partOf = j.value("partOf", Reference{});

      }

    }
  }
}
