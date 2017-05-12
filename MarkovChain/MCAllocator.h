#include <memory>
#include <stdio.h>


template <typename T>
class MCAllocator : public std::allocator<T>
{
public:
	typedef size_t size_type;
	typedef T* pointer;
	typedef const T* const_pointer;

	template<typename _Tp1>
	struct rebind
	{
		typedef MCAllocator<_Tp1> other;
	};

	pointer allocate(size_type n, const void *hint = 0)
	{
		return std::allocator<T>::allocate(n, hint);
	}

	void deallocate(pointer p, size_type n)
	{
		return std::allocator<T>::deallocate(p, n);
	}

	MCAllocator() throw() : std::allocator<T>() { fprintf(stderr, "Hello allocator!\n"); }
	MCAllocator(const MCAllocator &a) throw() : std::allocator<T>(a) { }
	template <class U>
	MCAllocator(const MCAllocator<U> &a) throw() : std::allocator<T>(a) { }
	~MCAllocator() throw() { }
};