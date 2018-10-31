#pragma once

#include "GenericEvent.h"

class EventGenerator {

public:

	/*
	* Constructores y destructores
	*/
	EventGenerator(void) {};
	virtual ~EventGenerator(void) {};

	/*
	* getEvent
	* Devuelve un evento del generador o la fuente de eventos
	*/
	virtual GenericEvent * getEvent(void) = 0;
};