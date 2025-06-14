/*
 * EDUBOT PLEDGE ALGORITHM EXAMPLE
 * @Author: Seu Nome
*/

#include <iostream>
#include "libs/EdubotLib.hpp"

using namespace std;

// Função que realiza o movimento do robô
void movimento(EdubotLib *edubotLib) {
    
    while (edubotLib->getSonar(3) > 0.15 ){
        edubotLib->move(0.1); 
        edubotLib->sleepMilliseconds(100);
    }
}

int main() {
    EdubotLib *edubotLib = new EdubotLib(); 
    
    if(edubotLib->connect()) {
    	edubotLib->move(0.1); 
        edubotLib->sleepMilliseconds(100);
        movimento(edubotLib);
        
        int direcao = 0; // Contador de direções (0 = reto, 1 = direita, -1 = esquerda)
        
        while (true) { // Loop contínuo

        
            double distanciaDireita = edubotLib->getSonar(6); 
            double distanciaEsquerda = edubotLib->getSonar(0); 
            
            // Verifica se há uma parede à direita
            if (distanciaDireita <= 0.15 && distanciaEsquerda >0.14) {
                
                edubotLib->rotate(-90);
                edubotLib->sleepMilliseconds(2000);
                movimento(edubotLib); 
                direcao = 1; 
                
            } else if (distanciaDireita >0.14 && distanciaEsquerda <= 0.15) {
                
                edubotLib->rotate(90);
                edubotLib->sleepMilliseconds(2000);
                movimento(edubotLib); 
                direcao = -1; 
                
            } else if (distanciaDireita > 0.15 && distanciaEsquerda > 0.15){
            	edubotLib->rotate(-90);
                edubotLib->sleepMilliseconds(2000);
                movimento(edubotLib); 
                direcao = -1; 
            }
        }
        
        edubotLib->disconnect();
    } else {
        std::cout << "Could not connect on robot!" << std::endl;
    }

    // Libera a memória alocada
    delete edubotLib;

    return 0;
}