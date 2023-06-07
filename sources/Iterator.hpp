 #pragma once

 namespace ariel
 {
    class Iterator
                {
                    public:
                        Iterator(const Iterator& other) = default;
                        Iterator() = default;
                        virtual ~Iterator() = default;
                        Iterator(Iterator&& other) = default;
                        Iterator& operator=(const Iterator& other) = default;
                        Iterator& operator=(Iterator&& other) = default;
                        virtual bool operator==(const Iterator &other) const = 0;
                        virtual bool operator!=(const Iterator &other) const = 0;
                        virtual bool operator<(const Iterator& other)const = 0;
                        virtual bool operator>(const Iterator& other)const = 0;
                };
 }
