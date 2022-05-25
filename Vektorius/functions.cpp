#include "functions.h"

bool onlyLetters(string name){
    for(auto i : name){
        if(isdigit(i) == true){
            return false;
        }
    }
    return true;
}

bool compare_pavarde(const duomenys &a, const duomenys &b){
    if(a.pavarde() == b.pavarde()){
        return a.vardas() < b.vardas();
    }
    return a.pavarde() < b.pavarde();
}

bool compare_g_paz(const duomenys &a, const duomenys &b){
    if(a.rezult() == b.rezult()){
        return a.pavarde() < b.pavarde();
    }
    return a.rezult() < b.rezult();
}

bool compare_vardas(const duomenys &a, const duomenys &b){
    if(a.vardas() == b.vardas()){
        return a.pavarde() < b.pavarde();
    }
    return a.vardas() < b.vardas();
}


double duomenys::skaiciuoti(duomenys& temp){
    double vidurkis = 0;
    int suma = 0;
    auto it = temp.paz_.begin();
    for(int i = 0; i < temp.kiekPaz(); i++){
        suma = suma + *it;
        std::advance(it, 1);
    }
    vidurkis = (double)suma / temp.kiekPaz();
    temp.rezult_ = 0.4 * vidurkis + 0.6 * temp.egz();
    //cout << temp.rezult << endl;
    return temp.rezult_;
}

double duomenys::mediana(duomenys& temp){
    double rez = 0;
    int index = temp.kiekPaz()/2;
    vector<int>::iterator it = temp.paz_.begin();
    vector<int>::iterator it2 = temp.paz_.begin();
    if(temp.kiekPaz() % 2 != 0){
        // 1 2 3
        std::advance(it, index);
        rez = *it;
    }
    else{
        // 1 2 3 4
        std::advance(it, index);
        std::advance(it2, index+1);
        rez = (double)((*it) + (*it2)) / 2;
    }
    return rez;
}

duomenys::~duomenys() {
    paz_.clear();
}
duomenys::duomenys(const duomenys& old_duom) {
    //cout << "Copy constructor called " << endl;
    zmogus::vardas_ = old_duom.vardas_;
    zmogus::pavarde_ = old_duom.pavarde_;
    paz_ = old_duom.paz_;
    egz_ = old_duom.egz_;
    kiekPaz_ = old_duom.kiekPaz_;
    rezult_ = old_duom.rezult_;
}

duomenys& duomenys::operator=(const duomenys& other) { // assignment operator
    //cout << "Assignment operator called " << endl;
    paz_.clear();
    if (this != &other) { // protect against invalid self-assignment
        zmogus::vardas_ = other.vardas_;
        zmogus::pavarde_ = other.pavarde_;
        paz_ = other.paz_;
        egz_ = other.egz_;
        kiekPaz_ = other.kiekPaz_;
        rezult_ = other.rezult_;
    }
    return *this;
}
std::ostream& operator << (std::ostream& out, duomenys& d) {
    out << std::left << std::setw(15) << d.pavarde() << std::left << std::setw(15) << d.vardas() << std::left << std::setw(19) << std::fixed << std::setprecision(2) << d.rezult() << std::fixed << std::setprecision(2) << d.mediana(d) << endl;
}

