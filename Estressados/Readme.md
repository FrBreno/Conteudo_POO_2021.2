## Autoria deste arquivo
- Arquivo baseado em Readme.md by https://github.com/senapk/estressados

## Contexto - estressados

- Na entrada de um evento de um experimento social, os participantes ganhavam uma pulseira especial que precisavam ficar utilizando.
- A pulseira informava, num pequeno visor, um número inteiro que representava o nível de stress daquele participante.
- Nenhum participante sabia o que aquele número significava.
- O número 1 significava totalmente tranquilo e ia aumentando conforme o stress do participante aumentava a´té o valor máximo de 99.
- Para fazer uma representação lógica, os números positivos representam homens e os números negativos representam mulheres em um vetor de inteiros.
- Precisamos escrever os algorítmos que identifiquem informações importantes sobre os participantes da fila.

## Exercícios

## PARTE I

### **Busca**: 4 funções
- **existe**: Alguém com o valor X está na fila?
- **contar**: Quantas vezes o valor X apareceu na fila?
- **procurar**: Em que posição da fila aparece X pela primeira vez?
- **procurar_apartir**: Dada a posição para iniciar a busca, qual a próxima posição em que aparece X?

### **Melhor caso**: 4 funções
- **procurar_menor**: qual o menor valor da lista?
- **procurar_pos_menor**: qual a posição do menor valor da lista?
- **procurar_pos_menor_apartir**: Dada a posição para iniciar a busca, qual a posição do menor valor da lista?
- **procurar_pos_melhor_se**: qual a posição do HOMEM mais calmo? (menor valor maior que 0)

### **Contagem**: 4 funções
- **calcular_stress_medio**: qual a média de stress da fila? (abs)
- **mais_homens_ou_mulheres**: Na fila existem mais homens ou mulheres?
- **qual_metade_eh_mais_estressada**: O nível de stress somado de todas as pessoas da primeira metade é maior que o nível de stress somado das pessoas da segunda metade da fila? (abs)
- **homens_sao_mais_estressados_que_mulheres**: a média do stress dos homens é maior que a das mulheres? 

## PARTE II

### **Filter - Operações de Filtragem**: 4 funções
- **clonar**: retorna um novo vetor copiando os valores do vetor de entrada
- **pegar_homens**: retorne uma lista com os homens (valores positivos)
- **pegar_calmos**: retorne uma lista com as pessoas com stress menor que 10 (abs)
- **pegar_mulheres_calmas**: retorne uma lista com as mulheres com nível de stress menor que 10.(negativos menor que 10)

### **Acesso**: 5 funções
- **inverter_com_copia**
- **inverter_inplace**
- **sortear**
- **embaralhar**
- **ordenar** - selection sort utilizando 

### **Conjuntos**: 3 funções
- **exclusivos**: O fiscal permitiu a entrada de um único representante de cada valor, ou seja, uma lista dos valores que aparecem na fila sem repetição. Que conjunto foi formado?
- **diferentes**: Qual a lista dos diferentes níveis de stress que aparecem?
- **abandonados**: quais pessoas ficaram na fila após remover um exemplar de cada valor?

## PARTE III

### **Map - Manipulação**: 3 funções
- **sozinhos**: Quais PESSOAS eram as únicas representantes do seu nível de stress na fila? (abs)
- **mais_ocorrencias**: Qual a maior quantidade de ocorrências do mesmo nível de stress. (abs)
- **mais_recorrentes**: Quais os níveis de stress mais recorrentes. (abs)

### **Proximidade**: 2 funções
- **briga** Quando alguém super estressado(>50) está ao lado de duas pessoas muito estressadas(>30) pode dar briga. Quantas vezes essa situação acontece?
- **apaziguado** Se alguém hiper estressado(>80) estiver ao lado de pelo menos uma pessoa bem tranquila (<10) ela vai ser apaziguada. Em que posições estão esses que serão apaziguados?

### **Sequências**: 3 funções
- **quantos_times** Duas ou mais pessoas do mesmo sexo seguidas podem formar um time. Quantos times existem na fila?
- **maior_time** Qual o maior time que apareceu na fila?
- **sem_time** Quantas pessoas não estavam em um time?

### **Grupos**: 2 funções
- **casais**: Casais são formados quando quando um homem e uma mulher com o mesmo nível de stress são formados. O 3 e o -3 formam um casal. Os participantes fossem orientados a sair da fila e procurar seu par. Quantos casais poderiam ser formados?
- **trios**: Pedimos pros participantes se organizassem em trios. Todos os 3 deveriam estar com o mesmo nível de stress.Quantos trios podem ser formados?

### **Alteração**: 3 funções
- **remove**: Dado a pessoa X, como fica a fila após remover X?
- **insert**: Como fica a fila se eu inserir a pessoa X na posição Y.
- **dance**: O coordenador disse: se você está do lado de alguém da com o mesmo nível de stress que você, saia da fila com ele. Quando os pares saiam, as vezes se formavam novos pares que também saíam. Quem ficou na fila?

