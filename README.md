# Alimentos y su Información Nutrimental.
**Proyecto Integral "A" de Programación de Estructuras de Datos.**  

Para este proyecto, se busca hacer un recopilatorio de información nutrimental de diversos alimentos.
Hasta este avance, el programa despliega un menú con 3 opciones:   
* Leer los datos: Carga los datos que se encuentran en un archivo con extensión *".txt"* y sus valores son almacenados en un vector de una clase en específico.
* Mostrar los datos: Como su nombre lo dice, muestra los datos que han sido almacenados.
* Ordenar los nombres: Ordena los nombres de los alimentos y despliega la lista con los nombres antes y después de pasar por un algoritmo de ordenamiento.   

# Avance 1

## SICT0302B: Toma decisiones

### Selecciona un algoritmo de ordenamiento adecuado al problema
Si bien por el momento el método de ordenamiento no resulta complicado, como se espera que la lista de alimentos se incremente o, que después de un tiempo a esta se le pueda agregar nueva información, se considera que el uso del método ***Merge*** es el más adecuado gracias a la rapidez con la que este trabaja y lo útil que podría resultar si la lista crece y hay una mayor cantidad de datos a ordenar.   
Este método puede verse dentro del archivo *sorts.h*, donde se encuentra elaborado y su aplicación en el main se observa en la **línea 113**.   

## SICT0301B: Evalúa los componentes

### Hace un análisis de complejidad correcto y completo para todo el programa y sus compenetes.
Hasta el momento, el único método a analizar es:   
* *ordenaMerge* posee una complejidad de ***O(n log(n))*** para todos sus casos con una complejidad espacial de ***O(n)***.   

## SICT0303B: Implementa acciones científicas

### Implementa mecanismos de lectura de archivos correctos y útiles dentro de un programa.   
Los alimentos se encuentran registrados dentro del archivo *"datost.txt"* los cuales son leídos mediante la primera opción.   

# Avance 2   
*Nota: Por la complejidad que se presentaba a la hora de almacenar datos de una clase, el archivo se revirtió a una versión en la cual no se hacía uso de la misma **(avance1OrdenaSim)**.*   

Para ver el avance anterior, puede cambiar a la rama **Avance 1**.   

En este avance, la información procedente del archivo es almacenada directamente en una lista; las funciones nuevas que se pueden realizar son:   
* Agregar un alimento: Como su nombre lo indica, el usuario puede agregar información sobre un alimento.
* Eliminar un alimento: El ususario es capaz de eliminar la información sobre algún alimento especificando la posición en la que este se encuentre dentro de la lista.   

*Se pierde la opción de ordenar un arreglo*.

## SICT0301B: Evalúa los componentes

### Hace un análisis de complejidad correcto y completo para todo el programa y sus compenetes.
Al implementar una lista ligada simple, el poder acceder a ella tendría una complejidad de ***O(n)*** y tanto la inserción y supresión de un elemento se ejecuta con una complejidad de ***O(1)***, todo esto para el **peor de los casos**.


# Avance 3

Para este avance, se integran los resultados de las dos actividades anteriores.   
Al archivo '.txt' inicial se le agregaron nuevos elementos y se integraron ambos menús en el main; el programa iniciará brindándole al usuario la oportunidad de agregar y eliminar datos para que posteriromente los cambios realizados sean guardados en un nuevo archivo de texto que será utilizado para generar un vector de tipo *comida* cuyos elementos serán ocupados para llevar un ordenamiento ya sea por medio de un **Merge** o haciendo uso de un **Árbol Binario**.   
Dentro de este programa, las opciones con las que el usuario puede interactuar son:   

