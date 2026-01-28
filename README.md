# Conversor-Binario-Decimal
Projeto em desenvolvimento em C++, com foco na compreensão de conceitos e técnicas da linguagem, incluindo manipulação de strings, conversões numéricas, limites de tipos e tratamento de erros.

# Limitações atuais
Na atual implementação, existe um limite para os valores suportados durante a conversão, imposto pelo tipo numérico utilizado (int de 32 bits com sinal).
Ao interpretar o argumento de entrada como um valor decimal, números como 1111111111 passam a representar aproximadamente 1,1 Bilhão, enquanto a adição de mais um zero a direita resulta em aproximadamente 11 Bilhões, ultrapassando o valor máximo suportado por um int com sinal, que é algo em torno de 2,1 Bilhões.

No contexto da conversão binária para decimal, o maior valor atualmente suportado é 1111111111 (10 bits), que corresponde a 1023 em decimal. Valores binários maiores não são suportados até o momento.

Valor decimal máximo atualmente suportado: 2147483647.

# Objetivo do projeto
O objetivo deste projeto é evoluir o conversor para suportar a conversão correta de números com mais de 500 bits, eliminando a dependência de tipos numéricos nativos e evitando problemas de overflow.
