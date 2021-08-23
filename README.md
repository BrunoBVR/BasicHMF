**Bruno Vieira Ribeiro 2/2013**

**Instituto de Física - Universidade de Brasília**

Programa: Dinâmica Molecular - HMF

O executável "compall" (compilador) gera 4 novos executáveis (programas):

- "simp_rep.exe" : HMF repulsivo, condição inicial -> Waterbag;
- "simp_rep_beam.exe" : HMF repulsivo, condição inicial -> Feixes;
- "simp_atr.exe" : HMF atrativo, condição inicial -> Waterbag;
- "simp_atr_beqm.exe" : HMF atrativo, condição inicial -> Feixes.

Ao rodar um programa, este cria os arquivos:
- energy.dat :	Evolução das energias cinética (segunda coluna) e potencial (terceira coluna);
- error.dat : 	O erro do integrador (testa conservação de energia);
- mag.dat :		Evolução da magnetização. Segunda coluna - Mx,		  Terceira - My, Quarta - M;
- InitPhase--" ".dat e FinalPhase--" ".dat :	Retrato de fases
	inicial e final do sistema. atr ou rep será escrito entre as
	" " indicando o tipo do potencial.


Além dos arquivos, duas pastas serão criadas:

- evol :	Contendo figura em .eps com os retratos de fase do sistema em t=0 e em t=tf;
- figs :	Contendo figuras em .eps com a evolução das energias e das magnetizações.


O nome de cada figura indica o número de partículas usadas na simulação e o valor de p0 ( alcance dos momentos na condição inicial, na caso de Waterbag; e valor mínimo do momento, no caso de Feixes).


FUNÇÕES DO PROGRAMA:

- condini.c : Gera condições iniciais Waterbag;
- condini_beam.c : Gera condições iniciais em Feixes;
- force_atr.c : Gera o array das forças no caso atrativo;
- force_rep.c : Gera o array das forças no caso repulsivo;
- ran2.c : Gerador de número pseudo-aleatório;
- timestep.c : Integrador numérico de quarta ordem (YOSHIDA);
- simp_atr.c e simp_rep.c : Programas principais.


REQUISITO DA MÁQUINA:

Versão 3.x do programa gnuplot instalado.

NOTA:	Rodar os executáveis a partir de um terminal Linux.

NOTA2:	O arquivo "data.in" carrega todas as informações iniciais do programa. São elas:
- dt : o passo do integrador;
- tf : tempo final da simulação;
- ts : tempo de início de plotagem;
- p0 : alcance dos momentos na condição inicial, na caso de Waterbag; e valor mínimo do momento, no caso de Feixes
- theta0 :	alcance dos valores de posição inicial;
- n : número total de partículas;
- seed : semente para o gerador "ran2.c" de números aleatórios.

Uma vez compilado o programa, basta modificar os valores em
"data.in" para gerar novos dados. Não é necessário compilar
novamente.

NOTA3: As pastas "evol" e "figs" já vem com algumas figuras de exemplo. As figuras de exemplo têm nome iniciando com "SAMPLE-----".
