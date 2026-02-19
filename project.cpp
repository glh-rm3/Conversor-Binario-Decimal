#include "project.h"
#include <iostream>
#include <cmath>

using namespace std;

void _help() {
    cout << endl;
    cout << "Uso: ./a.out [--parametros] [numero]\n"
                 " --dec2bin Para Converter decimal para binário\n"
                 " --bin2dec Para Converter binário para decimal\n\n";
}

void dec2bin(int num) {
    int bin_arr[32], i = {0};
    
    if(num == 0) {
        cout << num << endl;
        return;
    }

    while(num > 0 ) {
        bin_arr[i] = num % 2;
        num = num / 2;
        i++;
    }

    for(int j = i - 1; j >= 0; j--) {
         cout << bin_arr[j];
    }
}

unsigned long long int bin2dec(string number) {
    
    const char *buf_bin = number.c_str();    
    for(size_t i = 0; i < number.size(); i++) {
        if (buf_bin[i] != '0' && buf_bin[i] != '1') {
            cout << "Utilize valores binarios: " << endl;
            return 0;
        }
    }

    int indice = 0;
    unsigned long long int somador = 0;
    for(size_t i = number.size() - 1; buf_bin[i] != '\0' > 0; i--) { //Necessário inverter buf_bin, 
                                                                     //pois o bit mais significativo(MSB) fica à esquerda.                                                               
        int j = buf_bin[i] - '0'; //convesao char para int.

        //aplicando a regra do polinomio
        if(j == 0) somador = somador + 0;
        if(j == 1) somador += pow(2, indice);
    indice++;
  }
  return somador;
}

void _start(int argc, char **argv) { 
   try {
      if(argv[1] == NULL || argv[2] == NULL) {
          cout << "Informe os dois argumentos!" << endl;
          _help();
          return;
      }

      string param = argv[1];
      string number = argv[2];
    
      if(argc > 2) {
         if(param == "--dec2bin" || param == "-b") {
              int num = stoi(number);
              dec2bin(num);
         } else if(param == "--bin2dec" || param == "-d") {
             cout << bin2dec(number) << endl;
         } 
      } 
   } catch (std::invalid_argument&) {
        cout << "Argumentos inválidos!" << endl;
        _help();        
   }
}