std::istream& duomenys::readStudent(std::ifstream& df, vector<duomenys> &sarasas, double& timeTaken){
    std::vector<std::string> splited;
    std::string eil;
    //----------------------------------------------------------------------
    auto start = std::chrono::high_resolution_clock::now();
    int fileLength = -1;
    //std::ifstream open_f(read_vardas);
    while (df){
      if (!df.eof()) {
          std::getline(df, eil);
          //cout << eil << endl;
          splited.push_back(eil);
          fileLength++;
          }
      else break;
    }
    df.close();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start; // Skirtumas (s)
    std::cout << fileLength << " eiluciu failo nuskaitymas tiesiai į eilučių vektorių užtruko: "<< diff.count() << " s\n";
    timeTaken += diff.count();

    int KiekTarpu = 0;
    for(auto &el : splited)
    {
        for(int i = 0; i < (int)el.length(); i++)
        {
            if(i != (int)el.length()-1){
                //cout << "symb " << el.at(i) << " symb+1 " << el.at(i+1) << endl;
                if((el.at(i) == ' ') && (el.at(i+1) != ' ')){
                    KiekTarpu++;
                }
            }
        }
        break;
    }
    stringstream ss;

    duomenys tempTemp;
    duomenys temp;

    int pazymys, kiek = 1, kiekPazymiu = KiekTarpu-2;
    string vardas, pavarde;

    for(auto &eilute: splited){
        if(kiek == 1)
        {
            ss << eilute;
            ss >> vardas >> pavarde;
            for(int i = 0; i < kiekPazymiu; i++)
                ss >> vardas;
            ss >> vardas;
            kiek = 0;
        }
        else
        {
            ss.clear();
            ss.str("");
            tempTemp = temp;
            ss << eilute;
            ss >> vardas >> pavarde;
            tempTemp.setVardas(vardas);
            tempTemp.setPavarde(pavarde);
            //cout << tempTemp.vardas << " " << tempTemp.pavarde << endl;
            for(int i = 0; i < kiekPazymiu; i++)
            {
                ss >> pazymys;
                tempTemp.setPaz(pazymys);
            }
            tempTemp.setKiekPaz(kiekPazymiu);
            ss >> pazymys;
            tempTemp.setEgz(pazymys);
            double paz;
            paz = tempTemp.skaiciuoti(tempTemp);
            tempTemp.setRezult(paz);
            sarasas.push_back(tempTemp);
        }
            ss.str("");
            ss.clear();
        }
    //auto end = std::chrono::high_resolution_clock::now();
    //std::chrono::duration<double> diff = end-start; // Skirtumas (s)
    //std::cout << fileLength << " eiluciu failo nuskaitymas tiesiai į eilučių vektorių užtruko: "<< diff.count() << " s\n";
    //timeTaken += diff.count();
        return df;
}

void isvedimas(duomenys &temp){
    cout << std::left << std::setw(15) << temp.pavarde() << std::left << std::setw(15) << temp.vardas() << std::left << std::setw(19) << std::fixed << std::setprecision(2) << temp.rezult() << std::fixed << std::setprecision(2) << temp.mediana(temp) << endl;
}

void spausdinti(vector<duomenys> &sarasas, vector<duomenys> &sarasas2, int fileLength/*, double &timeTaken*/){
    auto start = std::chrono::high_resolution_clock::now();
    start = std::chrono::high_resolution_clock::now();
    stringstream my_buffer;

    std::ofstream rf;
    rf.open("kietekai.txt");

    my_buffer << std::left << std::setw(15) << "Pavarde" << std::left << std::setw(15) << "Vardas" << std::left << std::setw(17) << "Galutinis (Vid.) " << "/ Galutinis (Med.)" << endl;
    my_buffer << "-------------------------------------------------------------------" << endl;
    for(auto &el : sarasas2){
        my_buffer << el;
    }
    rf << my_buffer.str();
    my_buffer.str("");
    my_buffer.clear();
    rf.close();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start; // Skirtumas (s)
    diff = std::chrono::high_resolution_clock::now()-start; // Skirtumas (s)
    //std::cout << fileLength << " eiluciu irasymas i faila (nelaimingieji.txt) uztruko: "<< diff.count() << " s\n";
    //timeTaken += diff.count();

    start = std::chrono::high_resolution_clock::now();
    std::ofstream rf2;
    rf2.open("nelaimingieji.txt");
    my_buffer << std::left << std::setw(15) << "Pavarde" << std::left << std::setw(15) << "Vardas" << std::left << std::setw(17) << "Galutinis (Vid.) " << "/ Galutinis (Med.)" << endl;
    my_buffer << "-------------------------------------------------------------------" << endl;
    for(auto &el : sarasas){
        my_buffer << el;
    }
    rf2 << my_buffer.str();
    my_buffer.str("");
    my_buffer.clear();
    rf2.close();

    end = std::chrono::high_resolution_clock::now();
    diff = std::chrono::high_resolution_clock::now()-start; // Skirtumas (s)
    //std::cout << fileLength << " eiluciu irasymas i faila (kietekai.txt) uztruko: "<< diff.count() << " s\n";
    //timeTaken += diff.count();
}

