#include "project.h"
#include <iostream>

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

    cout << endl;
}

int bin2dec(int num) {
    
    string valida_binario = to_string(num);
    const char *buf_bin = valida_binario.c_str();
    
    for(size_t i = 0; i < valida_binario.size(); i++) {
        if (buf_bin[i] != '0' && buf_bin[i] != '1') {
            cout << "Utilize valores binarios: " << endl;
            return 0;
        }
    }

    int ultimo_digito = {0}, num_dec = {0}, base = {1};
    
    if(num == 0){
        return 0;
    }
    
    while(num) {
       ultimo_digito = num % 10;
       num = num / 10;
       num_dec = num_dec + ultimo_digito * base;
       base = base * 2;
    }
    return num_dec;
}

void _start(int argc, char **argv) { 
   try {
      if(argv[1] == NULL || argv[2] == NULL) {
          cout << "Informe os dois argumentos!" << endl;
          _help();
          return;
      }

      string param = argv[1];
      int number = std::stoi(argv[2]);

      if(argc > 2) {
         if(param == "--dec2bin" || param == "-b") {
             dec2bin(number);
         } else if(param == "--bin2dec" || param == "-d") {
             cout << bin2dec(number) << endl;
         } 
      } 
   } catch (std::invalid_argument&) {
        cout << "Argumentos inválidos!" << endl;
        _help();        
   }
}
