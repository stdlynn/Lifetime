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

    // Destructor
    ~Lifetime() noexcept { log( "Destructor" ); }

    // Copy constructor / assignment operator
    Lifetime( const Lifetime& other ) noexcept { log( "Copy constructor", other ); }
    Lifetime& operator=( const Lifetime& other ) noexcept { log( "Copy assignment operator", other ); return *this; }

    // Move constructor / assignment operator
    Lifetime( Lifetime&& other ) noexcept { log( "Move constructor", other ); }
    Lifetime& operator=( Lifetime&& other ) noexcept { log( "Move assignment operator", other ); return *this; }

    // Function call operator
    const Lifetime&  operator()() const &  noexcept { log( "const lvalue" ); return *this; }
          Lifetime&  operator()()       &  noexcept { log( "lvalue"       ); return *this; }
    const Lifetime&& operator()() const && noexcept { log( "const rvalue" ); return std::move( *this ); }
          Lifetime&& operator()()       && noexcept { log( "rvalue"       ); return std::move( *this ); }

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