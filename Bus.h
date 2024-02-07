#ifndef BUS_H
#define BUS_H

#include "Transporter_Interface.h"
#include "Person.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <array>

template <typename T = std::string, typename N = float>
class Bus : public Transporter<T, N>
{
private:
	std::vector<Person<T, N>*> person_vect;
	std::string bus_route[4] = { "bus stop: 1", "bus stop: 2", "bus stop: 3", "bus stop: 4" };
	int bus_location = 0;
	float fare = 5.0f;
public:
	struct compareHeight
	{
		bool operator()(const Person<T, N>* p1, const Person<T, N>* p2) const
		{
			return p1->getPersonHeight() < p2->getPersonHeight();
		}
	};

	void loadItem(T person_name, N person_height)
	{
		person_vect.push_back(new Person<T, N>(person_name, person_height));
		std::sort(person_vect.begin(), person_vect.end(), compareHeight());
	}

	void unloadItem()
	{
		if (person_vect.size() > 0) { person_vect.erase(person_vect.begin()); }
	}

	void emptyAllItems()
	{
		for (auto i : person_vect) { person_vect.clear(); }
	}

	void getTransporterInfo()
	{
		for (auto i : person_vect)
		{
			std::cout << i->getPersonName() << ", " << i->getPersonHeight() << " meters." << std::endl;
		}
	}

	int getItemCount()
	{
		return person_vect.size();
	}

	bool isEmpty()
	{
		if (person_vect.size() > 0) { return false; }
		else { return true; }
	}

	std::string & Move()
	{
		bus_location = (bus_location + 1) % (sizeof(bus_route) / sizeof(bus_route[0]));
		return bus_route[bus_location];
	}

	float getTotalFare()
	{
		float total_fare = 0;
		for (int i = 0; i < person_vect.size(); i++)
		{
			total_fare += fare;
		}
		return total_fare;
	}

	void setFare(float new_fare)
	{
		fare = new_fare;
	}
};

#endif
