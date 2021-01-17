/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mondrew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:16:13 by mondrew           #+#    #+#             */
/*   Updated: 2021/01/15 23:34:33 by mondrew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <cmath>
# include <stdexcept>

namespace ft
{
	template < typename T, typename A = std::allocator<T> >
	class vector {

		private:

			T		*_array;
			size_t	_size;
			size_t	_capacity;

		public:

			class iterator {

				private:

					T		*_ptr;
					T		*first;
					size_t	_size;

				public:

					// CONSTRUCTORS (4 kinds)
					// #1 default constructor
					iterator(void) : _ptr(0), _first(0), _size(0) { }
					// #2 parameterized constructor (for iterator init: begin, end, etc)
					iterator(T *ptr, T *first, size_t size) : _ptr(ptr), _first(first), _size(size) { }
					// #3 parameterized constructor
					iterator(vector<T, A> const &src) {

						this->_ptr = &src._array[0];
						this->_first = &src._array[0];
						this->_size = src._size();
					}
					// #4 copy constructor
					iterator(iterator const &src) {

						*this = src;
					}

					// DESTRUCTOR
					~iterator(void) { }

					iterator	&iterator=(iterator const &rhs) {

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

						this->_prt--;

						return (*this);
					}
					// Decrement postfix
					iterator	operator--(int) {

						iterator	tmp(*this);

						this->_ptr--;

						return (tmp);
					}

					// Addiction operator
					iterator	&operator+(size_t n) {

						this->_ptr += n;

						return (*this);
					}
					iterator	&operator+=(size_t n) {

						this->_ptr += n;

						return (*this);
					}
					// Substruction operator
					iterator	&operator-(size_t n) {

						this->_ptr -= n;

						return (*this);
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
					T		*first;
					size_t	_size;

				public:

					// CONSTRUCTORS (4 kinds)
					// #1 default constructor
					reverse_iterator(void) : _ptr(0), _first(0), _size(0) { }
					// #2 parameterized constructor (for iterator init: begin, end, etc)
					reverse_iterator(T *ptr, T *first, size_t size) : 
										_ptr(ptr), _first(first), _size(size) { }
					// #3 parameterized constructor
					reverse_iterator(vector<T, A> const &src) {

						this->_ptr = &src._array[src._size - 1];
						this->_first = &src._array[src._size - 1];
						this->_size = src._size;
					}
					// #4 copy constructor
					reverse_iterator(reverse_iterator const &src) {

						*this = src;
					}

					// DESTRUCTOR
					~reverse_iterator(void) { }

					// ASSIGNMENT OPERATION OVERLOAD
					reverse_iterator	&reverse_iterator=(reverse_iterator const &rhs) {

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

						iterator	tmp(*this);

						this->_ptr--;

						return (tmp);
					}
					// Decrement prefix
					reverse_iterator	&operator--(void) {

						this->_prt++;

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

			// MEMBER FUNCTIONS OF VECTOR CLASS

			// CONSTRUCTORS (4 kinds)
			// #1 default constructor (empty container with no elements)
			explicit vector<T, A>(void);
			// #2 fill constructor (n elements, each is a copy of val)
			explicit vector<T, A>(size_t n, T const &val);
			// #3 range constructor [first, last)
			vector<T>(vector<T, A>::iterator first, vector<T>::iterator last);
			// #4 copy constructor
			vector<T, A>(vector<T, A> const &src);

			// DESTRUCTOR
			~vector<T, A>(void);

			// ASSIGNMENT OPERATION OVERLOAD
			vector<T, A>		&operator=(vector<T, A> const &rhs);

			// ITERATORS
			iterator			begin(void) {

				return (iterator(&this->_array[0], &this->_array[0], this->_size));
			}
			iterator			end(void) {

				return (iterator(this->_array[this->_size - 1], this->_array[0], this->_size));
			}
			reverse_iterator	rbegin(void) {

				return (iterator(this->_array[this->_size - 1], this->_array[0], this->_size));
			}
			reverse_iterator	rend(void) {

				return (iterator(&this->_array[0], &this->_array[0], this->_size));
			}

			// CAPACITY
			size_t				size(void) {

				return (this->_size);
			}

			size_t				max_size(void) {

				int		arch;

				if (sizeof(void *) == 8)
					arch = 64;
				else (sizeof(void *) == 4)
					arch = 32;
				else
					arch = 16;

				return (pow(2, arch) / sizeof(T) - 1);
			}

			void				resize(size_t n, T val = 0) {

				int		i = 0;

				if (n == 0)
					return ;
				if (n > this->_capacity)
				{
					T	*tmp = new T[n];
					while (i < this->_capacity)
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
				else if (n < this->_capacity)
				{
					T	*tmp = new T[n];

					while (i < n)
					{
						tmp[i] = this->_array[i];
						i++;
					}
					if (this->_array)
						delete [] this->_array;
					this->_array = tmp;
					this->_size = n;
					this->_capacity = n;
				}
			}

			size_t				capacity(void) {

				return (this->_capacity);
			}

			bool				empty(void) {

				if (this->_size == 0)
					return (true);
				return (false);
			}

			void				reserve(size_t n) {

				if (n > this->_capacity)
				{
					T	*tmp = new T[n];
					while (i < this->_capacity)
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

			T const				&operator[](size_t n) {

				return (this->_array[n]);
			}

			T					&at(size_t n) {

				if (n >= this->_size)
					throw(std::out_of_range);
				return (this->_array[n]);
			}

			T const				&at(size_t n) {

				if (n >= this->_size)
					throw(std::out_of_range);
				return (this->_array[n]);
			}

			T					&front(void) {

				return (this->_array[0]);
			}

			T const				&front(void) {

				return (this->_array[0]);
			}

			T					&back(void) {

				return (this->_array[this->_size - 1]);
			}

			T const				&back(void) {

				return (this->_array[this->_size - 1]);
			}

			// MODIFIERS
			void				assign(iterator first, iterator last) {

				int		i = 0;
				int		new_size = last - first;

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
					int		new_capacity = this->_capacity * static_cast<int>(log(this->_capacity));
					T		*tmp = new T[new_capacity];

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
	};
}

#endif
