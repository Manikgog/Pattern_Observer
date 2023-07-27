#ifndef _CURRENTCONDITIONSDISPLAY_H_
#define _CURRENTCONDITIONSDISPLAY_H_

#include <iostream>
#include "ISubject.h"
#include "IObserver.h"
#include "IDisplayElement.h"

class CurrentConditionsDisplay : public IObserver, public IDisplayElement
{
private:
	float temper_;
	float humid_;
	ISubject* weatherData_;

public:
	CurrentConditionsDisplay(ISubject* weatherData) : weatherData_(weatherData)
	{
		weatherData->registerObserver(this);
	}

	void update(float temper, float humid, float pressure)
	{
		this->temper_ = temper;
		this->humid_ = humid;
		display();
	}

	void display()
	{
		std::cout << "Current conditions: " << this->temper_ << " F degrees and " << humid_ << " % humidity\n";
	}


};


#endif // !
