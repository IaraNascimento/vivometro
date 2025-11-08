# 💖 Vivômetro

**Vivômetro** é um contador de vida digital para jogos de cartas como *Magic: The Gathering*, desenvolvido para telas *touchscreen* com Arduino e display TFT.  
O projeto evolui em versões incrementais, sempre com foco em simplicidade, jogabilidade e uma interface intuitiva.

---

## ⚙️ Estrutura do projeto

```cpp
// counter.ino
#include "display.h"
#include "touch.h"
#include "modes.h"
#include "draw_screens.h"
#include "logic.h"

void setup() {
  Serial.begin(9600);
  uint16_t ID = tft.readID();
  tft.begin(ID);
  tft.setRotation(1);
  // calibrateTouch();
  drawModeSelectLife();
}

void loop() {
  processTouch();
}
```

---

## 📁 Cada módulo é responsável por uma parte específica da aplicação

| Arquivo | Função |
|----------|--------|
| **display.h** | Inicializa e configura o display TFT |
| **touch.h** | Lida com a leitura e calibração do toque |
| **modes.h** | Gerencia os diferentes modos de jogo (1, 2, 4 jogadores, etc.) |
| **draw_screens.h** | Desenha as telas e elementos gráficos |
| **logic.h** | Contém a lógica principal de interação e atualização de vida |

---

## 🚀 Funcionalidades por versão

### 🩸 **MVP (Versão Inicial)**
- Contador de energia individual (1 jogador)
- Interface simples com toque direto na tela

### 👥 **v1**
- Suporte para **1, 2 ou 4 jogadores**

### ⚖️ **v2**
- Opção de iniciar com **20, 30 ou 40 pontos de vida**

### ⚔️ **v3**
- Inclusão do **dano de comandante**

### 🧹 **v4**
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

- **Arduino UNO**, **MEGA** ou similar  
- **Display TFT** compatível com a biblioteca `MCUFRIEND_kbv`  
- **Tela touchscreen** resistiva  

### 📚 Bibliotecas necessárias

- `MCUFRIEND_kbv`  
- `Adafruit_GFX`  
- `TouchScreen`

---

## 🕹️ Como usar

1. Faça o upload do código para o seu Arduino.  
2. Conecte o display TFT.  
3. Toque na tela para escolher o modo (**1**, **2** ou **4 jogadores**).  
4. Toque nos números para adicionar ou remover pontos de vida.  
5. Divirta-se jogando! 🎲

---

## 💡 Sobre o nome

> **Vivômetro**  
> *Se tá vivo, tá valendo!*

Um nome simpático, inspirado em *“life counter”*, mas com um toque de humor e brasilidade.

---

## 📄 Licença

Este projeto é de código aberto sob a licença **MIT**.  
Sinta-se à vontade para usar, modificar e contribuir.

---

🧑‍💻 **Autoria:** [Iara Nascimento](https://github.com/IaraNascimento)  
💬 *Feito com amor, lógica e um toque de magia.*