**Menú 1**   
* Mostrar los datos: Como su nombre lo dice, muestra los datos que han sido cargados.
* Agregar un alimento: Como su nombre lo indica, el usuario puede agregar información sobre un alimento.
* Eliminar un alimento: El ususario es capaz de eliminar la información sobre algún alimento especificando la posición en la que este se encuentre dentro de la lista. 
* Terminar con la edición: Finaliza el ciclo que se da en el primer menú para posteriormente guardar los cambos realizados en un nuevo *.txt.* que será cargado para el siguiente ciclo.   

**Menú 2**   

* Mostrar los datos: Como su nombre lo dice, muestra los datos que han sido almacenados.
* Buscar por nombre: Le permite al usuario mostrar los datos de un alimento en específico.
* Ordenar por calorías: Ordena los  alimentos de menor a mayor calorías después de uqe estos pasen por un *BST*.
* Ordenar los nombres: Ordena los nombres de los alimentos y despliega la lista después de pasar por un algoritmo de ordenamiento.

## SICT0302B: Toma decisiones

### Selecciona un algoritmo de ordenamiento adecuado al problema.

Si bien por el momento el método de ordenamiento no resulta complicado, como se espera que la lista de alimentos se incremente o, que después de un tiempo a esta se le pueda agregar nueva información, se considera que el uso del método ***Merge*** es el más adecuado gracias a la rapidez con la que este trabaja y lo útil que podría resultar si la lista crece y hay una mayor cantidad de datos a ordenar.

### Selecciona y usa una estructura lineal adecuada al problema.

Se decidió hacer uso de una *lista simple* ya que los archivos con los que se trabajan no requieren ser agregados a una lista que esté doblemente ligada para el tipo de actividades que se harán con ellos.   

### Usa un árbol adecuado para resolver un problema.

Se integró un **Árbol de Búsqueda Binaria** para que resultase sencillo el ordenamiento y acomodo de los datos a utilizar; al tener valores que continuamente cambian de valor, no consideré que fuera necesario utilizar un *AVL* al no necesitar que las ramas comiencen a acomodarse.

## SICT0301B: Evalúa los componentes

### Hace un análisis de complejidad correcto y completo para todo el programa y sus compenetes.

* *ordenaMerge* posee una complejidad de ***O(n log(n))*** para todos sus casos con una complejidad espacial de ***O(n)***.
* Al implementar una lista ligada simple, el poder acceder a ella tendría una complejidad de ***O(n)*** y tanto la inserción y supresión de un elemento se ejecuta con una complejidad de ***O(1)***, todo esto para el **peor de los casos**.
* El uso de un **Árbol de Búsqueda Binaria** posee una complejidad de ***O(n)*** para los *peores casos* en inserción de datos, el acceso al árbol y la búsqueda de valores.
* El uso de búsqueda por nombre tiene una complejidad de ***O(n)*** para el peor de sus casos al tratarse de un *if* que se encuentra dentro de un *for*.

## SICT0303B: Implementa acciones científicas

### Implementa mecanismos para consultar información de las estructuras correctos y útiles dentro de un programa.

Para este último avance se permite encontrar un alimento especificando su nombre, el usuario debe de introducirlo asegurándose de respetar las mayúsculas y los espacios generados por un guion bajo ('**_**'). Después de ingresarlo, el programa mostrará todas las características de dicho alimento.   
De igual manera, siempre es posible despelgar la lista con todos los elementos.   

### Implementa mecanismos de lectura de archivos correctos y útiles dentro de un programa.

En varias partes del programa, la creación y carga de los archivos *.txt* se lleva a cabo; el programa trabaja adquiriendo la información de estos archivos y las agrega a las variables correspondientes.

### Implementa mecanismos de escritura de archivos correctos y útiles dentro de un programa.

En varias partes del programa, la creación y carga de los archivos *.txt* se lleva a cabo; dentro del primer menú, el usuario es capaz de alterar la lista inicial de alimentos y sus cambios son guardados en un nuevo documento que será utilizado en el siguiente menú.   


**Hecho por:**  
Cristian Leilael Rico Espinosa.  
Matrícula: A01707023.
