#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <iomanip>
#include <string>
#include <random>
#include <ctime>
//#include <vector>
//#include <list>
//#include <deque>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <Windows.h>
#include <memory>
//#include <execution>
#include "vector.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;
//using std::vector;
//using std::list;
//using std::deque;
using std::stringstream;
using std::to_string;

class zmogus {
    protected:
        string vardas_, pavarde_;
    public: 
        inline string vardas() const { return vardas_; }    // get'eriai, inline
        inline string pavarde() const { return pavarde_; }  // get'eriai, inline
        virtual void setVardas(string v) = 0;
        virtual void setPavarde(string p) = 0;
        zmogus(string var = "", string pav = "") : vardas_{var}, pavarde_{pav}{}
};

class duomenys : public zmogus{
    private:
        vector<int> paz_;
        int egz_ = 0;
        int kiekPaz_ = 0;
        double rezult_ = 0;
    public:
        duomenys(vector<int> paz_ = { 0 }, int egz_ = 0, int kiekPaz_ = 0, double rezult_ = 0, string var = "", string pav = "") : zmogus{var, pav} {}
        friend std::ostream& operator << (std::ostream& out, duomenys& d);

        inline double rezult() const { return rezult_; }  // get'eriai, inline
        inline int egz() const { return egz_; }  // get'eriai, inline
        inline int kiekPaz() const { return kiekPaz_; }  // get'eriai, inline
        double skaiciuoti(duomenys&);  // get'eriai
        double mediana(duomenys&);  // get'eriai
        int getPaz(int &i) const {return paz_.at(i);}  // get'eriai

        std::istream& readStudent(std::ifstream&, vector<duomenys>&, double&);  // set'eriai
        void setPaz(int p){paz_.push_back(p);}
        void setKiekPaz(int kiek){kiekPaz_ = kiek;}
        void setRezult(double rez){rezult_ = rez;}
        void setEgz(int egz){egz_ = egz;}
        void setVardas(string v) { vardas_ = v; }
        void setPavarde(string p) { pavarde_ = p; }

        ~duomenys(); // destructor
        duomenys(const duomenys&); // copy constructor
        duomenys& operator=(const duomenys&); // assignment operator
};

//void isvedimas(duomenys&);
bool compare_pavarde(const duomenys&, const duomenys&);
bool compare_g_paz(const duomenys&, const duomenys&);
bool compare_vardas(const duomenys&, const duomenys&);
bool onlyLetters(string);
void rikiavimas(vector<duomenys>&, int, double&);
void spausdinti(vector<duomenys>&, vector<duomenys>&, int/*, double&*/);
int generateFileName(string&, int&);
void generateFileData(string, int, int, double&);
void atskirti(vector<duomenys>&, vector<duomenys>&, int&, double&);
#endif
