# ltpp_p2
Entregable
Una vez efectuados todos los ejercicios planteados en la práctica, proponemos efectuar una
implementación dinámica del tipo de datos diccionario en C, algo que encontramos en otros
lenguajes de programación como Python.

Podríamos pensar que un diccionario funciona como un ‘diccionario en la vida real’
Un diccionario es una colección de pares (clave, valor). Podría ser considerado como una especie
de array dinámico, donde los índices (las claves) no tienen por qué ser necesariamente números
enteros. 
El diccionario que implementaremos poseerá las siguientes características:
- Será dinámico, en el sentido de que no se creará el par (clave, valor) hasta que sea
necesario. 
Deberá trabajar por tanto internamente con listas enlazadas de nodos.
- Tanto claves como valores pertenecerán a los tipos de datos int, float o char*, es decir,
números y strings.
- Como C es fuertemente tipado, necesitaremos rutinas de conversión de tipos de datos
para almacenar/recuperar los elementos del diccionario.
- Un diccionario, por definición, no permite claves duplicadas. Si insertamos un valor con
una clave que ya existe, el valor asociado a la clave ha de ser modificado (cambiar el valor
para dicha clave)
Para ello planteamos implementar una nueva librería. Como hemos visto en el punto 5, crearemos
dos ficheros:
- dict.c: este fichero contendrá la definición/implementación de todas las operaciones de
la librería.
- dict.h: este fichero contendrá la declaración de los tipos de datos y las operaciones que
se implementarán en dict.c. Cualquier programa que desee trabajar con nuestra librería
deberá primero incluir (#include) este fichero.