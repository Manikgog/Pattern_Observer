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
	
	void registerObserver(IObserver* o) override
	{
		observers_.push_back(o);
	}

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

	void notifyObservers()
	{
		for (size_t i = 0; i < observers_.size(); i++)
		{
			observers_.at(i)->update(temperature_, humidity_, pressure_);
		}
	}

	void measurementsChanged()
	{
		notifyObservers();
	}

	void setMeasurements(float temperature, float humidity, float pressure)
	{
		this->temperature_ = temperature;
		this->humidity_ = humidity;
		this->pressure_ = pressure;
		measurementsChanged();
	}

};


#endif // !_WEATHERDATA_h_
