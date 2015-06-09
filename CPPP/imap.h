#include <map>


namespace cppp
{
	template<class _Kty,
	class _Ty,
	class _Pr = std::less<_Kty>,
	class _Alloc = std::allocator<std::pair<const _Kty, _Ty> > >
	class IMap : public std::map < _Kty, _Ty, _Pr, _Alloc >
	{
	private:
		std::pair<const _Kty, _Ty> __atIndex(int index)
		{
			if (this->begin() == this->end())
				throw std::out_of_range("no node in map");
			
			for (iterator it = this->begin();;)
			{
				if (--index < 0)
					return *it;
				if (++it == this->end())
					it = this->begin();
			}
		}

		std::pair<const _Kty, _Ty> __atIndex_reverse(int index)
		{
			if (this->begin() == this->end())
				throw std::out_of_range("no node in map");

			index = -index - 1;
			for (reverse_iterator it = this->rbegin();;)
			{
				if (--index < 0)
					return *it;
				if (++it == this->rend())
					it = this->rbegin();
			}
		}

	public:
		std::pair<const _Kty, _Ty> atIndex(int index)
		{
			return (index < 0) ? __atIndex_reverse(index) : __atIndex(index);
		}
	};
}