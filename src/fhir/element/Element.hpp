#pragma once

/*
  Order is important.  Identifier MUST go last or C2908.
  Identifier calls Element<CodeableConcept>, etc; so Element<CodeableConcept> must be specialized first.
*/

#include "fhir/datatypes/Element.hpp"
#include "fhir/element/CodeableConcept.hpp"
#include "fhir/element/Period.hpp"
#include "fhir/element/Quantity.hpp"
#include "fhir/element/Reference.hpp"
#include "fhir/element/Coding.hpp"
#include "fhir/element/Range.hpp"
#include "fhir/element/Ratio.hpp"
#include "fhir/element/SampledData.hpp"
#include "fhir/element/Attachment.hpp"
#include "fhir/element/Identifier.hpp"
