#pragma once
#include <vector>
#include <set>
#include "Iterator.hpp"
#include <stdexcept>
namespace ariel
{
    class MagicalContainer
    {
        private:

            std::set<int> my_elements;
            std::vector<const int *> ascending;
			std::vector<const int *> sidecross;
			std::vector<const int *> prime;

            static bool isPrime(int number)
            {
                if (number <= 1)
                {
		            return false;
                }
	
                for (int i = 2; i*i <= number; ++i)
                {
                    if (number % i == 0)
                    {
                        return false;
                    }
                }
                
                return true;
            }

        public:
            MagicalContainer(){}
            void addElement(int number);
            void removeElement(int number);
            size_t size() const;
           
            class AscendingIterator:public Iterator
            {
                private:
                    MagicalContainer& container;
                    size_t index;
                    AscendingIterator(MagicalContainer &container, size_t index):container(container), index(index){}

                public:
                    AscendingIterator(MagicalContainer& cont):container(cont), index(0){}
                    ~AscendingIterator()override = default;
                    AscendingIterator(const AscendingIterator &other);
                    AscendingIterator(AscendingIterator&& other) noexcept;
                    AscendingIterator& operator=(AscendingIterator&& other) noexcept;
  
                    int operator*() const;
                    bool operator==(const Iterator &other) const override;
                    bool operator!=(const Iterator &other) const override;
                    bool operator>(const Iterator& other)const override;
                    bool operator<(const Iterator& other)const override;
                    AscendingIterator& operator++()
                    {
                        if (index >= container.ascending.size())
                            {
                                throw std::runtime_error("out of range");
                            }
                                        
                        index++;
                        return *this;
                    }
            
                    AscendingIterator& operator=(const AscendingIterator& other)
                    {
                        if(this != &other)
                        {
                            if(&container != &other.container)
                            {
                                throw std::runtime_error("It is not possible to assign to another container");
                            }

                            index = other.index;
                        }

                        return *this;
                    }
                    AscendingIterator begin() const
                    {
                        return AscendingIterator(container, 0);
                    }
                    AscendingIterator end() const
                    {
                        return AscendingIterator(container, container.ascending.size());
                    }

                    bool operator==(const AscendingIterator &other) const;
				    bool operator!=(const AscendingIterator &other) const;
				    bool operator<(const AscendingIterator &other) const;				
				    bool operator>(const AscendingIterator &other) const;
            
            };

            class SideCrossIterator:public Iterator
            {
                private:

                    MagicalContainer& container;
                    size_t index;
                    SideCrossIterator(MagicalContainer &container, size_t index):container(container), index(index){}

                public:
                    SideCrossIterator(MagicalContainer& cont):container(cont), index(0){}
                    ~SideCrossIterator()override = default;
                    SideCrossIterator(const SideCrossIterator &other);
                    SideCrossIterator(SideCrossIterator&& other) noexcept;
                    SideCrossIterator& operator=(SideCrossIterator&& other) noexcept;
  
                    int operator*() const;
                    
                    SideCrossIterator& operator=(const SideCrossIterator& other)
                    {
                        if(this != &other)
                        {
                            if(&container != &other.container)
                            {
                                throw std::runtime_error("It is not possible to assign to another container");
                            }

                            index = other.index;
                        }

                        return *this;
                    }

                    bool operator==(const Iterator &other) const override;
                    bool operator!=(const Iterator &other) const override;
                    bool operator>(const Iterator& other)const override;
                    bool operator<(const Iterator& other)const override;
            
                    SideCrossIterator begin()const
                    {
                        return SideCrossIterator(container, 0);
                    }
                    SideCrossIterator end() const
                    {
                        return SideCrossIterator(container, container.sidecross.size());
                    }

                    SideCrossIterator& operator++()
                    {
                        if (index >= container.sidecross.size())
                            {
                                throw std::runtime_error("out of range");
                            }
                                        
                        index++;
                        return *this;
                    }
                    bool operator==(const SideCrossIterator &other) const;
				    bool operator!=(const SideCrossIterator &other) const;
				    bool operator<(const SideCrossIterator &other) const;				
				    bool operator>(const SideCrossIterator &other) const;
            };

            class PrimeIterator:public Iterator
            {
                private:

                    MagicalContainer& container;
                    size_t index;
                    PrimeIterator(MagicalContainer &container, size_t index):container(container), index(index){}

                public:

                    PrimeIterator(MagicalContainer& cont):container(cont), index(0){}
                    ~PrimeIterator()override = default;
                    PrimeIterator(const PrimeIterator &other);
                    PrimeIterator(PrimeIterator&& other) noexcept;
                    PrimeIterator& operator=(PrimeIterator&& other) noexcept;
  
                    int operator*() const;
                    bool operator==(const Iterator &other) const override;
                    bool operator!=(const Iterator &other) const override;
                    bool operator>(const Iterator& other)const override;
                    bool operator<(const Iterator& other)const override;
            
                    PrimeIterator& operator++()
                    {
                        if (index >= container.prime.size())
                            {
                                throw std::runtime_error("out of range");
                            }
                                        
                        index++;
                        return *this;
                    }

                    PrimeIterator& operator=(const PrimeIterator& other)
                    {
                        if(this != &other)
                        {
                            if(&container != &other.container)
                            {
                                throw std::runtime_error("It is not possible to assign to another container");
                            }

                            index = other.index;
                        }

                        return *this;
                    }
 
                    PrimeIterator begin() const
                    {
                        return PrimeIterator(container, 0);
                    }
                    PrimeIterator end() const
                    {
                        return PrimeIterator(container, container.prime.size());
                    }

                    bool operator==(const PrimeIterator &other) const;
				    bool operator!=(const PrimeIterator &other) const;
				    bool operator<(const PrimeIterator &other) const;				
				    bool operator>(const PrimeIterator &other) const;
                    
            };
    };
}
