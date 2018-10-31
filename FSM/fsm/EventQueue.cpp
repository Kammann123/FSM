#include "EventQueue.h"

EventQueue::EventQueue() {}

EventQueue::~EventQueue() {}

bool
EventQueue::attach(EventGenerator* gen) {

	try {

		this->generators.push_back(gen);
		return true;	
	}
	catch (...) {

		return false;
	}
}

bool
EventQueue::detach(EventGenerator* gen) {

	try {

		this->generators.remove(gen);
		return true;
	}
	catch (...) {

		return false;
	}
}

GenericEvent*
EventQueue::getNextEvent(void) {

	/* Actualizo la cola de eventos de cada una de las fuentes */
	for (EventGenerator* gen : generators) {

		/* Busco los eventos y los agrego */
		GenericEvent* newEvent = gen->getEvent();
		
		/* Si hubo algun evento lo agrego */
		if (newEvent != nullptr) {
			
			queue.push_back(newEvent);
		}
	}

	/* Busco y devuelvo algun evento */
	GenericEvent* retEvent = nullptr;
	if (!queue.empty()) {

		retEvent = queue.front();

		queue.pop_front();
	}

	return retEvent;
}