#include "GenericEvent.h"

GenericEvent::GenericEvent() {}

GenericEvent::~GenericEvent() {}

bool
GenericEvent::operator==(EventType ev) {

	return (this->getType() == ev);
}

bool const 
GenericEvent::operator!(void) const {

	return false;
}