void rikiavimas(vector<duomenys>& sarasas, int fileLength, double &timeTaken){
    string rusiuoti = "3";
    //cout << "Pagal ka norite rusiuoti? (nieko nerusiuoti - 0, varda - 1, pavarde - 2, galutini pazymi - 3)" << endl;
    //cin >> rusiuoti;
    //while((rusiuoti != "1" && rusiuoti != "2" && rusiuoti != "3" && rusiuoti != "0") || onlyLetters(rusiuoti) == true){ //|| rusiuoti != 1 || rusiuoti != 2 || rusiuoti != 3
    //    cout << "Ivedete netinkamus duomenis, bandykite dar karta!" << endl;
    //    cin.clear();
    //    cin.ignore(256,'\n');
    //    cin >> rusiuoti;
    //}
    auto start = std::chrono::high_resolution_clock::now();

//    if(rusiuoti == "1")
//        //sort(sarasas.begin(), sarasas.end(), compare_vardas);
//    else if(rusiuoti == "2")
//        //sort(sarasas.begin(), sarasas.end(), compare_pavarde);
//    else if(rusiuoti == "3")

//        auto lambda_func = [&](duomenys t1, duomenys t2){
//            if(t1.rezult == t2.rezult){
//                return t1.pavarde < t2.pavarde;
//            }
//            return t1.rezult < t2.rezult;
//        };
//        sort(sarasas.begin(), sarasas.end(), lambda_func);
        sort(sarasas.begin(), sarasas.end(), compare_g_paz);

        //sarasas.sort(compare_g_paz);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start; // Skirtumas (s)
    std::cout << fileLength << " eiluciu rusiavimas uztruko: "<< diff.count() << " s\n";
    timeTaken += diff.count();
}

int generateFileName(string& generatedFileName, int& pazymiuKiekis) {
    int fileLength;
    generatedFileName = "kursiokai";
    cout << "Kokio ilgio faila generuoti?" << endl;
    cin >> fileLength;
    /*while(cin.fail()){
        cout << "Ivedete netinkamus duomenis, bandykite dar karta!" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> fileLength;
    }*/
    generatedFileName += to_string(fileLength) + ".txt";
    //cout << fileLength << endl;
    //cout << generatedFileName << endl;

    cout << "Iveskite kiek pazymiu tures studentai?" << endl;
    cin >> pazymiuKiekis;
    cout << endl;
    /*while(cin.fail()){
        cout << "Ivedete netinkamus duomenis, bandykite dar karta!" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> pazymiuKiekis;
    }*/

    return fileLength;
}

