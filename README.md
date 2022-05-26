# vector

## Funkcijų pavyzdžiai (6)

*  **vector::push_back()**
  Kodas:
    ```c++
    std::vector<int> v;

    for (int i = 1; i < 10; i++)
        v.push_back(i);

    std::cout << "v contains:";
    for (int i = 0; i < v.size(); i++)
        std::cout << ' ' << v[i];
    std::cout << '\n';


    vector<int> v1;

    for (int i = 1; i < 10; i++)
        v1.push_back(i);

    std::cout << "v1 contains:";
    for (int i = 0; i < v1.mysize(); i++)
        std::cout << ' ' << v1[i];
    std::cout << '\n';
    ```
    Rezultatas:
    ```console
     v contains: 1 2 3 4 5 6 7 8 9
     v1 contains: 1 2 3 4 5 6 7 8 9
    ```
    
*  **vector::resize()**
  Kodas:
    ```c++
    std::vector<int> v;

    for (int i = 1; i < 10; i++) v.push_back(i);

    v.resize(5);

    std::cout << "v contains:";
    for (int i = 0; i < v.size(); i++)
        std::cout << ' ' << v[i];
    std::cout << '\n';


    vector<int> v1;

    for (int i = 1; i < 10; i++) v1.push_back(i);

    v1.resize(5);

    std::cout << "v1 contains:";
    for (int i = 0; i < v1.mysize(); i++)
        std::cout << ' ' << v1[i];
    std::cout << '\n';
    ```
    Rezultatas:
    ```console
     v contains: 1 2 3 4 5
     v1 contains: 1 2 3 4 5
    ```
  
*  **vector::size()**
  Kodas:
    ```c++
    std::vector<int> v;

    for (int i = 1; i < 10; i++) v.push_back(i);

    cout << v.size() << endl;
    std::cout << '\n';


    vector<int> v1;

    for (int i = 1; i < 10; i++) v1.push_back(i);

    cout << v1.mysize() << endl;
    ```
    Rezultatas:
    ```console
     v size: 9
     v1 size: 9
    ```
    
*  **vector::shrink_to_fit()**
  Kodas:
    ```c++
    std::vector<int> v;

    for (int i = 1; i < 10; i++)
        v.push_back(i);
        
    cout << "v capacity before shrinkt_to_fit(): " << v.capacity() << endl;
    v.shrink_to_fit();
    cout << "v capacity after shrinkt_to_fit(): " << v.capacity() << endl;


    vector<int> v1;

    for (int i = 1; i < 10; i++)
      v1.push_back(i);

    cout << "v1 capacity before shrinkt_to_fit(): " << v1.mycapacity() << endl;
    v1.shrink_to_fit();
    cout << "v1 capacity after shrinkt_to_fit(): " << v1.mycapacity() << endl;
    ```
    Rezultatas:
    ```console
     v capacity before shrinkt_to_fit(): 9
     v capacity after shrinkt_to_fit(): 9
     
     v1 capacity before shrinkt_to_fit(): 16
     v1 capacity after shrinkt_to_fit(): 9
    ```
    
*  **vector::reserve()**
  Kodas:
    ```c++
    std::vector<int> v;

    for (int i = 1; i < 10; i++) {
        v.push_back(i);
    }
    cout << "v capacity before reserve(20): " << v.capacity() << endl;
    v.reserve(20);
    cout << "v capacity after reserve(20): " << v.capacity() << endl;


    vector<int> v1;

    for (int i = 1; i < 10; i++) {
        v1.push_back(i);
    }
    cout << "v1 capacity before reserve(20): " << v1.mycapacity() << endl;
    v1.reserve(20);
    cout << "v1 capacity after reserve(20): " << v1.mycapacity() << endl;
    ```
    Rezultatas:
    ```console
     v capacity before reserve(20): 9
     v capacity after reserve(20): 20
     
     v1 capacity before reserve(20): 16
     v1 capacity after reserve(20): 20
    ```
    
