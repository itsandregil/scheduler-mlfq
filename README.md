# Scheduler MLFQ

Programa en la terminal que simula la ejecución de un algoritmo MLFQ para la orquestación de procesos en la CPU.

## Tecnologías
- C

## Features
- Uso de Colas implementadas con Listas Ligadas
- Visualización de la ejecución de los procesos en las colas
- Resultados almacenados en archivo `.csv`

## Estructura del Código
```text
.
├── include/                # Archivos de cabecera (.h) compartidos por el proyecto
│
├── src/                    # Código fuente principal
│   ├── process/
│   ├── queue/
│   ├── scheduler/
│   ├── utils/
│   └── main.c
│
├── .gitignore
├── Makefile
└── README.md
```


### Makefile

```bash
make all     # Compila todo el proyecto
make clean   # Elimina archivos generados durante la compilación
make run     # Compila y ejecuta el programa compilado
```

## Getting Started

Sigue estos pasos para clonar, compilar y ejecutar el proyecto.

```bash
# Clonar el repositorio
git clone <URL_DEL_REPOSITORIO>
cd <NOMBRE_DEL_REPOSITORIO>

# Compilar y ejecutar el programa
make run

# Limpiar archivos de compilación (opcional)
make clean
```
