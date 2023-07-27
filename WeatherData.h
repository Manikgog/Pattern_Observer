#ifndef _WEATHERDATA_h_
#define _WEATHERDATA_h_

#include <vector>
#include "ISubject.h"
#include "IObserver.h"
#include "CurrentConditionsDisplay.h"

class WeatherData : public ISubject
{
private:
	std::vector<IObserver*> observers_;
	float temperature_;
	float humidity_;
	float pressure_;

public:
	WeatherData() : temperature_(0.0f), humidity_(0.0f), pressure_(0.0f) {}
	
	/*!
	\brief метод для добавления новых наблюдателей для оповещения
	\param[in] o - указатель на объект класса IObserver, который добавляется в вектор наблюдателей
	*/
	void registerObserver(IObserver* o) override
	{
		observers_.push_back(o);
	}

	/*!
	\brief метод для удаления наблюдателя из вектора
	\param[in] o - указатель на объект класса IObserver
	*/
	void removeObservers(IObserver* o) override
	{
		for (size_t i = 0; i < observers_.size(); i++)
		{
			if (observers_.at(i) == o)
			{
				observers_.erase(observers_.begin() + i);
				return;
			}
		}
		return;
	}
	
	/*!
	\brief метод для оповещения наблюдателей о появлении новых данных
	*/
	void notifyObservers()
	{
		for (size_t i = 0; i < observers_.size(); i++)
		{
			observers_.at(i)->update(temperature_, humidity_, pressure_);
		}
	}

	/*!
	\brief метод для вызова метода для оповещения наблюдателей о появлении новых данных
	*/
	void measurementsChanged()
	{
		notifyObservers();
	}

	/*!
	\brief метод для имитации чтения данных с датчиков температуры, влажности и атмосферного давления
	\param[in] temperature - температура,  humidity - влажность,  pressure - давление
	*/
	void setMeasurements(float temperature, float humidity, float pressure)
	{
		this->temperature_ = temperature;
		this->humidity_ = humidity;
		this->pressure_ = pressure;
		measurementsChanged();
	}

};


#endif // !_WEATHERDATA_h_
