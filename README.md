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

    std::cout << "v contains:";
    for (int i = 0; i < v.size(); i++)
        std::cout << ' ' << v[i];
    std::cout << '\n';


    vector<int> v1;

    for (int i = 1; i < 10; i++) v1.push_back(i);

    cout << v1.mycapacity() << endl;
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
Tetavimo kodas:
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

#AntraStrategija - Bendro studentų konteinerio (vector, list ir deque) skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį: "vargšiukai". Tokiu būdu, jei studentas yra vargšiukas, jį turime įkelti į naująjį "vargšiukų" konteinerį ir ištrinti iš bendro studentai konteinerio. Po šio žingsnio studentai konteineryje liks vien tik kietiakai. Atminties atveju tai efektyviau, tačiau dažni trynimai gali būti "skausmingi", ypač tam tikro tipo konteineriams.

## Spartos analizė (#AntraStrategija)
| File Size   | VECTOR    | LIST      | DEQUE     |
| ----------- | --------- | --------- | --------- |
| 10 000 000  |           |           |           |
| Nuskaitymas | 6,56743   | 7,4048    | 6,57549   |
| Rūšiavimas  | 22,5238   | 15,1803   | 48,5964   |
| Atskyrimas  | 6,14556   | 9,90316   | 8,91084   |
| Visas Laikas| 35,2368   | 32,4883   | 64,0827   |
| 1 000 000   |           |           |           |
| Nuskaitymas | 0,674196  | 0,732539  | 0,661231  |
| Rūšiavimas  | 1,81215   | 1,22027   | 4,02281   |
| Atskyrimas  | 0,540555  | 0,922065  | 0,734049  |
| Visas Laikas| 3,0269    | 2.87487   | 5,41809   |
| 100 000     |           |           |           |
| Nuskaitymas | 0,0787889 | 0,0797862 | 0,0668212 |
| Rūšiavimas  | 0,140624  | 0,0812882 | 0,299705  |
| Atskyrimas  | 0,0468748 | 0,0862754 | 0,0618351 |
| Visas Laikas| 0,266288  | 0,24735   | 0,428361  |
| 10 000      |           |           |           |
| Nuskaitymas | 0,0069805 | 0,009973  | 0,0089758 |
| Rūšiavimas  | 0,0119678 | 0,0059842 | 0,0239358 |
| Atskyrimas  | 0,0049868 | 0,005984  | 0,0059839 |
| Visas Laikas| 0,0239351 | 0,0219412 | 0,0388955 |
| 1 000       |           |           |           |
| Nuskaitymas | 0,0009974 | 0,0009963 | 0,0009976 |
| Rūšiavimas  | 0,0009971 | 0,0009985 | 0,0019944 |
| Atskyrimas  | 0,0009968 | 0,0009971 | 0,0000000 |
| Visas Laikas| 0,0029913 | 0,0029919 | 0,002992  |
