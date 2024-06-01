# Project Krie~~k~~gBot

## liens amazon

- moteurs+roues (x2) 7€/robot (https://www.amazon.fr/%C3%A9lectrique-Vitesses-Engrenages-Plastique-Arduino/dp/B096Z5C3R4/)
- servo 2€/robot (https://www.amazon.fr/Miuzei-H%C3%A9licopt%C3%A8re-Voiture-V%C3%A9hicule-Commande/dp/B07KPS9845/)
- driver MX1508 2€/robot (https://www.amazon.fr/pi%C3%A8ces-Moteur-Contr%C3%B4leur-Vitesse-H-Bridge/dp/B09VSF8XNW/)
- Nucleo L432KC gratuit
- VL53L1X (x2) gratuit
- capteur position moteur (x2) 4€/robot (https://www.amazon.fr/dp/B0817H9436)
- PCB...
- PLA...

Prix total élec : 15€ le robot

## Fonctions utilisables 

Toutes les classes ont les méthodes suivantes : 
```cpp
begin(...)
end()
```

### Commandes moteurs

```cpp
// Precise commands
setSpeeds(int32_t speed_left, int32_t speed_right);

// Less precise commands
move(Direction_t dir, int32_t speed); // dir : FEURWARD, BACKWARD, LEFT, RIGHT

// Position-wise commands ???
goForward(int32_t dist_mm); // go forward at base speed
goBackward(int32_t dist_mm); // go backward at base speed
turnLeft(int32_t angle_degrees); // turn 90° left
turnRight(int32_t angle_degrees); // turn 90° right

// JUST STOP
stop(); // stop any movement
```

### Capteurs 

```cpp
getDistance(); // Get last measurement of a sensor (in mm)
```

### Servo

A priori utiliser un servo 300° si possible... sinon 180° normalement OK

Servo regarde vers l'avant ou l'arrière ?? 

```cpp
setAngle(int32_t angle); // Should be in °, with 0 being forward, positive to the left (cuz trigonometry)

lookForward(); // setAngle(0);
lookRight(); // setAngle(-90);
lookLeft(); // setAngle(90);
```

# Composants et tailles

| Nom du composant                     | Quantité | Dimensions (mm)      | Restrictions                         | Commentaires |
| ------------------------------------ | -------- | -------------------- | ------------------------------------ | ------------ |
| Nucleo L432KC                        | 1        | 58.42 x 22.86        | Sur le PCB                           |              |
| Driver MX1508                        | 1        | 24.7 x 21            | Sur le PCB                           |              |
| Moteur DC Jaune ?                    | 2        | 37 x 37 x 22         | Contact roues + codeurs incrémentaux |              |
| Servo 180°                           | 1        | 23 x 12.2 x 29       | Face haute libre pour capteur        |              |
| Capteur ToF VL53L1X (breakout board) | 2 (3?)   |                      | Un à l'avant, un sur le servo        |              |
| Roues                                | 2        | (cylindre) h:?? d:?? | Sur le côté, moteurs                 |              |
| Capteur de sol (?)                   | 1        |                      |                                      |              |