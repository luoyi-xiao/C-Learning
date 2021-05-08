#include<iostream>
#include<vector>
//#include<vld.h>
using namespace std;


namespace bit
{
	template<class _Ty>
	class vector
	{
	public:
		typedef _Ty* iterator;
	public:
		vector()
			:_First(nullptr), _Last(nullptr), _End(nullptr)
		{}
		~vector()
		{
			delete _First;
			_First = _Last = _End = nullptr;
		}
	public:
		size_t size()const
		{
			return _Last - _First;
		}
		size_t capacity()const
		{
			return _End - _First;
		}
		iterator begin()
		{
			return _First;
		}
		iterator end()
		{
			return _Last;
		}
		void push_back(const _Ty& x)
		{
			insert(end(), x);
		}
	public:
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				//À©ÈÝ
				size_t old_size = size();
				_Ty* new_first = new _Ty[n];
				memcpy(new_first, _First, sizeof(_Ty) * old_size);

				delete[]_First;

				_First = new_first;
				_Last = _First + old_size;
				_End = _First + n;
			}
		}

		void resize(size_t n, const _Ty& x = _Ty())
		{
			if (n <= size())
			{
				_Last = _First + n;
				return;
			}

			if (n > capacity())
			{
				reserve(n);
			}

			iterator cur = _Last;
			_Last = _First + n;
			while (cur != _Last)
			{
				*cur = x;
				++cur;
			}
		}

		iterator insert(iterator _P, const _Ty& x)
		{
			if (_Last == _End)
			{
				size_t p_size = _P - _First;
				size_t new_size = size() == 0 ? 1 : size() * 2;
				reserve(new_size);
				//ÐÞ¸Ä_Pµü´úÆ÷
				_P = _First + p_size;
			}
			iterator end = _Last;
			while (end > _P)
			{
				*end = *(end - 1);
				--end;
			}

			*_P = x;
			++_Last;
			return _P;
		}
	private:
		iterator _First;
		iterator _Last;
		iterator _End;
	};
};

/*void main()
{
	bit::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	for (auto& e : v)
		cout << e << " ";
	cout << endl;

	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;

	v.resize(70, 9);

	for (auto& e : v)
		cout << e << " ";
	cout << endl;

	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;
}*/
int main()
{
	vector<int> v{ 1, 2, 3, 4 };
	auto it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
		{
			it = v.erase(it);
		}
		else
			++it;
	}
	return 0;
}