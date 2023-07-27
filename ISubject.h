#ifndef _SUBJECT_H_
#define _SUBJECT_H_

#include "IObserver.h"

/*!
\brief интерфейс субьекта, используется объектами для регистрации в качестве наблюдателя, а также исключения из списка
*/
class ISubject
{
public:
	virtual void registerObserver(IObserver* o) = 0;	//> метод для добавления в список наблюдателей
	virtual void removeObservers(IObserver* o) = 0;		//> метод для удадения наблюдателя из списка
	virtual void notifyObservers() = 0;					//> метод для оповещения наблюдателей о появлении новых данных
};


#endif