﻿#ifndef _IOBSERVER_H_
#define _IOBSERVER_H_

/*!
\brief интерфейсный класс IObserver
*/
class IObserver
{
public:
	virtual void update(float temp, float hum, float pressure) {}
};




#endif // !_IOBSERVER_H_
