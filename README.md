# 💖 Vivômetro {{{ Se tá vivo, tem jogo! }}}

**Vivômetro** é um contador de vida digital para jogos como *Magic: The Gathering*, desenvolvido para telas *touchscreen* com Arduino e display TFT. O projeto evolui em versões incrementais, sempre com foco em simplicidade, jogabilidade e uma interface intuitiva.

---

## 🚀 Funcionalidades por versão

### 🩸 **MVP (Versão Inicial)** (30/10/2025)
- Contador de energia individual (1 jogador)
- Interface simples com toque direto na tela

### 👥 **v1** (31/10/2025)
- Suporte para **1, 2 ou 4 jogadores**

### ⚖️ **v2** (01/11/2025)
- Opção de iniciar com **20, 30 ou 40 pontos de vida**

### ⚔️ **v3** (02/11/2025)
- Inclusão do **dano de comandante**

### 🧹 **v4** (08/11/2025)
- **Remoção do calibrador** de toque manual (já calibrado)

---

## 🧭 Próximos passos

| Versão | Funcionalidade planejada |
|--------|---------------------------|
| **v5** | Sorteador de jogador inicial |
| **v6** | Contador de veneno |
| **v7** | Melhorias de usabilidade e interface |

---

## 🔧 Requisitos de hardware

- **Arduino UNO**, **MEGA** ou similar (Placa Arduino Uno R3 Atmega328p SMD)
- **Display TFT / Tela touchscreen** compatível com a biblioteca `MCUFRIEND_kbv` (Tela / Display LCD Tft 2.4' Touchscreen R3)
- **Alimentação de energia** (cabo adaptador para arduino bateria 9v)

### 📚 Bibliotecas necessárias

- `MCUFRIEND_kbv`  
- `Adafruit_GFX`  
- `TouchScreen`

---

## 🕹️ Como usar

1. Faça o upload do código para o seu Arduino.
2. Conecte o display visual TFT.
3. Toque na tela para escolher quantidade de vida (**20**, **30** ou **40 de vida**).
4. Escolher o modo (**1**, **2** ou **4 jogadores**).
5. Toque no **"-"** e no **"+"** para remover ou adicionar pontos de vida.  
6. **Divirta-se**!

---

## 💡 Sobre o nome

> **Vivômetro**  
> *Se tá vivo, tem jogo!*

Um nome simpático, inspirado em *“life counter”*, mas com um toque de humor e brasilidade.

---

## 📄 Licença

Este projeto é de código aberto sob a licença **MIT**.  
Sinta-se à vontade para usar, modificar e contribuir.

---

🧑‍💻 **Autoria:** [Iara Nascimento](https://github.com/IaraNascimento)  
💬 *Feito com carinho, lógica e um toque de magia.*
