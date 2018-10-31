#include "GenericFsm.h"

#include <iostream>
#include <functional>

GenericFsm::
GenericFsm(const FsmCell* const _table, const unsigned int rows, const unsigned int columns, StateType initState) : table(_table), rowCount(rows), columnCount(columns) {

	state = initState;
	fsmEvent = nullptr;
}

GenericFsm::~GenericFsm() {}

GenericEvent*
GenericFsm::getEvent(void) {

	return this->fsmEvent;
}

void
GenericFsm::cycle(GenericEvent* event) {

	/* Verifico evento invalido */
	if (event != nullptr) {

		/* Recupero datos de accion y dato */
		FsmCell temp = table[static_cast<unsigned int>(state)*rowCount + static_cast<unsigned int>(event->getType())];
		auto f = bind(temp.action, this, event);

		/* Ejecuto rutina de accion */
		f();

		/* Muevo a siguiente estado de fsm */
		state = temp.nextState;
	}
}