#include <iostream>
#include <locale.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include "WeatherData.h"
#include "StatisticsDisplay.h"

int main() {

	WeatherData* weatherData = new WeatherData();
	CurrentConditionsDisplay* currentDisplay = new CurrentConditionsDisplay(weatherData);
	StatisticsDisplay* statDisplay = new StatisticsDisplay(weatherData);

	weatherData->setMeasurements(80, 65, 30.4);
	weatherData->setMeasurements(82, 70, 29.2);
	weatherData->setMeasurements(78, 90, 29.2);

	currentDisplay->display();
	statDisplay->display();

	delete statDisplay;
	delete currentDisplay;
	delete weatherData;
	return 0;
}
