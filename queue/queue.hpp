#ifndef QUEUE_HPP
# define QUEUE_HPP

# include <deque>

namespace ft
{
	template < typename T, typename Container = std::deque<T> >
	class queue {

		private:

			Container	_ctnr;

		public:

			// Constructor
			explicit queue(Container const &ctnr = Container()) : _ctnr(ctnr) {

				return ;
			}

			// Empty
			bool		empty(void) const {

				return (this->_ctnr.empty());
			}

			// Size
			std::size_t		size(void) const {

				return (this->_ctnr.size());
			}

			// Front
			T				&front(void) {

				return (this->_ctnr.front());
			}

			T const			&front(void) const {

				return (this->_ctnr.front());
			}

			// Back
			T				&back(void) {

				return (this->_ctnr.back());
			}

			T const			&back(void) const {

				return (this->_ctnr.back());
			}

			// Push
			void			push(T const &val) {

				this->_ctnr.push_back(val);

				return ;
			}

			// Pop
			void			pop(void) {

				this->_ctnr.pop_front();

				return ;
			}

			// Non-member functions
			friend bool		operator==(Container const &lhs, \
														Container const &rhs) {

				return (lhs._ctnr == rhs._ctnr);
			}

			friend bool		operator!=(Container const &lhs, \
														Container const &rhs) {

				return (lhs._ctnr != rhs._ctnr);
			}

			friend bool		operator<(Container const &lhs, \
														Container const &rhs) {

				return (lhs._ctnr < rhs._ctnr);
			}

			friend bool		operator<=(Container const &lhs, \
														Container const &rhs) {

				return (lhs._ctnr <= rhs._ctnr);
			}

			friend bool		operator>(Container const &lhs, \
														Container const &rhs) {

				return (lhs._ctnr > rhs._ctnr);
			}

			friend bool		operator>=(Container const &lhs, \
														Container const &rhs) {

				return (lhs._ctnr >= rhs._ctnr);
			}
	};
}

#endif
