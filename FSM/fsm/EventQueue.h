#pragma once

#include "EventGenerator.h"
#include "GenericEvent.h"

#include <list>
#include <deque>

using namespace std;

/*
* EventQueue
* Administra los generadores de eventos para buscar eventos de los mismos
*/
class EventQueue {

public:

	/*
	* Constructores y destructores
	*/
	EventQueue(void);
	virtual ~EventQueue(void);

	/*
	* Devuelve el siguiente evento de la cola de eventos.
	*/
	GenericEvent* getNextEvent(void);

	/*
	* attach
	* Agrega a la lista de generadores uno de ellos.
	*/
	bool attach(EventGenerator* gen);

	/*
	* detach
	* Remueve de la lista de generadores a uno de ellos.
	*/
	bool detach(EventGenerator* gen);

private:

	deque<GenericEvent*> queue;
	list<EventGenerator*> generators;
};