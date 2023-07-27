#ifndef _STATISTICSDISPLAY_H_
#define _STATISTICSDISPLAY_H_

#include <iostream>
#include <vector>
#include "ISubject.h"
#include "IObserver.h"
#include "IDisplayElement.h"

class StatisticsDisplay : public IObserver, public IDisplayElement
{
private:
	std::vector<float> avgtemperature_;
	std::vector<float> avghumidity_;
	ISubject* weatherData_;

	float CalculationOfAvg(std::vector<float> data)
	{
		float sum = 0.0f;
		for (const auto& el : data)
			sum += el;
		return sum / data.size();
	}

public:
	StatisticsDisplay(ISubject* weatherData) : weatherData_(weatherData)
	{
		weatherData->registerObserver(this);
	}

	void update(float temper, float humid, float pressure)
	{
		this->avgtemperature_.push_back(temper);
		this->avghumidity_.push_back(humid);
		display();
	}

	void display()
	{
		std::cout << "Average temperature: " << CalculationOfAvg(avgtemperature_) << " F degrees\n"
			<< "Average humidity: " << CalculationOfAvg(avghumidity_) << " %\n";
	}


};

#endif // !_STATISTICSDISPLAY_H_
