## Backlog do Projeto miniRT

### Fase 1: Setup e Estrutura Base
- [x] Criar estrutura de diretórios do projeto
- [x] Configurar Makefile com flags `-Wall -Wextra -Werror`
- [x] Adicionar regras: `all`, `clean`, `fclean`, `re`
- [x] Integrar libft (se for usar)
- [x] Configurar MiniLibX (sistema ou fontes)
- [x] Criar estrutura básica de arquivos `.c` e `.h`
- [x] Implementar função `main()` básica

### Fase 2: Parsing do Arquivo .rt
- [x] Ler e validar argumentos (arquivo `.rt`)
- [x] Implementar parser para ler linhas do arquivo
- [x] Validar formato básico do arquivo
- [x] Parser para Iluminação Ambiente (A)
  - [x] Validar taxa [0.0, 1.0]
  - [x] Validar cores RGB [0-255]
- [x] Parser para Câmera (C)
  - [x] Validar coordenadas x,y,z
  - [x] Validar vetor normalizado [-1,1]
  - [x] Validar FOV [0,180]
- [x] Parser para Luz (L)
  - [X] Validar coordenadas x,y,z
  - [X] Validar taxa de brilho [0.0, 1.0]
- [x] Parser para Esfera (sp)
- [x] Parser para Plano (pl)
- [x] Parser para Cilindro (cy)
- [x] Validar que A, C, L aparecem apenas uma vez
- [x] Tratamento de erros com mensagens explícitas
- [x] Liberar memória corretamente em caso de erro

### Fase 3: Matemática e Estruturas de Dados
- [x] Criar estruturas para vetores 3D
- [x] Implementar operações básicas de vetores (soma, subtração, produto escalar, produto vetorial)
- [x] Implementar operações básicas de matrizes (comparação, multiplicalção, transposição, determinante)
- [x] Implementar normalização de vetores
- [ ] Criar estruturas para raios (origem, direção) (vou implementar essa estrutura na fase 5)
- [x] Criar estruturas para objetos (esfera, plano, cilindro)
- [x] Criar estruturas para câmera e luz

### Fase 4: Transformação de Matrizes
- [ ] Implementar matrizes de translação para pontos e objetos
- [ ] Implementar matrizes de escala para pontos, vetores e objetos
- [ ] Implementar matrizes de rotação (eixos X, Y, Z)
- [ ] Implementar matriz de shear (cisalhamento)
- [ ] Implementar composição/encadeamento de transformações (produto de matrizes)
- [ ] Aplicar transformações de matriz à câmera e aos objetos da cena

### Fase 5: Cálculo de Interseções
- [ ] Implementar interseção raio-esfera
  - [ ] Tratar todos os casos (sem interseção, uma, duas)
  - [ ] Tratar interior da esfera
- [ ] Implementar interseção raio-plano
  - [ ] Tratar todos os casos
  - [ ] Tratar interior do plano
- [ ] Implementar interseção raio-cilindro
  - [ ] Tratar interseção com corpo do cilindro
  - [ ] Tratar interseção com tampas (topo e base)
  - [ ] Tratar todos os casos possíveis
  - [ ] Tratar interior do cilindro
- [ ] Implementar função para encontrar interseção mais próxima
- [ ] Calcular normal no ponto de interseção para cada objeto

### Fase 6: Sistema de Iluminação
- [ ] Implementar iluminação ambiente
- [ ] Implementar iluminação difusa
- [ ] Implementar cálculo de sombras duras
  - [ ] Verificar se há objetos entre ponto e luz
- [ ] Combinar iluminação ambiente + difusa
- [ ] Garantir que objetos nunca fiquem completamente escuros

### Fase 7: Ray Tracing Core
- [ ] Implementar função principal de ray tracing
- [ ] Calcular raio primário para cada pixel
- [ ] Encontrar interseção mais próxima
- [ ] Calcular cor do pixel baseado na iluminação
- [ ] Renderizar imagem completa

### Fase 8: MiniLibX e Interface
- [x] Inicializar conexão com MiniLibX
- [x] Criar janela
- [x] Criar imagem (usar `images` é recomendado)
- [ ] Renderizar cena na imagem
- [x] Exibir imagem na janela
- [x] Implementar hook para tecla ESC (fechar programa)
- [x] Implementar hook para botão X (fechar programa)
- [ ] Gerenciar eventos da janela (minimizar, alternar, etc.)
- [x] Limpar recursos ao sair

### Fase 9: Transformações (se necessário)
- [ ] Implementar translação de objetos
- [ ] Implementar rotação de objetos (exceto esferas e luzes)
- [ ] Implementar redimensionamento (diâmetro esfera, dimensões cilindro)

### Fase 10: Validação e Testes
- [ ] Criar cenas de teste básicas
- [ ] Testar cada objeto isoladamente
- [ ] Testar múltiplos objetos na mesma cena
- [ ] Testar diferentes posições de câmera
- [ ] Testar diferentes posições de luz
- [ ] Testar casos de erro no arquivo `.rt`
- [ ] Validar que não há vazamentos de memória
- [ ] Testar com valgrind
- [ ] Verificar norma da 42

### Fase 11: Refinamento
- [ ] Revisar código para seguir norma da 42
- [ ] Otimizar se necessário
- [ ] Documentar funções complexas
- [ ] Criar conjunto completo de cenas para defesa
- [ ] Preparar explicação do código para avaliação

## Sugestões de Organização

1. Dividir tarefas entre vocês dois
2. Priorizar: Setup → Parsing → Matemática → Interseções → Iluminação → Ray Tracing → Interface
3. Testar incrementalmente: após cada funcionalidade, testar antes de seguir
4. Revisar código em conjunto: especialmente partes críticas como interseções e iluminação

## Estrutura de pastas

```
miniRT/
├── includes/         # Arquivos de cabeçalho (.h)
├── src/              # Arquivos fonte (.c)
│   ├── main.c
│   ├── parsing/      # Parser do arquivo .rt
│   ├── math/         # Operações matemáticas (vetores, etc)
│   ├── obj/          # Objetos geométricos (esfera, plano, cilindro)
│   ├── ray_tracing/  # Lógica de ray tracing
│   ├── lighting/     # Sistema de iluminação
│   ├── interface/    # Operações com MiniLibX
│   └── test/         # Testes dos objetos e operações
├── libft/            # Libft
├── minilibx/         # Gerenciamento da MiniLibX
├── Makefile
├── .gitignore
├── .cursorrules
└── BACKLOG.md
```