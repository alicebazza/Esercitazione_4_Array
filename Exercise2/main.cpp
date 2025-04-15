#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "src/Utils.hpp"

using namespace std;

int main()
{
	string inputFileName = "./data.txt";
    size_t n = 0;
    double* w = nullptr;
    double* r = nullptr;
    double S = 0.0;
    double R = 0.0;

    if (!ImportData(inputFileName, n, w, r, S))
    {
        cerr<< "Something goes wrong with import"<< endl;
        return -1;
    }
    else
        cout<< "Import successful " << endl;
        cout << "w = " << ArrayToString(n, w)<< endl;
        cout << "r = " << ArrayToString(n, r)<< endl;

    double V = CalculateV(n, w, r, S, R);
    cout << "Tasso di rendimento totale: " << fixed << setprecision(4) << R << endl;
    cout << "Valore finale del portafoglio: " << fixed << setprecision(2) << V << endl;

    string outputFileName = "./result.txt";
    if (!ExportResult(outputFileName, n, w, r, V, S))
    {
        cerr<< "Something goes wrong with export"<< endl;
        return -1;
    }
    else
        cout<< "Export successful"<< endl;

    delete[] w;
    delete[] r;

    return 0;
}

