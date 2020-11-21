STATO READY:

- AZIONE: inizializza var time / interrupt timer

- AZIONE: ACCENDI L1

- AZIONE: scrivi stato su seriale

- TASK : leggi pot e scrivi freq su seriale

- TASK : Leggi bottone bstart /  INTERRUPT :interruzione su bottone

- TASK / INTERRUPT : gestire timer per sleep_time

- EXIT : leggi sonar e cambia stato

  

STATO SLEEP:

- AZIONE: spegni L1
- AZIONE: Scrivi stato su seriale
- AZIONE: attiva interrupt su pir
- AZIONE: Attiva risparmio energetico
- EXIT: disattiva interrupt su pir



STATO ESP_NON_PARTITO:

- AZIONE: inizializza var time
- AZIONE: scrivi stato su seriale

- TASK : blink L2

- TASK / INTERRUPT: check time per blinking per error_time

  

STATO ESP_PARTITO:

- AZIONE: accendi L2
- AZIONE: inzializza var time
- AZIONE: scrivi stato su seriale
- TASK: traccia l'oggetto
- TASK: elabora dati
- TASK: aggiorna / setta tachimetro
- TASK: scrivi dati su seriale
- TASK / INTERRUPT: leggi Bstop 
- TASK / INTERRUPT : controlla timer per MAX_TIME



STATO ESP_TERMINATO:

- AZIONE: scrivi stato su seriale

- TASK : blink L2

- TASK: leggi dati da seriale

  

# Dubbio #  

TimerTask viene gestito dentro ReadyTask o fuori da tutto??