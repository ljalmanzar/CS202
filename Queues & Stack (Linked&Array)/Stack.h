#ifndef __STACK_H_
#define __STACK_H_
#include <iostream>

using namespace std;

template <typename T>
class Stack {
        public:
                Stack(int = 10);
                Stack(const Stack&);
                ~Stack();
                Stack<T>& operator=(const Stack&);
                bool push(T);
                bool pop(T&);
                bool empty() const;
                bool full() const;
                bool clear();
                void print() const;
        private:
                int max;
                int top;
                int actual; //only used in stack (stay) implementation
                T* data;
};

#endif
