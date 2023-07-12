#include <type_traits>

/*
 * Logic to iterate over an enum class.
 * You'll need to specialize it like so:
 * ```
 * typedef Iterator<foo, foo::one, foo::three> fooIterator;
 * ```
 * Afterwards you're able to iterate over it like so:
 * ```
 * for (foo i : fooIterator() ) { do_stuff(i); }
 * ```
 * Credit to 425nesp & Francesco Chermolli:
 * https://stackoverflow.com/questions/261963/how-can-i-iterate-over-an-enum
 */

template <typename C, C beginVal, C endVal>
class Iterator {
    typedef typename std::underlying_type<C>::type val_t;
    int val;
    public:
        Iterator(const C & f) : val(static_cast<val_t>(f)) {}
        Iterator() : val(static_cast<val_t>(beginVal)) {}
        Iterator operator++() {
        ++val;
        return *this;
        }
        C operator*() { return static_cast<C>(val); }
        Iterator begin() { return *this; } //default ctor is good
        Iterator end() {
          static const Iterator endIter=++Iterator(endVal); // cache it
          return endIter;
        }
        bool operator!=(const Iterator& i) { return val != i.val; }
};