*  **vector::pop_back()**
  Kodas:
    ```c++
    std::vector<int> v;

    for (int i = 1; i < 10; i++)
        v.push_back(i);

    cout << "before pop_back(), v contains: ";
    for (int i = 1; i < v.size(); i++)
        cout << v.at(i) << " ";

    cout << endl;

    v.pop_back();
    cout << "after pop_back(), v contains: ";
    for (int i = 1; i < v.size(); i++)
        cout << v.at(i) << " ";


    vector<int> v1;

    for (int i = 1; i < 10; i++)
        v1.push_back(i);

    cout << "before pop_back(), v1 contains: ";
    for (int i = 1; i < v1.mysize(); i++)
        cout << v1.at(i) << " ";

    cout << endl;

    v1.pop_back();
    cout << "after pop_back(), v1 contains: ";
    for (int i = 1; i < v1.mysize(); i++)
        cout << v1.at(i) << " ";
    ```
    Rezultatas:
    ```console
     before pop_back(), v contains: 2 3 4 5 6 7 8 9
     after pop_back(), v contains: 2 3 4 5 6 7 8
     
     before pop_back(), v1 contains: 2 3 4 5 6 7 8 9
     after pop_back(), v1 contains: 2 3 4 5 6 7 8
    ```

## Vektoriaus užpildymas, naudojant *vector::push_back()* spartos palyginmas

Testavimo kodas:
```c++
#include <chrono>
using hrClock = std::chrono::high_resolution_clock;
```
```c++
    auto v1_start = hrClock::now();
    unsigned int sz = 10000;  // 100000, 1000000, 10000000, 100000000
    
    std::vector<int> v1;
    for (int i = 1; i <= sz; ++i)
        v1.push_back(i);
    auto v1_stop = hrClock::now();
    auto v1_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(v1_stop - v1_start);
    std::cout << v1_duration.count() * 1e-9 << "s\n";

    auto v2_start = hrClock::now();
    vector<int> v2;
    for (int i = 1; i <= sz; ++i)
        v2.push_back(i);
    auto v2_stop = hrClock::now();
    auto v2_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(v2_stop - v2_start);
    std::cout << v2_duration.count() * 1e-9 << "s\n";
```
<br>  

### Rezultatai
|  | 10,000 | 100,000 | 1,000,000 | 10,000,000 | 100,000,000 |
|---|---|---|---|---|---|
| std::vector | 7.41e-05s | 0.0021592s | 0.0031754s | 0.0363714s | 0.495144s |
| vector | 7.26e-05s | 0.0004596s | 0.0026671s | 0.0369054s | 0.366815s |

### Atminties perskirstymas
Testavimo kodas:
```c++
    unsigned int sz = 100000000;
    int p1 = 0, p2 = 0;

    vector<int> v1;
    for (int i = 1; i <= sz; ++i) {
        v1.push_back(i);
        if (v1.mysize() == v1.mycapacity())
            p1++;
    }
    cout << "v1 Perskirstymas ivyko: " << p1 << endl;


    unsigned int sz = 100000000;
    int p1 = 0, p2 = 0;

    std::vector<int> v;
    for (int i = 1; i <= sz; ++i) {
        v.push_back(i);
        if (v.size() == v.capacity())
            p2++;
    }
    cout << "v Perskirstymas ivyko: " << p2 << endl;
```
Rezultatas:
```console
    v Perskirstymas ivyko: 46
    v1 Perskirstymas ivyko: 27
```

## Spartos analizė

### std::vector
| Įrašų kiekis | Duomenų skaitymas, s | Studentų rūšiavimas pagal pažymius, s | Studentų rūšiavimas į dvi kategorijas, s | Visos programos veikimo laikas, s |
|---|---|---|---|---|
| 1,000 | 0,0009606 | 0,0006687 | 0,0005706 | 0,0021999 |
| 10,000 | 0,0086893 | 0,0106566 | 0,0069483 | 0,0262942 |
| 100,000 | 0,0679738 | 0,0946483 | 0,0642741 | 0,226896 |
| 1,000,000 | 0,70264 | 0,905958 | 0,613416 | 2,22201 |
| 10,000,000 | 7,19385 | 9,50958 | 6,11496 | 22,8184 |

### vector
| Įrašų kiekis | Duomenų skaitymas, s | Studentų rūšiavimas pagal pažymius, s | Studentų rūšiavimas į dvi kategorijas, s | Visos programos veikimo laikas, s |
|---|---|---|---|---|
| 1,000 | 0,0016126 | 0,0012641 | 0,0013291 | 0,0042058 |
| 10,000 | 0,022117 | 0,0172078 | 0,0156485 | 0,0549733 |
| 100,000 | 0,0870578 | 0,253838 | 0,229104 | 0,5700 |
| 1,000,000 | 0,870056 | 1,61418 | 1,51275 | 3,99699 |
| 10,000,000 | 9,77585 | 19,115 | 19,9128 | 48,8036 |

## Išvados
1. Programa veikė greičiau naudojant std::vector;
2. Atminties valdymas buvo sklandesnis naudojant std::vector;
