#pragma once

#include <iostream>

using namespace std;

// ImportData legge i valori di input 
// inputFilePath: nome del file di input
// n: numero di elementi in w e r
// w: frazioni di investimento
// r: tassi di rendimento
// S: valore iniziale dell'investimento
// restituisce true se il file è stato letto correttamente, false in caso di errore
bool ImportData(const string& inputFilePath, 
                   size_t& n,
                   double*& w, 
                   double*& r,
                   double& S);

// CalculateV calcola il valore finale del portafoglio
// n: numero di elementi in w e r
// w: frazioni di investimento
// r: tassi di rendimento
// S: valore iniziale dell'investimento
// R: tasso di rendimento totale
// restituisce il valore totale del portafoglio
double CalculateV(const size_t& n,
                        const double* const& w,
                        const double* const& r,
                        const double& S,
                        double& R);

// ArrayToString converte un array di valori in una stringa formattata
// n: numero di elementi nell'array
// v: array da convertire
// Restituisce la stringa
string ArrayToString(const size_t& n,
                     const double* const& v);

// ExportResult esporta i risultati in un file di output
// inputFilePath: nome del file di input
// n: numero di elementi in w e r
// w: frazioni di investimento
// r: tassi di rendimento
// V: valore finale del portafoglio
// S: valore iniziale dell'investimento
bool ExportResult(const string& outputFilePath,
                  const size_t& n,
                  const double* const& w,
                  const double* const& r,
                  const double& V,
                  const double& S);
