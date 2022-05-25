# V1.5 programos versija
1. Pridėta abstrakti klasė 'zmogus'.
2. Klasė 'duomenys' paveldi klasę 'zmogus'.
# V1.2 programos versija
1. Pridėta #rule of three
# V1.1 programos versija
1. Pakeista iš struktūros i klasę.
2. Panaudoti optimizavimo flag'ai.
## Optimizavimo analizė VECTOR VS CODE MINGW64 (O1, O2, O3) 10 000 000 - CODEBLOCKS
|     FLAG    |    -O1    |   -O2     |   -O3     |  REGULAR  |
| ----------- | --------- | --------- | --------- | --------- |
| 10 000 000  |           |           |           |           |
| Nuskaitymas |  7,16445  |  7,11857  |  7,2323   |  7,09068  |
| Rūšiavimas  | 28,2978   | 28,7362   | 29,7261   | 28,4544   |
| Atskyrimas  |  6,57801  |  7,07288  |  6,68226  |  7,0109   |
| Visas Laikas| 42,0402   | 42,9277   | 43,6406   | 42,556    |
| 1 000 000   |           |           |           |           |
| Nuskaitymas |  1,12     |  1,11801  |  1,2798   |   1,25664 |
| Rūšiavimas  |  7,75227  |  7,73233  |  7,69243  |   8,12727 |
| Atskyrimas  |  1,19181  |  1,18284  |  1,18084  |   1,50797 |
| Visas Laikas| 10,0641   | 10,03318  | 10,15307  |  10,8919  |
| 100 000     |           |           |           |           |
| Nuskaitymas | 0,120677  | 0,120677  | 0,123669  |  0,11968  |
| Rūšiavimas  | 0,583439  | 0,58344   | 0,595408  |  0,61336  |
| Atskyrimas  | 0,119681  | 0,115691  | 0,139627  |  0,147606 |
| Visas Laikas| 0,823797  | 0,819808  | 0,858704  |  0,880646 |

## Analizė CLASS vs STRUCT
| File Size   | VECTOR CLASS | VECTOR STRUCT |
| ----------- | ------------ | ------------- |
| 10 000 000  |              |               |
| Nuskaitymas | 6,96538      | 6,56743       |
| Rūšiavimas  | 27,5603      | 22,5238       |
| Atskyrimas  |  6,359       | 6,14556       |
| Visas Laikas| 40,8847      | 35,2368       |
| 1 000 000   |              |               |
| Nuskaitymas | 0,676192     | 0,674196      |
| Rūšiavimas  | 2,18715      | 1,81215       |
| Atskyrimas  | 0,630314     | 0,540555      |
| Visas Laikas| 3,49366      | 3,0269        |
| 100 000     |              |               |
| Nuskaitymas | 0.069812     | 0,0787889     |
| Rūšiavimas  | 0.16855      | 0,140624      |
| Atskyrimas  | 0.0608369    | 0,0468748     |
| Visas Laikas| 0.299199     | 0,269788      |
| 10 000      |              |               |
| Nuskaitymas | 0,0089759    | 0,0069805     |
| Rūšiavimas  | 0,0159573    | 0,0119678     |
| Atskyrimas  | 0,0059842    | 0,0049868     |
| Visas Laikas| 0,0309174    | 0,0239351     |
| 1 000       |              |               |
| Nuskaitymas | 0,0019948    | 0,0009974     |
| Rūšiavimas  | 0,0009976    | 0,0009971     |
| Atskyrimas  | 0,0009971    | 0,0009968     |
| Visas Laikas| 0,0039895    | 0,0029913     |

# V1.0 programos versija
#PirmaStrategija - Bendro studentai konteinerio (vector, list ir deque tipų) skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius: "vargšiukų" ir "kietiakų". Tokiu būdu tas pats studentas yra dvejuose konteineriuose: bendrame studentai ir viename iš suskaidytų (vargšiukai arba kietiakai). Nesunku pastebėti, kad tokia strategija yra neefektyvi užimamos atminties atžvilgiu (įsitikinkite tuo!), tačiau šiame žingsnyje svarbiausia yra patyrinėti, kaip programos veikimo sparta priklauso nuo konteinerio tipo?

