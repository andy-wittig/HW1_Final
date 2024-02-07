#include "Train.h"
#include "Bus.h"

int main()
{
	Train<> train; //template arguments default to <std::string, float>, specify if otherwise needed.
	Bus<> bus;

	std::cout << "Welcome to the transportation system of C++!" << std::endl;

	//Train Functions Demo
	std::cout << "All aboard the train!" << std::endl;
	train.loadItem("Steel Rods", 3.012f);
	train.loadItem("Wooden Logs", 100);
	train.loadItem("Coal Stack", 270.3f);
	train.loadItem("Hay Bale", 152);
	train.unloadItem();

	train.getTransporterInfo(); //function for demonstration purposes

	std::cout << "The total weight of the cargo onboard is: " << train.getWeight() << " kilograms." << std::endl;

	std::cout << "There are " << train.getItemCount() << " cargo items on board the train." << std::endl;

	if (train.isEmpty()) { std::cout << "There is nothing onboard the train." << std::endl; }
	else { std::cout << "There are items onboard the train." << std::endl; }

	train.emptyAllItems();
	std::cout << "All the items from the train have been cleared." << std::endl;

	std::cout << "There are " << train.getItemCount() << " cargo items on board the train." << std::endl;

	if (train.isEmpty()) { std::cout << "There is nothing onboard the train." << std::endl; }
	else { std::cout << "There are items onboard the train." << std::endl; }

	for (int i = 0; i < 4; i++) { std::cout << "The train has moved and is at " << train.Move() << std::endl; }

	std::cout << std::endl;

	//Bus Functions Demo
	std::cout << "All aboard the bus!" << std::endl;
	bus.loadItem("George", 4.15f);
	bus.loadItem("Lupe", 3);
	bus.loadItem("Ema", 1);
	bus.loadItem("Andy", 2);
	bus.unloadItem();

	bus.getTransporterInfo();

	bus.setFare(10.50f);
	std::cout << "Setting the new bus fare to $10.50" << std::endl;
	std::cout << "The total fare for all passengers onboard is: $" << bus.getTotalFare() << std::endl;

	std::cout << "There are " << bus.getItemCount() << " people on board the bus." << std::endl;

	if (bus.isEmpty()) { std::cout << "There are no people onboard the bus." << std::endl; }
	else { std::cout << "There are people onboard the bus." << std::endl; }

	bus.emptyAllItems();
	std::cout << "Everyone from the bus has been cleared off." << std::endl;

	std::cout << "There are " << bus.getItemCount() << " people on board the bus." << std::endl;

	if (bus.isEmpty()) { std::cout << "There are no people onboard the bus." << std::endl; }
	else { std::cout << "There are people onboard the bus." << std::endl; }

	for (int i = 0; i < 4; i++) { std::cout << "The bus has moved and is at " << bus.Move() << std::endl; }
};
