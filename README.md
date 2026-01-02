# Lifetime

The class covers virtually any lifetime event, including unrealistic ones. This goes as far as having templated conversion operators, allowing conversion to any type. The function call operator can be used to log the current value category.

`lifetime_simple.h` only covers real-world usecases and is recommended unless you're just messing around for funsies or to learn.

The code in `lifetime_example.cpp` showcases how each lifetime event from `lifetime.h` can be triggered, in order.

## Usage
```cpp
Lifetime a{ "A" }; // Optionally, you can specify a name for Lifetime objects
Lifetime b{ false }; // You can use a boolean to specify if the object should log its lifetime, true by default
```
Output:
```
[A] Constructor
[A] Destructor
```
