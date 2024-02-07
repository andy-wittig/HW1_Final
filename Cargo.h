#ifndef CARGO_H
#define CARGO_H

template <typename T, typename N>
class Cargo
{
private:
	T cargo_name;
	N cargo_weight;
public:
	Cargo(T cargoName, N cargoWeight) : cargo_name(cargoName), cargo_weight(cargoWeight) {}

	const T getCargoName() const
	{
		return cargo_name;
	}

	const N getCargoWeight() const
	{
		return cargo_weight;
	}
};

#endif