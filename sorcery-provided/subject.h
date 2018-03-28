#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>

class Subject {
public:
    virtual void attach(int player, TriggerObserver observer) = 0;
    virtual void detach(int player, TriggerObserver observer) = 0;
//    virtual void notify(bool isYourTurn, enum phase) = 0;
};


#endif //SUBJECT_H
