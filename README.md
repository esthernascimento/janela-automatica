# 🪟 Projeto Janela Automática com Arduino

Este projeto consiste em uma janela automatizada que abre e fecha com base na presença de chuva, utilizando um sensor de chuva, fim de curso, botões manuais e LEDs de indicação. Desenvolvido por Esther Nascimento, Gisele Nunes, Gabriel Sampaio e Hyago Inácio.

## 📋 Funcionalidades

- Modo **automático**: Fecha a janela ao detectar chuva e abre quando não há.
- Modo **manual**: Controle por botões para abrir ou fechar a janela.
- LEDs indicam o modo atual (automático ou manual).
- Sensores de fim de curso evitam que o motor force além do necessário.
- Comunicação via monitor serial para depuração.

## 🔌 Componentes Utilizados

- Arduino Uno
- Sensor de chuva
- Ponte H (L298N ou similar)
- Motor DC
- 2 sensores de fim de curso
- 3 botões (modo, abrir, fechar)
- 2 LEDs (modo manual/automático)
- Resistores de pull-up (internos)
- Jumpers e fonte de alimentação

## 🖥️ Esquema de Pinos

| Componente                   | Pino Arduino  |
|-----------------------------|---------------|
| Sensor de Chuva             | A0            |
| Fim de Curso - Janela Fechada | 12          |
| Fim de Curso - Janela Aberta  | 13          |
| Botão Modo Manual/Automático | 5           |
| Botão Abrir Manual           | 7           |
| Botão Fechar Manual          | 6           |
| LED Automático               | 8           |
| LED Manual                   | 9           |
| Motor IN1 (Ponte H)          | 3           |
| Motor IN2 (Ponte H)          | 2           |

## ⚙️ Como Funciona

- **Modo Automático**:
  - Se **não estiver chovendo**, a janela **abre** automaticamente.
  - Se **começar a chover**, a janela **fecha** automaticamente.
- **Modo Manual**:
  - O usuário controla a janela com os botões "Abrir" e "Fechar".

A alternância de modo é feita através de um botão específico. LEDs indicam se o sistema está em modo manual ou automático.

## 🧠 Lógica de Controle

- Leituras do sensor de chuva definem o estado "chovendo" (valores < 800).
- Fins de curso impedem que o motor continue girando após abrir/fechar totalmente.
- Botões manuais só têm efeito em modo manual.

## 📦 Estrutura do Código

O projeto está todo implementado no `janela-automatica.ino`. As principais funções são:
- `abrirJanela()` – Aciona o motor para abrir.
- `fecharJanela()` – Aciona o motor para fechar.
- `pararMotor()` – Para o motor completamente.

## 👨‍💻 Autores

- Esther Nascimento
- Gisele Nunes  
- Gabriel Sampaio  
- Hyago Inácio  

---

Projeto desenvolvido como parte de atividade educacional com Arduino e automação básica.
