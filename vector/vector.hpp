/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mondrew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:16:13 by mondrew           #+#    #+#             */
/*   Updated: 2021/01/21 15:41:43 by mondrew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <cmath>
# include <stdexcept>
# include <cstddef>
# include <iostream>

namespace ft
{
	template < typename T, typename A = std::allocator<T> >
	class vector {

		private:

			T		*_array;
			size_t	_size;
			size_t	_capacity;

		public:

			class iterator;

			// MEMBER FUNCTIONS OF VECTOR CLASS

			// CONSTRUCTORS (4 kinds)
			// #1 default constructor (empty container with no elements)
			explicit vector<T, A>(void) {

				this->_array = 0;
				this->_size = 0;
				this->_capacity = 0;

				return ;
			}
			// #2 fill constructor (n elements, each is a copy of val)
			explicit vector<T, A>(size_t n, T const &val) { // maybe not size_t

				size_t	i = 0;

				if (n == 0) // ??? // check original!
					return ;

				this->_array = new T[n];
				this->_size = n;
				this->_capacity = n;

				while (i < n)
				{
					this->_array[i] = val;
					i++;
				}
			}
			// #3 range constructor [first, last)
			vector<T, A>(vector<T, A>::iterator first, \
												vector<T, A>::iterator last) {

				size_t	i = 0;

				if (&(*last) <= &(*first)) // ???
					throw (std::bad_alloc{});

				size_t	n = static_cast<size_t>(&(*last) - &(*first));

				this->_array = new T[n];
				this->_size = n;
				this->_capacity = n;

				while (i < n)
				{
					this->_array[i] = *first;
					i++;
					first++;
				}
			}
			// #4 copy constructor
			vector<T, A>(vector<T, A> const &src) {

				*this = src;

				return ;
			}

			// DESTRUCTOR
			~vector<T, A>(void) {

				delete [] this->_array;

				return ;
			}

			// ASSIGNMENT OPERATION OVERLOAD
			vector<T, A>		&operator=(vector<T, A> const &rhs) {

				size_t	i = 0;

				if (rhs.getArray() == 0 || rhs.size() == 0)
				{
					this->_array = 0;
					this->_size = 0;
					this->_capacity = 0;
					return (*this);
				}

				this->_array = new T[rhs.capacity()];
				this->_size = rhs.size();
				this->_capacity = rhs.capacity();

				while (i < this->_size)
				{
					this->_array[i] = rhs.getArray()[i];
					i++;
				}

				return (*this);
			}

			class iterator {

				private:

					T		*_ptr;
					T		*_first;
					size_t	_size;

				public:

					// CONSTRUCTORS (4 kinds)
					// #1 default constructor
					iterator(void) : _ptr(0), _first(0), _size(0) { return ; }
					// #2 param constructor (for iterator init: begin, end, etc)
					iterator(T *ptr, T *first, size_t size) : 
							_ptr(ptr), _first(first), _size(size) { return ; }
					// #3 parameterized constructor
					iterator(vector<T, A> const &src) {

						this->_ptr = &src._array[0];
						this->_first = &src._array[0];
						this->_size = src._size();

						return ;
					}
					// #4 copy constructor
					iterator(iterator const &src) {

						*this = src;

						return ;
					}

					// DESTRUCTOR
					~iterator(void) { return ; }

					iterator	&operator=(iterator const &rhs) {

						this->_ptr = rhs._ptr;
						this->_first = rhs._first;
						this->_size = rhs._size;

						return (*this);
					}

					// Increment prefix
					iterator	&operator++(void) {

						this->_ptr++;

						return (*this);
					}
					// Increment postfix
					iterator	operator++(int) {

						iterator	tmp(*this);

						this->_ptr++;

						return (tmp);
					}
					// Decrement prefix
					iterator	&operator--(void) {

						this->_ptr--;

						return (*this);
					}
					// Decrement postfix
					iterator	operator--(int) {

						iterator	tmp(*this);

						this->_ptr--;

						return (tmp);
					}

					// Addiction operator
					iterator	operator+(size_t n) {

						iterator	tmp(*this);

						tmp._ptr += n;

						return (tmp);
					}
					iterator	&operator+=(size_t n) {

						this->_ptr += n;

						return (*this);
					}
					// Substruction operator
					iterator	operator-(size_t n) {

						iterator	tmp(*this);

						tmp._ptr -= n;

						return (tmp);
					}
					iterator	&operator-=(size_t n) {

						this->_ptr -= n;

						return (*this);
					}

					// Comparison operators
					bool		operator==(iterator const &rhs) {

						if (this->_ptr == rhs._ptr)
							return (true);
						return (false);
					}
					bool		operator!=(iterator const &rhs) {

						if (this->_ptr != rhs._ptr)
							return (true);
						return (false);
					}
					bool		operator<(iterator const &rhs) {

						if (this->_ptr < rhs._ptr)
							return (true);
						return (false);
					}
					bool		operator<=(iterator const &rhs) {

						if (this->_ptr <= rhs._ptr)
							return (true);
						return (false);
					}
					bool		operator>(iterator const &rhs) {

						if (this->_ptr > rhs._ptr)
							return (true);
						return (false);
					}
					bool		operator>=(iterator const &rhs) {

						if (this->_ptr >= rhs._ptr)
							return (true);
						return (false);
					}

					// Dereference operator
					T			&operator*(void) {

						return (*(this->_ptr));
					}

					// Offset dereference operator
					T			&operator[](size_t idx) {

						return (this->_first[idx]);
					}
			};

			class reverse_iterator {

				private:

					T		*_ptr;
					T		*_first;
					size_t	_size;

				public:

					// CONSTRUCTORS (4 kinds)
					// #1 default constructor
					reverse_iterator(void) : 
									_ptr(0), _first(0), _size(0) { return ; }
					// #2 param constructor (for iterator init: begin, end, etc)
					reverse_iterator(T *ptr, T *first, size_t size) : 
							_ptr(ptr), _first(first), _size(size) { return ; }
					// #3 parameterized constructor
					reverse_iterator(vector<T, A> const &src) {

						this->_ptr = &src._array[src._size - 1];
						this->_first = &src._array[src._size - 1];
						this->_size = src._size;

						return ;
					}
					// #4 copy constructor
					reverse_iterator(reverse_iterator const &src) {

						*this = src;

						return ;
					}

					// DESTRUCTOR
					~reverse_iterator(void) { return ; }

					// ASSIGNMENT OPERATION OVERLOAD
					reverse_iterator	&operator=(reverse_iterator const &rhs){

						this->_ptr = rhs._ptr;
						this->_first = rhs._first;
						this->_size = rhs._size;

						return (*this);
					}

					// Increment prefix
					reverse_iterator	&operator++(void) {

						this->_ptr--;

						return (*this);
					}
					// Increment postfix
					reverse_iterator	operator++(int) {

						reverse_iterator	tmp(*this);

						this->_ptr--;

						return (tmp);
					}
					// Decrement prefix
					reverse_iterator	&operator--(void) {

						this->_ptr++;

						return (*this);
					}
					// Decrement postfix
					reverse_iterator	operator--(int) {

						reverse_iterator	tmp(*this);

						this->_ptr++;

						return (tmp);
					}

					// Addiction operator
					reverse_iterator	&operator+(size_t n) {

						this->_ptr -= n;

						return (*this);
					}
					reverse_iterator	&operator+=(size_t n) {

						this->_ptr -= n;

						return (*this);
					}
					// Substruction operator
					reverse_iterator	&operator-(size_t n) {

						this->_ptr += n;

						return (*this);
					}
					reverse_iterator	&operator-=(size_t n) {

						this->_ptr += n;

						return (*this);
					}

					// Comparison operators
					bool		operator==(reverse_iterator const &rhs) {

						if (this->_ptr == rhs._ptr)
							return (true);
						return (false);
					}
					bool		operator!=(reverse_iterator const &rhs) {

						if (this->_ptr != rhs._ptr)
							return (true);
						return (false);
					}
					bool		operator<(reverse_iterator const &rhs) {

						if (this->_ptr < rhs._ptr)
							return (true);
						return (false);
					}
					bool		operator<=(reverse_iterator const &rhs) {

						if (this->_ptr <= rhs._ptr)
							return (true);
						return (false);
					}
					bool		operator>(reverse_iterator const &rhs) {

						if (this->_ptr > rhs._ptr)
							return (true);
						return (false);
					}
					bool		operator>=(reverse_iterator const &rhs) {

						if (this->_ptr >= rhs._ptr)
							return (true);
						return (false);
					}

					// Dereference operator
					T			&operator*(void) {

						return (*(this->_ptr));
					}

					// Offset dereference operator
					T			&operator[](size_t idx) {

						return (this->_first[this->_size - 1 - idx]);
					}
			};


			// ITERATORS
			iterator			begin(void) {

				return (iterator(&this->_array[0], &this->_array[0], \
																this->_size));
			}
			iterator			end(void) {

				return (iterator(&this->_array[this->_size], \
												&this->_array[0], this->_size));
			}
			reverse_iterator	rbegin(void) {

				return (reverse_iterator(&this->_array[this->_size - 1], \
												&this->_array[0], this->_size));
			}
			reverse_iterator	rend(void) {

				return (reverse_iterator(&this->_array[0] - 1, \
												&this->_array[0], this->_size));
			}

			// CAPACITY
			size_t				size(void) const {

				return (this->_size);
			}

			size_t				max_size(void) const {

				int		arch;

				if (sizeof(void *) == 8)
					arch = 64;
				else if (sizeof(void *) == 4)
					arch = 32;
				else
					arch = 16;

				return (pow(2, arch) / sizeof(T) - 1);
			}

			void				resize( size_t n, T val = T() ) {

				int		i = 0;

				if (n == 0)
					return ;
				if (n > this->_capacity)
				{
					T	*tmp = new T[n];
					while (i < this->_size)
					{
						tmp[i] = this->_array[i];
						i++;
					}
					while (i < n)
					{
						tmp[i] = val;
						i++;
					}
					if (this->_array)
						delete [] this->_array;
					this->_array = tmp;
					this->_size = n;
					this->_capacity = n;
				}
				else
				{
					if (n < this->_size)
					{
						i = n;
						while (i < this->_size)
						{
							this->_array[i].~T();
							i++;
						}
					}
					else
					{
						i = this->_size;
						while (i < n)
						{
							this->_array[i] = val;
							i++;
						}
					}
					this->_size = n;
				}
			}

			size_t				capacity(void) const {

				return (this->_capacity);
			}

			bool				empty(void) const {

				if (this->_size == 0)
					return (true);
				return (false);
			}

			void				reserve(size_t n) {

				int		i = 0;

				if (n > this->_capacity)
				{
					T	*tmp = new T[n];
					while (i < this->_size)
					{
						tmp[i] = this->_array[i];
						i++;
					}
					if (this->_array)
						delete [] this->_array;
					this->_array = tmp;
					this->_capacity = n;
				}
			}

			// ELEMENT ACCESS
			T					&operator[](size_t n) {

				return (this->_array[n]);
			}

			T const				&operator[](size_t n) const {

				return (this->_array[n]);
			}

			T					&at(size_t n) {

				if (n >= this->_size)
					throw (std::out_of_range("Out of range error"));
				return (this->_array[n]);
			}

			T const				&at(size_t n) const {

				if (n >= this->_size)
					throw (std::out_of_range("Out of range error"));
				return (this->_array[n]);
			}

			T					&front(void) {

				return (this->_array[0]);
			}

			T const				&front(void) const {

				return (this->_array[0]);
			}

			T					&back(void) {

				return (this->_array[this->_size - 1]);
			}

			T const				&back(void) const {

				return (this->_array[this->_size - 1]);
			}

			// MODIFIERS
			// Assign range
			void				assign(iterator first, iterator last) {

				int		i = 0;
				int		new_size = &(*last) - &(*first);

				if (&(*last) < &(*first))
					throw (std::bad_alloc{});

				if (new_size > this->_capacity)
				{
					if (this->_array)
						delete [] this->_array;
					T	*tmp = new T[new_size];
					while (i < new_size)
					{
						tmp[i] = *first;
						i++;
						first++;
					}
					this->_size = new_size;
					this->_capacity = new_size;
					this->_array = tmp;
				}
				else
				{
					while (i < new_size)
					{
						this->_array[i] = *first;
						i++;
						first++;
					}
					while (i < this->_size)
					{
						this->_array[i].~T();
						i++;
					}
					this->_size = new_size;
				}
			}

			// Assign fill
			void				assign(size_t n, T const &val) {

				int		i = 0;

				if (n > this->_capacity)
				{
					if (this->_array)
						delete [] this->_array;
					T	*tmp = new T[n];
					while (i < n)
					{
						tmp[i] = val;
						i++;
					}
					this->_size = n;
					this->_capacity = n;
					this->_array = tmp;
				}
				else
				{
					while (i < n)
					{
						this->_array[i] = val;
						i++;
					}
					while (i < this->_size)
					{
						this->_array[i].~T();
						i++;
					}
					this->_size = n;
				}
			}

			void				push_back(T const &val) {

				if (this->_size + 1 > this->_capacity)
				{
					int		i = 0;
					int		new_capacity;
					int		inc;
					T		*tmp;

					inc = this->_capacity + 1;
					if (inc == 1) // to protect from log(1)
						inc = 2;

					new_capacity = inc * \
									static_cast<int>(ceil(log(inc)));

					if (new_capacity <= 10) // high-level efficiency
						new_capacity *= 2;

					tmp = new T[new_capacity];

					while (i < this->_size)
					{
						tmp[i] = this->_array[i];
						i++;
					}
					tmp[i] = val;

					this->_size++;
					this->_capacity = new_capacity;
					if (this->_array)
						delete [] this->_array;
					this->_array = tmp;
				}
				else
				{
					this->_array[this->_size] = val;
					this->_size++;
				}
			}

			void				pop_back(void) {

				if (this->_size && this->_array)
				{
					this->_array[this->_size - 1].~T();
					this->_size--;
				}
			}

			// Insert #1 (single element)
			iterator			insert(iterator position, T const &val) {

				int			i = 0;
				int			j = 0;
				iterator	it = this->begin();
				iterator	ite = this->end();

				if (position < it || position > ite) // not original behaviour
					throw (std::out_of_range("Error: std::out_of_range"));

				if (this->_size + 1 > this->_capacity)
				{
					T	*big = new T[this->_size + 1];

					while (i < this->_size)
					{
						if (it != position)
						{
							big[j] = this->_array[i];
							i++;
						}
						else
							big[j] = val;
						j++;
						it++;
					}
					if (position == ite) // double protection
						big[j] = val;

					if (this->_array)
						delete [] this->_array;
					this->_array = big;
					this->_size++;
					this->_capacity = this->_size;
				}
				else
				{
					i = this->_size;
					while (i > 0)
					{
						if (ite != position)
							this->_array[i] = this->_array[i - 1];
						else
						{
							this->_array[i] = val;
							break ;
						}
						i--;
						ite--;
					}
					if (position == it)
						this->_array[i] = val;
					this->_size++;
				}

				return (position);
			}

			// Insert #2 fill
			void				insert(iterator position, size_t n, \
																T const &val) {

				int			i = 0;
				int			j = 0;
				int			k = 0;
				iterator	it = this->begin();
				iterator	ite = this->end();

				if (position < it || position > ite) // not original behaviour
					throw (std::out_of_range("Error: std::out_of_range"));

				if (this->_size + n > this->_capacity)
				{
					T	*big = new T[this->_size + n];

					while (i < this->_size)
					{
						if (it != position)
						{
							big[j] = this->_array[i];
							i++;
							j++;
						}
						else
						{
							while (k < n)
							{
								big[j] = val;
								k++;
								j++;
							}
						}
						it++;
					}
					if (position == ite) // double protection
					{
						while (k < n)
						{
							big[j] = val;
							k++;
							j++;
						}
					}

					if (this->_array)
						delete [] this->_array;
					this->_array = big;
					this->_size += n;
					this->_capacity = this->_size;
				}
				else
				{
					i = this->_size + n - 1; // start from the end
					j = this->_size - 1;
					while (j >= 0)
					{
						if (ite != position)
							this->_array[i] = this->_array[j];
						else
						{
							while (k < n)
							{
								this->_array[i] = val;
								i--;
								k++;
							}
						}
						i--;
						j--;
						ite--;
					}
					if (position == it)
					{
						while (k < n)
						{
							this->_array[i] = val;
							i--;
							k++;
						}
					}
					this->_size += n;
				}
			}

			// Insert #3 range
			void			insert(iterator position, iterator first, \
																iterator last) {

				int			i = 0;
				int			j = 0;
				int			k = 0;
				int			n = &(*last) - &(*first);
				iterator	it = this->begin();
				iterator	ite = this->end();

				if (position < it || position > ite || n < 0) // == ???
					throw (std::out_of_range("Error: std::out_of_range"));

				if (this->_size + n > this->_capacity)
				{
					T	*big = new T[this->_size + n];

					while (i < this->_size)
					{
						if (it != position)
						{
							big[j] = this->_array[i];
							i++;
							j++;
						}
						else
						{
							while (k < n)
							{
								big[j] = *first;
								k++;
								j++;
								first++;
							}
						}
						it++;
					}
					if (position == ite) // double protection
					{
						while (k < n)
						{
							big[j] = *first;
							k++;
							j++;
							first++;
						}
					}

					if (this->_array)
						delete [] this->_array;
					this->_array = big;
					this->_size += n;
					this->_capacity = this->_size;
				}
				else
				{
					i = this->_size + n - 1;
					j = this->_size - 1;
					while (j >= 0)
					{
						if (ite != position)
							this->_array[i] = this->_array[j];
						else
						{
							while (k < n)
							{
								this->_array[i] = *(last - 1);
								i--;
								k++;
								last--;
							}
						}
						i--;
						j--;
						ite--;
					}
					if (position == it)
					{
						while (k < n)
						{
							this->_array[i] = *(last - 1);
							i--;
							k++;
							last--;
						}
					}
					this->_size += n;
				}
			}

			// Erase #1 single
			iterator			erase(iterator position) {

				int			i = 0;
				iterator	it = this->begin();
				iterator	ite = this->end();

				if (position < it || position > ite) // not original behaviour
					throw (std::out_of_range("Error: std::out_of_range"));

				while (i < this->_size && it != position)
				{
					i++;
					it++;
				}

				while (i < this->_size - 1)
				{
					this->_array[i].~T();
					this->_array[i] = this->_array[i + 1];
					i++;
				}
				this->_array[i].~T();

				this->_size--;

				return (position);
			}

			// Erase #2 range
			iterator			erase(iterator first, iterator last) {

				int			i = 0;
				int			j;
				int			rem = &(*last) - &(*first);
				iterator	it = this->begin();
				iterator	ite = this->end();

				if (first < it || last > ite || rem < 0)
					throw (std::out_of_range("Error: std::out_of_range"));

				if (rem == 0)
					return (first);

				while (i < this->_size && it != first)
				{
					i++;
					it++;
				}
				j = i;
				while (i < this->_size && rem > 0)
				{
					this->_array[i].~T();
					rem--;
					i++;
				}

				while (i < this->_size)
				{
					this->_array[j] = this->_array[i];
					this->_array[i].~T();
					i++;
					j++;
				}

				this->_size -= &(*last) - &(*first);

				return (first);
			}

			// Swap
			void				swap(vector &x) {

				T		*tmp_array = this->_array;
				size_t	tmp_size = this->_size;
				size_t	tmp_capacity = this->_capacity;

				this->_array = x._array;
				x._array = tmp_array;

				this->_size = x._size;
				x._size = tmp_size;

				this->_capacity = x._capacity;
				x._capacity = tmp_capacity;
			}

			// Clear
			void				clear(void) {

				// A reallocation is not guaranteed to happen
				// Possible it means that values can stay the same in the memory
				// even though objects are deleted
				int		i = 0;

				while (i < this->_size)
				{
					this->_array[i].~T();
					i++;
				}
				if (this->_array)
					delete [] this->_array;
				this->_array = 0;

				this->_size = 0;
			}

			// Getters
			T			*getArray(void) const {

				return (this->_array);
			}

			// Setters
			void		setArray(T *array) {

				this->_array = array;
			}

			void		setSize(size_t size) {

				this->_size = size;
			}

			void		setCapacity(size_t capacity) {

				this->_capacity = capacity;
			}
	};
}

// NON-MEMBER FUNCTIONS OVERLOADS
// Relational operators

template < typename T, typename A = std::allocator<T> >
bool	operator==(const ft::vector<T, A> &lhs, const ft::vector<T, A> &rhs) {

	int		i = 0;

	if (lhs.size() != rhs.size())
		return (false);
	while (i < rhs.size())
	{
		if (lhs.getArray()[i] != rhs.getArray()[i])
			return (false);
		i++;
	}
	return (true);
}

template < typename T, typename A = std::allocator<T> >
bool	operator!=(const ft::vector<T, A> &lhs, const ft::vector<T, A> &rhs) {

	int		i = 0;

	if (lhs.size() != rhs.size())
		return (true);
	while (i < rhs.size())
	{
		if (lhs.getArray()[i] != rhs.getArray()[i])
			return (true);
		i++;
	}
	return (false);
}

template < typename T, typename A = std::allocator<T> >
bool	operator<(const ft::vector<T, A> &lhs, const ft::vector<T, A> &rhs) {

	int		i = 0;

	// Only elements counts! Not size and not capacity!
	while (i < lhs.size() || i < rhs.size())
	{
		if (lhs.getArray()[i] < rhs.getArray()[i])
			return (true);
		i++;
	}
	return (false);
}

template < typename T, typename A = std::allocator<T> >
bool	operator<=(const ft::vector<T, A> &lhs, const ft::vector<T, A> &rhs) {

	int		i = 0;

	// Only elements counts! Not size and not capacity!
	while (i < lhs.size() || i < rhs.size())
	{
		if (lhs.getArray()[i] <= rhs.getArray()[i])
			return (true);
		i++;
	}
	return (false);
}

template < typename T, typename A = std::allocator<T> >
bool	operator>(const ft::vector<T, A> &lhs, const ft::vector<T, A> &rhs) {

	int		i = 0;

	// Only elements counts! Not size and not capacity!
	while (i < lhs.size() || i < rhs.size())
	{
		if (lhs.getArray()[i] > rhs.getArray()[i])
			return (true);
		i++;
	}
	return (false);
}

template < typename T, typename A = std::allocator<T> >
bool	operator>=(const ft::vector<T, A> &lhs, const ft::vector<T, A> &rhs) {

	int		i = 0;

	// Only elements counts! Not size and not capacity!
	while (i < lhs.size() || i < rhs.size())
	{
		if (lhs.getArray()[i] >= rhs.getArray()[i])
			return (true);
		i++;
	}
	return (false);
}

// SWAP OVERLOAD

template < typename T, typename A = std::allocator<T> >
void			swap(ft::vector<T, A> &x, ft::vector<T, A> &y) {

	T		*tmp_array = x.getArray();
	size_t	tmp_size = x.size();
	size_t	tmp_capacity = x.capacity();

	x.setArray(y.getArray());
	y.setArray(tmp_array);

	x.setSize(y.getSize());
	y.setSize(tmp_size);

	x.setCapacity(y.getCapacity());
	y.setCapacity(tmp_capacity);
}

#endif
