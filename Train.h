#ifndef TRAIN_H
#define TRAIN_H

#include "Transporter_Interface.h"
#include "Cargo.h"

#include <iostream>
#include <vector>
#include <string>
#include <array>

template <typename T = std::string, typename N = float>
class Train : public Transporter<T, N>
{
private:
	std::vector<Cargo<T, N>*> cargo_vect; //might need to use array so people can be added aswell.
	std::string train_route[4] = { "train station: 1", "train station: 2", "train station: 3", "train station: 4" };
	int train_location = 0;
public:
	N getWeight()
	{
		N total_weight = 0;
		for (auto i : cargo_vect)
		{ 
			total_weight += i->getCargoWeight();
		}
		return total_weight;
	}

	void loadItem(T cargo_name, N cargo_weight) //for example parameter should be class that accesses name and weight and adds to array
	{
		cargo_vect.push_back(new Cargo<T, N>(cargo_name, cargo_weight));
	}

	void unloadItem() 
	{
		if (cargo_vect.size() > 0) { cargo_vect.erase(cargo_vect.begin()); }	
	}

	void emptyAllItems()
	{
		for (auto i : cargo_vect) { cargo_vect.clear(); }
	}

	void getTransporterInfo()
	{
		for (auto i : cargo_vect)
		{
			std::cout << i->getCargoName() << ", " << i->getCargoWeight() << " kilograms." << std::endl;
		}
	}

	int getItemCount()
	{
		return cargo_vect.size();
	}

	bool isEmpty()
	{
		if (cargo_vect.size() > 0) { return false; }
		else { return true; }
	}

	std::string & Move()
	{
		train_location = (train_location + 1) % (sizeof(train_route)/sizeof(train_route[0]));
		return train_route[train_location];
	}

};

#endif
