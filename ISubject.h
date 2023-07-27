#ifndef _SUBJECT_H_
#define _SUBJECT_H_

#include "IObserver.h"

class ISubject
{
public:
	virtual void registerObserver(IObserver* o) = 0;
	virtual void removeObservers(IObserver* o) = 0;
	virtual void notifyObservers() = 0;
};


#endif