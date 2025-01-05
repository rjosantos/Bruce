#include "PowerOffMenu.h"
#include "core/display.h"
#include "core/settings.h"

void PowerOffMenu::optionsMenu() {

    digitalWrite(PIN_POWER_ON,LOW); 
    esp_sleep_enable_ext0_wakeup(GPIO_NUM_6,LOW); 
    esp_deep_sleep_start();

}

void PowerOffMenu::drawIcon(float scale) {
    // Limpa a área do ícone (ajuste para sua implementação)
    clearIconArea();

    // Define o raio base
    int radius = scale * 30;
    float outerRadius = 1.1f * radius;
    float innerRadius = radius;

    // Desenha o arco do símbolo de power
    tft.drawArc(
        iconCenterX,
        iconCenterY,
        outerRadius,         
        innerRadius,        
        0,
        140,
        bruceConfig.priColor,  
        bruceConfig.bgColor
    );

    // Desenha o arco do símbolo de power
    tft.drawArc(
        iconCenterX,
        iconCenterY,
        outerRadius,         
        innerRadius,        
        220,
        360,
        bruceConfig.priColor,  
        bruceConfig.bgColor
    );

    // Agora, desenhamos a “barrinha” vertical do power com mais espessura
    // Para isso, desenhamos várias linhas paralelas, simulando grossura.
    // Ajuste quantas linhas quiser para ficar mais grosso ou mais fino.
    int lineThickness = 5;  // tente variar para mais ou menos espesso
    for (int i = -(lineThickness / 2); i <= (lineThickness / 2); i++) {
        tft.drawLine(
            iconCenterX + i,                  // desloca horizontalmente pra engrossar
            iconCenterY - (radius * 1.1f),   // ponto de início (topo)
            iconCenterX + i,
            iconCenterY - (radius * 0.05f),   // ponto de fim (pouco acima do centro)
            bruceConfig.priColor
        );
    }
}