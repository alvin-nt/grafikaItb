#ifndef SINGLETON_H_
#define SINGLETON_H_

#include <cstddef>

template <class T>
class Singleton
{
public:
    static T *instance() {
        if(_instance == NULL) {
            _instance = new T;
        }

        return _instance;
    }

	// call this when program is finished
	static void destroy() {
		delete _instance;
	}
protected:
    Singleton();
    ~Singleton();

private:
    Singleton(Singleton const&) = delete;
    Singleton& operator=(Singleton const&) = delete;

private:
    static T* _instance;
};

template <class T> T* Singleton<T>::_instance = NULL;

#endif // SINGLETON_H
