/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mondrew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 20:54:31 by mondrew           #+#    #+#             */
/*   Updated: 2021/01/24 22:19:54 by mondrew          ###   ########.fr       */
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
				this->_head->prev = this->_head;
				this->_head->next = this->_head;

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
				this->_head->prev = this->_head;
				this->_head->next = this->_head;
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
				this->_head->prev = this->_head;
				this->_head->next = this->_head;
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
				this->_head->prev = this->_head;
				this->_head->next = this->_head;
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

			void				pop_front(void) {

				t_list		*tmp = this->_head->next;

				if (this->_size == 0)
					return ;

				delete this->_head;
				this->_head = tmp;
				this->_size--;

				this->_head->prev = this->_tail;
				this->_tail->next = this->head;
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

			void				pop_back(void) {

				t_list		*tmp = this->_tail->prev->prev;

				if (this->_size == 0)
					return ;

				delete this->_tail->prev;
				this->_size--;

				tmp->next = this->_tail;
				this->_tail->prev = tmp;
				return ;
			}

			// Insert #1 (single element)
			iterator			insert(iterator position, T const &val) {

				t_list		*tmp = new t_list;

				tmp->val = val;
				tmp->prev = position->_node->prev;
				tmp->next = position->_node;
				position->_node->prev->next = tmp;
				position->_node->prev = tmp;
				this->_size++;

				position--;

				return (position); // test it
			}

			// Insert #2 (fill)
			void				insert(iterator position, size_t n, \
																T const &val) {

				int			i = n;
				t_list		*tmp;

				while (n > 0)
				{
					tmp = new t_list;

					tmp->val = val;
					tmp->prev = position.prev;
					tmp->next = position;
					position._node->prev->next = tmp;
					position._node->prev = tmp;
					this->_size++;

					n--;
				}

				while (i > 0)
				{
					position--;
					i--;
				}

				return (position); // test it
			}

			// Insert #3 (range)
			void				insert(iterator position, iterator first, \
																iterator last) {

				int			n = 0;
				t_list		*tmp;

				while (first != last)
				{
					tmp = new t_list;
					tmp->val = *first;
					tmp->prev = position._node->prev;
					tmp->next = position._node;
					position._node->prev->next = tmp;
					position._node->prev = tmp;
					this->_size++;
					first++;
					n++;
				}

				while (n > 0)
				{
					position--;
					n--;
				}
				return (position);
			}

			// Erase #1
			iterator			erase(iterator position) {

				t_list		*tmp = position._node->prev;

				if (this->_size == 0) // check the original
					return (position);

				tmp->prev = position._node;
				position._node->prev = tmp->prev;

				delete tmp;

				this->_size--;

				return (position);
			}

			// Erase #2
			iterator			erase(iterator first, iterator last) {

				t_list		*tmp;

				if (first == last) // check original
					return (this->_head);

				while (first != last)
				{
			   		tmp = first._node;
					first._node->prev->next = first._node->next;
					first._node->next->prev = first._node->prev;
					delete tmp;
					this->_size--;

					first++;
				}
				return (last);
			}

			// Swap
			void				swap(list &x) {

				t_list		*tmp_head = x._head;
				t_list		*tmp_tail = x._tail;
				size_t		tmp_size = x._size;

				x._head = this->_head;
				x._tail = this->_tail;
				x._size = this->_size;

				this->_head = tmp_head;
				this->_tail = tmp_tail;
				this->_size = tmp_size;

				return ;
			}

			// Resize
			void				resize( size_t n, T val = T() ) {

				int		i = 0;

				if (n < this->_size)
				{
					while (n < this->_size)
					{
						this->pop_back();
						this->_size--;
					}
				}
				else if (n > this->_size)
				{
					while (this->_size < n)
					{
						this->push_back(val);
						this->_size++;
					}
				}
				return ;
			}

			// Clear
			void				clear(void) {

				while (this->_size)
				{
					this->pop_back();
					this->_size--;
				}
				delete this->_head;
				this->_head = 0;
				this->_tail = 0;
			}

			// OPERATIONS
			// Splice #1 (entire list)
			void				splice(iterator position, list &x) {

				t_list		*before = position._node->prev;
				t_list		*after = position._node;
				t_list		*tmp;

				while (x._size)
				{
					tmp = x._head;
					x._tail->next = x._head->next;
					x._head->next->prev = x._tail;
					x._size--;

					before->next = tmp;
					tmp->prev = before;
					after->prev = tmp;
					tmp->next = after;
					this->_size++;
					before = before->next;
				}
			}

			// Splice #2 (single element)
			void				splice(iterator position, list &x, iterator i) {

				t_list		*before = position._node->prev;
				t_list		*after = position._node;
				t_list		*tmp;

				tmp = iterator._node;

				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
				x._size--;

				before->next = tmp;
				tmp->prev = before;
				after->prev = tmp;
				tmp->next = after;
				this->_size++;
			}

			// Splice #3 (element range)
			void				splice(iterator position, list &x, \
												iterator first, iterator last) {

				t_list		*before = position._node->prev;
				t_list		*after = position._node;
				t_list		*tmp;

				while (first != last)
				{
					tmp = first._node;
					tmp->prev->next = tmp->next;
					tmp->next->prev = tmp->prev;
					x._size--;

					before->next = tmp;
					tmp->prev = before;
					after->prev = tmp;
					tmp->next = after;
					this->_size++;
					first++;
					before = before->next;
				}
			}

			// Remove
			void				remove(T const &val) {

				int			i = 0;
				t_list		*tmp = this->_head;
				t_list		*tmp2;

				while (tmp != this->_tail)
				{
					tmp2 = tmp->next;
					if (tmp->val == val)
					{
						tmp->prev->next = tmp->next;
						tmp->next->prev = tmp->prev;
						delete tmp;
						this->_size--;
					}
					tmp = tmp2;
				}
			}

			// Remove if
			template <class Predicate>
			void				remove_if(Predicate pred) {

				iterator	it = this->begin();
				iterator	ite = this->end();
				t_list		*tmp;

				while (it != ite)
				{
					if (pred(*it))
					{
						tmp = it._node;
						it++;
						tmp->prev->next = tmp->next;
						tmp->next->prev = tmp->prev;
						delete tmp;
						this->_size--;
					}
					else
						it++;
				}
			}

			// Unique #1
			void				unique(void) {

				t_list		*fst = this->_head;
				t_list		*snd = this->_head->next;

				while (snd != this->_tail)
				{
					if (fst->val == snd->val)
					{
						fst->next = snd->next;
						snd->next->prev = fst;
						delete snd;
						this->_size--;
					}
					else
						fst = fst->next;
					snd = fst->next;
				}
			}

			// Unique #2
			template <class BinaryPredicate>
			void				unique(BinaryPredicate binary_pred) {

				iterator	it = this->begin();
				iterator	ite = this->end();
				iterator	tmp;

				it++;
				while (it != ite)
				{
					tmp = it + 1;
					if (binary_pred(*it, *(it - 1)))
						erase(it);
					it = tmp;
				}
			}

			// Merge #1
			void				merge(list &x) {

				t_list		*src = x._head;
				t_list		*dest = this->_head;
				t_list		*tmp;

				if (x._size == 0)
					return ;
				while (src != x._tail)
				{
					tmp = src->next;
					while (dest != this->_tail && dest->val <= src->val)
						dest = dest->next;
					src->prev->next = src->next;
					src->next->prev = src->prev;
					x._size--;

					src->prev = dest->prev;
					src->next = dest;

					dest->prev->next = src;
					dest->prev = src;
					this->_size++;

					src = tmp;
				}
			}

			// Merge #2
			template <class Compare>
			void				merge(list &x, Compare comp) {

				if (&x == this || x._size == 0)
					return ;
				t_list		*src = x._head;
				t_list		*dest = this->_head;
				t_list		*tmp;

				while (src != x._tail)
				{
					tmp = src->next;
					while (dest != this->_tail && !comp(dest->val, src->val))
						dest = dest->next;
					src->prev->next = src->next;
					src->next->prev = src->prev;
					x._size--;

					src->prev = dest->prev;
					src->next = dest;

					dest->prev->next = src;
					dest->prev = src;
					this->_size++;

					src = tmp;
				}
			}

	};
}

#endif
