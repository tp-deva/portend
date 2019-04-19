# Portend

Quick intro goes here.

### Code style:

* File names with classes with *CamelCase* other *snake_case*

* Indentation with 4 spaces

* Members, methods, functions, variables *snake_case*

* Class names with *CamelCase*

* Members with m_*** prefix

* Static members with s_*** prefix


#### Samples


Class definition
```
class SomeClass {
public:
    SomeClass();
    ~SomeClass();
    
    type* sample_method(int, int*);
    static void& sample_static_method(int, int*);
    
private:
    m_some_member;
    s_some_static_member;
}


SomeClass::SomeClass {
    // implementation
}
```

Function definition 
```
void* sample function(type* arg, type& arg) {
    // implementation
}
```

Coditions
```
if (cond) {
    // action
} else if (cond) {
    // action
} else {
    // action
}
```

Loops
```
while (true) {
    // action
}

for (size_t i = 0; i < n; ++i) {
    // action
}
```