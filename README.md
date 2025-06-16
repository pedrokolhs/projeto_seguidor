 Algoritmo de Navegação seguidor de parede

Este projeto é um exemplo simples de implementação do algoritmo de seguidor de parede usando o robô Edubot e a biblioteca `EdubotLib`. O objetivo é permitir que o robô navegue evitando obstáculos, tomando decisões com base nas distâncias medidas por sensores.

Descrição do Funcionamento

O algoritmo faz com que o robô:

- Ande para frente até encontrar um obstáculo.
- Use sensores laterais para decidir o próximo movimento.
- Execute giros de 90° para contornar obstáculos.
- Continue se movendo, sempre tentando manter uma direção de avanço.

A lógica é baseada em uma versão simplificada da técnica de seguir paredes (wall following).

Lógica de Decisão

- Sensor 6 (direita): Mede a distância lateral direita.
- Sensor 0 (esquerda): Mede a distância lateral esquerda.

 Condições principais:

- Se parede na direita e livre na esquerda → Girar 90° à esquerda.
- Se parede na esquerda e livre na direita → Girar 90° à direita.
- Se ambos os lados estão livres → Girar 90° à esquerda (por padrão).

Após cada giro, o robô avança até encontrar novo obstáculo à frente.

 Estrutura do Projeto
├──main.cpp # Código-fonte principal
└── libs/
└── EdubotLib.hpp # Biblioteca de controle do Edubot
