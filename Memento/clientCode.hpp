#pragma once
#include "CareTaker.hpp"

void clientCode() {
    Originator *originator = new Originator("Super-duper-super-puper-super.");
    CareTaker *caretaker = new CareTaker(originator);
    caretaker->backup();
    originator->changeSatate();
    caretaker->backup();
    originator->changeSatate();
    caretaker->backup();
    originator->changeSatate();
    std::cout << "\n";
    caretaker->showHistory();
    std::cout << "\nClient: Now, let's rollback!\n\n";
    caretaker->undo();
    std::cout << "\nClient: Once more!\n\n";
    caretaker->undo();

    delete originator;
    delete caretaker;
}