#ifndef TRANSPORTER_INTERFACE
#define TRANSPORTER_INTERFACE

#include <string>

template <typename T, typename N>
class Transporter
{
public:
	//Functions
	virtual void loadItem(T item_name, N item_weight) = 0;
	virtual void unloadItem() = 0;
	virtual void emptyAllItems() = 0;
	virtual void getTransporterInfo() = 0;
	virtual int getItemCount() = 0;
	virtual bool isEmpty() = 0;
	virtual std::string & Move() = 0;
};

#endif
