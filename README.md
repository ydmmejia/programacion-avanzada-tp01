# TP01 - Programación Avanzada en C++

**Universidad Nacional de Colombia - Sede La Paz**  
**Programa Académico:** Ingeniería Mecatrónica  
**Curso:** Programación Avanzada  
**Docente:** Ing. Mauro Baquero-Suárez.  
**Octubre 2025**

---

## Equipo de Desarrollo

Este trabajo fue desarrollado colaborativamente por:

- Juan David Jaimes Rebolledo
- Sebastian Camilo Nova Ovalle
- Yeison David Mejia Mosquera

---

## Acerca de Este Proyecto

Primer trabajo práctico del curso, enfocado en repasar y fortalecer fundamentos de programación en C++. Se implementaron cinco ejercicios progresivos que van desde operaciones básicas hasta algoritmos avanzados de álgebra lineal computacional.

**Distribución de puntaje:**
- Ejercicio 1: 10%
- Ejercicio 2: 20%
- Ejercicio 3: 10%
- Ejercicio 4: 20%
- Ejercicio 5: 40%

---

## Organización del Código

```
.
└── src/
    ├── ejercicio1.cpp    → Calculadora básica con validaciones
    ├── ejercicio2.cpp    → Búsqueda de extremos en arreglos
    ├── ejercicio3.cpp    → Análisis de cadenas de texto
    ├── ejercicio4.cpp    → Cálculo de normas vectoriales
    └── ejercicio5.cpp    → Operaciones con matrices
```

---

## Requisitos Técnicos

**Compilador requerido:**
- GCC/G++ (versión 7.0 en adelante)
- Alternativamente: Microsoft Visual Studio 2017+

**Estándar de C++:** Mínimo C++11

**Dependencias:** Solo librerías estándar de C++
- `<iostream>` para entrada/salida
- `<vector>` para contenedores dinámicos
- `<string>` para manejo de texto
- `<cmath>` para operaciones matemáticas
- `<cctype>` para manipulación de caracteres
- `<iomanip>` para formateo de salida

---

## Guía de Compilación

### Método 1: Línea de Comandos

**Sistema Linux/Mac:**
```bash
g++ -std=c++11 -Wall src/ejercicio1.cpp -o ejercicio1
./ejercicio1
```

**Sistema Windows (con MinGW):**
```cmd
g++ -std=c++11 -Wall src/ejercicio1.cpp -o ejercicio1.exe
ejercicio1.exe
```

### Método 2: IDE Visual Studio

1. Iniciar Visual Studio
2. Crear nuevo proyecto: "Aplicación de consola C++"
3. Reemplazar el código generado con el contenido del archivo deseado
4. Ejecutar con `F5` (con depurador) o `Ctrl+F5` (sin depurador)

### Método 3: Compilación en Batch (Windows)

Si prefieres compilar todos los ejercicios de una vez, ejecuta:
```cmd
for %%f in (src\*.cpp) do g++ -std=c++11 %%f -o %%~nf.exe
```

---

## Detalle de Ejercicios Implementados

### Ejercicio 1 - Calculadora de Operaciones Básicas

**Funcionalidad:** Programa interactivo que recibe dos valores numéricos y ejecuta las cuatro operaciones fundamentales.

**Implementación destacada:**
- Manejo robusto de división por cero
- Uso de tipo `double` para soportar decimales
- Validación de entrada del usuario

**Prueba rápida:**
```
Input: 15, 3
Output: Suma=18, Resta=12, Mult=45, Div=5
```

---

### Ejercicio 2 - Identificador de Valores Extremos

**Funcionalidad:** Analiza un conjunto de números para identificar el máximo y mínimo, incluyendo sus ubicaciones.

**Técnica utilizada:**
- Contenedor `vector<double>` de tamaño dinámico
- Estructura personalizada `ResultadoMinMax` para encapsular resultados
- Recorrido único del arreglo (eficiencia O(n))

**Arquitectura de la solución:**
```
Input → Vector dinámico → Búsqueda lineal → Struct resultado → Output
```

**Caso de prueba:**
```
Entrada: {8.2, -3.5, 15.7, 0.0, -7.1}
Salida: Max=15.7[pos:2], Min=-7.1[pos:4]
```

---

### Ejercicio 3 - Contador Inteligente de Vocales

**Funcionalidad:** Procesa texto ingresado por el usuario y cuantifica las vocales presentes.

**Características:**
- Lectura completa de línea con espacios mediante `getline()`
- Normalización a minúsculas con `tolower()`
- Detección de vocales: a, e, i, o, u

**Algoritmo:**
```
Texto → Normalización → Iteración carácter a carácter → Conteo → Resultado
```

