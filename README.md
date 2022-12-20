<h1 align = center> PIM - IV </h1>

***Curso: Análise e Desenvolvimento de Sistemas - UNIP - 2022***

## 👩🏻‍💻👩🏻‍💻👨🏻‍💻Integrantes:

- 2273384 - BEATRIS ANTUNES SILVA 

- 2292834 - BIANCA ANTUNES SILVA

- 2292870 - MÁRCIO SANTANA PORTELA

## 📑Descrição do Problema:

O projeto tem o intuito de desenvolver um sistema de cadastro de casos da COVID-19 em linguagem C, bem como a utilização dos fundamentos de engenharia de software para  administrar o progresso do projeto.
O sistema será utilizado pelos hospitais para registro e acompanhamento de casos positivos de COVID-19, onde os pacientes cadastrados serão verificados pelo software e se está no grupo de risco, arquivados externamente, permitindo assim consultas. 


## 🔗Link:
[Site ](http://www.codeblocks.org/)

Ao receber o diagnóstico positivo os profissionais da saúde devem realizar o login no sistema (informando o usuário e a senha) e
informar os dados pessoais do paciente, como:
- Nome;
- CPF;
- Telefone;
- Endereço (Rua, Número, Bairro, Cidade, Estado e CEP);
- Data de Nascimento;
- E-mail;
- Data do diagnóstico;
- Informar alguma comorbidade do paciente (diabetes, obesidade, hipertensão, tuberculose, outros);

Serão salvos em um arquivo (a principal vantagem de um arquivo é que as informações
armazenadas podem ser consultadas a qualquer momento).

Após o cadastro, o sistema deverá calcular a idade e verificar se o paciente possui
alguma comorbidade e se pertence ao grupo de risco (maiores de 65 anos). Caso o paciente
pertença ao grupo de risco o sistema deverá salvar em um arquivo de texto o CEP e a idade
do paciente para que essa informação possa ser enviada para a central da Secretaria da
Saúde da cidade.

## 📝  Instruções Para Compilação:

 1 - Instale o CodeBlocks no seu sistema.

 Caso esteja usando uma distribuição linux baseada no Ubuntu você pode instalar o CodeBlocks executando o comando abaixo:
 ```
sudo apt install codeblocks --install-suggests
 ```

 2 - Clone este repositório. No Linux, abra o terminal e digite:
 ```
 git clone https://github.com/beatrisantunes/PIM-IV.git
 ```

 3 - No seu gerenciador de arquivos, navegue até o diretório PIM-IV e abra o arquivo 'pim.cbp' utilizando o CodeBlocks. O projeto será aberto.

 4 - Para executar, com o projeto aberto no CodeBlocks, vá em 'Build > Build and Run' e o programa será executado.

## 🔗Link Parte Escrita:
[Projeto ](https://github.com/beatrisantunes/PIM-IV/blob/main/PROJETO%20CADASTRO%20DE%20PACIENTES%20DA%20COVID-19%20EM%20C.docx)

## 💻🛠 Tecnologias e Ferramentas:
- C
- Git e Github

## 📌 Resultado:

1 - Ao rodar o projeto, a seguinte tela vai aparecer: 

 <img width="500" src="https://i.imgur.com/Ds26kE0.png">

2 - Ao selecionar a opção 1, será direcionado para a tela de login:

 <img width="500" src="https://i.imgur.com/76V9au0.png">
 
3 - Ao selecionar 2, será direcionado para a tela de cadastro de novo usuário:

 <img width="500" src="https://i.imgur.com/sm2VUXt.png">

4 - Após inserir um novo login e senha e apertar enter, um novo usuário será criado:

 <img width="500" src="https://i.imgur.com/kpYbnyo.png">
 
5 - Ao realizar login, o usuário será direcionado à tela principal:

  <img width="500" src="https://i.imgur.com/xkaU6s2.png">

6 - Caso selecione a opção 1, será direcionado à tela de consulta de pacientes cadastrados no sistema:

 <img width="500" src="https://i.imgur.com/Y42vTOK.png">
 
7 - Caso a opção 2 seja selecionada, será direcionado à tela de consulta de pacientes no grupo de risco:

 <img width="500" src="https://i.imgur.com/mBygNNa.png">

8 - Já, ao selecionar a opção 3, a tela para qual será direcionado é a tela de cadastro de novos pacientes:

 <img width="500" src="https://i.imgur.com/H5wmDZh.png">
 
9 - Ao preencher todas as informações e pressionar enter o programa irá perguntar se deseja salvar:

<img width="500" src="https://i.imgur.com/4iLWNQ8.png">

> Telas do software

Software operando em CodeBlocks.
