#include "stdafx.h"

// Example: std::variant, boost::any, std::any

struct var {
	template <typename _Ty> var(_Ty src) : _inner(new inner<_Ty>(std::forward<_Ty>(src))) {}

	template <typename _Ty> var& operator = (_Ty src) {
		_inner = std::make_unique<inner<_Ty>>(std::forward<_Ty>(src));
		return *this;
	}
	const std::type_info& Type() const { return _inner->Type(); }

	struct inner_base {
		using ptr = std::unique_ptr<inner_base>;
		virtual const std::type_info& Type() const = 0;
	};
	template <typename _Ty> struct inner : inner_base {
		inner(_Ty newval) : _value(newval) {}
		virtual const std::type_info& Type() const override { return typeid(_Ty); }
	private:
		_Ty _value;
	};
private:
	typename inner_base::ptr _inner;
};

void type_erasure()
{
	var v = 1;
	cout << v.Type().name();

	v = "a string";
	cout << v.Type().name();
}