void generateFileData(string generatedFileName, int fileLength, int pazymiuKiekis, double & timeTaken){
    vector<string> vardas = {"Petras", "Antanas", "Jonas", "Tomas", "Valdas", "Romas", "Lukas", "Matas", "Virgis", "Mantas", "Kazys"};
    string generatedName;

    vector<string> pavarde = {"Petraitis", "Antanaitis", "Jonaitis", "Tomaitis", "Valdaitis", "Romaitis", "Lukaitis", "Mataitis", "Virgaitis", "Mantaitis", "Kazaitis"};
    string generatedSurname;

    using hrClock = std::chrono::high_resolution_clock;
    std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
    std::uniform_int_distribution<int> name(0, vardas.size()-1);
    std::uniform_int_distribution<int> surname(0, pavarde.size()-1);
    std::uniform_int_distribution<int> pazymys(1, 10);

    std::ofstream rf;
    rf.open(generatedFileName);
    string ND;
    int a = 0;
    std::stringstream my_buffer;

    auto start = std::chrono::high_resolution_clock::now();

    //Virsutines eilutes spausdinimas
    my_buffer << std::left << std::setw(15)<< "Vardas" <<
    std::left << std::setw(15) << "Pavarde";
    for(int i = 0; i < pazymiuKiekis; i++){
        ND = "";
        ND += "ND" + to_string(i+1);
        my_buffer << std::setw(10) << ND;
    }
    my_buffer << "Egz.";
    my_buffer << endl;

    //Studentu eilutes spausdinimas
    for(int i = 0; i < fileLength; i++){
        generatedName = vardas.at(name(mt));
        generatedSurname = pavarde.at(surname(mt));
        my_buffer << std::setw(15) << generatedName
        << std::left << std::setw(15) << generatedSurname;
        for(int j = 0; j < pazymiuKiekis; j++){
           my_buffer << std::setw(10) << pazymys(mt);
        }
        a++;
        my_buffer << pazymys(mt);
        if(a < fileLength)
            my_buffer << endl;
    }
    rf << my_buffer.str();
    my_buffer.str("");
    my_buffer.clear();
    rf.close();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start; // Skirtumas (s)
    std::cout << fileLength << " eiluciu failo sukurimas uztruko: "<< diff.count() << " s\n";
    timeTaken += diff.count();

    cout << "Failas: " << generatedFileName << " sekmingai sukurtas!" << endl;
}

void atskirti(vector<duomenys>& sarasas, vector<duomenys>& sarasas2, int& fileLength, double &timeTaken){
    auto start = std::chrono::high_resolution_clock::now();

   //vector<duomenys>::iterator it;
   //for(it = sarasas.begin(); it != sarasas.end(); ++it){
   //    if(it->rezult() >= 5){
   //        break;
   //    }
   //}
   //std::copy(it, sarasas.end(), back_inserter(sarasas2));
   ////sarasas.erase(it, sarasas.end());
   ////cout << sarasas.size()-sarasas2.size() << endl;
   //sarasas.reserve(sarasas.size()-sarasas2.size());

    //vector<duomenys>::iterator it = sarasas.end(); it--;
    for(auto it = sarasas.size(); it > 0; --it){
        //cout << sarasas.at(it).pavarde() << endl;
        if(sarasas.at(it-1).rezult() >= 5){
            sarasas2.push_back(sarasas.at(it-1));
            sarasas.pop_back();
        }
        if(sarasas2.size() % (fileLength / 10) == 0){
            sarasas2.shrink_to_fit();
            //neveikia!
            //sarasas.shrink_to_fit();
        }
    }

    //netikslinga
    //sarasas2.reserve(fileLength);

//    for(auto el = sarasas.end()-1; el >= sarasas.begin(); el--){
//        if(el->rezult >= 5){
//            sarasas2.push_back(*el);
//            sarasas.pop_back();
//        }
//        if(sarasas2.size() % (fileLength / 10) == 0){
//            sarasas2.shrink_to_fit();
//            //sarasas.shrink_to_fit();
//        }
//    }
//    for(long int i = sarasas.size()-1; i >= 0; i--){
//        //cout << el.vardas << "    " << el.pavarde << "      " << el.rezult << endl;
//        if(sarasas.at(i).rezult >= 5){
//            sarasas2.push_back(sarasas.at(i));
//            sarasas.pop_back();
//        }
//    }
//    vector<duomenys> temp;
//    for(auto &el : sarasas){
//        //cout << el.vardas << "    " << el.pavarde << "      " << el.rezult << endl;
//        if(el.rezult >= 5){
//            sarasas2.push_back(el);
//        }
//        else{
//            temp.push_back(el);
//        }
//    }
//    sarasas = temp;
//    temp.clear();
    sarasas.shrink_to_fit();
    sarasas2.shrink_to_fit();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start; // Skirtumas (s)
    std::cout << fileLength << " eiluciu failo dalijimo i dvi grupes laikas, panaikinant pradini vector: "<< diff.count() << " s\n";
    timeTaken += diff.count();
}
