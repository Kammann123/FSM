#pragma once

#include "EventQueue.h"

#define TX(fsm, action) (static_cast<void (GenericFsm::* )(GenericEvent *)>(&fsm::action))

class GenericFsm;

using StateType = unsigned int;


struct FsmCell {
	StateType nextState;
	void (GenericFsm::*action)(GenericEvent*);
};

class GenericFsm : public EventGenerator {

public:

	/*
	* Constructores y destructores
	*/
	GenericFsm(const FsmCell* const _table, const unsigned int rows, const unsigned int columns, StateType initState);
	~GenericFsm(void);

	/*
	* getEvent
	* Devuelve un evento generador por la fsm.
	*/
	virtual GenericEvent* getEvent(void);

	/*
	* cycle
	* Corre un ciclo de la fsm con el evento dado.
	*/
	void cycle(GenericEvent* event);

private:
	StateType state;
	GenericEvent* fsmEvent;

	const unsigned int rowCount;
	const unsigned int columnCount;
	const FsmCell* const table;
};