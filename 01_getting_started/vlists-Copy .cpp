#include <iostream>

namespace vlists 
{
// Main declaration
template<auto...> struct VList {};


// Declarations
template<typename> struct null {};

template<auto, typename> struct elem {};

template<typename> struct length {};

template<typename> struct sum {};

template<typename> struct product {};


// Definitions
// null
template<> struct null<VList<>>
{static constexpr auto value = true;};

template<auto X, auto... Xs> struct null<VList<X, Xs...>>
{static constexpr auto value = false;};

// elem
template<auto Y> struct elem<Y, VList<>>
{static constexpr auto value = false;};

template<auto Y, auto X, auto... Xs> struct elem<Y, VList<X, Xs...>>
{static constexpr auto value = (X == Y) || elem<Y, VList<Xs...>>::value;};

// and

// or

// all

// any

// length
template<> struct length<VList<>>
{static constexpr auto value = 0;};

template<auto... Xs> struct length<VList<Xs...>>
{static constexpr auto value = sizeof...(Xs);};

// sum
template<> struct sum<VList<>>
{static constexpr auto value = 0;};

template<auto X, auto... Xs> struct sum<VList<X, Xs...>>
{static constexpr auto value = X + sum<VList<Xs...>>::value;};

// product
template<> struct product<VList<>>
{static constexpr auto value = 1;};

template<auto X, auto... Xs> struct product<VList<X, Xs...>>
{static constexpr auto value = X * product<VList<Xs...>>::value;};

// min

// max

} // namespace vlists

using std::cout; 
using std::endl; 
using namespace vlists;

int main() {
    cout << sum<VList<1,2,3,4>>::value << endl;
    cout << elem<7, VList<1,2,3,4>>::value << endl;
}