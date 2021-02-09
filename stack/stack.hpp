/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mondrew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 19:00:15 by mondrew           #+#    #+#             */
/*   Updated: 2021/02/09 10:33:52 by mondrew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include <deque>

namespace ft
{
	template < typename T, typename Container = std::deque<T> >
	class stack {

		private:

			Container	_ctnr;

		public:

			// Constructor
			explicit stack(Container const &ctnr = Container()) : _ctnr(ctnr) {

				return ;
			}

			// Empty
			bool			empty(void) const {

				return (this->_ctnr.empty());
			}

			// Size
			std::size_t		size(void) const {

				return (this->_ctnr.size());
			}

			// Top
			T				&top(void) {

				return (this->_ctnr.back());
			}

			T const			&top(void) const {

				return (this->_ctnr.back());
			}

			// Push
			void			push(T const &val) {

				this->_ctnr.push_back(val);

				return ;
			}

			// Pop
			void			pop(void) {

				this->_ctnr.pop_back();

				return ;
			}

			// Non-member functions overloads
			friend bool		operator==(stack<T, Container> const &lhs, \
											stack<T, Container> const &rhs) {
				
				return (lhs._ctnr == rhs._ctnr);
			}

			friend bool		operator!=(stack<T, Container> const &lhs, \
											stack<T, Container> const &rhs) {

				return (lhs._ctnr != rhs._ctnr);
			}

			friend bool		operator<(stack<T, Container> const &lhs, \
											stack<T, Container> const &rhs) {

				return (lhs._ctnr < rhs._ctnr);
			}

			friend bool		operator<=(stack<T, Container> const &lhs, \
											stack<T, Container> const &rhs) {

				return (lhs._ctnr <= rhs._ctnr);
			}

			friend bool		operator>(stack<T, Container> const &lhs, \
											stack<T, Container> const &rhs) {

				return (lhs._ctnr > rhs._ctnr);
			}

			friend bool		operator>=(stack<T, Container> const &lhs, \
											stack<T, Container> const &rhs) {

				return (lhs._ctnr >= rhs._ctnr);
			}
	};
}

#endif
