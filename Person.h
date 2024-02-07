#ifndef PERSON_H
#define PERSON_H

template <typename T, typename N>
class Person
{
private:
	T person_name;
	N person_height;
public:
	Person(T personName, N personHeight) : person_name(personName), person_height(personHeight) {}

	const T getPersonName() const
	{
		return person_name;
	}

	const N getPersonHeight() const
	{
		return person_height;
	}
};

#endif



