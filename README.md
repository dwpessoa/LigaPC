# LigaPC
Timer para forçar a inicialização do PC após ocorrer queda de energia usando um relé.

Isso resolve quando PC com BIOS antiga que não tem suporte para "Auto Power On" ou "Restore Power On"

## Ligação
- Usando Arduino UNO
- Pino D8 > A1 do Relé

## Funcionamento
1. Ao ligar o Arduino ocorre um atraso de 10 segundos (se houver oscilação da rede evita ligar desnecessáriamente)
2. Após o atraso o relé é ligado por 1 segundo e em seguida desligado


Coisa beeeeeeeeeeeeeeeeeeeeeeeeeeem simples... :)