#AntraStrategija - Bendro studentų konteinerio (vector, list ir deque) skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį: "vargšiukai". Tokiu būdu, jei studentas yra vargšiukas, jį turime įkelti į naująjį "vargšiukų" konteinerį ir ištrinti iš bendro studentai konteinerio. Po šio žingsnio studentai konteineryje liks vien tik kietiakai. Atminties atveju tai efektyviau, tačiau dažni trynimai gali būti "skausmingi", ypač tam tikro tipo konteineriams.
1. Palyginta programos sparta naudojant #PirmaStrategija ir #AntraStrategija
2. Patyrinėti ankčiau nenaudoti algoritmai (bandyta, bet nepavykta)
3. Sukurtas MakeFile.
  3.1. Naudoti UNIX OS terminalą.
  3.2. Parašyti make
  3.3. Parašyti ./main
  3.4. Sekti kas rašoma ekrane.
  3.5. Norint ištrinti *.o ir main.exe failus, parašyti make clean
  
## Spartos analizė (#PirmaStrategija)
| File Size   | VECTOR    | LIST      | DEQUE     | 
| ----------- | --------- | --------- | --------- |
| 10 000 000  |           |           |           |
| Nuskaitymas | 6,56743   | 7,4048    | 6,57549   |
| Rūšiavimas  | 22,5238   | 15,1803   | 48,5964   |
| Atskyrimas  | 6,60743   | 19,0359   | 92,5585   |
| Visas Laikas| 35,69864  | 42,5798   | 148,575   |
| 1 000 000   |           |           |           |
| Nuskaitymas | 0,674196  | 0,732539  | 0,661231  |
| Rūšiavimas  | 1,81215   | 1,22027   | 4,02281   |
| Atskyrimas  | 0,590926  | 1,78077   | 1,32697   |
| Visas Laikas| 3,27331   | 3,6892    | 5,98459   |
| 100 000     |           |           |           |
| Nuskaitymas | 0,0787889 | 0,0797862 | 0,0668212 |
| Rūšiavimas  | 0,140624  | 0,0812882 | 0,299705  |
| Atskyrimas  | 0,0518615 | 0,165558  | 0,115691  |
| Visas Laikas| 0,269788  | 0,325131  | 0,480726  |
| 10 000      |           |           |           |
| Nuskaitymas | 0,0069805 | 0,009973  | 0,0089758 |
| Rūšiavimas  | 0,0119678 | 0,0059842 | 0,0239358 |
| Atskyrimas  | 0,0059844 | 0,0139627 | 0,0119675 |
| Visas Laikas| 0,0269274 | 0,0309178 | 0,0428845 |
| 1 000       |           |           |           |
| Nuskaitymas | 0,0009974 | 0,0009963 | 0,0009976 |
| Rūšiavimas  | 0,0009971 | 0,0009985 | 0,0019944 |
| Atskyrimas  | 0,0009975 | 0,0009973 | 0,0009974 |
| Visas Laikas| 0,0029924 | 0,0029921 | 0,0039884 |

Išvada: 
1. Naudojant #AntraStrategija išnaudojama ko ne perpus mažiau atminties.
2. Naudojant #AntraStrategija programos vykdymo greitis spartesnis.

# V0.5 programos versija
## Kas pasikeitė nuo v0.4 versijos?
1. Sukurtos programos naudojant VECTOR, LIST ir DEQUE
2. Programų matavimo sparta.
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

