# Alimentos y su Información Nutrimental.
**Proyecto Integral "A" de Programación de Estructuras de Datos.**  

Para este proyecto, se busca hacer un recopilatorio de información nutrimental de diversos alimentos.  

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


**Hecho por:**  
Cristian Leilael Rico Espinosa.  
Matrícula: A01707023.
