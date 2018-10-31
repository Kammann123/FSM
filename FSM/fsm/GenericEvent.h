#pragma once

using EventType = unsigned int;

/*
* GenericEvent
* Es un evento generico de la FSM. Clase base.
*/
class GenericEvent {

public:

	/*
	* Constructores y destructores
	*/
	GenericEvent(void);
	virtual ~GenericEvent(void);

	/*
	* Sobrecarga de operadores
	*/
	bool operator==(EventType ev);
	virtual bool const operator!(void) const;

	/*
	* getType
	* Devuelve el tipo de evento
	*/
	virtual EventType getType(void) = 0;
};