#include "Utils.hpp"
#include "iostream"
#include "fstream"
#include "sstream"
#include "iomanip"

using namespace std;

bool ImportData(const string& inputFilePath, 
                   size_t& n,
                   double*& w, 
                   double*& r,
                   double& S)
{   
	// Apro il file
    ifstream file(inputFilePath);

    if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }

    // Ottengo la dimensione di w e r
    string line;
    
    getline(file, line);
    S = stod(line.substr(line.find(";") + 1));
    getline(file, line);
    n = stoi(line.substr(line.find(";") + 1));    

    // Costruisco w e r
    getline(file,line); // salto la riga w;r
    w = new double [n];
    r = new double [n];
    
    int i = 0;
    while(getline(file,line) && i<n) {
	    w[i] = stod(line.substr(0, line.find(";")));
        r[i] = stod(line.substr(line.find(";") + 1));
	    i ++;
	}
	
    // Chiudo il file
    file.close();

    return true;	
}

double CalculateV(const size_t& n,
                        const double* const& w,
                        const double* const& r,
                        const double& S,
                        double& R)
{
	R = 0.0;
	double V = 0.0;
	for (unsigned int i = 0; i < n; i++)
	    R += w[i] * r[i];
	V = S * (1 + R);
    return V;
}

string ArrayToString(const size_t& n,
                     const double* const& v)
{
    string str;
    ostringstream toString;
    
    toString << "[ ";
    for (unsigned int i = 0; i < n; i++)
        toString<< v[i]<< " ";
    toString << "]";

    return toString.str();
}

bool ExportResult(const string& outputFilePath,
                  const size_t& n,
                  const double* const& w,
                  const double* const& r,
                  const double& V,
                  const double& S)
{
    // Apro il file
    ofstream file;
    file.open(outputFilePath);

    if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }

    file << "S = " << fixed << setprecision(2) << S << ", n = " << n << endl;

    file << "w = " << ArrayToString(n,w) << endl;
    file << "r= " << ArrayToString(n,r) << endl;
    file << "Rate of return of the portfolio: " << fixed << setprecision(4) << (V - S) / S << endl;
    file << "V: " << fixed << setprecision(2) << V << endl;
    
    // Chiudo il file
    file.close();

    return true;
}

