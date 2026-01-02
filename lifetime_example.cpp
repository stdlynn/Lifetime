#include "lifetime.h"

#include <iostream>

// The class covers virtually any lifetime event, including unrealistic ones
// This goes as far as having templated conversion operators, allowing conversion to any type
// The simple version only covers real-world usecases and is recommended unless you're just messing around for funsies or to learn
// The function call operator can be used to log the current value category

int main()
{
    // Constructor
    Lifetime a{};
    const Lifetime b{ 42 }; // One example of non-default constructor
    std::cout << "\n";

    // Copy constructor / assignment operator
    Lifetime c{ b };
    const Lifetime d{ a };
    a = b;
    a = c;
    std::move( a ) = b; // Not real-world code, just for demonstration purposes
    std::move( a ) = c; // Not real-world code, just for demonstration purposes
    b = d;
    b = a;
    std::move( b ) = d; // Not real-world code, just for demonstration purposes
    std::move( b ) = a; // Not real-world code, just for demonstration purposes
    std::cout << "\n";

    // Move constructor / assignment operator
    Lifetime e{ std::move( b ) };
    Lifetime f{ std::move( a ) };
    a = std::move( b );
    a = std::move( c );
    std::move( a ) = std::move( b ); // Not real-world code, just for demonstration purposes
    std::move( a ) = std::move( c ); // Not real-world code, just for demonstration purposes
    b = std::move( d );
    b = std::move( a );
    std::move( b ) = std::move( d ); // Not real-world code, just for demonstration purposes
    std::move( b ) = std::move( a ); // Not real-world code, just for demonstration purposes
    std::cout << "\n";

    // Function call operator
    b();
    a();
    std::move( b )(); // Not real-world code, just for demonstration purposes
    std::move( a )(); // Not real-world code, just for demonstration purposes
    std::cout << "\n";

    // Conversion operator
    std::ignore = static_cast<int>( b );
    std::ignore = static_cast<char>( a );
    std::ignore = static_cast<float>( std::move( b ) ); // Not real-world code, just for demonstration purposes
    std::ignore = static_cast<double>( std::move( a ) ); // Not real-world code, just for demonstration purposes
    std::cout << "\n";

    // Destructor
    return 0;
}