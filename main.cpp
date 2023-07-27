#include <iostream>
#include <locale.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include "WeatherData.h"
#include "StatisticsDisplay.h"

int main() {

	WeatherData* weatherData = new WeatherData();			//> создание указателя и выделение памяти на объект метеостанции
	CurrentConditionsDisplay* currentDisplay = new CurrentConditionsDisplay(weatherData);	//> создание указателя и выделение памяти на объект наблюдателя, который хранит последние полученные значения метеоданных
	
	StatisticsDisplay* statDisplay = new StatisticsDisplay(weatherData);					//> создание указателя и выделение памяти на объект наблюдателя, который хранит все метеоданные и выводит статистику
	

	weatherData->setMeasurements(80, 65, 30.4);		//> имитация получения данных с датчиков температуры, влажности и атмосферного давления
	weatherData->setMeasurements(82, 70, 29.2);
	weatherData->setMeasurements(78, 90, 29.2);

	weatherData->removeObservers(statDisplay);		//> удаления наблюдателя из списка

	delete statDisplay;
	delete currentDisplay;
	delete weatherData;
	return 0;
}
