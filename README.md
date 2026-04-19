# Programación 2 - Práctica 4

## Tablas de hash
A lo largo de la guía se construye el motor de un "Sistema de Gestión de Alumnos" universitario.

***Nota**: Los ejercicios son acumulativos. El código de un ejercicio sirve como base para el siguiente. También pueden hacer uso de clases de ejercicios pasados (lista encadenada) para agilizar la implementación.*

---
# Punto 1 — Funciones de hash

## 1.1 Método de la División
Implemente una función en C++ `int hashDivision(int clave, int m)` que aplique el método de la división: $h(k) = k \bmod m$.

- Pregunta:** ¿Si nuestro sistema espera unos 1000 alumnos inscritos, por qué sería una mala idea elegir $m = 1000$ o $m = 1024$? ¿Qué tipo de número debería ser $m$ y por qué?

## 1.2 - Método de la Multiplicación
Implemente una función `int hashMultiplicacion(int clave, int m)` usando el método de la multiplicación: $h(k) = \lfloor m \cdot ((k \cdot A) \bmod 1) \rfloor$, donde $A = (\sqrt{5} - 1) / 2 \approx 0.6180339887$. 
*(Ayuda C++: Para la parte fraccionaria use `modf` de `<cmath>` o simplemente `(k * A) - floor(k * A)`).*
- Pregunta: A diferencia del método de la división, el método de la multiplicación no exige que $m$ sea un número primo. ¿Por qué ocurre esto?

# Punto 2: Hash Cerrado

## 2.1 - Estructura Base y estado de celdas
Defina la estructura `Alumno` con atributos  `int legajo` y `string nombre`). 
Cree la clase `TablaHashCerrada`. Internamente debe tener un arreglo estático de alumnos y debe gestionar estado de cada celda (`LIBRE`, `OCUPADO`, `BORRADO`). (Ayuda: se puede agregar información al hash original o usar un arreglo paralelo y un enumerador (`enum`). Implementar un constructor que inicialice todas las ranuras como `LIBRE`.

## 2.2 - Inserción con Sondeo Lineal
Implemente el método `bool insertarLineal(Alumno a)` en su clase. Utilice `hashDivision` para encontrar la posición inicial. Si hay una colisión, aplique la política de *Sondeo Lineal* ($h(k, i) = (h'(k) + i) \bmod m$) para encontrar la siguiente ranura libre.

## 2.3 - Búsqueda, Factor de Carga y Agrupamiento
Agregue el método `Alumno* buscarLineal(int legajo)` y el método `float calcularFactorCarga()`, el cual debe retornar la relación $\alpha = n / m$.
- Pregunta: Notar que se forman grandes bloques de celdas contiguas ocupadas. ¿Cómo se llama este fenómeno y por qué el Sondeo Lineal es particularmente vulnerable a él? ¿Qué formas de evitar este problema se le ocurren?.

## 2.4 - Doble Hash
Para solucionar el problema del Ejercicio 4, implemente `bool insertarDobleHash(Alumno a)`. 
Diseñe una segunda función de hash $h_2(k) = 1 + (k \bmod (m - 1))$.
La secuencia de exploración ahora será: $h(k, i) = (h_1(k) + i \cdot h_2(k)) \bmod m$.
- Pregunta: ¿Por qué es críticamente importante que $h_2(k)$ jamás retorne el valor 0?

# Punto 3: Hash Abierto
A partir de este punto, suponer que la cantidad de alumnos crecerá dinámicamente y la versión implementada en Hash Cerrado se está quedando sin memoria constantemente. Pasaremos a la "Versión 2.0".

## 3.1 - Tabla de Hash abierto
Cree una nueva clase `TablaHashAbierta`. Internamente usará un arreglo de listas enlazadas: `ListaAlumno`.
Implemente el método `void insertar(Alumno a)`. Observe cómo el manejo de colisiones se simplifica al hacer un `InsertarAlFinal` en la lista correspondiente.

## 3.2 - Búsqueda y Eliminación
Implemente `bool eliminar(int legajo)` y `Alumno* buscar(int legajo)` para la tabla hash abierta.
- Pregunta: ¿por qué eliminar un elemento en un Hash Abierto (Listas) es una operación trivial y limpia, mientras que en un Hash Cerrado (Direccionamiento Abierto) requiere el uso de "Lápidas" (marcas especiales. Estado `BORRADO`)?.

## 3.4 - Rehashing Dinámico
Modifique el método `insertar` de su `TablaHashAbierta`. Justo antes de insertar, verifique el factor de carga. Si $\alpha > 0.75$, ejecute un método privado `void rehash()`.
El método `rehash` debe duplicar el tamaño $m$ del vector al siguiente número primo disponible, y reubicar todos los nodos existentes en las nuevas listas.
- Pregunta: Sabiendo que la operación `rehash()` cuesta $O(n)$, explique utilizando el concepto de **costo computacional amortizado** por qué podemos seguir afirmando que la inserción en nuestra tabla hash sigue siendo, en promedio, $O(1)$.
