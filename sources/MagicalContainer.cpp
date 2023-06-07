#include <stdexcept>
#include <algorithm>
#include "MagicalContainer.hpp"
using namespace std;
using namespace ariel; 
 
void MagicalContainer::addElement(int number) {

    auto it = my_elements.insert(number);


    if(isPrime(number))
	{
		auto index_prime = lower_bound(prime.begin(), prime.end(), &(*it.first), [](const int *a, const int *b) {
		return *a < *b;});

        prime.insert(index_prime, &(*it.first));
    }

    auto index_ascending = lower_bound(ascending.begin(), ascending.end(), &(*it.first), [](const int *a, const int *b) {
	return *a < *b;});

    ascending.insert(index_ascending, &(*it.first));
	sidecross.clear();

    if(size() == 1)
    {
		sidecross.push_back(ascending.front());
        return;
    }

	for(size_t start = 0, end = size() - 1;start <= end && end != 0;end--, start++)
	{
		sidecross.push_back(ascending.at(start));

		if (start != end)
        {
			sidecross.push_back(ascending.at(end));
        }
    }
}

void MagicalContainer::removeElement(int number) {
    
    auto it = my_elements.find(number);

    if(it == my_elements.end())
    {
        throw runtime_error("the number not in the vector.");
    }

    if(isPrime(number))
	{
		auto index_prime = find(prime.begin(), prime.end(), &(*it));

        prime.erase(index_prime);
    }

    auto index_ascending = find(ascending.begin(), ascending.end(), &(*it));

    ascending.erase(index_ascending);

    my_elements.erase(number);
	sidecross.clear();

    if(size() == 1)
    {
		sidecross.push_back(ascending.front());
        return;
    }

	for(size_t start = 0, end = size() - 1;start <= end && end != 0;end--, start++)
	{
		sidecross.push_back(ascending.at(start));

		if (start != end)
        {
			sidecross.push_back(ascending.at(end));
        }
    }
}

size_t MagicalContainer::size() const
{
    return my_elements.size();
}


MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other):container(other.container), index(other.index){}

  
bool MagicalContainer::AscendingIterator::operator==(const Iterator &other) const 
{
    const AscendingIterator *other_iterator = dynamic_cast<const AscendingIterator*>(&other);

    if(!other_iterator)
    {
        throw std::runtime_error("The iterators must be of the same type");
    }

    if(&container != &other_iterator->container)
    {
        throw std::runtime_error("It is not possible to compare to another container");
    }

    return index == other_iterator->index;
}

bool MagicalContainer::AscendingIterator::operator!=(const Iterator &other) const
{
    const AscendingIterator *other_iterator = dynamic_cast<const AscendingIterator*>(&other);

    if(!other_iterator)
    {
        throw std::runtime_error("The iterators must be of the same type");
    }

    if(&container != &other_iterator->container)
    {
        throw std::runtime_error("It is not possible to compare to another container");
    }

    return index != other_iterator->index;
}

bool MagicalContainer::AscendingIterator::operator>(const Iterator& other)const 
{
    const AscendingIterator *other_iterator = dynamic_cast<const AscendingIterator*>(&other);

    if(!other_iterator)
    {
        throw std::runtime_error("The iterators must be of the same type");
    }

    if(&container != &other_iterator->container)
    {
        throw std::runtime_error("It is not possible to compare to another container");
    }

    return index > other_iterator->index;
}

bool MagicalContainer::AscendingIterator::operator<(const Iterator& other)const 
 {
    const AscendingIterator *other_iterator = dynamic_cast<const AscendingIterator*>(&other);

    if(!other_iterator)
    {
        throw std::runtime_error("The iterators must be of the same type");
    }

    if(&container != &other_iterator->container)
    {
        throw std::runtime_error("It is not possible to compare to another container");
    }

    return index < other_iterator->index;
}     
      
bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
{
        if(&container != &other.container)
    {
        throw std::runtime_error("It is not possible to compare to another container");
    }

    return index == other.index;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
{
        if(&container != &other.container)
    {
        throw std::runtime_error("It is not possible to compare to another container");
    }

    return index != other.index;
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const			
{
        if(&container != &other.container)
    {
        throw std::runtime_error("It is not possible to compare to another container");
    }

    return index < other.index;
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
{
        if(&container != &other.container)
    {
        throw std::runtime_error("It is not possible to compare to another container");
    }

    return index > other.index;
}


int MagicalContainer::AscendingIterator::operator*() const
{
    if (index > container.ascending.size())
		{
			throw std::out_of_range("Index out of range");
		}

	return *(container.ascending.at(index));
}



////////////////////////////////////////////////////////////////////////////////

            

MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other):container(other.container), index(other.index){}

bool MagicalContainer::SideCrossIterator::operator==(const Iterator &other) const
 {
    const SideCrossIterator *other_iterator = dynamic_cast<const SideCrossIterator*>(&other);

    if(!other_iterator)
    {
        throw std::runtime_error("The iterators must be of the same type");
    }

    if(&container != &other_iterator->container)
    {
        throw std::runtime_error("It is not possible to compare to another container");
    }

    return index == other_iterator->index;
}

bool MagicalContainer::SideCrossIterator::operator!=(const Iterator &other) const
 {
    const SideCrossIterator *other_iterator = dynamic_cast<const SideCrossIterator*>(&other);

    if(!other_iterator)
    {
        throw std::runtime_error("The iterators must be of the same type");
    }

    if(&container != &other_iterator->container)
    {
        throw std::runtime_error("It is not possible to compare to another container");
    }

    return index != other_iterator->index;
}

bool MagicalContainer::SideCrossIterator::operator>(const Iterator& other)const
 {
    const SideCrossIterator *other_iterator = dynamic_cast<const SideCrossIterator*>(&other);

    if(!other_iterator)
    {
        throw std::runtime_error("The iterators must be of the same type");
    }

    if(&container != &other_iterator->container)
    {
        throw std::runtime_error("It is not possible to compare to another container");
    }

    return index > other_iterator->index;
}

bool MagicalContainer::SideCrossIterator::operator<(const Iterator& other)const
 {
    const SideCrossIterator *other_iterator = dynamic_cast<const SideCrossIterator*>(&other);

    if(!other_iterator)
    {
        throw std::runtime_error("The iterators must be of the same type");
    }

    if(&container != &other_iterator->container)
    {
        throw std::runtime_error("It is not possible to compare to another container");
    }

    return index < other_iterator->index;
}            

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
{
    if(&container != &other.container)
    {
        throw runtime_error("It is not possible to compare to another container");
    }

    return index == other.index;
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
{
    if(&container != &other.container)
    {
        throw std::runtime_error("It is not possible to compare to another container");
    }

    return index != other.index;
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const			
{
    if(&container != &other.container)
    {
        throw std::runtime_error("It is not possible to compare to another container");
    }

    return index < other.index;
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
{
    if(&container != &other.container)
    {
        throw std::runtime_error("It is not possible to compare to another container");
    }

    return index > other.index;
}
  
int MagicalContainer::SideCrossIterator::operator*() const
{
    if (index > container.sidecross.size())
		{
			throw std::out_of_range("Index out of range");
		}

	return *(container.sidecross.at(index));
}

MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other):container(other.container), index(other.index){}
 
bool MagicalContainer::PrimeIterator::operator==(const Iterator &other) const
 {
    const PrimeIterator *other_iterator = dynamic_cast<const PrimeIterator*>(&other);

    if(!other_iterator)
    {
        throw std::runtime_error("The iterators must be of the same type");
    }

    if(&container != &other_iterator->container)
    {
        throw std::runtime_error("It is not possible to compare to another container");
    }

    return index == other_iterator->index;
} 

bool MagicalContainer::PrimeIterator::operator!=(const Iterator &other) const
 {
    const PrimeIterator *other_iterator = dynamic_cast<const PrimeIterator*>(&other);

    if(!other_iterator)
    {
        throw std::runtime_error("The iterators must be of the same type");
    }

    if(&container != &other_iterator->container)
    {
        throw std::runtime_error("It is not possible to compare to another container");
    }

    return index != other_iterator->index;
} 

bool MagicalContainer::PrimeIterator::operator>(const Iterator& other)const
 {
    const PrimeIterator *other_iterator = dynamic_cast<const PrimeIterator*>(&other);

    if(!other_iterator)
    {
        throw std::runtime_error("The iterators must be of the same type");
    }

    if(&container != &other_iterator->container)
    {
        throw std::runtime_error("It is not possible to compare to another container");
    }

    return index > other_iterator->index;
} 

bool MagicalContainer::PrimeIterator::operator<(const Iterator& other)const
 {
    const PrimeIterator *other_iterator = dynamic_cast<const PrimeIterator*>(&other);

    if(!other_iterator)
    {
        throw std::runtime_error("The iterators must be of the same type");
    }

    if(&container != &other_iterator->container)
    {
        throw std::runtime_error("It is not possible to compare to another container");
    }

    return index < other_iterator->index;
} 
            
bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
{
    if(&container != &other.container)
    {
        throw std::runtime_error("It is not possible to compare to another container");
    }

    return index == other.index;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
{
    if(&container != &other.container)
    {
        throw std::runtime_error("It is not possible to compare to another container");
    }

    return index != other.index;
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
{
    if(&container != &other.container)
    {
        throw std::runtime_error("It is not possible to compare to another container");
    }

    return index < other.index;
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
{
    if(&container != &other.container)
    {
        throw std::runtime_error("It is not possible to compare to another container");
    }

    return index > other.index;
}

int MagicalContainer::PrimeIterator::operator*() const
{
    if (index > container.prime.size())
		{
			throw std::out_of_range("Index out of range");
		}

	return *(container.prime.at(index));
}
//////////////////////////////////////////////////////////////////////////////////