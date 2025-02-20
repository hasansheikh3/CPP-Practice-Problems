#include <iostream>
#include <concepts>
#include <type_traits>
#include <set>

// A basic function using a template, basically this function could be used anywhere, and it type will be
// deduced in compile time, rather than run time.

template <typename T>
T add(T a, T b) {
    return a + b;
}

// A template-based class to store radius and compute diameter
// template <typename X>
// class Circle {
//     X radius;

// public:
//     Circle(X radius) : radius(radius) {}  // Constructor initializes radius
    
//     void printDiameter() {
//         std::cout << "Diameter: " << this->radius * 2.0 << std::endl;
//     }
// };


// This too is the same above class, but now we are stuck with numeric data types
// since what is the purpose of calculating radius of a char or a string?
// That's where concepts come in, a concept is a way to constrain templates
// Remember, it's part of C++20, won't work with 17 or below
template <typename T>
concept Numeric = std::is_arithmetic_v<T> && !std::is_same_v<T, char>;

template <Numeric T>
class Circle {
    T radius;

public:
    Circle(T radius) : radius(radius) {}
    void printDiameter() {
        std::cout << "Diameter: " << this->radius * 2.0 << std::endl;
    }
};

// variadic templates, 
template <typename T>
T sum(T v) {
    return v;
}

template <typename First, typename... Rest>
First sum(First first, Rest... rest) {
    return first + sum(rest...);
}

template <typename... Ts>
constexpr bool areAllIntegral = (std::is_integral_v<Ts> && ...);

template <typename... Ts>
void check() {
    if constexpr (areAllIntegral<Ts...>) {
        std::cout << "All types are integral.\n";
    } else {
        std::cout << "Not all types are integral.\n";
    }
}

int main(int argc, char **argv) {
    // ************* Step 1 **************
    // std::cout << add(1,2) << std::endl; // works for int
    // std::cout << add(9.9, 1.9) << std::endl; // works for double
    // std::cout << add('c', 'a'); // Why does it shows garbage for chars?
    // // std::cout << add("Hello", " World!") // will it work for string literals?
    // // std::cout << add(1.2, 3) << std::endl; // will it work?

    // ************** Step 2 ****************
    // Circle<int> c1(5);
    // c1.printDiameter();  // Prints: Diameter: 10

    // Circle<double> c2(5.5);
    // c2.printDiameter();  // Prints: Diameter: 11.0

    // Circle<char> c3('a');
    // c3.printDiameter(); // what it should print? Or should it be legal? 

    // *****************step 3 *****************
    // Circle<int> c1(5);
    // c1.printDiameter();  // Output: Diameter: 10

    // Circle<double> c2(5.5);
    // c2.printDiameter();  // Output: Diameter: 11

    // Circle<char> c3('a');
    // c3.printDiameter(); // will give a compile time error

    std::cout << sum(1,2,3,4.5,5) << std::endl;

    check<int, long, short>();
    check<int, double, short>();

    return 0;
}