---

### Ejercicio 4 - Calculadora de Normas Vectoriales

**Funcionalidad:** Calcula dos métricas fundamentales de vectores numéricos.

**Normas implementadas:**

**L₂ (Euclidiana):**
```
||v||₂ = √(v₁² + v₂² + ... + vₙ²)
```
Interpretación: Distancia desde el origen en espacio n-dimensional

**L∞ (Infinito):**
```
||v||∞ = max{|v₁|, |v₂|, ..., |vₙ|}
```
Interpretación: Componente de mayor magnitud absoluta

**Aplicaciones prácticas:**
- Medición de errores en algoritmos numéricos
- Análisis de convergencia
- Procesamiento digital de señales

**Ejemplo numérico:**
```
Vector: [3, -4, 0, 5]
L₂ = √(9+16+0+25) = √50 = 7.071
L∞ = max{3,4,0,5} = 5
```

---

### Ejercicio 5 - Sistema de Inversión Matricial

**Funcionalidad:** Herramienta completa para cálculo de inversas y pseudoinversas matriciales.

**Capacidades del sistema:**
1. Detección automática del tipo de matriz (cuadrada/rectangular)
2. Cálculo de determinante vía eliminación gaussiana
3. Inversión por método Gauss-Jordan
4. Pseudoinversa de Moore-Penrose para casos rectangulares
5. Verificación automática del resultado

**Flujo de trabajo:**

```
Matriz de entrada
    ↓
¿Es cuadrada?
    ├─ Sí → Calcular det
    │        ↓
    │   ¿det ≠ 0?
    │        ├─ Sí → Gauss-Jordan → Inversa
    │        └─ No → "Matriz singular"
    │
    └─ No → Moore-Penrose → Pseudoinversa
```

**Método Gauss-Jordan:**
- Construcción de matriz aumentada [A|I]
- Pivoteo parcial para estabilidad
- Reducción por filas
- Extracción de inversa

**Pseudoinversa (matrices m×n):**
```
A⁺ = (AᵀA)⁻¹Aᵀ
```

**Validaciones implementadas:**
- Detección de matrices singulares
- Verificación numérica (A·A⁻¹ ≈ I)
- Manejo de matrices mal condicionadas

**Caso de prueba 2×2:**
```
A = [4  7]    →    A⁻¹ = [ 0.6  -0.7]
    [2  6]              [-0.2   0.4]

Verificación: A·A⁻¹ = I ✓
```

---

## Estrategia de Pruebas

Cada ejercicio fue sometido a múltiples escenarios:

| Ejercicio | Casos Probados |
|-----------|----------------|
| 1 | Positivos, negativos, ceros, división por cero |
| 2 | Arreglos pequeños/grandes, duplicados, todos iguales |
| 3 | Texto sin vocales, solo vocales, mayúsculas/minúsculas |
| 4 | Vectores unitarios, negativos, ceros |
| 5 | Matrices 2×2, 3×3, singulares, rectangulares |

---

## Conceptos de Programación Aplicados

**Estructuras de Datos:**
- Arreglos dinámicos (`vector`)
- Estructuras personalizadas (`struct`)
- Matrices bidimensionales

**Paradigmas:**
- Programación estructurada
- Modularización con funciones
- Paso por referencia para eficiencia

**Algoritmos:**
- Búsqueda lineal
- Eliminación gaussiana
- Método de Gauss-Jordan
- Procesamiento de cadenas

**Buenas Prácticas:**
- Validación de entrada
- Manejo de casos límite
- Código autodocumentado
- Separación de lógica y presentación

---

## Material de Consulta

- **Bjarne Stroustrup** - "The C++ Programming Language" (4ta Edición, 2013)
- **cplusplus.com** - Referencia del lenguaje C++
- **cppreference.com** - Documentación técnica completa
- Material didáctico del curso - UNAL Sede La Paz

---

## Información de Contacto

**Desarrolladores:**
- Juan David Jaimes Rebolledo
- Sebastian Camilo Nova Ovalle  
- Yeison David Mejia Mosquera

**Institución:** Universidad Nacional de Colombia  
**Sede:** La Paz  
**Programa:** Ingeniería Mecatrónica

---

## Observaciones Finales

- Código probado en Windows 10/11 con Visual Studio 2022
- Compatible con compiladores que soporten C++11 o superior
- Sin dependencias externas - solo librerías estándar
- Código fuente disponible en formato .cpp para facilitar revisión

---

**Entrega:** 17 de Octubre, 2025  
**Repositorio:** github.com/[yemejiam]/programacion-avanzada-tp01