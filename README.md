# Trabalho de Métodos Numéricos II

## Implementação do filtro de detecção de borda com aproximação de derivada simples.

### Integrantes
João Batista de Freitas Filho - Matrícula: 414644
Felipe Barros Damasceno - Matricula: 412983 


### Como iniciar o programa

Extraia o programa em algum diretório

Compile-o com make (se quiser compilar todos os arquivos do zero, use make fresh)

Execute o arquivo .out que estará localizado na pasta build

Para executar o arquivo, passe o path relativo à imagem que deseja usar.

Por fins de conveniência, a pata build já contém algumas imagens para usar de teste para o programa, mas, para uma utilização mais fácil, é recomendado que as fotos sejam colocadas na pasta build para que o path dos arquivos seja mais fimples.

Ex: make && /build/program.out sc1.png


**OBS:** A foto não precisa estar emm escala de cinza, o programa irá automaticamente convertê-la em escala de cinza para fazer a leitura.


### Bibliotecas e Ferramentas utilizadas

Implementamos o programa na linguagem C++, usando o Make para uma agilização e organização da compilação dos arquivos e geração de executáveis.

Usamos a biblioteca OpenCv para a manipulação dos pixeis da imagem e para a sua leitura.
A máscara de derivada foi implementadda manualmente como requisitado.

Para facilidade de leitura do código devido ao seu tamanho pequeno, todo o código está localizado no arquivo main.c dentro da pasta src.