# Casos de uso



### Añadir alumno

** ID:** 001  
** Breve descripción:** El sistema le permite al profesor añadir a un alumno


** Actores principales:** Profesor  
**Actores secundarios:** Alumno


** Precondiciones:**
1. El alumno debe validarse por el profesorado.
2. El alumno no deberá existir previamente.

** Flujo principal:**
1. Se pide al profesor los datos del nuevo alumno.
2. Se compueba que no exista dicho alumno en la base de datos.
3. Se persiste los datos en la base de datos.


** Postcondiciones:**
1. El alumno añadido se podrá mostrar por pantalla.
2. El alumno quedará registrado en el sistema.


** Flujos alternativos:**

* Si algunos de los campos introducidos a la hora de añadir al usuario son incorrectos, aparecerá el mensaje de error.



---

### Búsqueda de alumno
** ID:** 002  
** Breve descripción:** El sistema nos permite realizar una búsqueda para encontrar al usuario que se desea.


** Actores principales:** Profesor  
**Actores secundarios:** Alumno


**Precondiciones:**
1. El alumno debe de existir en el sistema

**Flujo principal:**

1. EL caso de uso comienza cuando el profesor desea buscar los datos de un alumno.
2. El sistema recoge los datos del alumno


**Postcondiciones:**
1. El sistema busca y muestra los datos del usuario deseado.


**Flujos alternativos:**

* Si no existe el alumno muestra un mensaje de error.



---

### Modificar alumno
** ID:** 003    
**Breve descripción:** EL sistema nos permitirá cambiar los datos que deseemos relacionados con el alumno.


**Actores principales:** Profesor  
**Actores secundarios:** Alumno


**Precondiciones:** El alumno debe de existir en el sistema

**Flujo principal:**

1. EL caso de uso comienza cuando el profesor desea modificar los datos de un alumno.
2. El sistema recoge los datos del alumno
3. El sistema nos actualiza los datos

**Postcondiciones:**

1. El sistema actualizará los datos, una vez que se hayan actualizado.
2. El sistema reflejará los cambios en la base de datos 


**Flujos alternativos:**

* Si el alumno que se desea modificar no se encuentra en la base de datos, aparecerá un mensaje de error.



---

### Borrar alumno
** ID:** 004  
**Breve descripción:** El sistema permitirá eliminar al alumno deseado


**Actores principales:** Profesor  
**Actores secundarios:** Alumno


**Precondiciones:**
1. El alumno debe de existir en el sistema

**Flujo principal:**
1. Se piden los datos del alumno a borrar.
2. Se compueba que el alumno existe en la base de datos.
3. Se elimina dicho alumno de la base de datos.


**Postcondiciones:**

1. Los alumnos seleccionados para ser eliminados desaparecerán del sistema si así lo desea el profesorado. En cualquier otro caso no se daría postcondición alguna.


Flujos alternativos:

* Si no existe el alumno muestra un mensaje de error.



---

### Exportar información de alumno
** ID:** 005  
**Breve descripción:** El sistema exportará los datos de alumno o de una serie de alumnos


**Actores principales:** Profesor  
**Actores secundarios:** Alumno


**Precondiciones:** -

**Flujo principal:**

1. Se exporta en HTML
2. Se muestra en el navegador dicho documento HTML al usuario

**Postcondiciones:**
1. El sistema creará un archivo donde estarán reflejadas la información del alumno


**Flujos alternativos:**  
ninguno


---

### Importar/exportar copias de seguridad
** ID:** 006  
**Breve descripción:** El sistema permite realizar y cargar copias de seguridad sobre los datos de alumnado


**Actores principales:** Profesor  
**Actores secundarios:** Alumno


**Precondiciones:**
1. Para la exportación de la base de datos se ha creado y esta 'caliente'

**Flujo principal:**
1. Se pide al usuario la ruta de exportación/importación
2. Se exporta/importa la base de datos

**Postcondiciones:**
1. Para la exportación de la base de datos, esta no se modificará durante la exportacion, creando una copia de esta en el directorio preestablecido o indicado por el usuario.
2. Para la importación de la base de datos, instancia de la base de datos ha de ser creada con anterioridad con la útilidad de 'exportación'
3. Para la importación de la base de datos, la base de datos reflejará los mismos datos que en la instancia de esta, en el momento de la posterior exportación.


**Flujos alternativos:**  
ninguno
