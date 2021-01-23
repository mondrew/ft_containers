/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mondrew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 20:54:31 by mondrew           #+#    #+#             */
/*   Updated: 2021/01/23 14:18:33 by mondrew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

// 1. end() дает элемент, следующий за последним, но после него - снова первый!
// 2. Если добавить в пустой лист элемент пустого листа - то он добавится, т.к.
// дефолтный конструктор создает нулевой элемент (val = 0)
// 3. Учесть в ++ и -- итератора зацикленность списка

namespace ft
{
	template < typename T, typename A = std::allocator<T> >
	class list {

		private:

			typedef struct		s_list
			{
				T				val;
				struct s_list	*prev;
				struct s_list	*next;

			}					t_list;

			t_list				*_head;
			size_t				_size;

		public:

			class iterator;

			// CONSTRUCTORS
			// #1 Default constructor
			explicit list<T, A>(void) {

				this->_head = new t_list;

				this->_head->val = 0;
				this->_head->prev = 0;
				this->_head->next = 0;

				this->_size = 0;
			}

			// #2 Fill constructor
			explicit list<T, A>(size_t n, T const &val) {

				int		i = 0;
				t_list	*tmp;

				// Create null-element
				this->_head = new t_list;
				this->_head->val = 0;
				this->_head->prev = 0;
				this->_head->next = 0;
				this->_size = 0;

				if (n == 0)
					return ;

				// Create first element
				tmp = new t_list;
				tmp->val = val;
				tmp->prev = 0;
				tmp->next = this->_head;
				this->_head->prev = tmp;
				this->_head = tmp;
				this->_size++;
				i++;

				// Create other elements if any
				while (i < n)
				{
					tmp = new t_list;
					tmp->val = val;
					tmp->prev = 0;
					tmp->next = this->_head;
					this->_head->prev = tmp;
					this->_head = tmp;
					this->_size++;
					i++;
				}
				// Link head and null-tail
				tmp = this->_head;
				while (tmp->next != 0)
					tmp = tmp->next;
				tmp->next = this->_head;
				this->_head->prev = tmp;
			}

			// #3 Range constructor
			list(iterator first, iterator last) {

				int		i = 0;
				int		n = &(*first) - &(*last);
				t_list	*tmp;
				t_list	*tail;

				if (n < 0)
					throw (std::bad_alloc {});

				// Create null-element
				this->_head = new t_list;
				this->_head->val = 0;
				this->_head->prev = 0;
				this->_head->next = 0;
				this->_size = 0;

				if (n == 0)
					return ;

				tail = this->_head;

				// Create first element
				tmp = new t_list;
				tmp->val = *first;
				tmp->prev = 0;
				tmp->next = this->_head;
				this->_head->prev = tmp;
				this->_head = tmp;
				this->_size++;
				first++;
				i++;

				// Create other elements if any
				while (i < n)
				{
					tmp = new t_list;
					tmp->val = *first;
					tmp->prev = tail->prev;
					tmp->next = tail;

					(tail->prev)->next = tmp;
					tail->prev = tmp;

					this->_size++;
					i++;
				}
				// Link head and null-tail
				tail->next = this->_head;
				this->_head->prev = tail;
				return ;
			}

			// #4 Copy constructor
			list(list const &src) {

				*this = src;
				return ;
			}

			// DESTRUCTOR
			~list(void) {

				t_list	*tmp;

				while (this->_head)
				{
					tmp = this->_head->next;
					delete this->_head;
					this->_head = 0;
					this->_head = tmp;
				}
				return ;
			}

			// Assignment operation overload
			list<T, A>		operator=(list<T, A> const &rhs) {

				int		i = 0;
				int		n = rhs.size();
				t_list	*tmp;
				t_list	*from = rhs._head;
				t_list	*tail;

				// Create null-element
				this->_head = new t_list;
				this->_head->val = 0;
				this->_head->prev = 0;
				this->_head->next = 0;
				this->_size = 0;

				if (rhs.size() == 0)
					return (*this);

				tail = this->_head;

				// Create first element
				tmp = new t_list;
				tmp->val = from->val;
				tmp->prev = 0;
				tmp->next = this->_head;
				this->_head->prev = tmp;
				this->_head = tmp;
				this->_size++;
				from = from->next;
				i++;

				// Create other elements if any
				while (i < n)
				{
					tmp = new t_list;
					tmp->val = from_val;
					tmp->prev = tail->prev;
					tmp->next = tail;

					(tail->prev)->next = tmp;
					tail->prev = tmp;

					this->_size++;
					i++;
				}
				// Link head and null-tail
				tail->next = this->_head;
				this->_head->prev = tail;
				return (*this);
			}

			// ITERATORS
			// Simple iterator
			class iterator {

				private:

					t_list		*_node;
					t_list		*_head;
					size_t		_size;

				public:

					// CONSTRUCTORS
					// #1 default constructor
					iterator(void) : _node(0), _head(0), _size(0) { return ; }
					// #2 param constructor (for iterator init: begin, end, etc)
					iterator(t_list *node, t_list *head, size_t size) : 
								_node(node), _head(head), _size(size) { return ; }
					// #3 Parameterized constructor
					iterator(list<T, A> const &src) {

						this->_node = src.getHead();
						this->_head = src.getHead();
						this->_size = src.size();

						return ;
					}

					// #4 Copy constructor
					iterator(iterator const &src) {

						*this = src;
					}

					// DESTRUCTOR
					~iterator(void) { return ; }

					iterator	&operator=(iterator const &rhs) {

						this->_node = rhs._node;
						this->_head = rhs._head;
						this->_size = rhs._size;

						return (*this);
					}

					// Increment prefix
					iterator	&operator++(void) {

						this->_node = this->_node->next;

						return (*this);
					}

					// Increment postfix
					iterator	operator++(int) {

						iterator	tmp(*this);

						this->_node = this->_node->next;

						return (tmp);
					}

					// Decrement prefix
					iterator	&operator--(void) {

						this->_node = this->_node->prev;

						return (*this);
					}

					// Decrement postfix
					iterator	operator--(int) {

						iterator	tmp(*this);

						this->_node = this->_node->prev;
						return (tmp);
					}

					// Addiction operator
					iterator	operator+(size_t n) {

						int			i = 0;
						iterator	tmp(*this);

						while (i < n)
						{
							tmp->_node = tmp->_node->next;
							i++;
						}
						return (tmp);
					}

					iterator	&operator+=(size_t n) {

						int		i = 0;

						while (i < n)
						{
							this->_node = this->_node->next;
							i++;
						}
						return (*this);
					}

					// Substruction operator
					iterator	operator-(size_t n) {

						int			i = 0;
						iterator	tmp(*this);

						while (i < n)
						{
							tmp->_node = tmp->_node->prev;
							i++;
						}
						return (tmp);
					}

					iterator	&operator-=(size_t n) {

						int			i = 0;

						while (i < n)
						{
							this->_node = this->_node->prev;
							i++;
						}
						return (*this);
					}

					// Comparison operators
					bool		operator==(iterator const &rhs) {

						return (this->_node == rhs._node);
					}

					bool		operator!=(iterator const &rhs) {

						return (this->_node != rhs._node);
					}

					bool		operator<(iterator const &rhs) {

						return (this->_node < rhs._node);
					}

					bool		operator<=(iterator const &rhs) {

						return (this->_node <= rhs._node);
					}

					bool		operator>(iterator const &rhs) {

						return (this->_node > rhs._node);
					}

					bool		operator>=(iterator const &rhs) {

						return (this->_node >= rhs._node);
					}

					// Dereference operator
					T			&operator*(void) {

						return (this->_node->val);
					}

					T			&operator*++(void) {

						iterator	*tmp(*this);

						this->_node = this->_node->next;

						return (tmp->val);
					}

					T			&operator*--(void) {

						iterator	*tmp(*this);

						this->_node = this->_node->prev;

						return (tmp->val);
					}
			};

			// Reverse iterator
			class reverse_iterator {

				private:

					t_list		*_node;
					t_list		*_head;
					size_t		_size;

				public:

					// CONSTRUCTORS
					// #1 default constructor
					reverse_iterator(void) : _node(0), _head(0), _size(0) { return ; }
					// #2 param constructor (for iterator init: begin, end, etc)
					reverse_iterator(t_list *node, t_list *head, size_t size) : 
								_node(node), _head(head), _size(size) { return ; }
					// #3 Parameterized constructor
					reverse_iterator(list<T, A> const &src) {

						if (src.getHead()->prev == 0)
						{
							this->_node = src.getHead();
							this->_head = src.getHead();
							this->_size = src.size();

							return ;
						}

						this->_node = src.getHead()->prev->prev;
						this->_head = src.getHead()->prev->prev;
						this->_size = src.size();

						return ;
					}

					// #4 Copy constructor
					reverse_iterator(reverse_iterator const &src) {

						*this = src;
					}

					// DESTRUCTOR
					~reverse_iterator(void) { return ; }

					reverse_iterator	&operator=(reverse_iterator const &rhs) {

						this->_node = rhs._node;
						this->_head = rhs._head;
						this->_size = rhs._size;

						return (*this);
					}

					// Increment prefix
					reverse_iterator	&operator++(void) {

						this->_node = this->_node->prev;

						return (*this);
					}

					// Increment postfix
					reverse_iterator	operator++(int) {

						reverse_iterator	tmp(*this);

						this->_node = this->_node->prev;

						return (tmp);
					}

					// Decrement prefix
					reverse_iterator	&operator--(void) {

						this->_node = this->_node->next;

						return (*this);
					}

					// Decrement postfix
					reverse_iterator	operator--(int) {

						reverse_iterator	tmp(*this);

						this->_node = this->_node->next;
						return (tmp);
					}

					// Addiction operator
					reverse_iterator	operator+(size_t n) {

						int			i = 0;
						reverse_iterator	tmp(*this);

						while (i < n)
						{
							tmp->_node = tmp->_node->prev;
							i++;
						}
						return (tmp);
					}

					reverse_iterator	&operator+=(size_t n) {

						int		i = 0;

						while (i < n)
						{
							this->_node = this->_node->prev;
							i++;
						}
						return (*this);
					}

					// Substruction operator
					reverse_iterator	operator-(size_t n) {

						int			i = 0;
						reverse_iterator	tmp(*this);

						while (i < n)
						{
							tmp->_node = tmp->_node->next;
							i++;
						}
						return (tmp);
					}

					reverse_iterator	&operator-=(size_t n) {

						int			i = 0;

						while (i < n)
						{
							this->_node = this->_node->next;
							i++;
						}
						return (*this);
					}

					// Comparison operators
					bool		operator==(reverse_iterator const &rhs) {

						return (this->_node == rhs._node);
					}

					bool		operator!=(reverse_iterator const &rhs) {

						return (this->_node != rhs._node);
					}

					bool		operator<(reverse_iterator const &rhs) {

						return (this->_node < rhs._node);
					}

					bool		operator<=(reverse_iterator const &rhs) {

						return (this->_node <= rhs._node);
					}

					bool		operator>(reverse_iterator const &rhs) {

						return (this->_node > rhs._node);
					}

					bool		operator>=(reverse_iterator const &rhs) {

						return (this->_node >= rhs._node);
					}

					// Dereference operator
					T			&operator*(void) {

						return (this->_node->val);
					}

					T			&operator*++(void) {

						reverse_iterator	*tmp(*this);

						this->_node = this->_node->prev;

						return (tmp->val);
					}

					T			&operator*--(void) {

						reverse_iterator	*tmp(*this);

						this->_node = this->_node->next;

						return (tmp->val);
					}
			};
			// ITERATORS
			iterator			begin(void) {

				return (iterator(this->_head, this->_head, this->_size));
			}

			//const_iterator 	begin(void) const {
			//}

			iterator			end(void) {

				if (this->_head->prev == 0)
					return (iterator(this->_head, this->_head, this->_size));

				return (iterator(this->_head->prev, this->_head, this->_size));
			}

			//const_iterator			begin(void) {
			//}

			reverse_iterator	rbegin(void) {

				if (this->_head->prev == 0)
					return (iterator(this->_head, this->_head, this->_size));
				return (iterator(this->_head->prev->prev, \
										this->_head->prev->prev, this->_size));
			}

			//const_reverse_iterator	rbegin(void) const {
			//}

			reverse_iterator	rend(void) {

				if (this->_head->prev == 0)
					return (iterator(this->_head, this->_head, this->_size));
				return (iterator(this->_head->prev, this->_head->prev->prev, \
																this->_size));
			}

			//const_reverse_iterator	rend(void) {
			//}
	};
}

#endif
