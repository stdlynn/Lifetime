#pragma once

#include <utility>
#include <string>
#include <iostream>

class Lifetime
{
public:

    // Constructor
    Lifetime() noexcept { log( "Default constructor" ); }
    Lifetime( bool log_lifetime, const char* name = "" ) noexcept : name{ name }, log_lifetime{ log_lifetime } { log( "Constructor" ); }
    Lifetime( const char* name, bool log_lifetime = true ) : name{ name }, log_lifetime{ log_lifetime } { log( "Constructor" ); }
    Lifetime( auto&&... ) noexcept { log( "Constructor" ); }

    // Destructor
    ~Lifetime() noexcept { log( "Destructor" ); }

    // Copy constructor / assignment operator
    Lifetime( const Lifetime& other ) noexcept { log( "Copy constructor (copy from const lvalue)", other ); }
    Lifetime(       Lifetime& other ) noexcept { log( "Copy constructor (copy from lvalue)",       other ); }
    Lifetime&  operator=( const Lifetime& other ) &  noexcept { log( "Copy assignment operator (lvalue from const lvalue)", other ); return *this; }
    Lifetime&  operator=(       Lifetime& other ) &  noexcept { log( "Copy assignment operator (lvalue from lvalue)",       other ); return *this; }
    Lifetime&& operator=( const Lifetime& other ) && noexcept { log( "Copy assignment operator (rvalue from const lvalue)", other ); return std::move( *this ); }
    Lifetime&& operator=(       Lifetime& other ) && noexcept { log( "Copy assignment operator (rvalue from lvalue)",       other ); return std::move( *this ); }
    const Lifetime&  operator=( const Lifetime& other ) const &  noexcept { log( "Copy assignment operator (const lvalue from const lvalue)", other ); return *this; }
    const Lifetime&  operator=(       Lifetime& other ) const &  noexcept { log( "Copy assignment operator (const lvalue from lvalue)",       other ); return *this; }
    const Lifetime&& operator=( const Lifetime& other ) const && noexcept { log( "Copy assignment operator (const rvalue from const lvalue)", other ); return std::move( *this ); }
    const Lifetime&& operator=(       Lifetime& other ) const && noexcept { log( "Copy assignment operator (const rvalue from lvalue)",       other ); return std::move( *this ); }

    // Move constructor / assignment operator
    Lifetime( const Lifetime&& other ) noexcept { log( "Move constructor (moved from const rvalue)", other ); }
    Lifetime(       Lifetime&& other ) noexcept { log( "Move constructor (moved from rvalue)",       other ); }
    Lifetime&  operator=( const Lifetime&& other ) &  noexcept { log( "Move assignment operator (lvalue from const rvalue)", other ); return *this; }
    Lifetime&  operator=(       Lifetime&& other ) &  noexcept { log( "Move assignment operator (lvalue from rvalue)",       other ); return *this; }
    Lifetime&& operator=( const Lifetime&& other ) && noexcept { log( "Move assignment operator (rvalue from const rvalue)", other ); return std::move( *this ); }
    Lifetime&& operator=(       Lifetime&& other ) && noexcept { log( "Move assignment operator (rvalue from rvalue)",       other ); return std::move( *this ); }
    const Lifetime&  operator=( const Lifetime&& other ) const &  noexcept { log( "Move assignment operator (const lvalue from const rvalue)", other ); return *this; }
    const Lifetime&  operator=(       Lifetime&& other ) const &  noexcept { log( "Move assignment operator (const lvalue from rvalue)",       other ); return *this; }
    const Lifetime&& operator=( const Lifetime&& other ) const && noexcept { log( "Move assignment operator (const rvalue from const rvalue)", other ); return std::move( *this ); }
    const Lifetime&& operator=(       Lifetime&& other ) const && noexcept { log( "Move assignment operator (const rvalue from rvalue)",       other ); return std::move( *this ); }

    // Function call operator
    const Lifetime&  operator()() const &  noexcept { log( "const lvalue" ); return *this; }
          Lifetime&  operator()()       &  noexcept { log( "lvalue"       ); return *this; }
    const Lifetime&& operator()() const && noexcept { log( "const rvalue" ); return std::move( *this ); }
          Lifetime&& operator()()       && noexcept { log( "rvalue"       ); return std::move( *this ); }

    // Conversion operator
    template <typename T> operator T() const &  noexcept { log( "Conversion operator (converted const lvalue)" ); return T{}; }
    template <typename T> operator T()       &  noexcept { log( "Conversion operator (converted lvalue)"       ); return T{}; }
    template <typename T> operator T() const && noexcept { log( "Conversion operator (converted const rvalue)" ); return T{}; }
    template <typename T> operator T()       && noexcept { log( "Conversion operator (converted rvalue)"       ); return T{}; }

private:

    void log( const char* msg, const Lifetime& other ) const noexcept
    {
        if (!log_lifetime) { return; }
        if (!name.empty()) { std::cout << "[" << name << "] "; }
        std::cout << msg;
        if (!other.name.empty()) { std::cout << " [" << other.name << "]"; }
        std::cout << "\n";
    }

    void log( const char* msg ) const noexcept 
    { 
        if (!log_lifetime) { return; }
        if (!name.empty()) { std::cout << "[" << name << "] "; }
        std::cout << msg << "\n"; 
    }

    std::string name{};
    bool log_lifetime{ true };

}; // Lifetime