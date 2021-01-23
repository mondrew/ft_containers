/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mondrew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 20:54:31 by mondrew           #+#    #+#             */
/*   Updated: 2021/01/24 00:12:09 by mondrew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

// 1. end() дает элемент, следующий за последним, но после него - снова первый!
// 2. Если добавить в пустой лист элемент пустого листа - то он добавится, т.к.
// дефолтный конструктор создает нулевой элемент (val = 0)
// 3. Учесть в ++ и -- итератора зацикленность списка

//	LOGIC OF DOUBLE-LINKED LIST
//	[null_node]<---node1<->node2<->node3<->[null_node]--->node1

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
			t_list				*_tail; // null-tail
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

				this->_tail = this->_head;

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
				this->_tail = this->_head;
				this->_size = 0;

				if (n == 0)
					return ;

				// Create other elements if any
				while (i < n)
				{
					tmp = new t_list;
					tmp->val = val;
					tmp->prev = this->_tail;
					tmp->next = this->_head;
					this->_head->prev = tmp;
					this->_tail->next = tmp;
					this->_head = tmp;
					this->_size++;
					i++;
				}
			}

			// #3 Range constructor
			list(iterator first, iterator last) {

				int		i = 0;
				t_list	*tmp;

				// Create null-element
				this->_head = new t_list;
				this->_head->val = 0;
				this->_head->prev = 0;
				this->_head->next = 0;
				this->_tail = this->_head;
				this->_size = 0;

				if (first == last)
					return ;

				// Create other elements if any
				while (i < n)
				{
					tmp = new t_list;
					tmp->val = *first;
					tmp->prev = this->_tail;
					tmp->next = this->_head;

					this->_tail->next = tmp;
					this->_head->prev = tmp;

					this->_head = tmp;
					this->_size++;
					first++;
					i++;
				}
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
				this->_size = 0;
				return ;
			}

			// Assignment operation overload
			list<T, A>		operator=(list<T, A> const &rhs) {

				t_list	*tmp;
				t_list	*from = rhs._head;

				// Create null-element
				this->_head = new t_list;
				this->_head->val = 0;
				this->_head->prev = 0;
				this->_head->next = 0;
				this->_tail = this->_head;
				this->_size = 0;

				if (rhs.size() == 0)
					return (*this);

				// Create other elements if any
				while (from != rhs._tail)
				{
					tmp = new t_list;
					tmp->val = from->val;
					tmp->prev = this->_tail;
					tmp->next = this->_head;

					this->_tail->next = tmp;
					this->_head->prev = tmp;

					this->_size++;
					from = from->next;
					i++;
				}
				return (*this);
			}

			// ITERATORS
			// Simple iterator
			class iterator {

				private:

					t_list		*_node;

				public:

					// CONSTRUCTORS
					// #1 default constructor
					iterator(void) : _node(0) { return ; }
					// #2 param constructor (for iterator init: begin, end, etc)
					iterator(t_list *node) : _node(node) { return ; }
					// #3 Parameterized constructor
					iterator(list<T, A> const &src) {

						this->_node = src.getHead();

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

				public:

					// CONSTRUCTORS
					// #1 default constructor
					reverse_iterator(void) : _node(0) { return ; }
					// #2 param constructor (for iterator init: begin, end, etc)
					reverse_iterator(t_list *node) : _node(node) { return ; }
					// #3 Parameterized constructor
					reverse_iterator(list<T, A> const &src) {

						this->_node = src.getTail()->prev;

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

				return (iterator(this->_head));
			}

			//const_iterator 	begin(void) const {
			//}

			iterator			end(void) {

				return (iterator(this->_tail));
			}

			//const_iterator			begin(void) {
			//}

			reverse_iterator	rbegin(void) {

				return (iterator(this->_tail->prev));
			}

			//const_reverse_iterator	rbegin(void) const {
			//}

			reverse_iterator	rend(void) {

				return (iterator(this->_head->prev));
			}

			//const_reverse_iterator	rend(void) {
			//}

			// CAPACITY

			bool				empty(void) const {

				return (this->_size == 0);
			}

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

				return (static_cast<size_t>(pow(2, arch) / sizeof(T)) - 1);
			}

			// ELEMENT ACCESS
			T					&front(void) {

				return (this->_head->val);
			}

			T					&back(void) {

				return (this->tail->prev->val);
			}

			// MODIFIERS
			// Assign #1 range
			void				assign(iterator first, iterator last) {

				t_list	*tmp = first;

				// Delete all nodes except tail-null-node
				while (this->_head->next)
				{
					tmp = this->_head->next;
					delete this->_head;
					this->_head = 0;
					this->_head = tmp;
				}
				this->_size = 0;

				if (first == last)
					return ;

				// Create first node
				while (tmp != this->_tail)
				{
					tmp = new t_list;
					tmp->val = *tmp;
					tmp->prev = this->_tail;
					tmp->next = this->_head;

					this->_head->prev = tmp;
					this->_tail->next = tmp;
					this->_head = tmp;

					this->_size++;
					tmp++;
				}
				return ;
			}

			// Assign #2 fill
			void				assign(size_t n, T const &val) {

				t_list	*tmp;

				// Delete all nodes except tail-null-node
				while (this->_head->next)
				{
					tmp = this->_head->next;
					delete this->_head;
					this->_head = 0;
					this->_head = tmp;
				}
				this->_size = 0;

				if (n == 0)
					return ;

				while (n > 0)
				{
					tmp = new t_list;
					tmp->val = val;
					tmp->prev = this->_head;
					tmp->_next = this->_tail;
					this->_head->next = tmp;
					this->_tail->prev = tmp;
					this->_head = tmp;
					this->_size++;
					n--;
				}
				return ;
			}

			// Push front
			void				push_front(T const &val) {

				t_list	*tmp = new t_list;

				tmp->val = val;
				tmp->prev = this->_tail;
				tmp->next = this->_head;
				this->_head->prev = tmp;
				this->_tail->next = tmp;

				this->_head = tmp;
				this->_size++;
				return ;
			}

			void				push_back(T const &val) {

				t_list		*tmp = new t_list;

				tmp->val = val;
				tmp->prev = this->_tail->prev;
				tmp->next = this->_tail;
				this->_tail->prev = tmp;
				this->_tail->_prev->next = tmp;

				this->_size++;
				return ;
			}
	};
}

#endif
