#include "functions.h"

int main()
{
    // Set console code page to UTF-8 so console known how to interpret string data
    SetConsoleOutputCP(CP_UTF8);

    // Enable buffering to prevent VS from chopping up UTF-8 byte sequences
    setvbuf(stdout, nullptr, _IOFBF, 1000);

    int fileLength;
    int pazymiuKiekis;
    double timeTaken = 0;

    string generuoti;
    cout << "Ar norite generuoti faila? (0 - ne, 1 - taip)" << endl;
    cin >> generuoti;
    //while((generuoti != "0" && generuoti != "1") || onlyLetters(generuoti) == true){
    //    cout << "Ivedete netinkamus duomenis, bandykite dar karta!" << endl;
    //    cin.clear();
    //    cin.ignore(256,'\n');
    //    cin >> generuoti;
    //}
    if(generuoti == "1"){
        string generatedFileName;
        //Failo pavadinimo ir ilgio pasirinkimas

        fileLength = generateFileName(generatedFileName, pazymiuKiekis);

        //Failo duomenu kurimas
        generateFileData(generatedFileName, fileLength, pazymiuKiekis, timeTaken);
    }
    else{
        string generatedFileName = "kursiokai";
        int fileLength;

        cout << "Iveskite failo ilgi" << endl;
        cin >> fileLength;

        //while(cin.fail()){
        //    cout << "Ivedete netinkamus duomenis, bandykite dar karta!" << endl;
        //    cin.clear();
        //    cin.ignore(256,'\n');
        //    cin >> fileLength;
        //}

        generatedFileName += to_string(fileLength) + ".txt";

        vector<duomenys> sarasas; //Nelaimingieji
        vector<duomenys> sarasas2; //Kietekai
        duomenys skaityti;
        try{
            std::ifstream df(generatedFileName);
            if(!df)
                throw 1;
            df.close();
        }
        catch(int x){
            cout << "Toks duomenu failas ('" << generatedFileName << "') neegzistuoja, Klaidos kodas: " << x << endl;
            exit(0);
        }
        std::ifstream df(generatedFileName);
        skaityti.readStudent(df, sarasas, timeTaken);
        //mix(generatedFileName, "kursiokai_copy.txt", sarasas, fileLength, timeTaken);
        rikiavimas(sarasas, fileLength, timeTaken);
        atskirti(sarasas, sarasas2, fileLength, timeTaken);
        spausdinti(sarasas, sarasas2, fileLength/*, timeTaken*/);
        cout << '\n';
        cout << fileLength << " irasu testo laikas: " << std::setprecision(6) << timeTaken << endl;   

        //duomenys str1, str2;
        //str1.setVardas("Hubertas");
        //str1.setPavarde("KL");
        //duomenys str3 = str1;
        //str2 = str1;

        //cout << str1.vardas() <<endl; // what is printed ?
        //cout << str2.vardas() << endl;

        //str2.setVardas("KLAN");

        //cout << str1.vardas() << endl; // what is printed now?
        //cout << str2.vardas() << endl;
        //duomenys zmog;
    }
    return 0;
}