Išvada: 
1. Naudojant list konteinerius programos bendras veikimo laikas greičiausias, antroje vietoje vector konteineris.
2. List rūšiavimas yra greičiausias.
3. Vector atskyrimas greičiausias.
4. Visų konteinerių nuskaitymo laikai +- vienodi.
### main.cpp - pagrindinis failas
### functions.h - struktūros, funkcijų apibrėžimai ir includes
### functions.cpp - funkcijų implementacijos
### mix.h - skaitymo iš failo funkcijos apibrėžimas
### mix.cpp - skaitymo iš failo funkcijos implementacija
### Ką galite daryti su šia programa?
1. Sukurti studentų failą, pasirenkant kiek studentų saugosite.
2. Surikiuoti rezultatus pagal galutinį pažymį.
3. Išvesti rezultatus į failus pagal galutinį pažymį (<5 nelaimingieji.txt, >= 5 kietekai.txt).
4. Pasirinkti kiek pažymių norite generuoti studentui.

# V0.4 programos versija
## Kas pasikeitė nuo v0.3 versijos?
1. Pridėta galimybė pasirinkti kokį dydžio failą generuoti.
2. Pridėta galimybė pasirinkti kiek pažymių generuoti.
3. Patobulintas atsitiktinių skaičių generavimas.
4. Programa išveda kiek laiko užtruko kiekvienas pagrindinis programos veiksmas.
5. Rezultatus išveda į failus kietekai.txt ir nelaimingieji.txt.
### main.cpp - pagrindinis failas
### functions.h - struktūros, funkcijų apibrėžimai ir includes
### functions.cpp - funkcijų implementacijos
### mix.h - skaitymo iš failo funkcijos apibrėžimas
### mix.cpp - skaitymo iš failo funkcijos implementacija
### Ką galite daryti su šia programa?
1. Sukurti studentų failą, pasirenkant kiek studentų saugosite.
2. Surikiuoti rezultatus pagal galutinį pažymį.
3. Išvesti rezultatus į failus pagal galutinį pažymį (<5 nelaimingieji.txt, >= 5 kietekai.txt).
4. Pasirinkti kiek pažymių norite generuoti studentui.

# V0.3 programos versija
## Kas pasikeitė nuo v0.2 versijos?
1. Pridėta exception handling.
2. Funckijos aprašymai ir implementacijos perktelti į atskirus failus. 
### main.cpp - pagrindinis failas
### functions.h - struktūros, funkcijų apibrėžimai ir includes
### functions.cpp - funkcijų implementacijos
### mix.h - skaitymo iš failo funkcijos apibrėžimas
### mix.cpp - skaitymo iš failo funkcijos implementacija
### Ką galite daryti su šia programa?
1. Nuskaityti studentų duomenis iš failo.
2. Surikiuoti rezultatus pagal vardą, pavardę, galutinį pažymį.
3. Išvesti rezultatus į ekraną arba failą.

# V0.2 programos versija
### main.cpp - pagrindinis failas
### functions.h - struktūros, funkcijų apibrėžimai ir includes
### functions.cpp - funkcijų implementacijos
### mix.h - skaitymo iš failo funkcijos apibrėžimas
### mix.cpp - skaitymo iš failo funkcijos implementacija
### Ką galite daryti su šia programa?
1. Nuskaityti studentų duomenis iš failo.
2. Surikiuoti rezultatus pagal vardą, pavardę, galutinį pažymį.
3. Išvesti rezultatus į ekraną.

# V0.1 programos versija
## main.cpp - dinaminis masyvas
## main vektoriai.cpp - vektoriai
### Ką galite daryti su šią programa?
1. Įvesti studentų vardus ir pavardes.
2. Įvesti studentų pažymius ir egzamino rezultatus.
3. Apskaičiuoti galutinį pažymį naudojant vidurkio ir medianos skaičiavimo metodus.
4. Pasirinkti kiek studentų norite įvesti, jei buvo pasirinktas per mažas skaičius, tai suteikiama galimybė įvesti dar.
5. Pasirinkti, jog pažymiai studentui būtų generuojami atsitiktinai.
